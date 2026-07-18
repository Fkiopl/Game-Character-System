#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

void clearScreen() {
    system("cls");
}

void showMenu() {
    cout << "=== MAIN MENU ===" << endl;
    cout << "1. Create Character" << endl;
    cout << "2. View Characters" << endl;
    cout << "3. Start Battle" << endl;
    cout << "4. Show History" << endl;
    cout << "5. Heal All" << endl;
    cout << "6. Exit" << endl;
}

int getChoice(int min, int max) {
    int choice;
    do {
        cout << "Enter choice: ";
        cin >> choice;
    } while (choice < min || choice > max);
    return choice;
}
