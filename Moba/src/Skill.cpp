#include "../include/Skill.h"
#include "../include/Hero.h"
#include <iostream>

/**
 * @brief 构造函数
 * @param name 技能名称
 * @param type 技能类型
 * @param manaCost 消耗法力值
 * @param cooldown 冷却时间
 * @param description 技能描述
 */
Skill::Skill(const std::string& name, SkillType type, int manaCost, int cooldown, const std::string& description)
    : name(name), type(type), manaCost(manaCost), cooldown(cooldown), currentCooldown(0), description(description) {
}

/**
 * @brief 虚析构函数
 */
Skill::~Skill() {
}

/**
 * @brief 获取技能名称
 * @return 技能名称
 */
std::string Skill::getName() const {
    return name;
}

/**
 * @brief 获取技能类型
 * @return 技能类型
 */
SkillType Skill::getType() const {
    return type;
}

/**
 * @brief 获取消耗法力值
 * @return 消耗法力值
 */
int Skill::getManaCost() const {
    return manaCost;
}

/**
 * @brief 获取冷却时间
 * @return 冷却时间
 */
int Skill::getCooldown() const {
    return cooldown;
}

/**
 * @brief 获取技能描述
 * @return 技能描述
 */
std::string Skill::getDescription() const {
    return description;
}

/**
 * @brief 检查技能是否在冷却中
 * @return 是否在冷却中
 */
bool Skill::isOnCooldown() const {
    return currentCooldown > 0;
}

/**
 * @brief 减少冷却时间
 */
void Skill::reduceCooldown() {
    if (currentCooldown > 0) {
        currentCooldown--;
    }
}

/**
 * @brief 重置冷却时间
 */
void Skill::resetCooldown() {
    currentCooldown = cooldown;
}

/**
 * @brief 显示技能信息
 */
void Skill::displayInfo() const {
    std::cout << "技能: " << name << " | 类型: " << (type == SkillType::ACTIVE ? "主动" : "被动")
              << " | 消耗: " << manaCost << " 法力 | 冷却: " << cooldown << " 回合 | 描述: " << description << std::endl;
}

/**
 * @brief 构造函数
 * @param name 技能名称
 * @param manaCost 消耗法力值
 * @param cooldown 冷却时间
 * @param damage 技能伤害
 * @param description 技能描述
 */
AttackSkill::AttackSkill(const std::string& name, int manaCost, int cooldown, int damage, const std::string& description)
    : Skill(name, SkillType::ACTIVE, manaCost, cooldown, description), damage(damage) {
}

/**
 * @brief 使用技能（重写父类方法）
 * @param caster 施法者
 * @param target 目标
 */
void AttackSkill::use(Hero* caster, Unit* target) {
    if (!caster || !target || !target->isAlive()) {
        return;
    }

    if (isOnCooldown()) {
        std::cout << "技能 " << name << " 正在冷却中!" << std::endl;
        return;
    }

    if (!caster->consumeMana(manaCost)) {
        std::cout << caster->getName() << " 法力值不足!" << std::endl;
        return;
    }

    std::cout << caster->getName() << " 使用技能 " << name << " 对 " << target->getName() 
              << " 造成 " << damage << " 点伤害!" << std::endl;
    
    target->takeDamage(damage);
    resetCooldown();
}

/**
 * @brief 构造函数
 * @param name 技能名称
 * @param manaCost 消耗法力值
 * @param cooldown 冷却时间
 * @param healAmount 治疗量
 * @param description 技能描述
 */
HealSkill::HealSkill(const std::string& name, int manaCost, int cooldown, int healAmount, const std::string& description)
    : Skill(name, SkillType::ACTIVE, manaCost, cooldown, description), healAmount(healAmount) {
}

/**
 * @brief 使用技能（重写父类方法）
 * @param caster 施法者
 * @param target 目标
 */
void HealSkill::use(Hero* caster, Unit* target) {
    if (!caster || !target) {
        return;
    }

    if (isOnCooldown()) {
        std::cout << "技能 " << name << " 正在冷却中!" << std::endl;
        return;
    }

    if (!caster->consumeMana(manaCost)) {
        std::cout << caster->getName() << " 法力值不足!" << std::endl;
        return;
    }

    std::cout << caster->getName() << " 使用技能 " << name << " 为 " << target->getName() 
              << " 恢复 " << healAmount << " 点生命值!" << std::endl;
    
    target->heal(healAmount);
    resetCooldown();
}

/**
 * @brief 构造函数
 * @param name 技能名称
 * @param statBonus 属性加成
 * @param description 技能描述
 */
PassiveSkill::PassiveSkill(const std::string& name, int statBonus, const std::string& description)
    : Skill(name, SkillType::PASSIVE, 0, 0, description), statBonus(statBonus) {
}

/**
 * @brief 应用被动技能效果
 * @param hero 英雄对象
 */
void PassiveSkill::applyEffect(Hero* hero) {
    if (!hero) {
        return;
    }
    
    // 这里只是一个示例，实际可以根据需要修改英雄属性
    std::cout << hero->getName() << " 的被动技能 " << name << " 生效，获得 " << statBonus << " 点属性加成!" << std::endl;
}

/**
 * @brief 使用技能（重写父类方法）
 * @param caster 施法者
 * @param target 目标
 */
void PassiveSkill::use(Hero* caster, Unit* target) {
    // 被动技能不需要主动使用
    // 这里可以移除或者保留基类的实现
    Skill::use(caster, target);
}