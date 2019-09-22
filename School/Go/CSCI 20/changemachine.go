// Project 1 --Sam's Change Maker
//
// Programmer name: Samuel Fuller
// Date completed: 11 Feb 2019

package main

import "fmt"

func main() {
	fmt.Printf("\nWelcome to Sam's Change Maker!\n\n")

	var quarters int
	fmt.Printf("How many quarters do you have? ")
	fmt.Scanln(&quarters)

	var dimes int
	fmt.Printf("How many dimes do you have? ")
	fmt.Scanln(&dimes)

	var nickels int
	fmt.Printf("How many nickels do you have? ")
	fmt.Scanln(&nickels)

	var pennies int
	fmt.Printf("How many pennies do you have? ")
	fmt.Scanln(&pennies)

	totalChange := (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)

	fmt.Printf("You have %d cents.\n", totalChange)

	FChange := float64(totalChange) * .01

	fmt.Printf("%d cents can also be written as $%.2f\n\n", totalChange, FChange)

	var cents int
	fmt.Printf("How many total cents do you have?(don't include special characters or decimals) ")
	fmt.Scanln(&cents)

	qBreakdown := cents / 25
	cents = cents % 25
	dBreakdown := cents / 10
	cents = cents % 10
	nBreakdown := cents / 5
	cents = cents % 5
	pBreakdown := cents / 1

	fmt.Printf("You have %d quarters, %d dimes, %d nickels, and %d pennies.\n", qBreakdown, dBreakdown, nBreakdown, pBreakdown)

}
