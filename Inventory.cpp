#include "Inventory.h"
#include"character.h"



Inventory::Inventory()
{
    evadeProAdd=0;
    accuracyProAdd=0;
    criticalProAdd=0;
    criticalAdd=0;
    blockProAdd=0;
    blockAdd=0;
    comboProAdd=0;
}


Inventory::~Inventory()
{
}

void Inventory::equip(Character* character)
{
}

void Inventory::unequip(Character* character)
{
}

void Inventory::load(Character* character)
{
}

void Inventory::unload(Character* character)
{
}

void Inventory::use(Character* character)
{
}

int Inventory::getId() const
{
    return id;
}

void Inventory::setId(int value)
{
    id = value;
}

std::string Inventory::getName() const
{
    return name;
}

void Inventory::setName(const std::string &value)
{
    name = value;
}

std::wstring Inventory::getCname() const
{
    return cname;
}

void Inventory::setCname(const std::wstring &value)
{
    cname = value;
}

int Inventory::getPrice() const
{
    return price;
}

void Inventory::setPrice(int value)
{
    price = value;
}

int Inventory::getWeight() const
{
    return weight;
}

void Inventory::setWeight(int value)
{
    weight = value;
}

Inventory::Type Inventory::getInventoryType() const
{
    return inventoryType;
}

void Inventory::setInventoryType(const Inventory::Type &value)
{
    inventoryType = value;
}

int Inventory::getEvadeProAdd() const
{
    return evadeProAdd;
}

void Inventory::setEvadeProAdd(int value)
{
    evadeProAdd = value;
}

int Inventory::getAccuracyProAdd() const
{
    return accuracyProAdd;
}

void Inventory::setAccuracyProAdd(int value)
{
    accuracyProAdd = value;
}

int Inventory::getCriticalProAdd() const
{
    return criticalProAdd;
}

void Inventory::setCriticalProAdd(int value)
{
    criticalProAdd = value;
}

int Inventory::getCriticalAdd() const
{
    return criticalAdd;
}

void Inventory::setCriticalAdd(int value)
{
    criticalAdd = value;
}

int Inventory::getBlockProAdd() const
{
    return blockProAdd;
}

void Inventory::setBlockProAdd(int value)
{
    blockProAdd = value;
}

int Inventory::getBlockAdd() const
{
    return blockAdd;
}

void Inventory::setBlockAdd(int value)
{
    blockAdd = value;
}

int Inventory::getComboProAdd() const
{
    return comboProAdd;
}

void Inventory::setComboProAdd(int value)
{
    comboProAdd = value;
}
