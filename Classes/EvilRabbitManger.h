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

};

#endif