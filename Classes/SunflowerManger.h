#ifndef	_SUNFLOWERMANGER_H_
#define _SUNFLOWERMANGER_H_

#include "Sunflower.h"
#include "PlantManger.h"
#include "GameSettings.h"

class SunflowerManger :public PlantManger{
public:
	CREATE_FUNC(SunflowerManger);
	virtual bool init();
	void planting(int row, int column);
	void mutUpdate(float dt);

	int getNumberOfClickedSunshine();
	virtual Vector<Sprite*>* getPeaInRow(int row) { return NULL; }

private:
	int myNumberOfClickedSunshine;

};

#endif