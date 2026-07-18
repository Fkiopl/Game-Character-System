#pragma once
#include "Character.h"
#include <vector>
using namespace std;

void viewChars(vector<Character*>& characters) {
    if (characters.size() == 0) {
        cout << "No characters yet!" << endl;
        return;
    }

    cout << "\n--- CHARACTER LIST ---" << endl;
    for (int i = 0; i < characters.size(); i++) {
        cout << i + 1 << ". ";
        characters[i]->displayStats();
    }
    cout << "--- END ---" << endl;
}

void healAll(vector<Character*>& characters) {
    if (characters.size() == 0) {
        cout << "No characters yet!" << endl;
        return;
    }

    for (int i = 0; i < characters.size(); i++) {
        characters[i]->heal();
    }
    cout << "All characters healed!" << endl;
}
