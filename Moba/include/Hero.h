#ifndef HERO_H
#define HERO_H

#include "Unit.h"
#include <vector>
#include <string>
#include <memory>

// Forward declarations
class Skill;

/**
 * @brief Hero type enumeration
 */
enum class HeroType {
    TANK,       // Tank
    WARRIOR,    // Warrior
    ASSASSIN,   // Assassin
    ARCHER,     // Archer
    MAGE,       // Mage
    SUPPORT     // Support
};

/**
 * @brief Hero class, inherits from Unit class
 */
class Hero : public Unit {
private:
    HeroType type;                          // Hero type
    int mana;                               // Current mana
    int maxMana;                            // Maximum mana
    std::vector<std::unique_ptr<Skill>> skills;  // Skill list
    int experience;                         // Current experience
    int expToNextLevel;                     // Experience needed for next level

public:
    /**
     * @brief Constructor
     * @param name Hero name
     * @param type Hero type
     * @param health Health points
     * @param mana Mana points
     * @param attack Attack power
     * @param defense Defense power
     */
    Hero(const std::string& name, HeroType type, int health, int mana, int attack, int defense);

    /**
     * @brief Destructor
     */
    ~Hero() override;

    /**
     * @brief Get hero type
     * @return Hero type
     */
    HeroType getType() const;

    /**
     * @brief Get current mana
     * @return Current mana
     */
    int getMana() const;

    /**
     * @brief Get maximum mana
     * @return Maximum mana
     */
    int getMaxMana() const;

    /**
     * @brief Get skill count
     * @return Skill count
     */
    size_t getSkillCount() const;

    /**
     * @brief Add skill
     * @param skill Skill pointer
     */
    void addSkill(std::unique_ptr<Skill> skill);

    /**
     * @brief Use skill
     * @param skillIndex Skill index
     * @param target Target unit
     */
    void useSkill(size_t skillIndex, Unit* target);

    /**
     * @brief Get skill
     * @param index Skill index
     * @return Skill pointer
     */
    Skill* getSkill(size_t index) const;

    /**
     * @brief Gain experience
     * @param exp Experience points
     */
    void gainExperience(int exp);

    /**
     * @brief Consume mana
     * @param amount Consumption amount
     * @return Whether consumption succeeded
     */
    bool consumeMana(int amount);

    /**
     * @brief Restore mana
     * @param amount Restore amount
     */
    void restoreMana(int amount);

    /**
     * @brief Take damage (override parent method)
     * @param damage Damage value
     */
    void takeDamage(int damage) override;

    /**
     * @brief Attack target (override parent method)
     * @param target Target unit
     */
    void attackTarget(Unit* target) override;

    /**
     * @brief Level up unit (override parent method)
     */
    void levelUp() override;

    /**
     * @brief Display hero information (override parent method)
     */
    void displayInfo() const override;
};

#endif // HERO_H