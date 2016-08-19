#include "battletestsystem.h"
#include"character.h"
#include"Inventory.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"weapon.h"
#include"armor.h"
#include"accessory.h"

using namespace std;

BattleTestSystem::BattleTestSystem()
{
    showMessage=false;
}

void BattleTestSystem::init()
{
    initCharacterA();
    initCharacterB();
    srand(unsigned(time(0)));
}

void BattleTestSystem::test()
{
    AWinCount=0;
    BWinCount=0;
    for(int i=0;i<100;i++)
    {
        initCharacterA();
        initCharacterB();
        battle(characterA,characterB);
    }
    cout<<"------------"<<endl;
    cout<<characterA->getName()<<" win :"<<AWinCount<<endl;
    cout<<characterB->getName()<<" win :"<<BWinCount<<endl;
}

void BattleTestSystem::showCharacterMessage()
{
    //cout<<characterA->getName()<<" | "<<characterB->getName()<<endl;
}

void BattleTestSystem::battle(Character *a, Character *b)
{
    while(true)
    {
        attack(a,b);
        if(b->isDead())
        {
            break;
        }
        attack(b,a);
        if(a->isDead())
        {
            break;
        }
    }
    if(showMessage)
    {
        cout<<"battle end"<<endl;
    }

    if(a->isDead())
    {
        if(showMessage)
        {
            cout<<a->getName()<<" is dead"<<endl;
            cout<<b->getName()<<" remain HP:"<<b->getHP()<<endl;
        }

        BWinCount++;
    }
    else if(b->isDead())
    {
        if(showMessage)
        {
            cout<<b->getName()<<" is dead"<<endl;
            cout<<a->getName()<<" remain HP"<<a->getHP()<<endl;
        }

        AWinCount++;
    }
    //getchar();
}

void BattleTestSystem::attack(Character *a, Character *b)
{
    combo=0;
    if(showMessage)
    {
        cout<<"#"<<a->getName()<<" attack "<<b->getName()<<endl;
    }



    do
    {
        if(isEvade(a,b))
        {
            if(showMessage)
            {
                cout<<"evade"<<endl;
            }

            break;
        }
        int attackCount=0;
        if(isCritical(a))
        {
            if(showMessage)
            {
                cout<<"critical attack"<<endl;
            }

            attackCount=getCriticalAttackCount(a);
        }
        else
        {
            attackCount=getAttackCount(a);
        }
        if(showMessage)
        {
            cout<<a->getName()<<" attack count:"<<attackCount<<endl;
        }

        sufferAttack(b,attackCount);

        if(!isCombo(a))
        {
            break;
        }
        else
        {
            if(showMessage)
            {
                cout<<"combo!"<<endl;
            }

            combo++;
        }
    }while(true);
    //getchar();
}

void BattleTestSystem::sufferAttack(Character *c, int attackCount)
{
    Armor* armor=c->getArmor();
    int armorCount=0;
    int blockCount=0;
    if(armor)
    {
        armorCount=armor->getArmorCount();
    }
    if(isBlock(c))
    {
        if(showMessage)
        {
            cout<<"block"<<endl;
        }

        blockCount=getBlockCount(c);
    }

    attackCount=attackCount-armorCount-blockCount;
    attackCount=attackCount>=1?attackCount:1;
    c->sufferDamage(attackCount);
    if(showMessage)
    {
        cout<<c->getName()<<" suffer damage:"<<attackCount<<endl;
        cout<<c->getName()<<" remain HP:"<<c->getHP()<<endl;
    }


}

int BattleTestSystem::getAttackCount(Character *a)
{
    int agility=a->getAgility();
    int strength=a->getStrength();

    Weapon* leftHand=a->getLeftHand();
    int leftHandAgiReq=0;
    int leftHandStrReq=0;
    double leftHandAttack=0;
    Weapon* rightHand=a->getRightHand();
    int rightHandAgiReq=0;
    int rightHandStrReq=0;
    double rightHandAttack=0;

    if(leftHand)
    {
        leftHandAgiReq=leftHand->getAgiRequire();
        leftHandStrReq=leftHand->getStrRequire();

        leftHandAttack=leftHand->getWeaponDamage();

        if(leftHandAgiReq!=0 && leftHandAgiReq>=agility)
        {
            leftHandAttack=leftHandAttack*double(agility)/double(leftHandAgiReq);
        }
        if(leftHandStrReq!=0 && leftHandStrReq>=strength)
        {
            leftHandAttack=leftHandAttack*double(strength)/double(leftHandStrReq);
        }


    }
    if(rightHand)
    {
        rightHandAgiReq=rightHand->getAgiRequire();
        rightHandStrReq=rightHand->getStrRequire();

        rightHandAttack=rightHand->getWeaponDamage();

        if(rightHandAgiReq!=0 && rightHandAgiReq>=agility)
        {
            rightHandAttack=rightHandAttack*double(strength)/double(rightHandStrReq);
        }
        if(rightHandStrReq!=0 && rightHandStrReq>=strength)
        {
            rightHandAttack=rightHandAttack*double(agility)/double(rightHandAgiReq);
        }
    }
    return int(leftHandAttack+rightHandAttack);
}

int BattleTestSystem::getCriticalAttackCount(Character *c)
{
    double k1=0.01;
    int attackCount=getAttackCount(c);
    double criticalAttack=double(attackCount)*(1+k1*double(c->getStrength()))+getCriticalAdd(c);
    return int(criticalAttack);
}

int BattleTestSystem::getBlockCount(Character *c)
{
    double k1=0.5;
    double str=c->getStrength();
    double count=k1*str+getBlockAdd(c)+5;
    return int(count);
}

bool BattleTestSystem::isEvade(Character *a, Character *b)
{
    double B_agi=b->getAgility();

    double B_evadeAdd=getEvadeProAdd(b);

    double A_agi=a->getAgility();

    double A_accuracyAdd=getAccuracyProAdd(a);

    double k1=1;
    double k2=1;
    double k3=1;
    double temp=((B_agi*k1+B_evadeAdd)-(A_agi*k2+A_accuracyAdd));
    temp=temp>0?temp:0;
    temp=temp*k3+5;
    temp=temp>95?95:temp;

    if(showMessage)
    {
        cout<<b->getName()<<" evade chance:"<<temp<<endl;
    }


    return roll(temp);
}

bool BattleTestSystem::isCritical(Character *c)
{
    double k1=1;
    double agi=c->getAgility();

    double criProAdd=getCriticalProAdd(c);

    double criPro=agi*k1+criProAdd+5;

    if(showMessage)
    {
        cout<<c->getName()<<" critical chance: "<<criPro<<endl;
    }


    return roll(criPro);
}

bool BattleTestSystem::isBlock(Character *c)
{
    double k1=1;
    double agi=c->getAgility();
    double blockProAdd=getBlockProAdd(c);

    double blockPro=agi*k1+blockProAdd+5;

    if(showMessage)
    {
        cout<<c->getName()<<" block chance: "<<blockPro<<endl;
    }


    return roll(blockPro);
}

bool BattleTestSystem::isCombo(Character *c)
{
    double k1=0.1;
    double k2=5;
    double agility=c->getAgility();
    double comboProAdd=getComboProAdd(c);

    double comboPro=agility*k1+comboProAdd+5;
    comboPro=comboPro-k2*combo;
    comboPro=comboPro<0?0:comboPro;

    if(showMessage)
    {
        cout<<c->getName()<<" combo chance:"<<comboPro<<endl;
    }

    return roll(comboPro);
}

void BattleTestSystem::initCharacterA()
{
    characterA=new Character();
    characterA->setName("character_A");
    characterA->setMaxHP(100);
    characterA->setMaxMP(100);
    characterA->setHP(100);
    characterA->setMP(100);
    characterA->setAgility(10);
    characterA->setIntellect(10);
    characterA->setStrength(10);

    Weapon* sword=new Weapon();
    sword->setWeaponDamage(10);
    characterA->setLeftHand(sword);

    Weapon* spear=new Weapon();
    spear->setWeaponDamage(10);
    characterA->setRightHand(spear);

    Armor* armor=new Armor();
    armor->setArmorCount(5);
    characterA->setArmor(armor);
}

void BattleTestSystem::initCharacterB()
{
    characterB=new Character();
    characterB->setName("character_B");
    characterB->setMaxHP(100);
    characterB->setMaxMP(100);
    characterB->setHP(100);
    characterB->setMP(100);
    characterB->setAgility(10);
    characterB->setIntellect(10);
    characterB->setStrength(10);

    Weapon* sword=new Weapon();
    sword->setWeaponDamage(10);
    characterB->setLeftHand(sword);

    Weapon* shield=new Weapon();
    shield->setBlockAdd(20);
    shield->setBlockProAdd(60);
    characterB->setRightHand(shield);

    Armor* armor=new Armor();
    armor->setArmorCount(5);
    characterB->setArmor(armor);
}

double BattleTestSystem::getRandom(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

bool BattleTestSystem::roll(double m)
{
    double rand=getRandom(0,100);

    if(showMessage)
    {
        cout<<"roll:"<<rand<<endl;
    }

    if(rand<m)
    {
        return true;
    }
    return false;
}

int BattleTestSystem::getEvadeProAdd(Character *c)
{
    Inventory* leftHand=c->getLeftHand();
    Inventory* rightHand=c->getRightHand();
    Inventory* armor=c->getArmor();
    Inventory* accessory=c->getAccessory();

    int leftHandEvadeProAdd=leftHand?leftHand->getEvadeProAdd():0;
    int rightHandEvadeProAdd=rightHand?rightHand->getEvadeProAdd():0;
    int armorEvadeProAdd=armor?armor->getEvadeProAdd():0;
    int accessoryEvadeProAdd=accessory?accessory->getEvadeProAdd():0;

    return leftHandEvadeProAdd
                    +rightHandEvadeProAdd
                    +armorEvadeProAdd
                    +accessoryEvadeProAdd;
}

int BattleTestSystem::getAccuracyProAdd(Character *c)
{
    Inventory* leftHand=c->getLeftHand();
    Inventory* rightHand=c->getRightHand();
    Inventory* armor=c->getArmor();
    Inventory* accessory=c->getAccessory();

    int leftHandAccProAdd=leftHand?leftHand->getAccuracyProAdd():0;
    int rightHandAccProAdd=rightHand?rightHand->getAccuracyProAdd():0;
    int armorAccProAdd=armor?armor->getAccuracyProAdd():0;
    int accessoryAccProAdd=accessory?accessory->getAccuracyProAdd():0;

    return leftHandAccProAdd
                    +rightHandAccProAdd
                    +armorAccProAdd
                    +accessoryAccProAdd;
}

int BattleTestSystem::getCriticalProAdd(Character *c)
{
    Inventory* leftHand=c->getLeftHand();
    Inventory* rightHand=c->getRightHand();
    Inventory* armor=c->getArmor();
    Inventory* accessory=c->getAccessory();

    int leftHandCriProAdd=leftHand?leftHand->getCriticalProAdd():0;
    int rightHandCriProAdd=rightHand?rightHand->getCriticalProAdd():0;
    int armorCriProAdd=armor?armor->getCriticalProAdd():0;
    int accessoryCriProAdd=accessory?accessory->getCriticalProAdd():0;

    return leftHandCriProAdd
                    +rightHandCriProAdd
                    +armorCriProAdd
                    +accessoryCriProAdd;
}

int BattleTestSystem::getCriticalAdd(Character *c)
{
    Inventory* leftHand=c->getLeftHand();
    Inventory* rightHand=c->getRightHand();
    Inventory* armor=c->getArmor();
    Inventory* accessory=c->getAccessory();

    int leftHandCriAdd=leftHand?leftHand->getCriticalAdd():0;
    int rightHandCriAdd=rightHand?rightHand->getCriticalAdd():0;
    int armorCriAdd=armor?armor->getCriticalAdd():0;
    int accessoryCriAdd=accessory?accessory->getCriticalAdd():0;

    return leftHandCriAdd
                    +rightHandCriAdd
                    +armorCriAdd
                    +accessoryCriAdd;
}

int BattleTestSystem::getBlockProAdd(Character *c)
{
    Inventory* leftHand=c->getLeftHand();
    Inventory* rightHand=c->getRightHand();
    Inventory* armor=c->getArmor();
    Inventory* accessory=c->getAccessory();

    int leftHandBloProAdd=leftHand?leftHand->getBlockProAdd():0;
    int rightHandBloProAdd=rightHand?rightHand->getBlockProAdd():0;
    int armorBloProAdd=armor?armor->getBlockProAdd():0;
    int accessoryBloProAdd=accessory?accessory->getBlockProAdd():0;

    return leftHandBloProAdd
                    +rightHandBloProAdd
                    +armorBloProAdd
                    +accessoryBloProAdd;
}

int BattleTestSystem::getBlockAdd(Character *c)
{
    Inventory* leftHand=c->getLeftHand();
    Inventory* rightHand=c->getRightHand();
    Inventory* armor=c->getArmor();
    Inventory* accessory=c->getAccessory();

    int leftHandBloAdd=leftHand?leftHand->getBlockAdd():0;
    int rightHandBloAdd=rightHand?rightHand->getBlockAdd():0;
    int armorBloAdd=armor?armor->getBlockAdd():0;
    int accessoryBloAdd=accessory?accessory->getBlockAdd():0;

    return leftHandBloAdd
                    +rightHandBloAdd
                    +armorBloAdd
                    +accessoryBloAdd;
}

int BattleTestSystem::getComboProAdd(Character *c)
{
    Inventory* leftHand=c->getLeftHand();
    Inventory* rightHand=c->getRightHand();
    Inventory* armor=c->getArmor();
    Inventory* accessory=c->getAccessory();

    int leftHandComProAdd=leftHand?leftHand->getComboProAdd():0;
    int rightHandComProAdd=rightHand?rightHand->getComboProAdd():0;
    int armorComProAdd=armor?armor->getComboProAdd():0;
    int accessoryComProAdd=accessory?accessory->getComboProAdd():0;

    return leftHandComProAdd
                    +rightHandComProAdd
                    +armorComProAdd
                    +accessoryComProAdd;
}
