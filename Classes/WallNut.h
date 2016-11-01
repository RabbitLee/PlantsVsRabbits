#ifndef _WALLNUT_H_
#define _WALLNUT_H_

#include "Entity.h"

class WallNut :public Entity{
public:
	CREATE_FUNC(WallNut);
	virtual bool init();

	void mutUpdate(float dt);

private:
	int myHealthLeval;

};

#endif