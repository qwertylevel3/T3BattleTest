#include "character.h"

Character::Character()
{
    dead=false;
    leftHand=nullptr;
    rightHand=nullptr;
    armor=nullptr;
    accessory=nullptr;
}

bool Character::isDead()
{
    return dead;
}

void Character::sufferDamage(int d)
{
    HP-=d;
    if(HP<=0)
    {
        dead=true;
    }
}

int Character::getAttack()
{
    return 0;
}

int Character::getStrength() const
{
    return strength;
}

void Character::setStrength(int value)
{
    strength = value;
}

int Character::getIntellect() const
{
    return intellect;
}

void Character::setIntellect(int value)
{
    intellect = value;
}

int Character::getAgility() const
{
    return agility;
}

void Character::setAgility(int value)
{
    agility = value;
}

int Character::getHP() const
{
    return HP;
}

void Character::setHP(int value)
{
    HP = value;
}

int Character::getMP() const
{
    return MP;
}

void Character::setMP(int value)
{
    MP = value;
}

int Character::getMaxHP() const
{
    return maxHP;
}

void Character::setMaxHP(int value)
{
    maxHP = value;
}

int Character::getMaxMP() const
{
    return maxMP;
}

void Character::setMaxMP(int value)
{
    maxMP = value;
}


std::string Character::getName() const
{
    return name;
}

void Character::setName(const std::string &value)
{
    name = value;
}

Weapon *Character::getLeftHand() const
{
    return leftHand;
}

void Character::setLeftHand(Weapon *value)
{
    leftHand = value;
}

Weapon *Character::getRightHand() const
{
    return rightHand;
}

void Character::setRightHand(Weapon *value)
{
    rightHand = value;
}

Armor *Character::getArmor() const
{
    return armor;
}

void Character::setArmor(Armor *value)
{
    armor = value;
}

Accessory *Character::getAccessory() const
{
    return accessory;
}

void Character::setAccessory(Accessory *value)
{
    accessory = value;
}
