// Lab 11 -- slices
//
// Programmer name: Samuel Fuller
// Date completed: 3 April 2019

package main

import (
	"fmt"
	"strings"
)

// IntSlice explores usage of an integer slice.
func IntSlice() {
	// NOTE: "pretty print" as much as possible

	// 1. Use the make function to create a slice of 0 integers named "numbers"
	numbers := make([]int, 0)
	// 2. Use %v to print the slice in its default format
	fmt.Printf("\nNumbers: %v", numbers)
	// 3. Print the length of the slice
	fmt.Printf("\nLength: %v", len(numbers))
	// 4a. Use a "counting" loop to prompt for and read in 5 values for "numbers"
	var count int
	for i := 0; i < 5; i++ {
		fmt.Printf("\nInput an integer: ")
		fmt.Scanln(&count)
		// 4b. Use the append function to add the input values into "numbers"
		numbers = append(numbers, count)
	}
	// 5. Use %v to print the slice in its default format
	fmt.Printf("\nSlice: %v", numbers)
	// 6. Print the length of the slice
	fmt.Printf("\nSlice length: %v", len(numbers))
}

// FloatSlice explores usage of a float slice.
func FloatSlice() {
	// NOTE: "pretty print" as much as possible

	// 1. Use the make function to create a slice of 5 float64s named "temperatures"
	temperatures := make([]float64, 5)
	// 2. Use %v to print the slice in its default format
	fmt.Printf("\nTemperatures: %v", temperatures)
	// 3. Use a "range" loop to prompt for and read in 5 values for "numbers"
	var value float64
	for i := range temperatures {
		fmt.Printf("\nInput 5 temperatures: ")
		fmt.Scanln(&value)
		temperatures[i] += value
	}
	fmt.Printf("Temperature array length: %v", temperatures)
	// 4. Use a "range" loop (ignoring index) to compute the sum of the temperatures
	sum := 0.0
	for _, num := range temperatures {
		sum += num
	}
	// 5. Print the sum of temperatures
	fmt.Printf("\nSum: %.1f", sum)
	// 6. Compute the average of temperatures

	avg := sum / float64(len(temperatures))
	// 7. Print the average of temperatures
	fmt.Printf("\nAverage Temp: %.1f degrees", avg)
}

// StringSlice explores usage of a string slice.
func StringSlice() {
	// NOTE: "pretty print" as much as possible

	// 1. Declare an array of 3 string named "originalGreetings" -- pre-populate
	//    the array with any 3 greetings strings of your choice (EX: "Howdy")
	originalGreetings := [3]string{"hi", "hello", "hey"}
	// 2. Use the make function to create a slice of strings, of equal length to
	//    "originalGreetings", name the slice "updatedGreetings"
	updatedGreetings := make([]string, 3)
	// 3. Use %v to print the slice "updatedGreetings" in its default format
	fmt.Printf("\nGreetings: %v", updatedGreetings)
	// 4. Use a "range" loop to overwrite each string in "updatedGreetings"
	//    with its upper-case form (HINT: use strings.ToUpper)
	for i := range updatedGreetings {
		updatedGreetings[i] += strings.ToUpper(originalGreetings[i])
	}
	// 5. Use %v to print the slice "updatedGreetings" in its default format
	fmt.Printf("\nUpdated Greetings: %v ", updatedGreetings)
}

// SliceExpressions explores the usage of slice expressions.
func SliceExpressions() {

	// 1. Declare an array of 5 string named "products" -- pre-populate
	//    the array with "bread", "milk", "eggs", "butter", "sugar"
	products := [5]string{"bread", "milk", "eggs", "butter", "sugar"}
	// 2. Use %v and a slice expression to print the first two strings in "products"
	//    (should be "bread" and "milk")
	fmt.Printf("\nFirst two: %v", products[0:2])
	// 3. Use %v and a slice expression to print the last two strings in "products"
	//    (should be "butter" and "sugar")
	fmt.Printf("\nLast two: %v", products[3:5])
	// 4. Use %v and a slice expression to print middle string in "products"
	//    (should be "eggs")
	fmt.Printf("\nMiddle: %v", products[2:3])
}

func main() {

	IntSlice()
	fmt.Printf("\n")

	FloatSlice()
	fmt.Printf("\n")

	StringSlice()
	fmt.Printf("\n")

	SliceExpressions()
	fmt.Printf("\n")
}
