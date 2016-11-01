#include "EvilRabbit.h"
#include "GameSettings.h"

bool EvilRabbit::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	setHealthPoint(HEALTH_POINT_OF_EVILRABBIT);
	this->bindSprite(Sprite::create("evilRabbit.png"));
	mySprite->runAction(createAnimate(5, Value("Jump1-")));

	return true;
}