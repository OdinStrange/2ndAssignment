#include "magician.h"
#include "monster.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname) 
{
    job_name = "마법사";
    cout << "* 마법사로 전직하였습니다." << endl;
    MP = 80;
}

void Magician::attack(Monster* monster) 
{
    cout << "* 매직 미사일을 1회 날린다" << endl;
	int damage = CalculateDamage(this->power, monster->getDefence());

	if (monster->getHP() > 0)
	{
		monster->setHP(monster->getHP() - damage);
	}
	else
	{
		cout << "플레이어의 승리!" << endl;
	}
	// 몬스터의 getHP를 호출 분기문이 실행됩니다.
	// 몬스터가 생존했을 경우 몬스터의 남은 HP 출력
	// 몬스터가 생존하지 못했을 경우 플레이어의 승리 문구 출력
}