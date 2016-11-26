#ifndef _FIRSTPASS_H_
#define _FIRSTPASS_H_

#include "cocos2d.h"
#include "GameSettings.h"

#include "PeaShooterManger.h"
#include "CarrotManger.h"
#include "SunflowerManger.h"
#include "WallNutManger.h"
#include "BlueEggManger.h"

#include "ZombieManger.h"
#include "EvilRabbitManger.h"

using namespace cocos2d;

class FirstPass: public Layer{
public :
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(FirstPass);
	void mutUpdate(float dt);
	void refreshPlantButtons();

	void selectPlant(int number);
	bool producePlants(int rowNumber, int columnNumber, int plantNumber);

private:
	int myMapOfPlant[WIDTH + 1][HEIGHT + 1];

	//bool myplantIsSeltcted[NUMBER_OF_PLANT + 1];
	int selectedPlantNumber;
	PeaShooterManger* myPeaShooterManger;
	CarrotManger* myCarrotManger;
	SunflowerManger* mySunflowerManger;
	WallNutManger* myWallNutManger;
	BlueEggManger* myBlueEggManger;

	Label* myRefrigerateTimeLabel[NUMBER_OF_PLANT + 1];
	int myRefrigerateTime[NUMBER_OF_PLANT + 1];

	int myEnemyInRow[HEIGHT + 1];
	int myNumberOfDeadEnemy;
	static int myNumberOfWholeZombie;

	ZombieManger* myZombieManger;
	EvilRabbitManger* myEvilRabbitManger;

	Label* mySunshineLabel;
	int mySunshine;
	int myLastUpdateSunshine;

	MenuItemImage* peaShooterProducer;
	MenuItemImage* carrotProducer;
	MenuItemImage* sunflowerProducer;
	MenuItemImage* wallNutProducer;
	MenuItemImage* blueEggProducer;
};

#endif