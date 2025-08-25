#ifndef TOWER_H
#define TOWER_H

#include "Unit.h"
#include <string>

// Forward declarations

/**
 * @brief Defense tower type enumeration
 */
enum class TowerType {
    OUTER,      // Outer tower
    INNER,      // Inner tower
    BASE        // Base tower
};

/**
 * @brief Tower class, inherits from Unit class
 */
class Tower : public Unit {
private:
    TowerType type;         // Tower type
    int range;              // Attack range
    int attackInterval;     // Attack interval
    int attackCounter;      // Attack counter

public:
    /**
     * @brief Constructor
     * @param name Tower name
     * @param type Tower type
     * @param health Health points
     * @param attack Attack power
     * @param range Attack range
     */
    Tower(const std::string& name, TowerType type, int health, int attack, int range);

    /**
     * @brief Get tower type
     * @return Tower type
     */
    TowerType getType() const;

    /**
     * @brief Get attack range
     * @return Attack range
     */
    int getRange() const;

    /**
     * @brief Check if tower can attack
     * @return Whether tower can attack
     */
    bool canAttack() const;

    /**
     * @brief Attack target unit
     * @param target Target unit
     */
    void attackTarget(Unit* target) override;

    /**
     * @brief Update tower status
     */
    void update();

    /**
     * @brief Display tower information
     */
    void displayInfo() const override;
};

#endif // TOWER_H