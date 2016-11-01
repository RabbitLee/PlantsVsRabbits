#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "cocos2d.h"
USING_NS_CC;

class Entity: public Node{
public:
	CREATE_FUNC(Entity);
	virtual bool init();

	void bindSprite(Sprite* sprite);

	void setHealthPoint(int healthPoint);
	int getHealthPoint();
	void getHurt(int hurt);

	Animate* createAnimate(int frameNumber, Value pngName);

protected:	
	Sprite* mySprite;

private:
	int myHealthPoint;
};

#endif