#include "PeaShooterManger.h"

bool PeaShooterManger::init(){
	initial();
	for (int i = 1; i < HEIGHT; i++){
		shootInRow[i] = false;
	}
	this->schedule(schedule_selector(PeaShooterManger::mutUpdate), INTERVAL_TIME);
	return true;
}

Vector<Sprite*>* PeaShooterManger::getPeaInRow(int row){
	return myMapOfPea + row;
}

void PeaShooterManger::planting(int row, int column){
	PlantManger::planting(PeaShooter::create(), row, column);
}

void PeaShooterManger::mutUpdate(float dt){
	for (int i = 1; i < HEIGHT;i++){
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
				auto peaShooter = (PeaShooter*)myMapOfPlant[i][j];
				if (peaShooter != NULL && peaShooter->shootPea()){
					auto pea = Sprite::create("whiteBall.png");
					Point positionOfPea;
					positionOfPea.x = (i - 0.1f)*LENGTH_OF_SIDE;
					positionOfPea.y = (j - 0.3f)*LENGTH_OF_SIDE;
					pea->setPosition(positionOfPea);

					myMapOfPea[j].pushBack(pea);
					this->addChild(pea);				
				}
			}			
		}
	}
}

void PeaShooterManger::setShootInRow(int row, bool shoot){
	shootInRow[row] = shoot;
}