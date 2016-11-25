#include "SunflowerManger.h"
#include "Rain.h"

SunflowerManger* SunflowerManger::mySunflowerManager = nullptr;

bool SunflowerManger::init(){
	myNumberOfClickedSunshine = 0;
	initial();
	this->schedule(schedule_selector(SunflowerManger::mutUpdate), INTERVAL_TIME);
	return true;
}

void SunflowerManger::planting(int row, int column){
	PlantManger::planting(Sunflower::create(), row, column);
}

void SunflowerManger::mutUpdate(float dt){
	for (int i = 2; i <= WIDTH; i++){
		for (int j = 1; j < HEIGHT; j++){
			auto sunflower = (Sunflower*)myMapOfPlant[i][j];
			if (sunflower != NULL&&sunflower->productSunshine()){
				auto sunshine = Rain::create();
				
				Point positionOfSunshine;
				positionOfSunshine.x = sunflower->getPositionX();
				positionOfSunshine.y = sunflower->getPositionY();
				sunshine->setPosition(positionOfSunshine);

				auto listener = EventListenerTouchOneByOne::create();
				listener->onTouchBegan = [&](Touch* touch, Event* event){
					auto position = Director::getInstance()->convertToGL(touch->getLocationInView());
					auto target = static_cast<Rain*>(event->getCurrentTarget());

					if (target->getBoundingBox().containsPoint(position)){
						target->unschedule(schedule_selector(Rain::mutUpdate));

						auto collect = MoveTo::create(1.0f, Point(LENGTH_OF_SIDE*0.5, LENGTH_OF_SIDE*(HEIGHT - 0.5f)));
						auto callBack = CallFunc::create([=](){
							myNumberOfClickedSunshine++;
							target->removeFromParent();
						});
						auto actions = Sequence::create(collect, callBack, NULL);
						target->runAction(actions);
						return true;
					}
					else{
						return false;
					}
				};
				listener->setSwallowTouches(true);

				_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sunshine);

				this->addChild(sunshine);
			}
		}
	}
}

int SunflowerManger::getNumberOfClickedSunshine(){
	int temp = myNumberOfClickedSunshine;
	myNumberOfClickedSunshine = 0;
	return temp;
}