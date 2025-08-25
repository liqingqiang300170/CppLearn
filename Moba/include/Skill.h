#ifndef SKILL_H
#define SKILL_H

#include <string>

// Forward declarations
class Unit;
class Hero;

/**
 * @brief Skill type enumeration
 */
enum class SkillType {
    ACTIVE,   // Active skill
    PASSIVE   // Passive skill
};

/**
 * @brief Base skill class
 */
class Skill {
protected:
    std::string name;       // Skill name
    SkillType type;         // Skill type
    int manaCost;           // Mana cost
    int cooldown;           // Cooldown time
    int currentCooldown;    // Current cooldown time
    std::string description; // Skill description

public:
    /**
     * @brief Constructor
     * @param name Skill name
     * @param type Skill type
     * @param manaCost Mana cost
     * @param cooldown Cooldown time
     * @param description Skill description
     */
    Skill(const std::string& name, SkillType type, int manaCost, int cooldown, const std::string& description);

    /**
     * @brief Virtual destructor
     */
    virtual ~Skill();

    /**
     * @brief Get skill name
     * @return Skill name
     */
    std::string getName() const;

    /**
     * @brief Get skill type
     * @return Skill type
     */
    SkillType getType() const;

    /**
     * @brief Get mana cost
     * @return Mana cost
     */
    int getManaCost() const;

    /**
     * @brief Get cooldown time
     * @return Cooldown time
     */
    int getCooldown() const;

    /**
     * @brief Get skill description
     * @return Skill description
     */
    std::string getDescription() const;

    /**
     * @brief Check if skill is on cooldown
     * @return Whether on cooldown
     */
    bool isOnCooldown() const;

    /**
     * @brief Reduce cooldown
     */
    void reduceCooldown();

    /**
     * @brief Reset cooldown
     */
    void resetCooldown();

    /**
     * @brief Use skill (pure virtual function)
     * @param caster Caster
     * @param target Target
     */
    virtual void use(Hero* caster, Unit* target) = 0;

    /**
     * @brief Display skill information
     */
    virtual void displayInfo() const;
};

/**
 * @brief Attack skill class
 */
class AttackSkill : public Skill {
private:
    int damage;     // Skill damage

public:
    /**
     * @brief Constructor
     * @param name Skill name
     * @param manaCost Mana cost
     * @param cooldown Cooldown time
     * @param damage Skill damage
     * @param description Skill description
     */
    AttackSkill(const std::string& name, int manaCost, int cooldown, int damage, const std::string& description);

    /**
     * @brief Use skill (override parent method)
     * @param caster Caster
     * @param target Target
     */
    void use(Hero* caster, Unit* target) override;
};

/**
 * @brief Heal skill class
 */
class HealSkill : public Skill {
private:
    int healAmount;     // Heal amount

public:
    /**
     * @brief Constructor
     * @param name Skill name
     * @param manaCost Mana cost
     * @param cooldown Cooldown time
     * @param healAmount Heal amount
     * @param description Skill description
     */
    HealSkill(const std::string& name, int manaCost, int cooldown, int healAmount, const std::string& description);

    /**
     * @brief Use skill (override parent method)
     * @param caster Caster
     * @param target Target
     */
    void use(Hero* caster, Unit* target) override;
};

/**
 * @brief Passive skill class
 */
class PassiveSkill : public Skill {
private:
    int statBonus;      // Stat bonus

public:
    /**
     * @brief Constructor
     * @param name Skill name
     * @param statBonus Stat bonus
     * @param description Skill description
     */
    PassiveSkill(const std::string& name, int statBonus, const std::string& description);

    /**
     * @brief Apply passive skill effect
     * @param hero Hero object
     */
    void applyEffect(Hero* hero);

    /**
     * @brief Use skill (override parent method)
     * @param caster Caster
     * @param target Target
     */
    void use(Hero* caster, Unit* target) override;
};

#endif // SKILL_H