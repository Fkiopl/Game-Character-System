#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// =====================
// BattleLog Struct
// =====================
struct BattleLog {
    string attackerName;
    string defenderName;
    int damage;
};

vector<BattleLog> history;

// =====================
// Character Base Class
// =====================
class Character {
protected:
    string name;
    int health;
    int maxHealth;

public:
    Character(string n, int hp) {
        name = n;
        health = hp;
        maxHealth = hp;
    }

    virtual ~Character() {}

    virtual void attack(Character* defender) = 0;
    virtual string getType() = 0;

    void displayStats() {
        cout << "[" << getType() << "] " << name << " — HP: " << health << "/" << maxHealth << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    void heal() {
        health = maxHealth;
    }

    string getName() { return name; }
    int getHealth() { return health; }
    int getMaxHealth() { return maxHealth; }
    bool isAlive() { return health > 0; }
};

// =====================
// Warrior Class
// =====================
class Warrior : public Character {
public:
    Warrior(string name) : Character(name, 120) {}
    ~Warrior() {}

    string getType() { return "Warrior"; }

    void attack(Character* defender) {
        int damage = 25 + rand() % 10;
        cout << name << " slashes for " << damage << " damage!" << endl;
        defender->takeDamage(damage);
    }
};

// =====================
// Mage Class
// =====================
class Mage : public Character {
public:
    Mage(string name) : Character(name, 70) {}
    ~Mage() {}

    string getType() { return "Mage"; }

    void attack(Character* defender) {
        int damage = 40 + rand() % 20;
        cout << name << " casts a spell for " << damage << " damage!" << endl;
        defender->takeDamage(damage);
    }
};

// =====================
// Archer Class
// =====================
class Archer : public Character {
public:
    Archer(string name) : Character(name, 90) {}
    ~Archer() {}

    string getType() { return "Archer"; }

    void attack(Character* defender) {
        int damage = 30 + rand() % 15;
        bool crit = rand() % 2 == 0;
        if (crit) {
            damage *= 2;
            cout << name << " CRITICAL SHOT for " << damage << " damage!" << endl;
        } else {
            cout << name << " shoots for " << damage << " damage!" << endl;
        }
        defender->takeDamage(damage);
    }
};
