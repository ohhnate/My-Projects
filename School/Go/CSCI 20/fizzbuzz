// Lab 9 -- control flow (for)
//
// Programmer name: Samuel Fuller
// Date completed: 20 Feb 2019

package main

import "fmt"

// PrintEvens prints the even numbers from 1 up to max.
func PrintEvens(max int) {
  for evens := 1; evens <= max; evens++{
    if evens%2==0{
      fmt.Println(evens)
    }
  }
}

// PrintOdds prints the odd numbers from 1 up to max.
func PrintOdds(max int) {
  for odds := 1; odds <= max; odds++{
    if odds%2!=0{
      fmt.Println(odds)
    }
  }
}

// FizzBuzz solves the Fizz Buzz challenge from 1 up to max.
// https://leetcode.com/problems/fizz-buzz/description/
func FizzBuzz(max int) {
  for numbers := 1; numbers <= max; numbers++{
    if numbers%3==0 && numbers%5==0{
      fmt.Println("FizzBuzz")
    } else if numbers%3==0{
      fmt.Println("Fizz")
    } else if numbers%5==0{
      fmt.Println("Buzz")
    } else {
      fmt.Println(numbers)
    }
  }
}
func main() {
	// call PrintEvens with any value for max
  PrintEvens(20)
	// call PrintOdds with any value for max
  PrintOdds(33)
	// call FizzBuzz with any value for max
  FizzBuzz(30)
}
