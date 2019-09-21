// Lab 8 -- control flow (if/else)
//
// Programmer name: Samuel Fuller
// Date completed: 23 February 2019

package main

import (
	"fmt"
	"math/rand"
	"time"
)

// ComputerPlay returns a random integer value representing
// the computer's choice in a game of Rock, Scissors, Paper.
// 0=rock, 1=scissors, 2=paper
func ComputerPlay() int {
	rand.Seed(time.Now().UnixNano())
	computerPlay := rand.Intn(3)
	return computerPlay
}

// PlayerPlay prompts for, reads in, and returns
// an integer value representing the players's choice
// in a game of Rock, Scissors, Paper.
// 0=rock, 1=scissors, 2=paper
func PlayerPlay() int {
	var humanPlay int
	fmt.Printf("Rock, Paper, or Scissors?(Type 0 for rock, 1 for scissors, or 2 for paper): ")
	fmt.Scanln(&humanPlay)
	return humanPlay
}

// PrintPlay "pretty prints" the player name (human or computer)
// and what they played (rock, scissors, or paper).
// Example: "Computer plays rock"
func PrintPlay(playerName string, play int) {
	if play == 0 {
		fmt.Printf("%s plays Rock.\n", playerName)
	} else if play == 1 {
		fmt.Printf("%s plays Scissors.\n", playerName)
	} else {
		fmt.Printf("%s plays Paper.\n", playerName)
	}
}

// ShowResult "pretty prints" the result of a round
// of Rock, Scissors, Paper.
// Example: "Rock crushes scissors. Player wins."
func ShowResult(computerPlay int, humanPlay int) {
	if humanPlay == computerPlay {
		fmt.Println("It's a draw! Try again!")
	} else if humanPlay == 0 {
		switch computerPlay {
		case 1:
			fmt.Println("Rock smashes Scissors! Player wins!")
		case 2:
			fmt.Println("Paper covers Rock! Computer wins!")
		}
	} else if humanPlay == 1 {
		switch computerPlay {
		case 0:
			fmt.Println("Rock smashes Scissors! Computer wins!")
		case 2:
			fmt.Println("Scissors cuts Paper! Player wins!")
		}
	} else if humanPlay == 2 {
		switch computerPlay {
		case 0:
			fmt.Println("Paper covers Rock! Player wins!")
		case 1:
			fmt.Println("Scissors cuts Paper! Computer wins!")
		}
	}
}

func main() {

	// call ComputerPlay
	computerPlay := ComputerPlay()
	// call PlayerPlay
	humanPlay := PlayerPlay()

	// call PrintPlay for computer
	PrintPlay("Computer", computerPlay)
	// call PrintPlay for human player
	PrintPlay("Player", humanPlay)

	// call ShowResult
	ShowResult(computerPlay, humanPlay)
}
