#include "monster.h"
#include "player.h"
#include <iostream>

using namespace std;

void Monster::attack(Player* player)
{
    if (player == nullptr) return;

    // 데미지 계산 (CalculateDamage는 최소 1을 반환하도록 구현되어 있음)
    int damage = CalculateDamage(this->power, player->getDefence());

    cout << this->name << "이(가) " << player->getNickname() << "에게 " << damage << "의 피해를 입혔습니다." << endl;

    int newHP = player->getHP() - damage;
    player->setHP(newHP);

    if (player->getHP() > 0)
    {
        cout << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
    }
    else
    {
        cout << player->getNickname() << "는(은) 사망했습니다." << endl;
    }
}

// 몬스터 상태 출력 (간단한 디버그용)
void Monster::printPlayerStatus()
{
    cout << "몬스터: " << this->name
         << ", HP: " << this->HP
         << ", Power: " << this->power
         << ", Defence: " << this->defence
         << ", Speed: " << this->speed
         << endl;
}

// Getter 정의
string Monster::getName() { return this->name; }
int Monster::getHP() { return this->HP; }
int Monster::getPower() { return this->power; }
int Monster::getDefence() { return this->defence; }
int Monster::getSpeed() { return this->speed; }

// Setter 정의
void Monster::setName(string name) { this->name = name; }
void Monster::setHP(int HP) { this->HP = HP; }
void Monster::setPower(int power) { this->power = power; }
void Monster::setDefence(int defence) { this->defence = defence; }
void Monster::setSpeed(int speed) { this->speed = speed; }
//이 cpp 전체 설명 필요합니다