// Lab 5 -- functions, pt 1
//
// Programmer name: Samuel Fuller
// Date completed:  __________

package main

import "fmt"

// ShowBanner prints a banner for the program.
func ShowBanner() {
  fmt.Printf("\n\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
  fmt.Printf("|FFFFFFFFFFFFFFFFFFFFFF                                                      |\n")
  fmt.Printf("|F::::::::::::::::::::F                                                      |\n")
  fmt.Printf("|F::::::::::::::::::::F                                                      |\n")
  fmt.Printf("|FF::::::FFFFFFFFF::::F                                                      |\n")
  fmt.Printf("|  F:::::F       FFFFFFuuuuuu    uuuuuunnnn  nnnnnnnn        cccccccccccccccc|\n")
  fmt.Printf("|  F:::::F             u::::u    u::::un:::nn::::::::nn    cc:::::::::::::::c|\n")
  fmt.Printf("|  F::::::FFFFFFFFFF   u::::u    u::::un::::::::::::::nn  c:::::::::::::::::c|\n")
  fmt.Printf("|  F:::::::::::::::F   u::::u    u::::unn:::::::::::::::nc:::::::cccccc:::::c|\n")
  fmt.Printf("|  F:::::::::::::::F   u::::u    u::::u  n:::::nnnn:::::nc::::::c     ccccccc|\n")
  fmt.Printf("|  F::::::FFFFFFFFFF   u::::u    u::::u  n::::n    n::::nc:::::c             |\n")
  fmt.Printf("|  F:::::F             u::::u    u::::u  n::::n    n::::nc:::::c             |\n")
  fmt.Printf("|  F:::::F             u:::::uuuu:::::u  n::::n    n::::nc::::::c     ccccccc|\n")
  fmt.Printf("|FF:::::::FF           u:::::::::::::::uun::::n    n::::nc:::::::cccccc:::::c|\n")
  fmt.Printf("|F::::::::FF            u:::::::::::::::un::::n    n::::n c:::::::::::::::::c|\n")
  fmt.Printf("|F::::::::FF             uu::::::::uu:::un::::n    n::::n  cc:::::::::::::::c|\n")
  fmt.Printf("|FFFFFFFFFFF               uuuuuuuu  uuuunnnnnn    nnnnnn    cccccccccccccccc|\n")
  fmt.Printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n")
}

func GreetUser(name string) {
  fmt.Printf("Hello %s. Welcome to the FuncLab.\n\n", name)
}

func EstimateAge(birthYear int) {
  age := 2019 - birthYear
  age2 := age - 1
  fmt.Printf("You are %d or %d years old.\n\n", age2, age)
}

func ComputeAverage(pointsEarned, pointsPossible float32){
  average := pointsEarned/pointsPossible * 100
  fmt.Printf("Your total average is: %.2f%%\n\n", average)
}

func SayGoodbye(name string){
  fmt.Printf("Goodbye %s! It was nice to meet you.\n\n", name)
}

func main() {

	// call ShowBanner
  ShowBanner()

	// prompt for and read in user name
	// call GreetUser -- pass the user name
  var name string
  fmt.Printf("What is your name? ")
  fmt.Scanln(&name)
  GreetUser(name)

	// prompt for and read in user birth year
	// call EstimateAge -- pass user birth year
  var birthYear int
  fmt.Printf("What year were you born? ")
  fmt.Scanln(&birthYear)
  EstimateAge(birthYear)

	// prompt for and read in points earned
	// prompt for and read in points possible
	// call ComputeAverage -- pass points earned and points possible
  var pointsEarned, pointsPossible float32
  fmt.Printf("What is the combined score of your last 2 tests? ")
  fmt.Scanln(&pointsEarned)
  fmt.Printf("What is the combined points possible from your last 2 tests? ")
  fmt.Scanln(&pointsPossible)
  ComputeAverage(pointsEarned, pointsPossible)

	// call SayGoodbye -- pass the user name
  SayGoodbye(name)
}
