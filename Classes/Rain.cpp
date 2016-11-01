#include "Rain.h"
#include "GameSettings.h"

bool Rain::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	this->bindSprite(Sprite::create("rain.png"));
	existenceOfRain = 0;
	this->schedule(schedule_selector(Rain::mutUpdate), INTERVAL_TIME);
	return true;
}

void Rain::mutUpdate(float dt){
	existenceOfRain++;
	if (existenceOfRain >= EXISTENCE_OF_SUNSHINE){
		this->removeFromParent();
	}
}