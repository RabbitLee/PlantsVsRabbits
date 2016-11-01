#include "EnemyManger.h"

void EnemyManger::initial(){
	waveNumber = 1;
	enemyNumberInWave = 0;
	frequenceOfEnemy = 0;
	for (int i = 1; i < HEIGHT; i++){
		enemyNumberInRow[i] = 0;
	}
	deadEnemy = 0;
	winEnemy = NULL;
}

int EnemyManger::getEnemyInRow(int row){
	return enemyNumberInRow[row];
}

Vector<Entity*>* EnemyManger::getMapOfEnemy(){
	return &myMapOfEnemy;
}

Entity* EnemyManger::getWinEnemy(){
	return winEnemy;
}

int EnemyManger::getNumberOfDeadEnemy(){
	return deadEnemy;
}


void EnemyManger::mutUpdate(float dt){
	for (auto enemy = myMapOfEnemy.begin(); enemy != myMapOfEnemy.end();)
	{
		if ((*enemy)->getHealthPoint() <= 0){
			enemyNumberInRow[(int)((*enemy)->getPositionY() / LENGTH_OF_SIDE) + 1]--;
			(*enemy)->removeFromParent();
			enemy = myMapOfEnemy.erase(enemy);
			deadEnemy++;
		}
		else{
			(*enemy)->setPositionX((*enemy)->getPositionX() - speed);
			if ((*enemy)->getPositionX() < 0){
				winEnemy = *enemy;
				enemy = myMapOfEnemy.erase(enemy);
				break;
			}
			else{
				enemy++;
			}
		}
	}

}