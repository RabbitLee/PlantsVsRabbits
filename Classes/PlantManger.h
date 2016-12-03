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
	void ParentPlanting(Entity* plant, int row, int column);
	virtual void planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime);
	virtual Vector<Sprite*>* getPeaInRow(int row) = 0;
	void removePlant(int row, int column);

protected:
	Entity* myMapOfPlant[WIDTH + 1][HEIGHT + 1];

};

#endif