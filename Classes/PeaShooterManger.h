#ifndef _PEASHOOTER_MANGER_H_
#define _PEASHOOTER_MANGER_H_

#include "PeaShooter.h"
#include "GameSettings.h"
#include "PlantManger.h"
#include "Entity.h"
class PeaShooterManger :public PlantManger{
public:
	CREATE_FUNC(PeaShooterManger);
	virtual bool init();

	void planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime);
	virtual void removePlant(int row, int column, int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine);

	virtual Vector<Sprite*>* getPeaInRow(int row);
	void mutUpdate(float dt);
	void setShootInRow(int row, bool shoot);

private:
	Vector<Sprite*> myMapOfPea[HEIGHT + 1];
	bool shootInRow[HEIGHT + 1];

private:
	static PeaShooterManger* myPeaShooterManager;

public:
	static PeaShooterManger* getInstance() {
		if (myPeaShooterManager == nullptr) {
			myPeaShooterManager = PeaShooterManger::create();
		}
		return myPeaShooterManager;
	}

};

#endif