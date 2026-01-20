#include "archer.h"
#include "monster.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname) {
    job_name = "궁수";
    cout << "* 궁수로 전직하였습니다." << endl;
    accuracy = 80;
}

void Archer::attack(Monster* monster) 
{
    for (int i = 0; i <= 2; i++)
    {
        if (monster->getHP() > 0)
        {
            cout << "* 활을 쏜다" << endl;
            int damage = CalculateDamage(this->power, monster->getDefence()) / 3;
            if (damage < 1)
            {
                damage = 1;
            }
            monster->setHP(monster->getHP() - damage);
            cout << "* 슬라임에게 화살로 3의 피해를 입혔다!" << endl;
        }
        else
        {
            cout << "플레이어의 승리!" << endl;
            break;
        }
    }
}