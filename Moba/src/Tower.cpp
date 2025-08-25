#include "../include/Tower.h"
#include <iostream>
#include <string>

/**
 * @brief Constructor
 * @param name Tower name
 * @param type Tower type
 * @param health Health points
 * @param attack Attack power
 * @param range Attack range
 */
Tower::Tower(const std::string& name, TowerType type, int health, int attack, int range)
    : Unit(name, health, attack, 0), type(type), range(range), attackInterval(1), attackCounter(0) {
    // Set tower defense to 0 because of the tower skin mechanism
    this->defense = 0;
}

/**
 * @brief Get tower type
 * @return Tower type
 */
TowerType Tower::getType() const {
    return type;
}

/**
 * @brief Get attack range
 * @return Attack range
 */
int Tower::getRange() const {
    return range;
}

/**
 * @brief Check if tower can attack
 * @return Whether tower can attack
 */
bool Tower::canAttack() const {
    return attackCounter <= 0;
}

/**
 * @brief Attack target unit
 * @param target Target unit
 */
void Tower::attackTarget(Unit* target) {
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
 * @brief Update tower status
 */
void Tower::update() {
    if (attackCounter > 0) {
        attackCounter--;
    }
}

/**
 * @brief Display tower information
 */
void Tower::displayInfo() const {
    std::string typeStr;
    switch (type) {
        case TowerType::OUTER: 
            typeStr = "Outer Tower"; 
            break;
        case TowerType::INNER: 
            typeStr = "Inner Tower"; 
            break;
        case TowerType::BASE: 
            typeStr = "Base Tower"; 
            break;
    }
    
    std::cout << "Tower: " << this->name << " | Type: " << typeStr
              << " | Health: " << this->health << "/" << this->maxHealth 
              << " | Attack: " << this->attack << " | Range: " << range << std::endl;
}