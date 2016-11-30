#include "PlantManger.h"

void PlantManger::initial(){
	for (int i = 2; i <= WIDTH; i++){
		for (int j = 1; j < HEIGHT; j++){
			myMapOfPlant[i][j] = NULL;
		}
	}
	this->schedule(schedule_selector(PlantManger::updateOfDeath), INTERVAL_TIME);
}

void PlantManger::getHurt(int row, int column, int hurt){
	if (myMapOfPlant[row][column] != NULL){
		myMapOfPlant[row][column]->getHurt(hurt);
	}
}

int PlantManger::getHealthPoint(int row, int column){
	if (myMapOfPlant[row][column] == NULL){
		return 0;
	}
	else{
		return myMapOfPlant[row][column]->getHealthPoint();
	}
}

void PlantManger::updateOfDeath(float dt){
	for (int i = 2; i <= WIDTH; i++){
		for (int j = 1; j < HEIGHT; j++){
			auto plant = myMapOfPlant[i][j];
			if (plant != NULL && plant->getHealthPoint() <= 0){
				plant->removeFromParent();
				myMapOfPlant[i][j] = NULL;
			}
		}
	}
}

void PlantManger::ParentPlanting(Entity* plant, int row, int column){
	Point position;
	position.x = (row - 0.5f)*LENGTH_OF_SIDE;
	position.y = (column - 0.5f)*LENGTH_OF_SIDE;

	plant->setPosition(position);

	myMapOfPlant[row][column] = plant;
	this->addChild(plant);
}

void PlantManger::planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime)
{
}