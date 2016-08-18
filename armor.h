#ifndef ARMOR_H
#define ARMOR_H

#include"Inventory.h"

class Armor:public Inventory
{
public:
    Armor();
    int getArmorCount() const;
    void setArmorCount(int value);

protected:
    int armorCount;
};

#endif // ARMOR_H
