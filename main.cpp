#include "Character.h"
#include "menu.h"
#include "createCharacter.h"
#include "viewChars.h"
#include "battle.h"
#include "startBattle.h"
#include "showHistory.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    vector<Character*> characters;
    int choice;

    do {
        clearScreen();
        showMenu();
        choice = getChoice(1, 6);

        switch (choice) {
            case 1: createCharacter(characters); break;
            case 2: viewChars(characters); break;
            case 3: startBattle(characters); break;
            case 4: showHistory(); break;
            case 5: healAll(characters); break;
        }

        if (choice != 6) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 6);

    for (int i = 0; i < characters.size(); i++)
        delete characters[i];

    return 0;
}
