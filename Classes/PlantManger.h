#ifndef	_PLANTMANGER_H_
#define _PLANTMANGER_H_

#include "cocos2d.h"
#include "GameSettings.h"
#include "Entity.h"
USING_NS_CC;

class PlantManger :public Node{
public:
	void initial();
	void getHurt(int row, int column, int hurt);
	int getHealthPoint(int row, int column);
	void updateOfDeath(float dt);
	void planting(Entity* plant, int row, int column);
	virtual Vector<Sprite*>* getPeaInRow(int row) = 0;

protected:
	Entity* myMapOfPlant[WIDTH + 1][HEIGHT + 1];

};

#endif