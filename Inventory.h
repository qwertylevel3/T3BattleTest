#ifndef INVENTORY_H
#define INVENTORY_H


#pragma once

#include<string>

class Character;

class Inventory
{

public:
    enum Type
    {
        Weapon, Armor, Supply, Accessory,Other
    };

	Inventory();
	~Inventory();
	virtual void equip(Character* character);
	virtual void unequip(Character* character);
	virtual void load(Character* character);
	virtual void unload(Character* character);
	virtual void use(Character* character);
    int getId() const;
    void setId(int value);

    std::string getName() const;
    void setName(const std::string &value);

    std::wstring getCname() const;
    void setCname(const std::wstring &value);

    int getPrice() const;
    void setPrice(int value);

    int getWeight() const;
    void setWeight(int value);

    Inventory::Type getInventoryType() const;
    void setInventoryType(const Inventory::Type &value);
    int getEvadeProAdd() const;
    void setEvadeProAdd(int value);

    int getAccuracyProAdd() const;
    void setAccuracyProAdd(int value);

    int getCriticalProAdd() const;
    void setCriticalProAdd(int value);

    int getCriticalAdd() const;
    void setCriticalAdd(int value);

    int getBlockProAdd() const;
    void setBlockProAdd(int value);

    int getBlockAdd() const;
    void setBlockAdd(int value);

    int getComboProAdd() const;
    void setComboProAdd(int value);

protected:
    int id;
    std::string name;
    std::wstring cname;
    int price;
    int weight;
    Inventory::Type inventoryType;

    int evadeProAdd;//闪避几率加成
    int accuracyProAdd;//准确度加成
    int criticalProAdd;//暴击几率加成
    int criticalAdd;//暴击伤害加成
    int blockProAdd;//格挡几率加成
    int blockAdd;//格挡抵消伤害加成
    int comboProAdd;//combo几率加成
};

#endif // INVENTORY_H
