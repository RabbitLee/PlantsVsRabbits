#include "HelloWorldScene.h"
#include "FirstPassScene.h"
#include "SimpleAudioEngine.h"
#include "FailureScene.h"
#include "MusicScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    /////////////////////////////
    // 3. add your codes below...

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sky_city.mp3");

    auto background = Sprite::create("Background.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, 0);


	auto label1 = Label::create("Start", "Broadway", 48);
	auto itemLabel1 = MenuItemLabel::create(
		label1,
		[](Ref* pSender){ 
			Director::getInstance()->replaceScene(FirstPass::createScene());
		}
	);
	itemLabel1->setPosition(Point(0, itemLabel1->getContentSize().height * 1.5f));

	auto label2 = Label::create("Music", "Broadway", 48);
	auto itemLabel2 = MenuItemLabel::create(
		label2,
		[](Ref* pSender){
		Director::getInstance()->replaceScene(Music::createScene());
		}
	);
	itemLabel2->setPosition(Point(0, 0));

	auto label3 = Label::create("Exit", "Broadway", 48);
	auto itemLabel3 = MenuItemLabel::create(
		label3,
		CC_CALLBACK_1(
			HelloWorld::menuCloseCallback,
			this
		)
	);
	itemLabel3->setPosition(Point(0, - itemLabel1->getContentSize().height * 1.5f));

	auto menu = Menu::create(itemLabel1, itemLabel2, itemLabel3, NULL);
	menu->setPosition(Point(LENGTH_OF_SIDE * 2.0f, LENGTH_OF_SIDE * 3.0f));
	this->addChild(menu, 1);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
