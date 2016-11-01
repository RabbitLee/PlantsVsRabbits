#include "BlueEggManger.h"

bool BlueEggManger::init(){
	initial();
	//this->schedule(schedule_selector(BlueEggManger::mutUpdate), INTERVAL_TIME);
	return true;
}

void BlueEggManger::planting(int row, int column){
	PlantManger::planting(BlueEgg::create(), row, column);
}

void BlueEggManger::mutUpdate(float dt){
}