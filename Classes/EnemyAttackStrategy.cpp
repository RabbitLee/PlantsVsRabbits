#include "EnemyAttackStrategy.h"

/*Game settings initialize easy*/
//AttackStrategyManger* AttackStrategyManger::myStrategy = nullptr;
//bool AttackStrategyManger::init()
//{
//	attackOfZombie = ATTACK_OF_ZOMBIE; 
//	speedOfZombie = SPEED_OF_ZOMBIE; 
//	attackOfEveil = ATTACK_OF_EVILRABBIT;
//	speedOfEveil = SPEED_OF_EVILRABBIT; 
//	numOfZombieWave = NUMBER_OF_ZOMBIE_WAVE; 
//	numOfEvilWave = NUMBER_OF_EVILRABBIT_WAVE;
//	contOfZombie = new Wave[numOfZombieWave+1];
//	int beginZNumber = 0, beginZFrequence = 0;
//	for(int i = 0; i < numOfZombieWave+1; i++, beginZFrequence+=20, beginZNumber+=2 )
//	{
//		contOfZombie[i].mynumber = beginZNumber;
//		contOfZombie[i].myfrequence = beginZFrequence;
//
//	}
//	contOfEvil = new Wave[numOfEvilWave+1];
//	int beginENumber = 0, beginEFrequence = 0;
//	for(int i = 0; i < numOfEvilWave+1; i++, beginEFrequence+=50, beginENumber+=1 )
//	{
//		contOfEvil[i].mynumber = beginENumber;
//		contOfEvil[i].myfrequence = beginEFrequence;
//	}
//
//	return true;
//}

/*strategy*/
EnemyAttackStrategy::EnemyAttackStrategy(){}
EasyStrategy::EasyStrategy(){}
NormalStrategy::NormalStrategy(){}
HardStrategy::HardStrategy(){}

void EnemyAttackStrategy::setAttack( int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack ){}
void EasyStrategy::setAttack( int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack )
{
	ZombieSpeed = 1;
	ZombieAttack = 1;
	EvilSpeed = 2;
	EvilAttack = 2;

	/*myStrategy->setNumOfZombieWave(NUMBER_OF_ZOMBIE_WAVE - 1);
	myStrategy->setNumOfEvilWave(NUMBER_OF_EVILRABBIT_WAVE - 1);
	Wave *contOfZombie = new Wave[myStrategy->getNumOfZombieWave() + 1];
	int beginZNumber = 0, beginZFrequence = 0;
	for(int i = 0; i < myStrategy->getNumOfZombieWave() + 1; i++, beginZFrequence+=20, beginZNumber+=2 )
	{
		contOfZombie[i].mynumber = beginZNumber;
		contOfZombie[i].myfrequence = beginZFrequence;

	}
	Wave *contOfEvil = new Wave[myStrategy->getNumOfEvilWave() + 1];
	int beginENumber = 0, beginEFrequence = 0;
	for(int i = 0; i < myStrategy->getNumOfEvilWave() + 1; i++, beginEFrequence+=50, beginENumber+=1 )
	{
		contOfEvil[i].mynumber = beginENumber;
		contOfEvil[i].myfrequence = beginEFrequence;
	}

	myStrategy->setContOfZombie(contOfZombie);
	myStrategy->setContOfEvil(contOfEvil);*/
}

void NormalStrategy::setAttack( int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack )
{
	ZombieSpeed = 3;
	ZombieAttack = 1;
	EvilSpeed = 2;
	EvilAttack = 2;

	//myStrategy->setNumOfZombieWave(NUMBER_OF_ZOMBIE_WAVE);
	//myStrategy->setNumOfEvilWave(NUMBER_OF_EVILRABBIT_WAVE);
	//Wave *contOfZombie = new Wave[myStrategy->getNumOfZombieWave() + 1];
	//int beginZNumber = 0, beginZFrequence = 0;
	//for(int i = 0; i <myStrategy->getNumOfZombieWave() + 1; i++, beginZFrequence+=20, beginZNumber+=2 )
	//{
	//	contOfZombie[i].mynumber = beginZNumber;
	//	contOfZombie[i].myfrequence = beginZFrequence;

	//}
	//contOfZombie[2].myfrequence = 50;
	//contOfZombie[3].mynumber = 3;
	//contOfZombie[3].myfrequence = 40;

	//Wave *contOfEvil = new Wave[myStrategy->getNumOfEvilWave() + 1];
	//int beginENumber = 0, beginEFrequence = 0;
	//for(int i = 0; i < myStrategy->getNumOfEvilWave()+1; i++, beginEFrequence+=50, beginENumber+=1 )
	//{
	//	contOfEvil[i].mynumber = beginENumber;
	//	contOfEvil[i].myfrequence = beginEFrequence;
	//}
	//contOfEvil[2].mynumber = 5;

	//myStrategy->setContOfZombie(contOfZombie);
	//myStrategy->setContOfEvil(contOfEvil);
}
void HardStrategy::setAttack( int &ZombieSpeed, int &ZombieAttack, int &EvilSpeed, int &EvilAttack )
{
	ZombieSpeed = 20;
	ZombieAttack = 2;
	EvilSpeed = 10;
	EvilAttack = 3;

	//myZombieManger->setAttack(2);
	//myEvilRabbitManger->setAttack(2);
	//myZombieManger->setSpeed(20);
	//myEvilRabbitManger->setSpeed(10);
	//myStrategy->setNumOfZombieWave(NUMBER_OF_ZOMBIE_WAVE + 1);
	//myStrategy->setNumOfEvilWave(NUMBER_OF_EVILRABBIT_WAVE + 1);
	//Wave *contOfZombie = new Wave[myStrategy->getNumOfZombieWave() + 1];
	//int beginZNumber = 0, beginZFrequence = 0;
	//for(int i = 0; i < myStrategy->getNumOfZombieWave() + 1; i++, beginZFrequence+=20, beginZNumber+=2 )
	//{
	//	contOfZombie[i].mynumber = beginZNumber;
	//	contOfZombie[i].myfrequence = beginZFrequence;

	//}
	//contOfZombie[2].myfrequence = 50;
	//contOfZombie[4].mynumber = 6;

	//Wave *contOfEvil = new Wave[myStrategy->getNumOfEvilWave() + 1];
	//int beginENumber = 0, beginEFrequence = 0;
	//for(int i = 0; i < myStrategy->getNumOfEvilWave() + 1; i++, beginEFrequence+=50, beginENumber+=1 )
	//{
	//	contOfEvil[i].mynumber = beginENumber;
	//	contOfEvil[i].myfrequence = beginEFrequence;
	//}
	//contOfEvil[3].myfrequence = 110;

	//myStrategy->setContOfZombie(contOfZombie);
	//myStrategy->setContOfEvil(contOfEvil);
}


