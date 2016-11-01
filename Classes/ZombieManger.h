#ifndef _ZOMBIEMANGER_H_
#define _ZOMBIEMANGER_H_

#include "Zombie.h"
#include "EnemyManger.h"
#include "GameSettings.h"

class ZombieManger :public EnemyManger{
public:
	CREATE_FUNC(ZombieManger);
	virtual bool init();

	void mutUpdate(float dt);

	static Wave waveOfZombie[NUMBER_OF_ZOMBIE_WAVE + 1];

};

#endif