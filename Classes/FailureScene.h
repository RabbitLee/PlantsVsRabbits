#ifndef _FAILURESCENE_H_
#define _FAILURESCENE_H_

#include "cocos2d.h"
#include "EvilRabbit.h"
USING_NS_CC;

class Failure : public Layer{
public:
	static Scene* createScene(int row);
	CREATE_FUNC(Failure);
	virtual bool init();
	void bindSprite(Sprite* sprite);

private:
	Sprite* rabbit;

};

#endif