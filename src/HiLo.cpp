#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>

constexpr int Lives{7};
constexpr int GuessRange[2]{1,100};

bool playGame(int number){
 
    for (int i{1} ; i <= Lives ; i++){
        
        //ask user for guess
        std::cout << "Guess #"<< i << ": ";
        int user_guess{};
        std::cin >> user_guess;

        //compare guess to hidden number:
        if (user_guess > number){
            std::cout << "Too high!, guess again \n";
        } else if (user_guess < number){
            std::cout << "Too Low!, guess again \n";
        } else {
            std::cout << "Correct! You Win! \n";
            return true;
        } 
    }
    //user lost
    std::cout << "Sorry you lose!. The correct answer was: " << number << '\n';
    return false;

}

//filter and check the input for restarting the game
bool checkInput(std::string_view string){
    if (string.length() == 1){
        return (string == "y") | (string == "n") ? true:false;
    }
    return false;

}   

int main(){

    //set player statuses:
    bool playerWin {false}; //not really needed in this implementation but could be useful in the future
    std::string playAgain {"y"};

    while (playAgain == "y"){

        //system choose random number and display starting message;
        int hidden_num{RANDOM::in_range(GuessRange[0],GuessRange[1])};
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is. \n";

        //play the game
        playerWin = playGame(hidden_num);

        //ask if the user wants to play again - otherwise quit
        while (true){
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> playAgain;
        
            //check if user input is valid - if not ask again:
            if (checkInput(playAgain)){
                break;
            }
        }
    }

    std::cout << "Thank you for playing!, see you next time";
    return 0;
}
