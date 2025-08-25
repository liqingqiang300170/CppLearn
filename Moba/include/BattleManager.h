#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

// Forward declarations
class Hero;
class Tower;
class Minion;
class Monster;
class Crystal;
class Shop;
class Fountain;
#include <vector>
#include <memory>
#include <string>

// 前向声明

/**
 * @brief 战斗管理器类
 * 管理整个战斗流程
 */
class BattleManager {
private:
    std::vector<std::unique_ptr<Hero>> heroes;          // Hero list
    std::vector<std::unique_ptr<Tower>> towers;         // Tower list
    std::vector<std::unique_ptr<Minion>> minions;       // Minion list
    std::vector<std::unique_ptr<Monster>> monsters;     // Monster list
    std::vector<std::unique_ptr<Crystal>> crystals;     // Crystal list
    std::vector<std::unique_ptr<Shop>> shops;           // Shop list
    std::vector<std::unique_ptr<Fountain>> fountains;   // Fountain list
    int round;                                          // Current round
    bool gameRunning;                                   // Game running status

public:
    /**
     * @brief 构造函数
     */
    BattleManager();

    /**
     * @brief 析构函数
     */
    ~BattleManager();

    /**
     * @brief 初始化游戏
     */
    void initializeGame();

    /**
     * @brief 添加英雄
     * @param hero 英雄指针
     */
    void addHero(std::unique_ptr<class Hero> hero);

    /**
     * @brief 添加防御塔
     * @param tower 防御塔指针
     */
    void addTower(std::unique_ptr<class Tower> tower);

    /**
     * @brief 添加小兵
     * @param minion 小兵指针
     */
    void addMinion(std::unique_ptr<class Minion> minion);

    /**
     * @brief 添加野怪
     * @param monster 野怪指针
     */
    void addMonster(std::unique_ptr<class Monster> monster);

    /**
     * @brief 添加水晶
     * @param crystal 水晶指针
     */
    void addCrystal(std::unique_ptr<class Crystal> crystal);

    /**
     * @brief 设置商店
     * @param shop 商店指针
     */
    void addShop(std::unique_ptr<Shop> shop);

    /**
     * @brief 设置泉水
     * @param fountain 泉水指针
     */
    void addFountain(std::unique_ptr<Fountain> fountain);

    /**
     * @brief 开始游戏循环
     */
    void startGame();

    /**
     * @brief 处理回合
     */
    void updateUnits();
    void performCombat();
    void checkGameEnd();

    /**
     * @brief 显示游戏状态
     */
    void displayStatus();

    /**
     * @brief 检查游戏是否结束
     * @return 游戏是否结束
     */
    bool isGameOver() const;

    /**
     * @brief 获取英雄
     * @param index 索引
     * @return 英雄指针
     */
    class Hero* getHero(size_t index) const;

    /**
     * @brief 获取单位总数
     * @return 单位总数
     */
    size_t getUnitCount() const;
};

#endif // BATTLE_MANAGER_H