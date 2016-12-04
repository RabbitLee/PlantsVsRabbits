#include "EvilRabbitManger.h"

EnemyManger::Wave EvilRabbitManger::waveOfEvilRabbit[NUMBER_OF_EVILRABBIT_WAVE + 1] = CONTENT_OF_EVILRABBIT_WAVE;
EvilRabbitManger* EvilRabbitManger::myEvilRabbitManager = nullptr;

bool EvilRabbitManger::init(){
	EnemyManger::initial();

	speed = SPEED_OF_EVILRABBIT;
	Evilattack = ATTACK_OF_EVILRABBIT;

	this->schedule(schedule_selector(EnemyManger::mutUpdate), INTERVAL_TIME);
	this->schedule(schedule_selector(EvilRabbitManger::mutUpdate), INTERVAL_TIME);

	return true;
}

void EvilRabbitManger::mutUpdate(float dt){

	if (waveNumber <= NUMBER_OF_EVILRABBIT_WAVE){
		frequenceOfEnemy++;
		if (frequenceOfEnemy >= waveOfEvilRabbit[waveNumber].myfrequence){
			Point randomPosition;
			int randomTemp;
			randomPosition.x = (WIDTH - 0.5f)* LENGTH_OF_SIDE;
			do{
				randomTemp = (int)(CCRANDOM_0_1()*HEIGHT);
			} while (randomTemp <= 0 || randomTemp >= HEIGHT);
			randomPosition.y = (randomTemp - 0.5f)*LENGTH_OF_SIDE;

			auto evilRabbit = EvilRabbit::create();
			evilRabbit->setPosition(randomPosition);

			enemyNumberInRow[randomTemp]++;

			frequenceOfEnemy = 0;
			enemyNumberInWave++;
			if (enemyNumberInWave >= waveOfEvilRabbit[waveNumber].mynumber){
				waveNumber++;
				enemyNumberInWave = 0;
			}
			myMapOfEnemy.pushBack(evilRabbit);
			this->addChild(evilRabbit);
		}
	}
}

int EvilRabbitManger::getSpeed()
{
	return speed;
}
int EvilRabbitManger::getAttack()
{
	return Evilattack;
}