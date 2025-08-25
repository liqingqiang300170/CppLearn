#ifndef UNIT_H
#define UNIT_H

#include <string>

/**
 * @brief Base unit class in the game, base class for all combat units
 */
class Unit {
protected:
    std::string name;           // Unit name
    int health;                 // Current health
    int maxHealth;              // Maximum health
    int attack;                 // Attack power
    int defense;                // Defense power
    int level;                  // Level
    bool alive;                 // Whether alive

public:
    /**
     * @brief Constructor
     * @param name Unit name
     * @param health Health points
     * @param attack Attack power
     * @param defense Defense power
     */
    Unit(const std::string& name, int health, int attack, int defense);

    /**
     * @brief Virtual destructor
     */
    virtual ~Unit();

    /**
     * @brief Get unit name
     * @return Unit name
     */
    std::string getName() const;

    /**
     * @brief Get current health
     * @return Current health
     */
    int getHealth() const;

    /**
     * @brief Get maximum health
     * @return Maximum health
     */
    int getMaxHealth() const;

    /**
     * @brief Get attack power
     * @return Attack power
     */
    int getAttack() const;

    /**
     * @brief Get defense power
     * @return Defense power
     */
    int getDefense() const;

    /**
     * @brief Get level
     * @return Level
     */
    int getLevel() const;

    /**
     * @brief Check if unit is alive
     * @return Whether alive
     */
    bool isAlive() const;

    /**
     * @brief Take damage
     * @param damage Damage value
     */
    virtual void takeDamage(int damage);

    /**
     * @brief Heal health
     * @param amount Heal amount
     */
    virtual void heal(int amount);

    /**
     * @brief Attack target unit
     * @param target Target unit
     */
    virtual void attackTarget(Unit* target);

    /**
     * @brief Level up unit
     */
    virtual void levelUp();

    /**
     * @brief Display unit information
     */
    virtual void displayInfo() const;
};

#endif // UNIT_H