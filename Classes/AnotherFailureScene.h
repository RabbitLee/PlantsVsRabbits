#ifndef _ANOTHERFAILURESCENE_H_
#define _ANOTHERFAILURESCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class AnotherFailure : public Layer{
public:
	static Scene* createScene();
	CREATE_FUNC(AnotherFailure);
	virtual bool init();

};

#endif