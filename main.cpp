#include <iostream>
#include"battletestsystem.h"


int main(int argc, char *argv[])
{
    BattleTestSystem::instance()->init();
    BattleTestSystem::instance()->test();
    return 0;
}
