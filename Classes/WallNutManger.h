#ifndef _WALLNUTMANGER_H_
#define _WALLNUTMANGER_H_

#include "PlantManger.h"
#include "WallNut.h"	

class WallNutManger: public PlantManger{
public:
	CREATE_FUNC(WallNutManger);
	virtual bool init();
	void planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime);
	void mutUpdate(float dt);
	virtual Vector<Sprite*>* getPeaInRow(int row) { return NULL; }

private:
	static WallNutManger* myWallNutManager;

public:
	static WallNutManger* getInstance() {
		if (myWallNutManager == nullptr) {
			myWallNutManager = WallNutManger::create();
		}
		return myWallNutManager;
	}
};

#endif