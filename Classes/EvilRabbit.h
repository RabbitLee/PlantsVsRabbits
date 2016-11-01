#ifndef _EVILRABBIT_H_
#define _EVILRABBIT_H_

#include "Entity.h"

class EvilRabbit :public Entity{
public:
	CREATE_FUNC(EvilRabbit);
	virtual bool init();

};

#endif