#include "../include/BattleManager.h"
#include <iostream>
#include <memory>

/**
 * @brief Main function
 * @param argc Argument count
 * @param argv Argument values
 * @return Exit code
 */
int main(int argc, char* argv[]) {
    std::cout << "Welcome to Honor of Kings Battle Simulator!" << std::endl;
    
    // Create battle manager
    auto battleManager = std::make_unique<BattleManager>();
    
    // Initialize game
    battleManager->initializeGame();
    
    // Start battle
    battleManager->startGame();
    
    std::cout << "Thank you for playing Honor of Kings Battle Simulator!" << std::endl;
    
    return 0;
}