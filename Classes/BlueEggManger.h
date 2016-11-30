#ifndef _BLUEEGGMANGER_H_
#define _BLUEEGGMANGER_H_

#include "PlantManger.h"
#include "BlueEgg.h"	

class BlueEggManger : public PlantManger{
public:
	CREATE_FUNC(BlueEggManger);
	virtual bool init();
	void planting(int row, int column,int myMapOfPlant[WIDTH + 1][HEIGHT + 1], int &mySunshine, int *myRefrigerateTime);
	void mutUpdate(float dt);
	virtual Vector<Sprite*>* getPeaInRow(int row) { return NULL; }

private:
	static BlueEggManger* myBlueManager;

public:
	static BlueEggManger* getInstance() {
		if (myBlueManager == nullptr) {
			myBlueManager = BlueEggManger::create();
		}
		return myBlueManager;
	}
};

#endif