#ifndef _PEASHOOTER_H_
#define _PEASHOOTER_H_

#include "Entity.h"

class PeaShooter:public Entity{
public:
	CREATE_FUNC(PeaShooter);
	virtual bool init();
	bool shootPea();

private:
	int myFrequenceOfPea;
};

#endif