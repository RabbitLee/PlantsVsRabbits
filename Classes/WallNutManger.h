#ifndef _WALLNUTMANGER_H_
#define _WALLNUTMANGER_H_

#include "PlantManger.h"
#include "WallNut.h"	

class WallNutManger: public PlantManger{
public:
	CREATE_FUNC(WallNutManger);
	virtual bool init();
	void planting(int row, int column);
	void mutUpdate(float dt);
	virtual Vector<Sprite*>* getPeaInRow(int row) { return NULL; }

};

#endif