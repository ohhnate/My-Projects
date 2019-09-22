//Samuel Fuller
//Sep 3rd 2019
//Rock Paper Scissors game allows user to pick RCP and computer randomly
//pick a response

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
  #include <windows.h>
#endif

using namespace std;

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int player(string choiceString, int choiceInt) {
  if (choiceString == "rock") {
    choiceInt = 1;
  } else if (choiceString == "paper") {
    choiceInt = 2;
  } else if (choiceString == "scissors") {
    choiceInt = 3;
  }
  return choiceInt;
}

int computer () {
  int compChoice = (rand() % 3) + 1;
  return compChoice;
}

void results (int compChoice, int playerChoice) {
  if (playerChoice == 1) {
    if (compChoice == 1) {
      cout << "You choose rock. The computer also chooses rock. It's a draw try again.\n";
    } else if (compChoice == 2) {
      cout << "You choose rock. The computer chooses paper. You lose! Try again.\n";
    } else if (compChoice == 3) {
      cout << "You choose rock. The computer chooses scissors. You win! Play again!\n";
    }
  } else if (playerChoice == 2) {
      if (compChoice == 1) {
        cout << "You choose paper. The computer chooses rock. You win! Play again!\n";
      } else if (compChoice == 2) {
        cout << "You choose paper. The computer also chooses paper. It's a draw try again.\n";
      } else if (compChoice == 3) {
        cout << "You choose paper. The computer chooses scissors. You lose! Try again.\n";
      }
  } else if (playerChoice == 3) {
      if (compChoice == 1) {
        cout << "You choose scissors. The computer chooses rock. You lose! Try again.\n";
      } else if (compChoice == 2) {
        cout << "You choose scissors. The computer chooses paper. You win! Play again!\n";
      } else if (compChoice ==3) {
        cout << "You choose scissors. The computer also chooses scissors. It's a draw try again.\n";
      }
    }
  }

void fancydelay (string delay) {
#ifdef _WIN32
    cout << delay;
    Sleep(500);
    cout << delay;
    Sleep(500);
    cout << delay;
    Sleep(500);
#endif
}

void banner () {

  cout << "______      _____ _                    ______ \n";
  cout << "| ___ \\    /  ___| |                   | ___ \\ \n";
  cout << "| |_/ /___ \\ `--.| |__   __ _ _ __ ___ | |_/ / ___\n";
  cout << "|    // _ \\ `--. \\ '_ \\ / _` | '_ ` _ \\| ___ \\/ _ \\\n";
  cout << "| |\\ \\ (_) /\\__/ / | | | (_| | | | | | | |_/ / (_) |\n";
  cout << "\\_| \\_\\___/\\____/|_| |_|\\__,_|_| |_| |_\\____/ \\___/ \n";

}

int main() {
  srand(time(0));

  string game = "running";
  while (game == "running") {
    system("CLS");
    banner();
    int choiceInt = 0;
    string choiceString;
    cout << "\nType rock, paper, or scissors: ";
    cin >> choiceString;
    int playerChoice = player(choiceString, choiceInt);
    int compChoice = computer();
    results(compChoice, playerChoice);
    cout << "Would you like to play again? Type yes or no: ";
    cin >> game;
    if (game == "yes") {
      cout << "Starting";
      fancydelay(".");
      game = "running";
      system("CLS");
    } else if (game == "no") {
      cout << "Exiting";
      fancydelay(".");
      system("CLS");
      exit(0);
    }
  }
  return 0;
}
