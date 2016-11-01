#include "WallNut.h"
#include "GameSettings.h"

bool WallNut::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	setHealthPoint(HEALTH_POINT_OF_WALLNUT);
	this->bindSprite(Sprite::create("pinkegg.png"));

	myHealthLeval = 3;
	this->schedule(schedule_selector(WallNut::mutUpdate), INTERVAL_TIME);

	return true;
}

void WallNut::mutUpdate(float dt){
	if (myHealthLeval >= 3 && this->getHealthPoint() <= HEALTH_POINT_OF_WALLNUT*0.67){
		mySprite->removeFromParent();
		this->bindSprite(Sprite::create("BrokenPinkegg1.png"));
		myHealthLeval--;
	}
	else if (myHealthLeval >= 2 && this->getHealthPoint() <= HEALTH_POINT_OF_WALLNUT*0.33){
		mySprite->removeFromParent();
		this->bindSprite(Sprite::create("BrokenPinkegg2.png"));
		myHealthLeval--;
	}
	else{
	}

}