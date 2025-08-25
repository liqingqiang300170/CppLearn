#include "../include/Minion.h"
#include <iostream>
#include <string>

/**
 * @brief Constructor
 * @param name Minion name
 * @param type Minion type
 * @param health Health points
 * @param attack Attack power
 * @param defense Defense power
 * @param range Attack range
 * @param damage Damage value
 */
Minion::Minion(const std::string& name, MinionType type, int health, int attack, int defense, int range, int damage)
    : Unit(name, health, attack, defense), type(type), range(range), damage(damage), attackInterval(1), attackCounter(0) {
}

/**
 * @brief Get minion type
 * @return Minion type
 */
MinionType Minion::getType() const {
    return type;
}

/**
 * @brief Get attack range
 * @return Attack range
 */
int Minion::getRange() const {
    return range;
}

/**
 * @brief Check if can attack
 * @return Whether can attack
 */
bool Minion::canAttack() const {
    return attackCounter <= 0;
}

/**
 * @brief Attack target unit
 * @param target Target unit
 */
void Minion::attackTarget(Unit* target) {
    if (!this->alive || !target || !target->isAlive()) {
        return;
    }

    if (canAttack()) {
        std::cout << this->name << " attacks " << target->getName() << " causing " << this->attack << " damage!" << std::endl;
        target->takeDamage(this->attack);
        attackCounter = attackInterval;
    }
}

/**
 * @brief Update minion status
 */
void Minion::update() {
    if (attackCounter > 0) {
        attackCounter--;
    }
}

/**
 * @brief Display minion information
 */
void Minion::displayInfo() const {
    std::string typeStr;
    switch (type) {
        case MinionType::MELEE: 
            typeStr = "Melee Minion"; 
            break;
        case MinionType::RANGED: 
            typeStr = "Ranged Minion"; 
            break;
        case MinionType::SIEGE: 
            typeStr = "Siege Minion"; 
            break;
    }
    
    std::cout << "Minion: " << this->name << " | Type: " << typeStr
              << " | Health: " << this->health << "/" << this->maxHealth 
              << " | Attack: " << this->attack << " | Defense: " << this->defense
              << " | Range: " << range << std::endl;
}