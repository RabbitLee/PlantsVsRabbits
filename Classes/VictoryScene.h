#ifndef _VICTORYSCENE_H_
#define _VICTORYSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class Victory :public Layer{
public:
	static Scene* createScene();
	CREATE_FUNC(Victory);
	virtual bool init();
};

#endif