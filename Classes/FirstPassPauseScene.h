#ifndef _FIRSTPASSPAUSESCENE_H_
#define _FIRSTPASSPAUSESCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class FirstPassPause :public Layer{
public:
	static Scene* createScene(RenderTexture* sqr);
	CREATE_FUNC(FirstPassPause);
	virtual bool init();

};

#endif