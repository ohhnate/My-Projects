// Lab 13 -- maps
//
// Programmer name: Samuel Fuller
// Date completed:

package main

import (
	"fmt"
	"sort"
)

// StringIntMap explores usage of map with string keys
// and integer values.
func StringIntMap() {
	// NOTE: "pretty print" as much as possible

	// 1. Use the make function to create a map with string keys and integer values
	//    NOTE: the map represents a shopping list of items (string) and quantities
	//          to purchase (integer)
	m := make(map[string]int)
	// 2. Use %v to print the map in its default format
	fmt.Printf("Default map: %v\n", m)

	items := [5]string{"apples", "sandwiches", "chips", "beverages", "cookies"}

	// 3a. Use a "range" loop over items to populate the map with user input
	//     NOTE: each string from items will be used as a key for the map
	for i := range items {
		m[items[i]] = 0
	}
	// 3b. Declare an integer variable
	var total int
	// 3c. Prompt for and read in a user value (e.g., "How many apples? ")
	// 3d. Assign the user input to the map
	for i := range items {
		fmt.Printf("How many %v? ", items[i])
		fmt.Scanln(&total)
		m[items[i]] = total
	}



	// 4. Use %v to print the slice in its default format
	fmt.Printf("\nUpdated map: %v\n", m)
}

// StringFloatMap explores usage of map with string keys
// and float values.
func StringFloatMap() {
	// NOTE: "pretty print" as much as possible

	// 1. Use the make function to create a map with string keys and float values
	//    NOTE: the map represents a list of months (string) and their average
	//          precipitation (float) for the city of Chico
	m := make(map[string]float64)
	// 2. Use %v to print the map in its default format
	fmt.Printf("Default float map: %v\n", m)
	// https://www.usclimatedata.com/climate/chico/california/united-states/usca0211
	//
	// 3. Using the data provided at the link above, enter the correct value for each
	//    month into the map (the month will be the key, the average precipitation will
	//    be the value)
	m["January"] = 4.84
	m["February"] = 4.41
	m["March"] = 4.29
	m["April"] = 1.73
	m["May"] = 1.02
	m["June"] = 0.47
	m["July"] = 0.04
	m["August"] = 0.08
	m["September"] = 0.43
	m["October"] = 1.42
	m["November"] = 3.27
	m["December"] = 4.61

	// 4. Use a "range" loop to display all of the months with their average precipitation
	//    values, in a formatted way (e.g., "Average January rainfall: 4.84 inches")
	for i, element := range m {
		fmt.Printf("Average %v rainfall: %v inches\n", i, element)
	}
}

// IntFloatMap explores usage of map with integer keys
// and float values. CHALLENGING.
func IntFloatMap() {
	// NOTE: "pretty print" as much as possible

	// Annual CPI averages from 2000-2018
	// https://inflationdata.com/Inflation/Consumer_Price_Index/HistoricalCPI.aspx
	cpiAverages := [19]float64{
		172.2, 177.1, 179.88, 183.96, 188.9, 195.3, 201.6, 207.342,
		215.303, 214.537, 218.056, 224.939, 229.594, 232.957,
		236.736, 237.017, 240.008, 245.12, 251.107,
	}

	// 1. Use the make function to create a map with integer keys and float values
	//    NOTE: the map represents a list of years (integer) and their Consumer Price
	//          Indices (float) for the USA for the years 2000-2018
	m := make(map[int]float64)
	// 2. Use a "range" loop over cpiAverages to populate the map with year (key) and
	//    CPI (value); cpiAverages has CPI values in order from 2000-2018
	year := 2000
	for i := range cpiAverages {
		m[year] = cpiAverages[i]
		year++
	}
	// 3. Use %v to print the map in its default format
	fmt.Printf("default CPI map: %v\n", m)
	// NOTE: these steps are needed to sort the values by year (maps are not by default
	//       sorted by their keys)
	// 4. Create an empty slice of integers to store years
	years := make([]int, 0)
	// 5. Use a "range" loop to get the years from the map and append them to the newly
	//     created years slice
	for i := range m {
		years = append(years, i)
	}
	// 6. Use sorts.Ints to sort the slice containing the years taken from the map
	//    (will require an import of "sort")
	sort.Ints(years)

	// 7. Use a "range" loop over the years slice created in the previous step to
	//    key the map and display the CPIs for years when a CPI decreased compared
	//    to the prior year
	stored := m[2000]
	for _, year := range years {
		//fmt.Printf("mi: %v",m[year])
		if m[year] < stored {
			fmt.Printf("Less CPI: %v", m[year])
		}
		stored = m[year]
	}
}

// IntBoolMap explores the usage of map with integer keys
// and boolean values. CHALLENGING.
func IntBoolMap() {
// NOTE: "pretty print" as much as possible
// 1. Use the make function to create a map with integer keys and boolean values
//    NOTE: the map represents a list of numbers (integer) and a boolean value
//          that flags the key as prime (true) or not prime (false)
	m := make(map[int]bool)
// 2a. Use a "range" loop over numbers to populate the map (the numbers will be the
//     keys)
// https://www.random.org/integers/
	numbers := [25]int{
	6992, 7224, 2572, 8290, 5021, 6631, 2690, 5462, 9970, 9933,
	8321, 7748, 2153, 5866, 1729, 6743, 9861, 5703, 2668, 9978,
	8148, 1821, 1963, 7999, 9440,
	}

	for i := range numbers {
		m[numbers[i]] = false
		for k := 2; k < numbers[i]; k++ {
			if numbers[i] % k != 0 {
				m[numbers[i]] = true
			}
		}
	}



// 2b. Use a nested "counting" loop to test the number to see if it is prime -- if
//     prime, set the value for that number/key to true, otherwise set the value
//     for that number/key to false





// 3. Use %v to print the map in its default format
	fmt.Printf("Map bool: %v\n", m)

// 4. Use a "range" loop over the map to print only the prime numbers
//    (the numbers/keys whose values are true)
for i := range m {
	if m[i] == true {
		fmt.Printf("\n%v is a prime number.\n", i)
		}
	}
}

func main() {

	StringIntMap()
	fmt.Printf("\n")

	StringFloatMap()
	fmt.Printf("\n")

	IntFloatMap()
	fmt.Printf("\n")

	IntBoolMap()
	fmt.Printf("\n")
}
