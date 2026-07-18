#pragma once
#include "Character.h"
#include "menu.h"
#include <vector>
using namespace std;

void createCharacter(vector<Character*>& characters) {
    clearScreen();

    string name;
    cout << "Enter character name: ";
    cin >> name;

    cout << "\n=== Choose Class ===" << endl;
    cout << "1 - Warrior" << endl;
    cout << "2 - Mage" << endl;
    cout << "3 - Archer" << endl;

    int choice = getChoice(1, 3);

    Character* newChar;

    if (choice == 1)
        newChar = new Warrior(name);
    else if (choice == 2)
        newChar = new Mage(name);
    else
        newChar = new Archer(name);

    characters.push_back(newChar);
    cout << "\nCharacter added!" << endl;
}
