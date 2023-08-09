#include <iostream>
#include <cstdlib>

std::string fields[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
bool availableFields[9] = {false};
std::string chosenPlayer;
std::string computer;
std::string activePlayer;
int decission;
void drawTiles();
void chooseAField();
void turn();
void nextPlayer();
bool checkWin();

int main() {

    system("clear");
    std::cout << "  XOX GAME" << "\n";
    std::cout << "************" << "\n";
    do {
        std::cout << "1) Player X" << "\n";
        std::cout << "2) Player O" << "\n";
        std::cout << "3) Exit game" << "\n";
        std::cout << "Choose a player: ";
        std::cin >> decission;

    } while (decission != 1 && decission != 2 && decission != 3);

    switch (decission) {

    case 1:
        chosenPlayer = "X";
        computer = "O";
        activePlayer = "X";
        system("clear");
        std::cout << " You chose player X\n";
        std::cout << "********************" << std::endl;
        break;
    
    case 2:
        chosenPlayer = "O";
        computer = "X";
        activePlayer = "O";
        system("clear");
        std::cout << " You chose player O\n";
        std::cout << "********************" << std::endl;
        break;
    
    case 3:
        return 0;
    
    default:
        break;
    }

    //first turn
    drawTiles();
    
    //it is impossible to win before fifth turn, so why wasting time to check the win?
    for (int i = 0; i < 4; i++) {
        turn();
        if (decission == 0) {
            return 0;  
        }
        
        if (checkWin()) {
            system("clear");
            std::cout << "  Player " << activePlayer << " won!" << std::endl;
            return 0;
        }
        
    }

    while (decission != 0) {

        turn();

        if (checkWin()) {
            system("clear");
            std::cout << "  Player " << activePlayer << " won!" << std::endl;
            return 0;
        }
    }

    
    

    return 0;
}

void drawTiles() {
    
    for (int i = 1; i <= 5; i++)
    {
        switch (i)
            {
            case 1:
                std::cout << "     " << fields[0] << " | " << fields[1] << " | " << fields[2] << "\n";
                break;
            case 2:
                std::cout << "     "  << "---------" << "\n";
                break;
            case 3:
                std::cout << "     "  << fields[3] << " | " << fields[4] << " | " << fields[5] << "\n";
                break;
            case 4:
                std::cout << "     "  << "---------" << "\n";
                break;
            case 5:
                std::cout << "     "  << fields[6] << " | " << fields[7] << " | " << fields[8] << "\n";
                break;
            
            default:
                break;
            }
        
    }
    
}

void chooseAField() {
    std::cout << "\n Available fields: ";

    // Display available fields
    bool first = true;
    for (int i = 0; i < 9; i++) {
        if (!availableFields[i]) {
            if (first) {
                std::cout << " " << (i + 1);
                first = false;
            } else {
                std::cout << ", " << (i + 1);
            }
        }
    }
    std::cout << "\n********************" << std::endl;

    // User input loop
    do {
        std::cout << " Type '0' to exit game. ";
        std::cout << " Choose a field: ";
        std::cin >> decission;

        // Validate input
        if (decission == 0) {
            return;
        } else if (decission >= 1 && decission <= 9 && !availableFields[decission - 1]) {
            fields[decission - 1] = chosenPlayer;
            availableFields[decission - 1] = true;
            break; // Valid input, exit loop
        } else {
            std::cout << "\n Invalid choice! Try again!";
        }

    } while (true);
}


void turn() {
    if (activePlayer == chosenPlayer){

        system("clear");
        drawTiles();
        chooseAField();

        if (checkWin()) {
            return;
        }

        nextPlayer();

    } else {
        do {
            int computers_decission = rand() % 9;
            if (availableFields[computers_decission] == 0)
            {
                fields[computers_decission] = computer;
                availableFields[computers_decission] = 1;
                
                if (checkWin())
                {
                    return;
                }
                
                nextPlayer();
                return;
            }
            
        } while (true);
        
    }
    

}

void nextPlayer() {

    activePlayer == chosenPlayer ? activePlayer = computer : activePlayer = chosenPlayer;

}

bool checkWin() {

    if (fields[0] == activePlayer && fields[1] == activePlayer && fields[2] == activePlayer) {
        return true;
    } else if (fields[3] == activePlayer && fields[4] == activePlayer && fields[5] == activePlayer) {
        return true;
    } else if (fields[6] == activePlayer && fields[7] == activePlayer && fields[8] == activePlayer) {
        return true;
    } else if (fields[0] == activePlayer && fields[3] == activePlayer && fields[6] == activePlayer) {
        return true;
    } else if (fields[1] == activePlayer && fields[4] == activePlayer && fields[7] == activePlayer) {
        return true;
    } else if (fields[2] == activePlayer && fields[5] == activePlayer && fields[8] == activePlayer) {
        return true;
    } else if (fields[0] == activePlayer && fields[4] == activePlayer && fields[8] == activePlayer) {
        return true;
    } else if (fields[2] == activePlayer && fields[4] == activePlayer && fields[6] == activePlayer) {
        return true;
    } else {
        return false;
    }
    
}