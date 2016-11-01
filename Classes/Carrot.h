#ifndef	_CARROT_H_
#define _CARROT_H_

#include "Entity.h"

class Carrot :public Entity{
public:
	CREATE_FUNC(Carrot);
	virtual bool init();
	bool shootPea();

private:
	int myFrequenceOfPea;
};

#endif