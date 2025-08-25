#include "../include/Shop.h"
#include "../include/Hero.h"
#include <iostream>
#include <iomanip>

/**
 * @brief Constructor
 */
Item::Item(const std::string& name, int price, const std::string& description,
           int healthBonus, int manaBonus, int attackBonus, int defenseBonus)
    : name(name), price(price), description(description), healthBonus(healthBonus),
      manaBonus(manaBonus), attackBonus(attackBonus), defenseBonus(defenseBonus) {
}

/**
 * @brief Constructor
 * @param name Shop name
 */
Shop::Shop(const std::string& name) : name(name) {
}

/**
 * @brief Destructor
 */
Shop::~Shop() {
}

/**
 * @brief Add item
 * @param item Item pointer
 */
void Shop::addItem(std::unique_ptr<Item> item) {
    if (item) {
        items.push_back(std::move(item));
    }
}

/**
 * @brief Display item list
 */
void Shop::displayItems() const {
    std::cout << "======= " << this->name << " Item List =======\n";
    for (size_t i = 0; i < items.size(); ++i) {
        const Item* item = items[i].get();
        std::cout << std::setw(2) << i + 1 << ". " << item->name 
                  << " - Price: " << item->price << " gold\n";
        std::cout << "    Description: " << item->description << "\n";
        
        if (item->healthBonus > 0) 
            std::cout << "    Health+" << item->healthBonus;
        if (item->manaBonus > 0) 
            std::cout << "    Mana+" << item->manaBonus;
        if (item->attackBonus > 0) 
            std::cout << "    Attack+" << item->attackBonus;
        if (item->defenseBonus > 0) 
            std::cout << "    Defense+" << item->defenseBonus;
        std::cout << "\n\n";
    }
}

/**
 * @brief Buy item
 * @param hero Hero
 * @param itemIndex Item index
 */
void Shop::buyItem(Hero* hero, size_t itemIndex) {
    // Note: Here we simplified the gold system, in actual projects there should be a gold management system
    if (itemIndex >= items.size()) {
        std::cout << "Invalid item index!" << std::endl;
        return;
    }

    Item* item = items[itemIndex].get();
    std::cout << hero->getName() << " bought " << item->name << std::endl;
    
    // Apply stat bonuses (simplified handling, actual projects should have an equipment system)
    std::cout << "Gained stat bonuses: ";
    if (item->healthBonus > 0) std::cout << "Health+" << item->healthBonus << " ";
    if (item->manaBonus > 0) std::cout << "Mana+" << item->manaBonus << " ";
    if (item->attackBonus > 0) std::cout << "Attack+" << item->attackBonus << " ";
    if (item->defenseBonus > 0) std::cout << "Defense+" << item->defenseBonus << " ";
    std::cout << std::endl;
}

/**
 * @brief Get item count
 * @return Item count
 */
size_t Shop::getItemCount() const {
    return items.size();
}

/**
 * @brief Get item
 * @param index Item index
 * @return Item pointer
 */
Item* Shop::getItem(size_t index) const {
    if (index >= items.size()) {
        return nullptr;
    }
    return items[index].get();
}