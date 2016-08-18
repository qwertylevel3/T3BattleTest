#include "weapon.h"


Weapon::Weapon()
{
    strRequire=0;
    intRequire=0;
    agiRequire=0;
    weaponDamage=0;
}

int Weapon::getWeaponDamage() const
{
    return weaponDamage;
}

void Weapon::setWeaponDamage(int value)
{
    weaponDamage = value;
}

int Weapon::getStrRequire() const
{
    return strRequire;
}

void Weapon::setStrRequire(int value)
{
    strRequire = value;
}

int Weapon::getAgiRequire() const
{
    return agiRequire;
}

void Weapon::setAgiRequire(int value)
{
    agiRequire = value;
}

int Weapon::getIntRequire() const
{
    return intRequire;
}

void Weapon::setIntRequire(int value)
{
    intRequire = value;
}
