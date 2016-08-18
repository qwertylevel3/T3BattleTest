#ifndef WEAPON_H
#define WEAPON_H

#include"Inventory.h"

class Weapon:public Inventory
{
public:
    Weapon();
    int getWeaponDamage() const;
    void setWeaponDamage(int value);

    int getStrRequire() const;
    void setStrRequire(int value);

    int getAgiRequire() const;
    void setAgiRequire(int value);

    int getIntRequire() const;
    void setIntRequire(int value);
protected:
    int weaponDamage;
    int strRequire;
    int agiRequire;
    int intRequire;
};

#endif // WEAPON_H
