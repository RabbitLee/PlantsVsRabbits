#include "Zombie.h"
#include "GameSettings.h"

bool Zombie::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	setHealthPoint(HEALTH_POINT_OF_ZOMBIE);
	this->bindSprite(Sprite::create("rabbit.png"));
	mySprite->runAction(createAnimate(5, Value("rabbit_")));

	return true;
}

