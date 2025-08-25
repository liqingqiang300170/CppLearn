#ifndef MINION_H
#define MINION_H

#include "Unit.h"
#include <string>

/**
 * @brief Minion type enumeration
 */
enum class MinionType {
    MELEE,      // Melee minion
    RANGED,     // Ranged minion
    SIEGE       // Siege minion
};

/**
 * @brief Minion class, inherits from Unit class
 */
class Minion : public Unit {
private:
    MinionType type;        // Minion type
    int range;              // Attack range
    int damage;             // Damage value
    int attackInterval;     // Attack interval
    int attackCounter;      // Attack counter

public:
    /**
     * @brief Constructor
     * @param name Minion name
     * @param type Minion type
     * @param health Health points
     * @param attack Attack power
     * @param defense Defense power
     * @param range Attack range
     * @param damage Damage value
     */
    Minion(const std::string& name, MinionType type, int health, int attack, int defense, int range, int damage);

    /**
     * @brief Get minion type
     * @return Minion type
     */
    MinionType getType() const;

    /**
     * @brief Get attack range
     * @return Attack range
     */
    int getRange() const;

    /**
     * @brief Check if can attack
     * @return Whether can attack
     */
    bool canAttack() const;

    /**
     * @brief Attack target unit
     * @param target Target unit
     */
    void attackTarget(Unit* target) override;

    /**
     * @brief Update minion status
     */
    void update();

    /**
     * @brief Display minion information
     */
    void displayInfo() const override;
};

#endif // MINION_H