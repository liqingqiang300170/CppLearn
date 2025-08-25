#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <vector>
#include <memory>

// Forward declarations
class Hero;

/**
 * @brief Item structure
 */
struct Item {
    std::string name;       // Item name
    int price;              // Price
    std::string description; // Description
    int healthBonus;        // Health bonus
    int manaBonus;          // Mana bonus
    int attackBonus;        // Attack bonus
    int defenseBonus;       // Defense bonus
    
    /**
     * @brief Constructor
     */
    Item(const std::string& name, int price, const std::string& description,
         int healthBonus = 0, int manaBonus = 0, int attackBonus = 0, int defenseBonus = 0);
};

/**
 * @brief Shop class
 */
class Shop {
private:
    std::string name;                           // Shop name
    std::vector<std::unique_ptr<Item>> items;   // Item list

public:
    /**
     * @brief Constructor
     * @param name Shop name
     */
    Shop(const std::string& name);

    /**
     * @brief Destructor
     */
    ~Shop();

    /**
     * @brief Add item
     * @param item Item pointer
     */
    void addItem(std::unique_ptr<Item> item);

    /**
     * @brief Display item list
     */
    void displayItems() const;

    /**
     * @brief Buy item
     * @param hero Hero
     * @param itemIndex Item index
     */
    void buyItem(Hero* hero, size_t itemIndex);

    /**
     * @brief Get item count
     * @return Item count
     */
    size_t getItemCount() const;

    /**
     * @brief Get item
     * @param index Item index
     * @return Item pointer
     */
    Item* getItem(size_t index) const;
};

#endif // SHOP_H