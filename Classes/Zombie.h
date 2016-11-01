#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include "Entity.h"

class Zombie :public Entity{
public:
	CREATE_FUNC(Zombie);
	virtual bool init();
};

#endif