#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player; // Player 포인터를 멤버로 쓰기 위해 전방선언

class Monster
{
public: 
    Monster(string name)
    {   
        // 기본 몬스터 이름은 슬라임으로 초기화 (자식 클래스에서 변경)
        this->name = "Slime";
        this->HP = 10;
        this->power = 30;
        this->defence = 10;
        this->speed = 10;
    }
    // 몬스터의 공격 함수
    // - 플레이어 객체 포인터를 매개변수로 입력 받습니다.
    // - 몬스터의 공격력-플레이어의 방어력을 데미지로 정의합니다.
    // - 만약 위에서 계산한 데미지가 0 이하라면, 데미지를 1로 정의합니다.
    // - 플레이어에게 얼마나 데미지를 입혔는지 출력합니다.
    // - 플레이어 객체의 getHP 함수를 실행하여 플레이어HP-데미지 계산 결과를
    // - 플레이어 객체의 setHP 매개변수로 전달합니다.
    // - 플레이어가 생존했을 경우, 플레이어의 남은 HP를 출력합니다.
    void attack(Player * player);

    void printPlayerStatus();
    

    // 몬스터의 속성값을 리턴하는 get 함수
    string getName();
    int getHP();
    int getPower();
    int getDefence();
    int getSpeed();


    // 몬스터의 속성값을 정의하는 set 함수
    void setName(string name);
    void setHP(int HP);
    void setPower(int power);
    void setDefence(int defence);
    void setSpeed(int speed);

    int CalculateDamage(int power, int defence)
    {
        int damage = power - defence;
        return (damage > 0) ? damage : 1;
    }

protected:
    string name; // 몬스터의 이름
    int HP; // 몬스터의 HP
    int power; // 몬스터의 공격력
    int defence; // 몬스터의 방어력
    int speed; // 몬스터의 스피드
};
