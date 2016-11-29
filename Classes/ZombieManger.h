#ifndef _ZOMBIEMANGER_H_
#define _ZOMBIEMANGER_H_

#include "Zombie.h"
#include "EnemyManger.h"
#include "PlantManger.h"
#include "GameSettings.h"


class ZombieManger :public EnemyManger{
public:
	CREATE_FUNC(ZombieManger);
	virtual bool init();
	virtual void AttackPlant(int myMapOfPlant[WIDTH + 1][HEIGHT + 1]);
	void SelectPlantStrategy(int numberOfPlant);
	void ExecutePlantStrategy(int rowNumber,int columnNumber, int myMapOfPlant[WIDTH + 1][HEIGHT + 1]);

	void mutUpdate(float dt);

	static Wave waveOfZombie[NUMBER_OF_ZOMBIE_WAVE + 1];

private:
	static ZombieManger* myZombieManager;
	PlantManger* myPlantManger;
public:
	static ZombieManger* getInstance() {
		if (myZombieManager == nullptr) {
			myZombieManager = ZombieManger::create();
		}
		return myZombieManager;
	}

};


#endif