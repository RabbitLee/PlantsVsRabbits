#ifndef	_SUNFLOWERMANGER_H_
#define _SUNFLOWERMANGER_H_

#include "Sunflower.h"
#include "PlantManger.h"
#include "GameSettings.h"

class SunflowerManger :public PlantManger{
public:
	CREATE_FUNC(SunflowerManger);
	virtual bool init();
	void planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime);
	void mutUpdate(float dt);
	virtual void removePlant(int row, int column, int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine);
	int getNumberOfClickedSunshine();
	virtual Vector<Sprite*>* getPeaInRow(int row) { return NULL; }

private:
	int myNumberOfClickedSunshine;

private:
	static SunflowerManger* mySunflowerManager;

public:
	static SunflowerManger* getInstance() {
		if (mySunflowerManager == nullptr) {
			mySunflowerManager = SunflowerManger::create();
		}
		return mySunflowerManager;
	}
};

#endif