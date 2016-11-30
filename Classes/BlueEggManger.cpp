#include "BlueEggManger.h"

BlueEggManger* BlueEggManger::myBlueManager = nullptr;

bool BlueEggManger::init(){
	initial();
	//this->schedule(schedule_selector(BlueEggManger::mutUpdate), INTERVAL_TIME);
	return true;
}

void BlueEggManger::planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime){
	PlantManger::ParentPlanting(BlueEgg::create(), row, column);
	myMapOfPlant[row][column] = NUMBER_OF_BLUEEGG;
	mySunshine -= PRICE_OF_BLUEEGG;
	myRefrigerateTime[NUMBER_OF_BLUEEGG] = REFRIGERATE_TIME_OF_BLUEEGG;
}

void BlueEggManger::mutUpdate(float dt){
}