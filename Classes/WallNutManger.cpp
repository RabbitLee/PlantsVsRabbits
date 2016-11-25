#include "WallNutManger.h"

WallNutManger* WallNutManger::myWallNutManager = nullptr;

bool WallNutManger::init(){
	initial();
	//this->schedule(schedule_selector(WallNutManger::mutUpdate), INTERVAL_TIME);
	return true;
}

void WallNutManger::planting(int row, int column){
	PlantManger::planting(WallNut::create(), row, column);
}

void WallNutManger::mutUpdate(float dt){
}