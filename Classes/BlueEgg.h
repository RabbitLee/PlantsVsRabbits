#ifndef _BLUEEGG_H_
#define _BLUEEGG_H_

#include "Entity.h"

class BlueEgg :public Entity{
public:
	CREATE_FUNC(BlueEgg);
	virtual bool init();
};

#endif