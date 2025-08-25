#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "Unit.h"
#include <string>

// 前向声明
class Hero;

/**
 * @brief 泉水类
 * 泉水可以恢复英雄的生命值和法力值
 */
class Fountain {
private:
    std::string name;       // 泉水名称
    int healAmount;         // 健康恢复量
    int manaAmount;         // 法力恢复量

public:
    /**
     * @brief 构造函数
     * @param name 泉水名称
     * @param healAmount 健康恢复量
     * @param manaAmount 法力恢复量
     */
    Fountain(const std::string& name, int healAmount, int manaAmount);

    /**
     * @brief 获取泉水名称
     * @return 泉水名称
     */
    std::string getName() const;

    /**
     * @brief 获取健康恢复量
     * @return 健康恢复量
     */
    int getHealAmount() const;

    /**
     * @brief 获取法力恢复量
     * @return 法力恢复量
     */
    int getManaAmount() const;

    /**
     * @brief 治疗英雄
     * @param hero 英雄指针
     */
    void healHero(Hero* hero);

    /**
     * @brief 显示泉水信息
     */
    void displayInfo() const;
};

#endif // FOUNTAIN_H