#include "Carrot.h"
#include "GameSettings.h"

bool Carrot::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	setHealthPoint(HEALTH_POINT_OF_CARROT);
	this->bindSprite(Sprite::create("carrot.png"));
	mySprite->runAction(createAnimate(2, Value("ShootCarrot")));
	myFrequenceOfPea = 0;
	return true;
}

bool Carrot::shootPea(){
	if (myFrequenceOfPea < FREQUENCE_OF_PEA){
		myFrequenceOfPea++;
		return false;
	}
	else{
		myFrequenceOfPea = 0;
		return true;
	}
}