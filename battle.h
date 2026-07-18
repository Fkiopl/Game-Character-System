#pragma once
#include "Character.h"
using namespace std;

void battle(Character* attacker, Character* defender) {
    cout << "\n--- BATTLE START ---" << endl;

    attacker->displayStats();
    cout << "vs" << endl;
    defender->displayStats();

    int healthBefore = defender->getHealth();

    attacker->attack(defender);

    int damage = healthBefore - defender->getHealth();

    BattleLog log;
    log.attackerName = attacker->getName();
    log.defenderName = defender->getName();
    log.damage = damage;

    history.push_back(log);

    cout << "--- BATTLE END ---" << endl;
}
