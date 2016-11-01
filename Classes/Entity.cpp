#include "Entity.h"
#include "GameSettings.h"

bool Entity::init(){
	return true;
}

void Entity::bindSprite(Sprite* sprite){
	mySprite = sprite;
	this->addChild(mySprite);

	auto size = mySprite->getContentSize();
	mySprite->setPosition(Point(size.width*0.5f, size.height*0.5f));
	this->setContentSize(size);
}

void Entity::setHealthPoint(int healthPoint){
	myHealthPoint = healthPoint;
}

int Entity::getHealthPoint(){
	return myHealthPoint;
}

void Entity::getHurt(int hurt){
	myHealthPoint -= hurt;
	if (myHealthPoint < 0){
		myHealthPoint = 0;
	}
}

Animate* Entity::createAnimate(int frameNumber, Value pngName){
	Vector<SpriteFrame*> frameVec;

	for (int i = 1; i <= frameNumber; i++){
		frameVec.pushBack(SpriteFrame::create(StringUtils::format("%s%d.png", pngName.asString().c_str(), i),
			Rect(0, 0, LENGTH_OF_SIDE, LENGTH_OF_SIDE)));
	}

	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(INTERVAL_TIME);

	auto action = Animate::create(animation);

	return action;
}