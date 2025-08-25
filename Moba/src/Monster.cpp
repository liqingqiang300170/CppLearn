#include "../include/Monster.h"
#include <iostream>
#include <string>

/**
 * @brief Constructor
 * @param name Monster name
 * @param type Monster type
 * @param health Health points
 * @param attack Attack power
 * @param defense Defense power
 * @param goldReward Gold reward for killing
 * @param expReward Experience reward for killing
 * @param isRespawnable Whether can respawn
 * @param respawnTime Respawn time
 */
Monster::Monster(const std::string& name, MonsterType type, int health, int attack, int defense,
                 int goldReward, int expReward, bool isRespawnable, int respawnTime)
    : Unit(name, health, attack, defense), type(type), goldReward(goldReward), expReward(expReward),
      isRespawnable(isRespawnable), respawnTime(respawnTime), respawnCounter(0) {
}

/**
 * @brief Get monster type
 * @return Monster type
 */
MonsterType Monster::getType() const {
    return type;
}

/**
 * @brief Get gold reward for killing
 * @return Gold reward
 */
int Monster::getGoldReward() const {
    return goldReward;
}

/**
 * @brief Get experience reward for killing
 * @return Experience reward
 */
int Monster::getExpReward() const {
    return expReward;
}

/**
 * @brief Check if can respawn
 * @return Whether can respawn
 */
bool Monster::getIsRespawnable() const {
    return isRespawnable;
}

/**
 * @brief Get respawn time
 * @return Respawn time
 */
int Monster::getRespawnTime() const {
    return respawnTime;
}

/**
 * @brief Check if can respawn
 * @return Whether can respawn
 */
bool Monster::canRespawn() const {
    return isRespawnable && !this->alive && respawnCounter <= 0;
}

/**
 * @brief Update monster status
 */
void Monster::update() {
    if (!this->alive && isRespawnable) {
        respawnCounter--;
        if (respawnCounter <= 0) {
            respawn();
        }
    }
}

/**
 * @brief Respawn monster
 */
void Monster::respawn() {
    this->alive = true;
    this->health = this->maxHealth;
    respawnCounter = respawnTime;
    std::cout << this->name << " has respawned!" << std::endl;
}

/**
 * @brief Attack target unit
 * @param target Target unit
 */
void Monster::attackTarget(Unit* target) {
    if (!this->alive || !target || !target->isAlive()) {
        return;
    }

    std::cout << this->name << " attacks " << target->getName() << " causing " << this->attack << " damage!" << std::endl;
    target->takeDamage(this->attack);
}

/**
 * @brief Display monster information
 */
void Monster::displayInfo() const {
    std::string typeStr;
    switch (type) {
        case MonsterType::NORMAL: 
            typeStr = "Normal Monster"; 
            break;
        case MonsterType::BOSS: 
            typeStr = "Boss Monster"; 
            break;
        case MonsterType::BUFF: 
            typeStr = "Buff Monster"; 
            break;
    }
    
    std::cout << "Monster: " << this->name << " | Type: " << typeStr
              << " | Health: " << this->health << "/" << this->maxHealth 
              << " | Attack: " << this->attack << " | Defense: " << this->defense << std::endl;
    
    if (!this->alive && isRespawnable) {
        std::cout << "Respawn countdown: " << respawnCounter << " rounds" << std::endl;
    }
}