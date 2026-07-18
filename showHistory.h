#pragma once
#include "Character.h"
using namespace std;

void showHistory() {
    if (history.size() == 0) {
        cout << "No battles yet!" << endl;
        return;
    }

    cout << "\n--- BATTLE HISTORY ---" << endl;
    for (int i = 0; i < history.size(); i++) {
        cout << i + 1 << ". "
             << history[i].attackerName
             << " attacked "
             << history[i].defenderName
             << " for "
             << history[i].damage
             << " damage!" << endl;
    }
    cout << "--- END ---" << endl;
}
