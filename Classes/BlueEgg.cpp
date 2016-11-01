#include "BlueEgg.h"
#include "GameSettings.h"

bool BlueEgg::init(){
	setAnchorPoint(ccp(0.5f, 0.5f));
	setHealthPoint(HEALTH_POINT_OF_BLUEEGG);
	this->bindSprite(Sprite::create("blueEgg.png"));

	auto createAnimate = [&](int frameNumber, Value pngName){
		Vector<SpriteFrame*> frameVec;

		for (int i = 1; i <= frameNumber; i++){
			frameVec.pushBack(SpriteFrame::create(StringUtils::format("%s%d.png", pngName.asString().c_str(), i),
				Rect(0, 0, LENGTH_OF_SIDE, LENGTH_OF_SIDE)));
		}

		auto animation = Animation::createWithSpriteFrames(frameVec);
		animation->setLoops(1);
		animation->setDelayPerUnit(INTERVAL_TIME);

		auto action = Animate::create(animation);

		return action;
	};

	mySprite->runAction(createAnimate(8, Value("Boomegg")));
	

	return true;
}