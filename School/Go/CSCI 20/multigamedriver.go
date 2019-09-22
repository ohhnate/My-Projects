// Project 2 - Sams Multi-Game
// Programmer name: Samuel Fuller
// Date completed: 23 Mar 2019

package main

import (
	"fmt"
	"math/rand"
	"time"
)

// function for game banner or greeting
func banner() {
	fmt.Printf("\n ~~~~~~~~~~~~~~~~~~~ \n")
	fmt.Printf("|     Welcome       |\n")
	fmt.Printf("|        To         |\n")
	fmt.Printf("|  Sams Multi-Game  |\n")
	fmt.Printf(" ~~~~~~~~~~~~~~~~~~~ \n")
}

// function to call players name
func name() string {
	var name string
	fmt.Printf("\nWhat is your name: ")
	fmt.Scanln(&name)
	return name
}

// function that shows the main menu to pick a game
func menu() {
	fmt.Printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n")
	fmt.Printf("|                            |\n")
	fmt.Printf("| (1) - Rock Scissors Paper  |\n")
	fmt.Printf("| (2) - Number Guesser       |\n")
	fmt.Printf("|                            |\n")
	fmt.Printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n")
}

// function driver that controlls which game is currently running from the main menu
func gameDriver(playerName string) {
	//variable that is used to break or start the loop for if a game is running
	playing := 0
	menu()
	for playing < 1 {
		fmt.Printf("\nHello %s! Please select a game or choices by typing the corresponding number: ", playerName)
		var game int
		fmt.Scanln(&game)

		for game == 1 {
			rpsGame(playerName)
		}
		for game == 2 {
			numberGame(playerName)
		}
	}
	fmt.Printf("\n\nGoodbye\n\n")
}

// function for the number game
func numberGame(playerName string) {
	// variable storing the random number to be guessed
	computerChoice := rand.Intn(100) + 1
	// counter variable that keeps track how many guesses he took the user to make the correct guess
	counter := 0
	// guess variable controls the loop and breaks once the users guess is correct
	guess := 0
	for guess < 1 {
		var playerGuess int
		fmt.Printf("\nGuess a number from 1 to 100: ")
		fmt.Scanln(&playerGuess)

		if playerGuess < 1 || playerGuess > 100 {
			wrong := 0
			for wrong < 1 {
				fmt.Printf("That is not a valid guess. Try again: ")
				fmt.Scanln(&playerGuess)
				if playerGuess >= 1 && playerGuess <= 100 {
					wrong = 1
				}
			}
		}
		// counter++ increases the counter by 1 every time AFTER the above condition
		counter++
		// below conditions determine if user guesses correctly or incorrect
		// also if the user is good or bad at guessing depending on how many attempts
		if playerGuess < computerChoice {
			fmt.Printf("\nYour guess is too low guess again!\n")
		} else if playerGuess > computerChoice {
			fmt.Printf("\nYour guess is too high guess again!\n")
		} else {
			fmt.Printf("\nGood job you guessed correct! It took you %d guesses.\n", counter)
			if counter <= 3 {
				fmt.Printf("You are a guessing master!\n")
				guess = guess + 1
			}
			if counter < 8 && counter > 3 {
				fmt.Printf("You are an average guesser. Try better next time.\n")
				guess = guess + 1
			}
			if counter >= 8 {
				fmt.Printf("You really suck at guessing. Try to do better next time.\n")
				guess = guess + 1
			}
		}
	}
	// below variable & condition to give the option to play again or back to main
	var again int
	fmt.Printf("\nPress 1 to play again or 2 to go back to the main menu: ")
	fmt.Scanln(&again)

	if again == 1 {
		numberGame(playerName)
	} else if again == 2 {
		gameDriver(playerName)
	} else {
		for {
			fmt.Printf("That is a not a valid selection. Choose again: ")
			fmt.Scanln(&again)
			if again == 1 || again == 2 {
				break
			}
		}
	}
}

// rock paper scissors function
func rpsGame(playerName string) {
	// game variable controls if rps is running or not. Needs to be rewritten for
	// better effeciency ***
	game := 0
	for game < 1 {
		computerPlay := rand.Intn(3) + 1

		//humanPlay variable containing output of users options
		var humanPlay int
		fmt.Printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n")
		fmt.Printf("|                            |\n")
		fmt.Printf("| (1) - Rock                 |\n")
		fmt.Printf("| (2) - Scissors             |\n")
		fmt.Printf("| (3) - Paper                |\n")
		fmt.Printf("|                            |\n")
		fmt.Printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n")
		fmt.Printf("\nRock, Scissors, or Paper: ")
		fmt.Scanln(&humanPlay)

		// condition for if the player chooses a non valid choice
		if humanPlay < 1 || humanPlay > 3 {
			guesses := 0
			wrong := 0
			for wrong < 1 {
				fmt.Printf("That is not a valid choice. Choose again.")
				guesses = guesses + 1
				fmt.Printf("\nRock, Scissors, or Paper: ")
				fmt.Scanln(&humanPlay)
				if humanPlay == 1 || humanPlay == 2 || humanPlay == 3 {
					wrong = 1
				}
				for guesses >= 3 {
					fmt.Printf("Are you an idiot??? Type 1 for Rock, 2 for Scissors or 3 for paper... Sheesh.")
					guesses = guesses + 1
					fmt.Printf("\nRock, Scissors, or Paper: ")
					fmt.Scanln(&humanPlay)
					if humanPlay == 1 || humanPlay == 2 || humanPlay == 3 {
						wrong = 1
						guesses = 0
					}
				}
			}
		}
		// conditions of if and switches for players choice and computers choice
		if humanPlay == 1 {
			fmt.Printf("%s plays Rock.\n", playerName)
		}
		if humanPlay == 2 {
			fmt.Printf("%s plays Scissors.\n", playerName)
		}
		if humanPlay == 3 {
			fmt.Printf("%s plays Paper.\n", playerName)
		}
		if computerPlay == 1 {
			fmt.Printf("Computer plays Rock.\n")
		}
		if computerPlay == 2 {
			fmt.Printf("Computer plays Scissors.\n")
		}
		if computerPlay == 3 {
			fmt.Printf("Computer plays Paper.\n")
		}

		if humanPlay == computerPlay {
			if humanPlay == 1 {
				fmt.Printf("It's a draw! Try again!\n")
			}
			if humanPlay == 2 {
				fmt.Printf("It's a draw! Try again!\n")
			}
			if humanPlay == 3 {
				fmt.Printf("It's a draw! Try again!\n")
			}
		} else if humanPlay == 1 {
			switch computerPlay {
			case 2:
				fmt.Printf("Rock smashes Scissors! %s wins!\n", playerName)
			case 3:
				fmt.Printf("Paper covers Rock! Computer wins!\n")
			}
		} else if humanPlay == 2 {
			switch computerPlay {
			case 3:
				fmt.Printf("Scissors cuts Paper! %s wins!\n", playerName)
			case 1:
				fmt.Printf("Rock smashes Scissors! Computer wins!\n")

			}
		} else if humanPlay == 3 {
			switch computerPlay {
			case 1:
				fmt.Printf("Paper covers Rock! %s wins!\n", playerName)
			case 2:
				fmt.Printf("Scissors cuts Paper! Computer wins!\n")
			}
		}
		// game var breaks the loop after one run through. for loop not necessarily needed
		// since there is only one round. only used for future round implementation
		game = game + 1

		// var again2 to play again or go back to main menu
		var again2 int
		fmt.Printf("\nPress 1 to play again or 2 to go back to the main menu: ")
		fmt.Scanln(&again2)

		if again2 == 1 {
			rpsGame(playerName)
		} else if again2 == 2 {
			gameDriver(playerName)
		} else {
			for {
				fmt.Printf("That is a not a valid selection. Choose again: ")
				fmt.Scanln(&again2)
				if again2 == 1 || again2 == 2 {
					break
				}
			}
		}
	}
}

func main() {
	// seed to reset the time for random number generation
	rand.Seed(time.Now().UnixNano())
	banner()
	playerName := name()
	gameDriver(playerName)

}
