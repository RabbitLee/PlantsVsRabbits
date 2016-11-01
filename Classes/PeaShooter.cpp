#include "PeaShooter.h"
#include "GameSettings.h"

bool PeaShooter::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	setHealthPoint(HEALTH_POINT_OF_PEASHOOTER);
	this->bindSprite(Sprite::create("radish.png"));
	mySprite->runAction(createAnimate(2, Value("ShootRadish")));
	myFrequenceOfPea = 0;
	return true;
}

bool PeaShooter::shootPea(){
	if (myFrequenceOfPea < FREQUENCE_OF_PEA){
		myFrequenceOfPea++;
		return false;
	}
	else{
		myFrequenceOfPea = 0;
		return true;
	}
}
