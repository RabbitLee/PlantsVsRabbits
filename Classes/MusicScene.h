#ifndef _MUSIC_H_
#define _MUSIC_H_

#include "cocos2d.h"
USING_NS_CC;

class Music : public Layer{
public:
	static Scene* createScene();
	CREATE_FUNC(Music);
	virtual bool init();


};

#endif