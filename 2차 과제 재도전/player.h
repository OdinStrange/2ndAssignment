#pragma once
#include <string>
#include <iostream>
using namespace std;

class Monster;
// Player 헤더에서 Monster* 를 사용하므로 전방선언 추가

class Player
{
    public: // 클래스 내부에서만 사용
    Player(string nickname);
    virtual void attack(Monster* monster) = 0;
    void printPlayerStatus();

    // getter 함수
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 함수
    void setNickname(string nickname);
    void setHP(int HP);
    void setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

    int CalculateDamage(int power, int defence)
    {
        int damage = power - defence;
        return (damage > 0) ? damage : 1;
    }

protected:
    string job_name;    // 누락된 멤버 변수 선언 추가
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;

};

