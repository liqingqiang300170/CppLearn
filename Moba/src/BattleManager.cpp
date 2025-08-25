#include "../include/BattleManager.h"
#include "../include/Hero.h"
#include "../include/Tower.h"
#include "../include/Minion.h"
#include "../include/Monster.h"
#include "../include/Crystal.h"
#include "../include/Shop.h"
#include "../include/Fountain.h"
#include "../include/Skill.h"
#include <iostream>
#include <algorithm>
#include <memory>

/**
 * @brief Constructor
 */
BattleManager::BattleManager() : round(0), gameRunning(false) {
}

/**
 * @brief Initialize game
 */
void BattleManager::initializeGame() {
    std::cout << "Initializing Honor of Kings Battle Simulator..." << std::endl;
    
    // Create heroes
    auto hero1 = std::make_unique<Hero>("Lu Ban Qi Hao", HeroType::ARCHER, 1000, 500, 80, 20);
    auto skill1 = std::make_unique<AttackSkill>("Rocket Jump", 50, 3, 100, "Lu Ban Qi Hao's skill, causes physical damage to enemies");
    auto skill2 = std::make_unique<HealSkill>("Emergency Repair", 60, 5, 150, "Lu Ban Qi Hao's healing skill, restores health for self or teammates");
    hero1->addSkill(std::move(skill1));
    hero1->addSkill(std::move(skill2));
    addHero(std::move(hero1));
    
    auto hero2 = std::make_unique<Hero>("Da Ji", HeroType::MAGE, 800, 800, 100, 15);
    auto skill3 = std::make_unique<AttackSkill>("Soul Shock", 70, 2, 130, "Da Ji's skill, causes spell damage to enemies");
    auto skill4 = std::make_unique<HealSkill>("Healing Spell", 80, 4, 200, "Da Ji's healing skill, restores health for self or teammates");
    hero2->addSkill(std::move(skill3));
    hero2->addSkill(std::move(skill4));
    addHero(std::move(hero2));
    
    // Create towers
    auto tower1 = std::make_unique<Tower>("Outer Tower", TowerType::OUTER, 2000, 100, 700);
    addTower(std::move(tower1));
    
    auto tower2 = std::make_unique<Tower>("Inner Tower", TowerType::INNER, 3000, 150, 700);
    addTower(std::move(tower2));
    
    // Create minions
    auto minion1 = std::make_unique<Minion>("Melee Minion", MinionType::MELEE, 500, 40, 10, 100, 50);
    addMinion(std::move(minion1));
    
    auto minion2 = std::make_unique<Minion>("Ranged Minion", MinionType::RANGED, 300, 50, 5, 500, 60);
    addMinion(std::move(minion2));
    
    // Create monsters
    auto monster1 = std::make_unique<Monster>("Baron", MonsterType::BOSS, 5000, 200, 50, 500, 300, true, 10);
    addMonster(std::move(monster1));
    
    // Create crystals
    auto crystal1 = std::make_unique<Crystal>("Our Crystal", 10000, true, 1000);
    addCrystal(std::move(crystal1));
    
    // Create shop
    auto shop1 = std::make_unique<Shop>("King's Shop");
    
    // Add items
    auto item1 = std::make_unique<Item>("Breaking Military", 2000, "Increases attack power significantly", 200, 0, 100, 0);
    auto item2 = std::make_unique<Item>("Sage's Protection", 2500, "Increases defense and health", 300, 0, 0, 50);
    auto item3 = std::make_unique<Item>("Teleport Scroll", 100, "Quickly return to fountain", 0, 0, 0, 0);
    
    shop1->addItem(std::move(item1));
    shop1->addItem(std::move(item2));
    shop1->addItem(std::move(item3));
    
    addShop(std::move(shop1));
    
    // Create fountain
    auto fountain1 = std::make_unique<Fountain>("Our Fountain", 1000, 500);
    addFountain(std::move(fountain1));
    
    gameRunning = true;
    std::cout << "Game initialization complete!" << std::endl;
}

/**
 * @brief Start game
 */
void BattleManager::startGame() {
    std::cout << "Honor of Kings Battle Simulator Started!" << std::endl;
    
    while (gameRunning) {
        round++;
        std::cout << "\n======= Round " << round << " =======\n" << std::endl;
        
        // Update all unit statuses
        updateUnits();
        
        // Perform combat logic
        performCombat();
        
        // Check if game is over
        checkGameEnd();
        
        // Display current status
        displayStatus();
        
        // Pause for observation
        system("pause");
    }
}

/**
 * @brief Update all unit statuses
 */
void BattleManager::updateUnits() {
    // Update heroes
    for (auto& hero : heroes) {
        // Heroes automatically recover small amounts of health and mana each round
        hero->heal(20);
        hero->restoreMana(30);
        
        // Reduce skill cooldowns
        for (size_t i = 0; i < hero->getSkillCount(); ++i) {
            Skill* skill = hero->getSkill(i);
            if (skill) {
                skill->reduceCooldown();
            }
        }
    }
    
    // Update towers
    for (auto& tower : towers) {
        tower->update();
    }
    
    // Update minions
    for (auto& minion : minions) {
        minion->update();
    }
    
    // Update monsters
    for (auto& monster : monsters) {
        monster->update();
    }
    
    // Update crystals
    for (auto& crystal : crystals) {
        crystal->update();
    }
}

/**
 * @brief Perform combat logic
 */
void BattleManager::performCombat() {
    // Simplified combat logic: hero attacks monster
    if (!heroes.empty() && !monsters.empty()) {
        Hero* hero = heroes[0].get();
        Monster* monster = monsters[0].get();
        
        if (hero->isAlive() && monster->isAlive()) {
            hero->attackTarget(monster);
            
            if (monster->isAlive()) {
                monster->attackTarget(hero);
            }
        }
    }
    
    // Other combat logic can be added here...
}

/**
 * @brief Check if game is over
 */
void BattleManager::checkGameEnd() {
    // Simplified game end condition: round count exceeds 10 or hero dies
    if (round >= 10) {
        std::cout << "Game over! Maximum rounds reached." << std::endl;
        gameRunning = false;
    }
    
    if (!heroes.empty() && !heroes[0]->isAlive()) {
        std::cout << "Game over! Hero defeated." << std::endl;
        gameRunning = false;
    }
}

/**
 * @brief Display current status
 */
void BattleManager::displayStatus() {
    std::cout << "\n======= Current Status =======\n" << std::endl;
    
    // Display hero status
    for (const auto& hero : heroes) {
        hero->displayInfo();
    }
    
    // Display monster status
    for (const auto& monster : monsters) {
        monster->displayInfo();
    }
    
    // Display tower status
    for (const auto& tower : towers) {
        tower->displayInfo();
    }
}

/**
 * @brief Add hero
 * @param hero Hero pointer
 */
void BattleManager::addHero(std::unique_ptr<Hero> hero) {
    if (hero) {
        heroes.push_back(std::move(hero));
    }
}

/**
 * @brief Add tower
 * @param tower Tower pointer
 */
void BattleManager::addTower(std::unique_ptr<Tower> tower) {
    if (tower) {
        towers.push_back(std::move(tower));
    }
}

/**
 * @brief Add minion
 * @param minion Minion pointer
 */
void BattleManager::addMinion(std::unique_ptr<Minion> minion) {
    if (minion) {
        minions.push_back(std::move(minion));
    }
}

/**
 * @brief Add monster
 * @param monster Monster pointer
 */
void BattleManager::addMonster(std::unique_ptr<Monster> monster) {
    if (monster) {
        monsters.push_back(std::move(monster));
    }
}

/**
 * @brief Add crystal
 * @param crystal Crystal pointer
 */
void BattleManager::addCrystal(std::unique_ptr<Crystal> crystal) {
    if (crystal) {
        crystals.push_back(std::move(crystal));
    }
}

/**
 * @brief Add shop
 * @param shop Shop pointer
 */
void BattleManager::addShop(std::unique_ptr<Shop> shop) {
    if (shop) {
        shops.push_back(std::move(shop));
    }
}

/**
 * @brief Add fountain
 * @param fountain Fountain pointer
 */
void BattleManager::addFountain(std::unique_ptr<Fountain> fountain) {
    if (fountain) {
        fountains.push_back(std::move(fountain));
    }
}

/**
 * @brief Get hero
 * @param index Hero index
 * @return Hero pointer
 */
Hero* BattleManager::getHero(size_t index) const {
    if (index >= heroes.size()) {
        return nullptr;
    }
    return heroes[index].get();
}

/**
 * @brief Get unit count
 * @return Unit count
 */
size_t BattleManager::getUnitCount() const {
    return heroes.size() + towers.size() + minions.size() + monsters.size() + crystals.size();
}