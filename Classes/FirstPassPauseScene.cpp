#include "FirstPassPauseScene.h"
#include "HelloWorldScene.h"
#include "GameSettings.h"

Scene* FirstPassPause::createScene(RenderTexture* sqr){
	auto scene = Scene::create();
	auto layer = FirstPassPause::create();
	scene->addChild(layer, 1);

    auto *_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());  
	_spr->setPosition(Point(LENGTH_OF_SIDE*WIDTH / 2, LENGTH_OF_SIDE*HEIGHT / 2)); 
    _spr->setFlipY(true);            
    _spr->setColor(Color3B::GRAY); 
	scene->addChild(_spr, 0);
	return scene;
}

bool FirstPassPause::init(){
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto goBackItem = Label::create("Back", "LetterGothicStd-Bold", 48);
	auto itemLabel1 = MenuItemLabel::create(
		goBackItem,
		[](Ref* pSender){
		Director::getInstance()->popScene();
	}
	);
	itemLabel1->setPosition(Point(0, itemLabel1->getContentSize().height * 1.5f));

	auto mainMenu = Label::create("Main Menu", "LetterGothicStd-Bold", 48);
	auto itemLabel2 = MenuItemLabel::create(
		mainMenu,
		[](Ref* pSender){
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	}
	);
	itemLabel2->setPosition(Point(0, 0));

	auto menu = Menu::create(itemLabel1, itemLabel2, NULL);
	menu->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(menu);

	return true;
}