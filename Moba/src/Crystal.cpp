#include "../include/Crystal.h"
#include <iostream>
#include <string>

/**
 * @brief Constructor
 * @param name Crystal name
 * @param health Health points
 * @param canAttack Whether can attack
 * @param attackPower Attack power
 */
Crystal::Crystal(const std::string& name, int health, bool canAttack, int attackPower)
    : Unit(name, health, canAttack ? attackPower : 0, 0), canAttack(canAttack), attackPower(attackPower) {
}

/**
 * @brief Check if can attack
 * @return Whether can attack
 */
bool Crystal::getCanAttack() const {
    return canAttack;
}

/**
 * @brief Get attack power
 * @return Attack power
 */
int Crystal::getAttackPower() const {
    return attackPower;
}

/**
 * @brief Attack target unit
 * @param target Target unit
 */
void Crystal::attackTarget(Unit* target) {
    if (!this->alive || !canAttack || !target || !target->isAlive()) {
        return;
    }

    std::cout << this->name << " attacks " << target->getName() << " causing " << this->attack << " damage!" << std::endl;
    target->takeDamage(this->attack);
}

/**
 * @brief Update crystal status
 */
void Crystal::update() {
    // Crystals do not need to update status in this implementation
}

/**
 * @brief Display crystal information
 */
void Crystal::displayInfo() const {
    std::cout << "Crystal: " << this->name << " | Health: " << this->health << "/" << this->maxHealth;
    if (canAttack) {
        std::cout << " | Attack Power: " << attackPower;
    } else {
        std::cout << " | Non-Combat";
    }
    std::cout << std::endl;
}