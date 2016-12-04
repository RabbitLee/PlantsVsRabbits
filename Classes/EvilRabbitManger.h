#ifndef _EVILRABBITMANGER_H_
#define _EVILRABBITMANGER_H_

#include "EvilRabbit.h"
#include "EnemyManger.h"
#include "GameSettings.h"

class EvilRabbitManger :public EnemyManger{
public:
	CREATE_FUNC(EvilRabbitManger);
	virtual bool init();

	void mutUpdate(float dt);

	static Wave waveOfEvilRabbit[NUMBER_OF_EVILRABBIT_WAVE + 1];

	int getSpeed();
	int getAttack();
	int Evilattack;
private:
	static EvilRabbitManger* myEvilRabbitManager; 

public:
	static EvilRabbitManger* getInstance() {
		if (myEvilRabbitManager == nullptr) {
			myEvilRabbitManager = EvilRabbitManger::create();
		}
		return myEvilRabbitManager;
	}

};

#endif