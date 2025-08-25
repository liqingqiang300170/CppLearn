#ifndef MONSTER_H
#define MONSTER_H

#include "Unit.h"
#include <string>

// Forward declarations

/**
 * @brief Monster type enumeration
 */
enum class MonsterType {
    NORMAL,     // Normal monster
    BOSS,       // Boss monster (Dragon/Baron)
    BUFF        // Buff monster (Red/Blue Buff)
};

/**
 * @brief Monster class, inherits from Unit class
 */
class Monster : public Unit {
private:
    MonsterType type;           // Monster type
    int goldReward;             // Gold reward for killing
    int expReward;              // Experience reward for killing
    bool isRespawnable;         // Whether can respawn
    int respawnTime;            // Respawn time
    int respawnCounter;         // Respawn counter

public:
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
    Monster(const std::string& name, MonsterType type, int health, int attack, int defense, 
            int goldReward, int expReward, bool isRespawnable, int respawnTime);

    /**
     * @brief Get monster type
     * @return Monster type
     */
    MonsterType getType() const;

    /**
     * @brief Get gold reward for killing
     * @return Gold reward
     */
    int getGoldReward() const;

    /**
     * @brief Get experience reward for killing
     * @return Experience reward
     */
    int getExpReward() const;

    /**
     * @brief Check if can respawn
     * @return Whether can respawn
     */
    bool getIsRespawnable() const;

    /**
     * @brief Get respawn time
     * @return Respawn time
     */
    int getRespawnTime() const;

    /**
     * @brief Check if can respawn
     * @return Whether can respawn
     */
    bool canRespawn() const;

    /**
     * @brief Update monster status
     */
    void update();

    /**
     * @brief Respawn monster
     */
    void respawn();

    /**
     * @brief Attack target unit
     * @param target Target unit
     */
    void attackTarget(Unit* target) override;

    /**
     * @brief Display monster information
     */
    void displayInfo() const override;
};

#endif // MONSTER_H