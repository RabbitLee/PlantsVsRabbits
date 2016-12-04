#ifndef	_ENEMYATTACKSTRATEGY_H_
#define _ENEMYATTACKSTRATEGY_H_

#include "cocos2d.h"
#include "GameSettings.h"
#include "ZombieManger.h"
#include "EvilRabbitManger.h"

USING_NS_CC;

//struct Wave{
//		int mynumber;
//		int myfrequence;
//	};
//
//class AttackStrategyManger : public Node{
//public:
//	CREATE_FUNC(AttackStrategyManger);
//	virtual bool init();
//
//	static AttackStrategyManger * getInstance()  
//    {  
//		if(myStrategy == nullptr)  //判断是否第一次调用  
//		{
//            myStrategy = AttackStrategyManger::create(); 
//		
//		}
//        return myStrategy;  
//    } 
//	/*static void DestoryInstance()
//	{
//		if (myStrategy != NULL )
//		{
//			delete myStrategy;
//			myStrategy = NULL ;
//		}
//	}*/
//
//	int getAttackOfZombie(){return attackOfZombie;}
//	int getAttackOfEveil(){return attackOfEveil;}
//	int getSpeedOfZombie(){return speedOfZombie;}
//	int getSpeedOfEveil(){return speedOfEveil;}
//	int getNumOfZombieWave(){return numOfZombieWave;}
//	int getNumOfEvilWave(){return numOfEvilWave;}
//	Wave *getContOfZombie(){return contOfZombie;}
//    Wave *getContOfEvil(){return contOfEvil;}
//
//	void setAttackOfZombie(int m_attack){attackOfZombie = m_attack;}
//	void setAttackOfEveil(int m_attack){attackOfEveil = m_attack;}
//	void setSpeedOfZombie(int m_speed){speedOfZombie = m_speed;}
//	void setSpeedOfEveil(int m_speed){speedOfEveil = m_speed;}
//	void setNumOfZombieWave(int m_wave){numOfZombieWave = m_wave;}
//	void setNumOfEvilWave(int m_wave){numOfEvilWave = m_wave;}
//	void setContOfZombie(Wave *m_cont){contOfZombie = m_cont;}
//    void setContOfEvil(Wave *m_cont){contOfEvil = m_cont;}
//private:
//	static AttackStrategyManger* myStrategy;
//	//AttackStrategyManger();
//    int attackOfZombie;
//    int speedOfZombie;
//    int attackOfEveil;
//    int speedOfEveil;
//    int numOfZombieWave;
//    int numOfEvilWave;
//
//    Wave *contOfZombie;
//    Wave *contOfEvil;
//};

class EnemyAttackStrategy{
public:
	EnemyAttackStrategy();
	virtual void setAttack( int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack );

};

class EasyStrategy : public EnemyAttackStrategy{
public:
	EasyStrategy();
	virtual void setAttack(int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack );

};

class NormalStrategy : public EnemyAttackStrategy{
public:
	NormalStrategy();
	virtual void setAttack(int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack );

};

class HardStrategy : public EnemyAttackStrategy{
public:
	HardStrategy();
	virtual void setAttack(int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack );

};

#endif