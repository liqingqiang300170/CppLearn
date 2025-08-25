#ifndef CRYSTAL_H
#define CRYSTAL_H

#include "Unit.h"
#include <string>

/**
 * @brief Crystal class, inherits from Unit class
 */
class Crystal : public Unit {
private:
    bool canAttack;     // Whether can attack
    int attackPower;    // Attack power

public:
    /**
     * @brief Constructor
     * @param name Crystal name
     * @param health Health points
     * @param canAttack Whether can attack
     * @param attackPower Attack power
     */
    Crystal(const std::string& name, int health, bool canAttack, int attackPower);

    /**
     * @brief Check if can attack
     * @return Whether can attack
     */
    bool getCanAttack() const;

    /**
     * @brief Get attack power
     * @return Attack power
     */
    int getAttackPower() const;

    /**
     * @brief Attack target unit
     * @param target Target unit
     */
    void attackTarget(Unit* target) override;

    /**
     * @brief Update crystal status
     */
    void update();

    /**
     * @brief Display crystal information
     */
    void displayInfo() const override;
};

#endif // CRYSTAL_H