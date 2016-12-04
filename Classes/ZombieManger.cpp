#include "ZombieManger.h"

EnemyManger::Wave ZombieManger::waveOfZombie[NUMBER_OF_ZOMBIE_WAVE + 1] = CONTENT_OF_ZOMBIE_WAVE;
ZombieManger* ZombieManger::myZombieManager = nullptr;


bool ZombieManger::init(){
	EnemyManger::initial();

	
	
	speed = SPEED_OF_ZOMBIE;

	Zombieattack = ATTACK_OF_ZOMBIE;

	this->schedule(schedule_selector(EnemyManger::mutUpdate), INTERVAL_TIME);
	this->schedule(schedule_selector(ZombieManger::mutUpdate), INTERVAL_TIME);

	return true;
}

void ZombieManger::mutUpdate(float dt){

	if (waveNumber <= NUMBER_OF_ZOMBIE_WAVE){
		frequenceOfEnemy++;
		if (frequenceOfEnemy >= waveOfZombie[waveNumber].myfrequence){
			Point randomPosition;
			int randomTemp;
			randomPosition.x = (WIDTH - 0.5f)* LENGTH_OF_SIDE;
			do{
				randomTemp = (int)(CCRANDOM_0_1()*HEIGHT);
			} while (randomTemp <= 0 || randomTemp >= HEIGHT);
			randomPosition.y = (randomTemp - 0.5f)*LENGTH_OF_SIDE;

			auto zombie = Zombie::create();
			zombie->setPosition(randomPosition);

			enemyNumberInRow[randomTemp]++;

			frequenceOfEnemy = 0;
			enemyNumberInWave++;
			if (enemyNumberInWave >= waveOfZombie[waveNumber].mynumber){
				waveNumber++;
				enemyNumberInWave = 0;
			}
			myMapOfEnemy.pushBack(zombie);
			this->addChild(zombie);
		}
	}
}
int ZombieManger::getSpeed()
{
	return speed;
}
int ZombieManger::getAttack()
{
	return Zombieattack;
}
/*strategy*/
//void ZombieManger::AttackPlant(int myMapOfPlant[WIDTH + 1][HEIGHT + 1])
//{
//	for (auto zombie : *(getMapOfEnemy())){
//			int rowNumber = (zombie->getPositionX() / LENGTH_OF_SIDE) + 1;
//			int columnNumber = (zombie->getPositionY() / LENGTH_OF_SIDE) + 1;
//			zombie->setPositionX(zombie->getPositionX() + SPEED_OF_ZOMBIE);
//			SelectPlantStrategy(myMapOfPlant[rowNumber][columnNumber]);
//			ExecutePlantStrategy(rowNumber,columnNumber, myMapOfPlant);
//	}
//			
//}

//void ZombieManger::ExecutePlantStrategy(int rowNumber,int columnNumber, int myMapOfPlant[WIDTH + 1][HEIGHT + 1])
//{
//	myPlantManger->getHurt(rowNumber, columnNumber, ATTACK_OF_ZOMBIE);
//	if (myPlantManger->getHealthPoint(rowNumber, columnNumber) <= 0)
//	{
//			myMapOfPlant[rowNumber][columnNumber] = NO_PLANT;
//	}
//}
//
//void ZombieManger::SelectPlantStrategy(int numberOfPlant)
//{
//	switch (numberOfPlant){
//			case NUMBER_OF_PEASHOOTER:
//				attackPlant(myPeaShooterManger);
//				break;
//			case NUMBER_OF_CARROT:
//				attackPlant(myCarrotManger);
//				break;
//			case NUMBER_OF_SUNFLOWER:
//				attackPlant(mySunflowerManger);
//				break;
//			case NUMBER_OF_WALLNUT:
//				attackPlant(myWallNutManger);
//				break;
//			case NUMBER_OF_BLUEEGG:
//				attackPlant(myBlueEggManger);
//				break;
//			default:
//				break;
//			}
//		
//}