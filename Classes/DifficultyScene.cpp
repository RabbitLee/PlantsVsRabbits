#include "DifficultyScene.h"
#include "SimpleAudioEngine.h"
#include "GameSettings.h"
#include "HelloWorldScene.h"

Scene* Difficulty::createScene(){
	auto scene = Scene::create();
	auto layer = Difficulty::create();
	scene->addChild(layer);
	return scene;
}

bool Difficulty::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto musicbg = Sprite::create("MusicScene.png", Rect(0, 0, 960, 640));
	musicbg->setPosition(Point(LENGTH_OF_SIDE*WIDTH*0.5f, LENGTH_OF_SIDE*HEIGHT*0.5f));
	this->addChild(musicbg);

		auto label1 = Label::create("Easy", "LetterGothicStd-Bold", 36);
		auto itemLabel1 = MenuItemLabel::create(
			label1,
			[](Ref* pSender){
				/*EasyStrategy *Strategy = new EasyStrategy();
				setStrategy(Strategy);
				ExecuteStrategy();*/
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("LaLaLa.mp3");
		}
		);
		itemLabel1->setPosition(Point(-LENGTH_OF_SIDE * 3.5f, itemLabel1->getContentSize().height * 1.5f));
		
		auto label2 = Label::create("Normal", "LetterGothicStd-Bold", 36);
		auto itemLabel2 = MenuItemLabel::create(
			label2,
			[](Ref* pSender){
				/*NormalStrategy *Strategy = new NormalStrategy();
				setStrategy(Strategy);
				ExecuteStrategy();*/
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Tingge.mp3");
		}
		);
		itemLabel2->setPosition(Point(-LENGTH_OF_SIDE * 3.5f, 0));
		
		auto label3 = Label::create("Hard", "LetterGothicStd-Bold", 36);
		auto itemLabel3 = MenuItemLabel::create(
			label3,
			[](Ref* pSender){
				/*HardStrategy *Strategy = new HardStrategy();
				setStrategy(Strategy);
				ExecuteStrategy();*/
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("We_Got_The_Power.mp3");
		}
		);
		itemLabel3->setPosition(Point(-LENGTH_OF_SIDE * 3.5f, -itemLabel1->getContentSize().height * 1.5f));
		
		auto label5 = Label::create("Main Menu", "LetterGothicStd-Bold", 36);
		auto itemLabel5 = MenuItemLabel::create(
			label5,
			[](Ref* pSender){
			Director::getInstance()->replaceScene(HelloWorld::createScene());
		}
		);
		itemLabel5->setPosition(Point(LENGTH_OF_SIDE * 3.5f, -itemLabel1->getContentSize().height * 0.75f));
 
	auto menu = Menu::create(itemLabel1, itemLabel2, itemLabel3, itemLabel5, NULL);
	menu->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(menu);

	return true;
}
void Difficulty::setStrategy(EnemyAttackStrategy *Strategy)
{
	attackStrategy = Strategy;
}
void Difficulty::ExecuteStrategy()
{
	//attackStrategy->setAttack();
}