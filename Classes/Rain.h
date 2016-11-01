#ifndef _RAIN_H_
#define _RAIN_H_

#include "Entity.h"

class Rain :public Entity{
public:
	CREATE_FUNC(Rain);
	virtual bool init();
	void mutUpdate(float dt);

private:
	int existenceOfRain;

};

#endif