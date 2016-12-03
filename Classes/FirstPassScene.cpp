#include "FirstPassScene.h"
#include "FirstPassPauseScene.h"
#include "VictoryScene.h"
#include "FailureScene.h"

int FirstPass::myNumberOfWholeZombie = 0;

Scene* FirstPass::createScene(){
	auto scene = Scene::create();
	auto layer = FirstPass::create();
	scene->addChild(layer);
	return scene;
}

bool FirstPass::init(){
	if (!Layer::create()){
		return false;
	}

	/* Background */
	auto mapTmx = TMXTiledMap::create("OhMap.tmx");
	this->addChild(mapTmx);

	mySunshine = INITIAL_SUNSHINE;
	myLastUpdateSunshine = INITIAL_SUNSHINE;
	mySunshineLabel = Label::create(Value(mySunshine).asString(), "Broadway", 30);
	mySunshineLabel->setColor(Color3B::ORANGE);
	mySunshineLabel->setPosition(Point(0.5f*LENGTH_OF_SIDE, (HEIGHT - 0.75f)*LENGTH_OF_SIDE));
	this->addChild(mySunshineLabel);

	auto rainPicture = Sprite::create("rain.png");
	rainPicture->setPosition(Point(0.5f*LENGTH_OF_SIDE, (HEIGHT - 0.25f)*LENGTH_OF_SIDE));
	this->addChild(rainPicture);

	/* redo/undo pattern */
	currentSize = 0;
	auto undoButton = MenuItemImage::create(
		"undo.png",
		"undo.png",
		[&](Ref* pSender){
		unProducePlants();
	}
	);
	undoButton->setPosition(Point(LENGTH_OF_SIDE*(-2.0f), 0));
	auto redoButton = MenuItemImage::create(
		"redo.png",
		"redo.png",
		[&](Ref* pSender){
		reProducePlants();
	});
	redoButton->setPosition(Point(LENGTH_OF_SIDE*(-1.0f), 0));
	auto pauseButton = MenuItemImage::create(
		"Pause.png",
		"Pause-.png",
		[&](Ref* pSender){
		auto renderTexture = RenderTexture::create(LENGTH_OF_SIDE*WIDTH, LENGTH_OF_SIDE*HEIGHT);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();
		Director::getInstance()->pushScene(FirstPassPause::createScene(renderTexture));
	}
	);
	
	auto menu = Menu::create(undoButton, redoButton, pauseButton, NULL);
	menu->setPosition(Point(LENGTH_OF_SIDE*(WIDTH - 0.5f), LENGTH_OF_SIDE*(HEIGHT - 0.5f)));
	this->addChild(menu);

	/* Planting */
	selectPlant(NO_PLANT);
	myPeaShooterManger = PeaShooterManger::getInstance();
	this->addChild(myPeaShooterManger, PRIORITY_OF_SHOOTER);
	myCarrotManger = CarrotManger::getInstance();
	this->addChild(myCarrotManger, PRIORITY_OF_SHOOTER);
	mySunflowerManger = SunflowerManger::getInstance();
	this->addChild(mySunflowerManger, PRIORITY_OF_PLANT);
	myWallNutManger = WallNutManger::getInstance();
	this->addChild(myWallNutManger, PRIORITY_OF_PLANT);
	myBlueEggManger = BlueEggManger::getInstance();
	this->addChild(myBlueEggManger, PRIORITY_OF_BOMB);

	for (int i = 2; i <= WIDTH; i++){
		for (int j = 1; j < HEIGHT; j++){
			myMapOfPlant[i][j] = NO_PLANT;
		}
	}

	/* Choosing */
	peaShooterProducer = MenuItemImage::create(
		"radishCard.png",
		"darkRadishCard.png",
		"darkRadishCard.png",
		[&](Ref* pSender){
		if (mySunshine >= PRICE_OF_PEASHOOTER && myRefrigerateTime[NUMBER_OF_PEASHOOTER] <= 0){
			selectPlant(NUMBER_OF_PEASHOOTER);
		}
	}
	);
	peaShooterProducer->setPosition(Point(LENGTH_OF_SIDE*(NUMBER_OF_PEASHOOTER - 0.5f),
		LENGTH_OF_SIDE*0.5f));

	carrotProducer = MenuItemImage::create(
		"carrotCard.png",
		"darkCarrotCard.png",
		"darkCarrotCard.png",
		[&](Ref* pSender){
		if (mySunshine >= PRICE_OF_CARROT && myRefrigerateTime[NUMBER_OF_CARROT] <= 0){
			selectPlant(NUMBER_OF_CARROT);
		}
	}
	);
	carrotProducer->setPosition(Point(LENGTH_OF_SIDE*(NUMBER_OF_CARROT - 0.5f),
		LENGTH_OF_SIDE*0.5f));

	sunflowerProducer = MenuItemImage::create(
		"cloudCard.png",
		"darkCloudCard.png",
		"darkCloudCard.png",
		[&](Ref* pSender){
		if (mySunshine >= PRICE_OF_SUNFLOWER && myRefrigerateTime[NUMBER_OF_SUNFLOWER] <= 0){
			selectPlant(NUMBER_OF_SUNFLOWER);
		}
	}
	);
	sunflowerProducer->setPosition(Point(LENGTH_OF_SIDE*(NUMBER_OF_SUNFLOWER - 0.5f),
		LENGTH_OF_SIDE*0.5f));

	wallNutProducer = MenuItemImage::create(
		"pinkEggCard.png",
		"DarkPinkEggCard.png",
		"DarkPinkEggCard.png",
		[&](Ref* pSender){
		if (mySunshine >= PRICE_OF_WALLNUT && myRefrigerateTime[NUMBER_OF_WALLNUT] <= 0){
			selectPlant(NUMBER_OF_WALLNUT);
		}
	}
	);
	wallNutProducer->setPosition(Point(LENGTH_OF_SIDE*(NUMBER_OF_WALLNUT - 0.5f),
		LENGTH_OF_SIDE*0.5f));

	blueEggProducer = MenuItemImage::create(
		"BlueeggCard.png",
		"DarkBlueeggCard.png",
		"DarkBlueeggCard.png",
		[&](Ref* pSender){
		if (mySunshine >= PRICE_OF_BLUEEGG && myRefrigerateTime[NUMBER_OF_BLUEEGG] <= 0){
			selectPlant(NUMBER_OF_BLUEEGG);
		}
	}
	);
	blueEggProducer->setPosition(Point(LENGTH_OF_SIDE*(NUMBER_OF_BLUEEGG - 0.5f),
		LENGTH_OF_SIDE*0.5f));

	auto plantProducer = Menu::create(
		peaShooterProducer,
		carrotProducer,
		sunflowerProducer,
		wallNutProducer,
		blueEggProducer,
		NULL
		);
	plantProducer->setPosition(Point(LENGTH_OF_SIDE*1.0f, LENGTH_OF_SIDE*(HEIGHT - 1.0f)));
	this->addChild(plantProducer);

	myRefrigerateTime[NUMBER_OF_PEASHOOTER] = REFRIGERATE_TIME_OF_PEASHOTER;
	myRefrigerateTime[NUMBER_OF_CARROT] = REFRIGERATE_TIME_OF_CARROT;
	myRefrigerateTime[NUMBER_OF_SUNFLOWER] = 0;
	myRefrigerateTime[NUMBER_OF_WALLNUT] = REFRIGERATE_TIME_OF_WALLNUT;
	myRefrigerateTime[NUMBER_OF_BLUEEGG] = REFRIGERATE_TIME_OF_BLUEEGG;

	for (int i = 1; i <= NUMBER_OF_PLANT; i++){
		myRefrigerateTimeLabel[i] = Label::create(Value(myRefrigerateTime[i]).asString(), "Broadway", 20);
		myRefrigerateTimeLabel[i]->setColor(Color3B::ORANGE);
		myRefrigerateTimeLabel[i]->setPosition(Point(LENGTH_OF_SIDE*(i + 1) - 20, LENGTH_OF_SIDE*(HEIGHT - 1) + 15));
		this->addChild(myRefrigerateTimeLabel[i]);
	}

	/* Planting */
	auto plantProduceListener = EventListenerTouchOneByOne::create();
	plantProduceListener->onTouchBegan = [&](Touch* touch, Event* event){
		auto position = Director::getInstance()->convertToGL(touch->getLocationInView());
		int rowNumber = position.x / LENGTH_OF_SIDE + 1;
		int columnNumber = position.y / LENGTH_OF_SIDE + 1;
		return producePlants(rowNumber, columnNumber, selectedPlantNumber);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(plantProduceListener, this);

	/* Zombies */
	//myZombieManger = ZombieManger::create();
	myZombieManger = ZombieManger::getInstance();
	this->addChild(myZombieManger, PRIORITY_OF_RABBIT);
	//myEvilRabbitManger = EvilRabbitManger::create();
	myEvilRabbitManger = EvilRabbitManger::getInstance();
	this->addChild(myEvilRabbitManger, PRIORITY_OF_RABBIT);


	for (int i = 1; i < HEIGHT; i++){
		myEnemyInRow[i] = 0;
	}
	//myNumberOfDeadEnemy = 0;
	myNumberOfWholeZombie = 0;
	for (int i = 1; i <= NUMBER_OF_ZOMBIE_WAVE; i++){
		myNumberOfWholeZombie += ZombieManger::waveOfZombie[i].mynumber;
	}
	for (int i = 1; i <= NUMBER_OF_EVILRABBIT_WAVE; i++){
		myNumberOfWholeZombie += EvilRabbitManger::waveOfEvilRabbit[i].mynumber;
	}



	/* Update */
	this->schedule(schedule_selector(FirstPass::mutUpdate), INTERVAL_TIME);

	return true;
}

void FirstPass::mutUpdate(float dt){
	/* judge win or fail */
	if (myZombieManger->getNumberOfDeadEnemy() + myEvilRabbitManger->getNumberOfDeadEnemy() >= myNumberOfWholeZombie){
		Director::getInstance()->replaceScene(Victory::createScene());
	}

	auto winEnemy = myZombieManger->getWinEnemy();
	if (winEnemy == NULL){
		winEnemy = myEvilRabbitManger->getWinEnemy();
	}
	if (winEnemy != NULL){
		int row = (int)(winEnemy->getPositionY() / LENGTH_OF_SIDE) + 1;
		winEnemy->removeFromParent();
		this->unschedule(schedule_selector(FirstPass::mutUpdate));
		Director::getInstance()->replaceScene(TransitionSlideInL::create(3.0f, Failure::createScene(row)));
	}


	/* refresh sunshine and plant buttons */
	mySunshine += mySunflowerManger->getNumberOfClickedSunshine()*WORTH_OH_SUNSHINE;
	if (mySunshine != myLastUpdateSunshine) {
		refreshPlantButtons();
		mySunshineLabel->setString(Value(mySunshine).asString());
	}
	myLastUpdateSunshine = mySunshine;

	for (int i = 1; i <= NUMBER_OF_PLANT; i++){
		if (myRefrigerateTime[i] > 0){
			myRefrigerateTime[i]--;
		}
		myRefrigerateTimeLabel[i]->setString(Value(myRefrigerateTime[i]).asString());
	}

	for (int i = 1; i < HEIGHT; i++){
		auto shoot = (myZombieManger->getEnemyInRow(i) + myEvilRabbitManger->getEnemyInRow(i) != 0);
		myPeaShooterManger->setShootInRow(i, shoot);
		myCarrotManger->setShootInRow(i, shoot);
	}

	/* Plants' Attack */
	auto plantAttackRabbit = [&](EnemyManger* enemyManger){
		auto attackZombie = [&](PlantManger* plantManger){
			for (auto zombie : *(enemyManger->getMapOfEnemy())){
				auto rowOfZombie = (int)(zombie->getPositionY() / LENGTH_OF_SIDE) + 1;
				auto peaInRow = plantManger->getPeaInRow(rowOfZombie);
				for (auto pea = peaInRow->begin(); pea != peaInRow->end();){
					if (zombie->getBoundingBox().containsPoint((*pea)->getPosition())){
						zombie->getHurt(ATTACK_OF_PEA);
						/*if (zombie->getHealthPoint() <= 0){
							myNumberOfDeadEnemy++;
							}*/
						(*pea)->removeFromParent();
						pea = peaInRow->erase(pea);
					}
					else{
						pea++;
					}
				}
				peaInRow = myCarrotManger->getPeaInRow(rowOfZombie);
			}
		};

		attackZombie(myPeaShooterManger);
		attackZombie(myCarrotManger);
	};

	plantAttackRabbit(myZombieManger);
	plantAttackRabbit(myEvilRabbitManger);


	/* Zombie's Attack */
	auto rabbitAttackPlant = [&](EnemyManger* myenemymanger, int speed){
		for (auto zombie : *(myenemymanger->getMapOfEnemy())){
			int rowNumber = (zombie->getPositionX() / LENGTH_OF_SIDE) + 1;
			int columnNumber = (zombie->getPositionY() / LENGTH_OF_SIDE) + 1;

			auto attackPlant = [&](PlantManger* plantManger){
				zombie->setPositionX(zombie->getPositionX() + speed);
				plantManger->getHurt(rowNumber, columnNumber, ATTACK_OF_ZOMBIE);
				if (plantManger->getHealthPoint(rowNumber, columnNumber) <= 0){
					myMapOfPlant[rowNumber][columnNumber] = NO_PLANT;
				}
			};

			switch (myMapOfPlant[rowNumber][columnNumber]){
			case NUMBER_OF_PEASHOOTER:
				attackPlant(myPeaShooterManger);
				break;
			case NUMBER_OF_CARROT:
				attackPlant(myCarrotManger);
				break;
			case NUMBER_OF_SUNFLOWER:
				attackPlant(mySunflowerManger);
				break;
			case NUMBER_OF_WALLNUT:
				attackPlant(myWallNutManger);
				break;
			case NUMBER_OF_BLUEEGG:
				attackPlant(myBlueEggManger);
				break;
			default:
				break;
			}
		}
	};
	rabbitAttackPlant(myZombieManger, SPEED_OF_ZOMBIE);
	rabbitAttackPlant(myEvilRabbitManger, SPEED_OF_EVILRABBIT);
}

void FirstPass::refreshPlantButtons() {
	//peaShooterProducer
	if (!peaShooterProducer->isEnabled() && mySunshine >= PRICE_OF_PEASHOOTER) {
		peaShooterProducer->setEnabled(true);
	}
	if (peaShooterProducer->isEnabled() && mySunshine < PRICE_OF_PEASHOOTER) {
		peaShooterProducer->setEnabled(false);
	}

	//carrotProductor
	if (!carrotProducer->isEnabled() && mySunshine >= PRICE_OF_CARROT) {
		carrotProducer->setEnabled(true);
	}
	if (carrotProducer->isEnabled() && mySunshine < PRICE_OF_CARROT) {
		carrotProducer->setEnabled(false);
	}

	//sunflowerProducer
	if (!sunflowerProducer->isEnabled() && mySunshine >= PRICE_OF_SUNFLOWER) {
		sunflowerProducer->setEnabled(true);
	}
	if (sunflowerProducer->isEnabled() && mySunshine < PRICE_OF_SUNFLOWER) {
		sunflowerProducer->setEnabled(false);
	}

	//wallNutProducer
	if (!wallNutProducer->isEnabled() && mySunshine >= PRICE_OF_WALLNUT) {
		wallNutProducer->setEnabled(true);
	}
	if (wallNutProducer->isEnabled() && mySunshine < PRICE_OF_WALLNUT) {
		wallNutProducer->setEnabled(false);
	}

	//blueEggProducer
	if (!blueEggProducer->isEnabled() && mySunshine >= PRICE_OF_BLUEEGG) {
		blueEggProducer->setEnabled(true);
	}
	if (blueEggProducer->isEnabled() && mySunshine < PRICE_OF_BLUEEGG) {
		blueEggProducer->setEnabled(false);
	}

}

void FirstPass::selectPlant(int number){
	selectedPlantNumber = number;
	//for (int i = 1; i <= NUMBER_OF_PLANT; i++){
	//	myplantIsSeltcted[i] = false;
	//}
	//myplantIsSeltcted[number] = true;
}


bool FirstPass::producePlants(int rowNumber, int columnNumber, int plantNumber) {
	if (rowNumber >= 2 && rowNumber <= WIDTH && columnNumber >= 1 && columnNumber < HEIGHT
		&& myMapOfPlant[rowNumber][columnNumber] == NO_PLANT) {
		switch (plantNumber)
		{
		case NUMBER_OF_PEASHOOTER:
			myPeaShooterManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_PEASHOOTER;
			mySunshine -= PRICE_OF_PEASHOOTER;
			myRefrigerateTime[NUMBER_OF_PEASHOOTER] = REFRIGERATE_TIME_OF_PEASHOTER;
			addPlantToVector(rowNumber, columnNumber, NUMBER_OF_PEASHOOTER);
			break;
		case NUMBER_OF_CARROT:
			myCarrotManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_CARROT;
			mySunshine -= PRICE_OF_CARROT;
			myRefrigerateTime[NUMBER_OF_CARROT] = REFRIGERATE_TIME_OF_CARROT;
			addPlantToVector(rowNumber, columnNumber, NUMBER_OF_CARROT);
			break;
		case NUMBER_OF_SUNFLOWER:
			mySunflowerManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_SUNFLOWER;
			mySunshine -= PRICE_OF_SUNFLOWER;
			myRefrigerateTime[NUMBER_OF_SUNFLOWER] = REFRIGERATE_TIME_OF_SUNFLOWER;
			addPlantToVector(rowNumber, columnNumber, NUMBER_OF_SUNFLOWER);
			break;
		case NUMBER_OF_WALLNUT:
			myWallNutManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_WALLNUT;
			mySunshine -= PRICE_OF_WALLNUT;
			myRefrigerateTime[NUMBER_OF_WALLNUT] = REFRIGERATE_TIME_OF_WALLNUT;
			addPlantToVector(rowNumber, columnNumber, NUMBER_OF_WALLNUT);
			break;
		case NUMBER_OF_BLUEEGG:
			myBlueEggManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_BLUEEGG;
			mySunshine -= PRICE_OF_BLUEEGG;
			myRefrigerateTime[NUMBER_OF_BLUEEGG] = REFRIGERATE_TIME_OF_BLUEEGG;

			auto bomb = CallFuncN::create([=](Node*){
				for (auto zombie : *(myZombieManger->getMapOfEnemy())){
					int rowOfZombie = (int)(zombie->getPositionX() / LENGTH_OF_SIDE) + 1;
					int columnOfZombie = (int)(zombie->getPositionY() / LENGTH_OF_SIDE) + 1;

					if (rowOfZombie >= rowNumber - 1 && rowOfZombie <= rowNumber + 1 && columnOfZombie >= columnNumber - 1 && columnOfZombie <= columnNumber + 1){
						zombie->getHurt(ATTACK_OF_BLUEEGG);
						/*if (zombie->getHealthPoint() <= 0){
						myNumberOfDeadEnemy++;
						}*/
					}
				}
				for (auto zombie : *(myEvilRabbitManger->getMapOfEnemy())){
					auto rowOfZombie = (int)(zombie->getPositionX() / LENGTH_OF_SIDE) + 1;
					auto columnOfZombie = (int)(zombie->getPositionY() / LENGTH_OF_SIDE) + 1;

					if (rowOfZombie >= rowNumber - 1 && rowOfZombie <= rowNumber + 1 && columnOfZombie >= columnNumber - 1 && columnOfZombie <= columnNumber + 1){
						zombie->getHurt(ATTACK_OF_BLUEEGG);
						/*if (zombie->getHealthPoint() <= 0){
						myNumberOfDeadEnemy++;
						}*/
					}
				}
				myBlueEggManger->getHurt(rowNumber, columnNumber, HEALTH_POINT_OF_BLUEEGG);
				myMapOfPlant[rowNumber][columnNumber] = NO_PLANT;
			});

			auto actions = Sequence::create(DelayTime::create(0.7f), bomb, NULL);
			this->runAction(actions);
			break;/*
				  default:
				  break;*/
		}

		selectPlant(NO_PLANT);
		return true;
	}
	else{
		return false;
	}
}

void FirstPass::unProducePlants() {
	if (currentSize > 0) {
		currentSize--;
		int rowNumber = commandVector.at(currentSize).rowNumber;
		int columnNumber = commandVector.at(currentSize).columnNumber;
		switch (commandVector.at(currentSize).plantNumber) {
		case NUMBER_OF_PEASHOOTER:
			myPeaShooterManger->removePlant(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NO_PLANT;
			mySunshine += PRICE_OF_PEASHOOTER;
			break;
		case NUMBER_OF_CARROT:
			myCarrotManger->removePlant(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NO_PLANT;
			mySunshine += PRICE_OF_CARROT;
			break;
		case NUMBER_OF_SUNFLOWER:
			mySunflowerManger->removePlant(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NO_PLANT;
			mySunshine += PRICE_OF_SUNFLOWER;
			break;
		case NUMBER_OF_WALLNUT:
			myWallNutManger->removePlant(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NO_PLANT;
			mySunshine += PRICE_OF_WALLNUT;
			break;
		default:
			break;
		}
	} 
}

void FirstPass::reProducePlants(){
	if (currentSize < commandVector.size()) {
		int rowNumber = commandVector.at(currentSize).rowNumber;
		int columnNumber = commandVector.at(currentSize).columnNumber;
		switch (commandVector.at(currentSize).plantNumber) {
		case NUMBER_OF_PEASHOOTER:
			myPeaShooterManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_PEASHOOTER;
			mySunshine -= PRICE_OF_PEASHOOTER;
			break;
		case NUMBER_OF_CARROT:
			myCarrotManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_CARROT;
			mySunshine -= PRICE_OF_CARROT;
			break;
		case NUMBER_OF_SUNFLOWER:
			mySunflowerManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_SUNFLOWER;
			mySunshine -= PRICE_OF_SUNFLOWER;
			break;
		case NUMBER_OF_WALLNUT:
			myWallNutManger->planting(rowNumber, columnNumber);
			myMapOfPlant[rowNumber][columnNumber] = NUMBER_OF_WALLNUT;
			mySunshine -= PRICE_OF_WALLNUT;
			break;
		}
		currentSize++;
	}
}

void FirstPass::addPlantToVector(int rowNumber, int columnNumber, int plantNumber) {
	if (currentSize < commandVector.size()) {
		while (currentSize < commandVector.size()) {
			commandVector.pop_back();
		}
	} 
	commandVector.push_back(Command{ rowNumber, columnNumber, plantNumber });
	currentSize++;
}