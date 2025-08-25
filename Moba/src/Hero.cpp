#include "../include/Hero.h"
#include "../include/Skill.h"
#include <iostream>
#include <algorithm>

/**
 * @brief 构造函数
 * @param name 英雄名称
 * @param type 英雄类型
 * @param health 生命值
 * @param mana 法力值
 * @param attack 攻击力
 * @param defense 防御力
 */
Hero::Hero(const std::string& name, HeroType type, int health, int mana, int attack, int defense)
    : Unit(name, health, attack, defense), type(type), mana(mana), maxMana(mana), experience(0), expToNextLevel(100) {
}

/**
 * @brief 析构函数
 */
Hero::~Hero() {
}

/**
 * @brief 获取英雄类型
 * @return 英雄类型
 */
HeroType Hero::getType() const {
    return type;
}

/**
 * @brief 获取当前法力值
 * @return 当前法力值
 */
int Hero::getMana() const {
    return mana;
}

/**
 * @brief 获取最大法力值
 * @return 最大法力值
 */
int Hero::getMaxMana() const {
    return maxMana;
}

/**
 * @brief 获取技能数量
 * @return 技能数量
 */
size_t Hero::getSkillCount() const {
    return skills.size();
}

/**
 * @brief 添加技能
 * @param skill 技能指针
 */
void Hero::addSkill(std::unique_ptr<Skill> skill) {
    if (skill) {
        skills.push_back(std::move(skill));
    }
}

/**
 * @brief 使用技能
 * @param skillIndex 技能索引
 * @param target 目标单位
 */
void Hero::useSkill(size_t skillIndex, Unit* target) {
    if (skillIndex >= skills.size()) {
        std::cout << this->name << " does not have a skill at index " << skillIndex << std::endl;
        return;
    }

    skills[skillIndex]->use(this, target);
}

/**
 * @brief 获取技能
 * @param index 技能索引
 * @return 技能指针
 */
Skill* Hero::getSkill(size_t index) const {
    if (index >= skills.size()) {
        return nullptr;
    }
    return skills[index].get();
}

/**
 * @brief 获得经验值
 * @param exp 经验值
 */
void Hero::gainExperience(int exp) {
    experience += exp;
    std::cout << name << " 获得了 " << exp << " 点经验值!" << std::endl;

    // 检查是否升级
    while (experience >= expToNextLevel) {
        experience -= expToNextLevel;
        levelUp();
        expToNextLevel = static_cast<int>(expToNextLevel * 1.5); // 增加经验需求并转换为整数
    }
}

/**
 * @brief 消耗法力值
 * @param amount 消耗量
 * @return 是否消耗成功
 */
bool Hero::consumeMana(int amount) {
    if (mana >= amount) {
        mana -= amount;
        return true;
    }
    return false;
}

/**
 * @brief 恢复法力值
 * @param amount 恢复量
 */
void Hero::restoreMana(int amount) {
    mana = std::min(maxMana, mana + amount);
    std::cout << name << " 恢复了 " << amount << " 点法力值!" << std::endl;
}

/**
 * @brief 受到伤害（重写父类方法）
 * @param damage 伤害值
 */
void Hero::takeDamage(int damage) {
    Unit::takeDamage(damage);
}

/**
 * @brief 攻击目标（重写父类方法）
 * @param target 目标单位
 */
void Hero::attackTarget(Unit* target) {
    if (!this->alive || !target || !target->isAlive()) {
        return;
    }

    std::cout << this->name << " attacks " << target->getName() << " causing " << this->attack << " damage!" << std::endl;
    target->takeDamage(this->attack);
}

/**
 * @brief 单位升级（重写父类方法）
 */
void Hero::levelUp() {
    this->level++;
    this->maxHealth += 20;
    this->health = this->maxHealth;  // Full heal on level up
    this->attack += 5;
    this->defense += 2;
    this->maxMana += 10;
    this->mana = this->maxMana;      // Restore mana on level up

    std::cout << this->name << " leveled up to level " << this->level << "!" << std::endl;
}

/**
 * @brief 显示英雄信息（重写父类方法）
 */
void Hero::displayInfo() const {
    std::string typeStr;
    switch (type) {
        case HeroType::TANK: typeStr = "Tank"; break;
        case HeroType::WARRIOR: typeStr = "Warrior"; break;
        case HeroType::ASSASSIN: typeStr = "Assassin"; break;
        case HeroType::ARCHER: typeStr = "Archer"; break;
        case HeroType::MAGE: typeStr = "Mage"; break;
        case HeroType::SUPPORT: typeStr = "Support"; break;
    }

    std::cout << "Hero: " << this->name << " | Type: " << typeStr << " | Level: " << this->level
              << " | Health: " << this->health << "/" << this->maxHealth
              << " | Mana: " << this->mana << "/" << this->maxMana
              << " | Attack: " << this->attack << " | Defense: " << this->defense << std::endl;
}