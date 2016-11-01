#ifndef _SUNFLOWER_H_
#define _SUNFLOWER_H_

#include "Entity.h"

class Sunflower :public Entity{
public:
	CREATE_FUNC(Sunflower);
	virtual bool init();
	bool productSunshine();

private:
	int myFrequenceOfSunshine;

};

#endif