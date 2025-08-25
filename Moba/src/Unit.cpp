#include "../include/Unit.h"
#include <iostream>
#include <algorithm>

/**
 * @brief 构造函数
 * @param name 单位名称
 * @param health 生命值
 * @param attack 攻击力
 * @param defense 防御力
 */
Unit::Unit(const std::string& name, int health, int attack, int defense)
    : name(name), health(health), maxHealth(health), attack(attack), defense(defense), level(1), alive(true) {
}

/**
 * @brief 虚析构函数
 */
Unit::~Unit() {
}

/**
 * @brief 获取单位名称
 * @return 单位名称
 */
std::string Unit::getName() const {
    return name;
}

/**
 * @brief 获取当前生命值
 * @return 当前生命值
 */
int Unit::getHealth() const {
    return health;
}

/**
 * @brief 获取最大生命值
 * @return 最大生命值
 */
int Unit::getMaxHealth() const {
    return maxHealth;
}

/**
 * @brief 获取攻击力
 * @return 攻击力
 */
int Unit::getAttack() const {
    return attack;
}

/**
 * @brief 获取防御力
 * @return 防御力
 */
int Unit::getDefense() const {
    return defense;
}

/**
 * @brief 获取等级
 * @return 等级
 */
int Unit::getLevel() const {
    return level;
}

/**
 * @brief 检查单位是否存活
 * @return 是否存活
 */
bool Unit::isAlive() const {
    return alive;
}

/**
 * @brief 受到伤害
 * @param damage 伤害值
 */
void Unit::takeDamage(int damage) {
    int actualDamage = std::max(1, damage - this->defense);  // 至少造成1点伤害
    this->health -= actualDamage;
    
    if (this->health <= 0) {
        this->health = 0;
        this->alive = false;
    }
    
    std::cout << this->name << " 受到 " << actualDamage << " 点伤害!";
    if (!this->alive) {
        std::cout << " " << this->name << " 被击败了!";
    }
    std::cout << std::endl;
}

/**
 * @brief 恢复生命值
 * @param amount 恢复量
 */
void Unit::heal(int amount) {
    if (this->alive) {
        this->health = std::min(this->maxHealth, this->health + amount);
        std::cout << this->name << " 恢复了 " << amount << " 点生命值!" << std::endl;
    }
}

/**
 * @brief 攻击目标单位
 * @param target 目标单位
 */
void Unit::attackTarget(Unit* target) {
    if (!this->alive || !target || !target->isAlive()) {
        return;
    }
    
    std::cout << this->name << " 攻击 " << target->getName() << " 造成 " << this->attack << " 点伤害!" << std::endl;
    target->takeDamage(this->attack);
}

/**
 * @brief 单位升级
 */
void Unit::levelUp() {
    this->level++;
    this->maxHealth += 20;
    this->health = this->maxHealth;  // 升级时回满血
    this->attack += 5;
    this->defense += 2;
    
    std::cout << this->name << " 升级到 " << this->level << " 级!" << std::endl;
}

/**
 * @brief 显示单位信息
 */
void Unit::displayInfo() const {
    std::cout << "单位: " << this->name << " | 等级: " << this->level 
              << " | 生命值: " << this->health << "/" << this->maxHealth 
              << " | 攻击力: " << this->attack << " | 防御力: " << this->defense << std::endl;
}