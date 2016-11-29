#ifndef _ENEMYMANGER_H_
#define _ENEMYMANGER_H_

#include "Entity.h"
#include "GameSettings.h"

class EnemyManger :public Node{
public:
	void initial();
	void mutUpdate(float dt);
	Vector<Entity*>* getMapOfEnemy();
	struct Wave{
		int mynumber;
		int myfrequence;
	};

	int getEnemyInRow(int row);
	int getNumberOfDeadEnemy();

	Entity* getWinEnemy();

	virtual void AttackPlant(int myMapOfPlant[WIDTH + 1][HEIGHT + 1]);
protected:
	Vector<Entity*> myMapOfEnemy;
	int speed;
	int waveNumber, enemyNumberInWave;
	int frequenceOfEnemy;
	int enemyNumberInRow[HEIGHT + 1];

	int deadEnemy;

	Entity* winEnemy;
};

#endif