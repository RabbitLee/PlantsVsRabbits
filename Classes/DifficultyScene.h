#ifndef _DIFFICULTY_H_
#define _DIFFICUKTY_H_

#include "cocos2d.h"
#include "EnemyAttackStrategy.h"
USING_NS_CC;

class Difficulty : public Layer{
public:
	static Scene* createScene();
	CREATE_FUNC(Difficulty);
	virtual bool init();
	void setStrategy(EnemyAttackStrategy *Strategy);
	void ExecuteStrategy();
private:
	EnemyAttackStrategy *attackStrategy;

};

#endif