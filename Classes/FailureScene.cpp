#include "FailureScene.h"
#include "HelloWorldScene.h"
#include "GameSettings.h"
#include "AnotherFailureScene.h"

Scene* Failure::createScene(int row){
	auto scene = Scene::create();
	auto layer = Failure::create();
	scene->addChild(layer);

	auto rabbit = Sprite::create();
	rabbit->setPosition(Point(LENGTH_OF_SIDE*WIDTH, LENGTH_OF_SIDE*(row - 0.5f)));
	layer->bindSprite(rabbit);

	auto animate = [&](int frameNumber, Value pngName){
		Vector<SpriteFrame*> frameVec;

		for (int i = 1; i <= frameNumber; i++){
			frameVec.pushBack(SpriteFrame::create(StringUtils::format("%s%d.png", pngName.asString().c_str(), i),
				Rect(0, 0, 100, 100)));
		}

		auto animation = Animation::createWithSpriteFrames(frameVec);
		animation->setLoops(-1);
		animation->setDelayPerUnit(INTERVAL_TIME);

		auto action = Animate::create(animation);
		return action;
	};
	rabbit->runAction(animate(9, Value("RabbitMove")));

	auto moveTo = MoveTo::create(4.0f, Point(LENGTH_OF_SIDE*8.0f, LENGTH_OF_SIDE*4.0f));
	auto callFunc = CallFunc::create([&](){
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, AnotherFailure::createScene()));
	});
	auto actions = Sequence::create(moveTo, callFunc, NULL);
	rabbit->runAction(actions);

	return scene;
}

void Failure::bindSprite(Sprite* sprite){
	rabbit = sprite;
	this->addChild(rabbit);
}

bool Failure::init(){
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("mapfinal.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y)); 
	this->addChild(background, 0);

	return true;
}