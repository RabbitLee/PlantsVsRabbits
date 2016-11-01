#include "ZombieManger.h"

EnemyManger::Wave ZombieManger::waveOfZombie[NUMBER_OF_ZOMBIE_WAVE + 1] = CONTENT_OF_ZOMBIE_WAVE;


bool ZombieManger::init(){
	EnemyManger::initial();

	speed = SPEED_OF_ZOMBIE;

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