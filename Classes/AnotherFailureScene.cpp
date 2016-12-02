#include "AnotherFailureScene.h"
#include "HelloWorldScene.h"
#include "GameSettings.h"

Scene* AnotherFailure::createScene(){
	auto scene = Scene::create();
	auto layer = AnotherFailure::create();
	scene->addChild(layer);

	return scene;
}

bool AnotherFailure::init(){
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("ULose.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, 0);

	auto label = Label::create("Main Menu", "LetterGothicStd-Bold", 48);
	auto itemLabel = MenuItemLabel::create(
		label,
		[](Ref* pSender){
		Director::getInstance()->replaceScene(HelloWorld::createScene());
		}
	);

	auto menu = Menu::create(itemLabel, NULL);
	menu->setPosition(Point(visibleSize.width / 2, visibleSize.height / 3));
	this->addChild(menu, 1);

	return true;
}