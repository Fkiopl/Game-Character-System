#pragma once
#include "Character.h"
#include "battle.h"
#include "menu.h"
#include <vector>
using namespace std;

void startBattle(vector<Character*>& characters) {
    if (characters.size() < 2) {
        cout << "Need at least 2 characters!" << endl;
        return;
    }

    cout << "\n=== Choose Attacker ===" << endl;
    for (int i = 0; i < characters.size(); i++) {
        cout << i + 1 << ". ";
        characters[i]->displayStats();
    }
    int a = getChoice(1, characters.size()) - 1;

    cout << "\n=== Choose Defender ===" << endl;
    for (int i = 0; i < characters.size(); i++) {
        if (i == a) continue;
        cout << i + 1 << ". ";
        characters[i]->displayStats();
    }
    int d = getChoice(1, characters.size()) - 1;

    if (a == d) {
        cout << "Can't fight yourself!" << endl;
        return;
    }

    battle(characters[a], characters[d]);
}
