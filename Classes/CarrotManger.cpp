#include "CarrotManger.h"
CarrotManger* CarrotManger::myCarrotManager = nullptr;

bool CarrotManger::init(){
	initial();
	for (int i = 1; i < HEIGHT; i++){
		shootInRow[i] = false;
	}
	this->schedule(schedule_selector(CarrotManger::mutUpdate), INTERVAL_TIME);
	return true;
}

Vector<Sprite*>* CarrotManger::getPeaInRow(int row){
	return myMapOfPea + row;
}

void CarrotManger::planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime){
	PlantManger::ParentPlanting(Carrot::create(), row, column);
	myMapOfPlant[row][column] = NUMBER_OF_CARROT;
	mySunshine -= PRICE_OF_CARROT;
	myRefrigerateTime[NUMBER_OF_CARROT] = REFRIGERATE_TIME_OF_CARROT;
}

void CarrotManger::mutUpdate(float dt){
	for (int i = 1; i < HEIGHT; i++){
		for (auto pea = myMapOfPea[i].begin(); pea != myMapOfPea[i].end();){
			if ((*pea)->getPositionX() > WIDTH * LENGTH_OF_SIDE){
				(*pea)->removeFromParent();
				pea = myMapOfPea[i].erase(pea);
			}
			else{
				(*pea)->setPositionX((*pea)->getPositionX() + SPEED_OF_PEA);
				pea++;
			}
		}
	}

	for (int i = 2; i <= WIDTH; i++){
		for (int j = 1; j < HEIGHT; j++){
			if (shootInRow[j]){
				auto carrot = (Carrot*)myMapOfPlant[i][j];
				if (carrot != NULL && carrot->shootPea()){
					auto pea1 = Sprite::create("orangeBall.png"), pea2 = Sprite::create("orangeBall.png");
					pea1->setPosition(Point(LENGTH_OF_SIDE*(i - 0.1f), LENGTH_OF_SIDE*(j - 0.3f)));
					pea2->setPosition(Point(LENGTH_OF_SIDE*(i + 0.1f), LENGTH_OF_SIDE*(j - 0.3f)));

					myMapOfPea[j].pushBack(pea1);
					myMapOfPea[j].pushBack(pea2);
					this->addChild(pea1);
					this->addChild(pea2);
				}
			}			
		}
	}
}

void CarrotManger::setShootInRow(int row, bool shoot){
	shootInRow[row] = shoot;
}
void CarrotManger::removePlant(int row, int column, int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine) {
	PlantManger::ParentRemovePlant(row, column);
	myMapOfPlant[row][column] = NO_PLANT;
	mySunshine += PRICE_OF_PEASHOOTER;
}