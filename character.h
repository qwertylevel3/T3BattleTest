#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>
class Inventory;
class Weapon;
class Accessory;
class Armor;

class Character
{
public:
    Character();
    bool isDead();
    void sufferDamage(int d);
    int getAttack();

    int getStrength() const;
    void setStrength(int value);

    int getIntellect() const;
    void setIntellect(int value);

    int getAgility() const;
    void setAgility(int value);

    int getHP() const;
    void setHP(int value);

    int getMP() const;
    void setMP(int value);

    int getMaxHP() const;
    void setMaxHP(int value);

    int getMaxMP() const;
    void setMaxMP(int value);

    std::string getName() const;
    void setName(const std::string &value);

    Weapon *getLeftHand() const;
    void setLeftHand(Weapon *value);

    Weapon *getRightHand() const;
    void setRightHand(Weapon *value);

    Armor *getArmor() const;
    void setArmor(Armor *value);

    Accessory *getAccessory() const;
    void setAccessory(Accessory *value);
protected:
    std::string name;
    Weapon* leftHand;
    Weapon* rightHand;
    Armor* armor;
    Accessory* accessory;

    bool dead;

    int strength;
    int intellect;
    int agility;
    int HP;
    int MP;
    int maxHP;
    int maxMP;
};

#endif // CHARACTER_H
