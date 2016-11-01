#include "Sunflower.h"
#include "GameSettings.h"

bool Sunflower::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	setHealthPoint(HEALTH_POINT_OF_SUNFLOWER);
	this->bindSprite(Sprite::create("cloud.png"));
	mySprite->runAction(createAnimate(5, Value("CloudMove")));
	myFrequenceOfSunshine = 0;
	return true;
}

bool Sunflower::productSunshine(){
	if (myFrequenceOfSunshine < FREQUENCE_OF_SUNSHINE){
		myFrequenceOfSunshine++;
		return false;
	}
	else{
		myFrequenceOfSunshine = 0;
		return true;
	}
}