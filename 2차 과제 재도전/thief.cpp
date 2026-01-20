#include "thief.h"
#include "monster.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname) {
    job_name = "도적";
    cout << "* 도적으로 전직하였습니다." << endl;
    speed = 80;
}

void Thief::attack(Monster* monster) 
{   
    for (int i = 0; i <= 4; i++)
    {
    
        if (monster->getHP() > 0)
        {
            cout << "* 단검을 던진다" << endl;
            int damage = CalculateDamage(this->power, monster->getDefence()) / 5;
            if (damage < 1)
            {
                damage = 1;
            }
            monster->setHP(monster->getHP() - damage);
            cout << "* 슬라임에게 단검으로 2의 피해를 입혔다!" << endl;
        }
        else
        {
            cout << "플레이어의 승리!" << endl;
            break;
        }
    }
    
}