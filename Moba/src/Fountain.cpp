#include "../include/Fountain.h"
#include "../include/Hero.h"
#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief 构造函数
 * @param name 泉水名称
 * @param healRate 生命值恢复速率
 * @param manaRate 法力值恢复速率
 * @param isEnemyAccessible 敌方是否可进入
 */
Fountain::Fountain(const std::string& name, int healAmount, int manaAmount)
    : name(name), healAmount(healAmount), manaAmount(manaAmount) {
}

/**
 * @brief 获取泉水名称
 * @return 泉水名称
 */
std::string Fountain::getName() const {
    return name;
}

/**
 * @brief 获取生命值恢复速率
 * @return 生命值恢复速率
 */
int Fountain::getHealAmount() const {
    return healAmount;
}

/**
 * @brief 获取法力值恢复速率
 * @return 法力值恢复速率
 */
int Fountain::getManaAmount() const {
    return manaAmount;
}


/**
 * @brief 英雄进入泉水
 * @param hero 英雄指针
 */
void Fountain::enter(Hero* hero) {
    if (!hero) {
        return;
    }
    
    std::cout << hero->getName() << " 进入了 " << this->name << std::endl;
}

/**
 * @brief 英雄离开泉水
 * @param hero 英雄指针
 */
void Fountain::leave(Hero* hero) {
    if (!hero) {
        return;
    }
    
    std::cout << hero->getName() << " 离开了 " << this->name << std::endl;
}

/**
 * @brief 恢复英雄状态
 * @param hero 英雄指针
 */
void Fountain::healHero(Hero* hero) {
    if (!hero || !hero->isAlive()) {
        return;
    }

    hero->heal(healAmount);
    hero->restoreMana(manaAmount);
    
    std::cout << "Hero " << hero->getName() << " has been healed at the fountain, recovering "
              << healAmount << " health and " << manaAmount << " mana!" << std::endl;
}

/**
 * @brief 显示泉水信息
 */
void Fountain::displayInfo() const {
    std::cout << "Fountain: " << name << " | Health Recovery: " << healAmount 
              << " | Mana Recovery: " << manaAmount << std::endl;
}