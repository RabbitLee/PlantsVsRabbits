#ifndef _CARROTMANGER_H_
#define _CARROTMANGER_H_

#include "Carrot.h"
#include "PlantManger.h"
#include "GameSettings.h"

class CarrotManger :public PlantManger{
public:
	CREATE_FUNC(CarrotManger);
	virtual bool init();

	void planting(int row, int column);

	virtual Vector<Sprite*>* getPeaInRow(int row);
	void mutUpdate(float dt);
	void setShootInRow(int row, bool shoot);

private:
	Vector<Sprite*> myMapOfPea[HEIGHT + 1];
	bool shootInRow[HEIGHT + 1];

};

#endif