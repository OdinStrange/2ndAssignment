#include "warrior.h"
#include "monster.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "전사";
    cout << "* 전사로 전직하였습니다." << endl;
    HP = 80;
}

void Warrior::attack(Monster* monster) 
{
    cout << "* 장검을 1회 휘두른다" << endl;
	// 플레이어의 공격력-몬스터의 방어력을 계산하여 데미지로 정의합니다.
	// 계산된 데미지가 0 이하일 경우, 데미지를 1로 정의합니다.
	
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
