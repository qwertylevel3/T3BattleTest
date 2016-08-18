#ifndef BATTLETESTSYSTEM_H
#define BATTLETESTSYSTEM_H

#include"Singleton.h"
class Character;

class BattleTestSystem:public Singleton<BattleTestSystem>
{
public:
    BattleTestSystem();
    void init();
    void test();
protected:
    void showCharacterMessage();
    void battle(Character* a,Character* b);

    void attack(Character* a,Character* b);

    void sufferAttack(Character* c,int attackCount);

    int getAttackCount(Character* a);
    int getCriticalAttackCount(Character* c);
    int getBlockCount(Character* c);

    bool isEvade(Character* a,Character* b);
    bool isCritical(Character* c);
    bool isBlock(Character* c);



    void initCharacterA();
    void initCharacterB();

    Character* characterA;
    Character* characterB;

    double getRandom(double start,double end);
    bool roll(double m);//0-100,m为下界，当roll值小于m返回true

    int getEvadeProAdd(Character* c);
    int getAccuracyProAdd(Character* c);
    int getCriticalProAdd(Character* c);
    int getCriticalAdd(Character* c);
    int getBlockProAdd(Character* c);
    int getBlockAdd(Character* c);
    int getComboProAdd(Character* c);

    int combo;

};

#endif // BATTLETESTSYSTEM_H
