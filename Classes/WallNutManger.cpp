#include "WallNutManger.h"

WallNutManger* WallNutManger::myWallNutManager = nullptr;

bool WallNutManger::init(){
	initial();
	//this->schedule(schedule_selector(WallNutManger::mutUpdate), INTERVAL_TIME);
	return true;
}

void WallNutManger::planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime){
	PlantManger::ParentPlanting(WallNut::create(), row, column);
	myMapOfPlant[row][column] = NUMBER_OF_WALLNUT;
	mySunshine -= PRICE_OF_WALLNUT;
	myRefrigerateTime[NUMBER_OF_WALLNUT] = REFRIGERATE_TIME_OF_WALLNUT;
}

void WallNutManger::mutUpdate(float dt){
}