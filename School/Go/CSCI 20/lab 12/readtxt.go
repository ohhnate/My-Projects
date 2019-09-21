// Lab 12 -- slices and functions
//
// Programmer name: Samuel Fuller
// Date completed:  17 April 2019

package main

import (
	"strings"
)

// StringsOfLength returns a slice containing all strings
// in a given list matching a given length.
func StringsOfLength(list []string, length int) []string {
	var total []string
	for i := range list {
		if len(list[i]) == length{
			total = append(total, list[i])
		}
	}
	return total
}

// StringsLongerThan returns a slice containing all strings
// in a given list longer than a given length.
func StringsLongerThan(list []string, length int) []string {
	var total []string
	for i := range list {
		if len(list[i]) > length {
			total = append(total, list[i])
		}
	}
	return total
}

// StringsShorterThan returns a slice containing all strings
// in a given list shorter than a given length.
func StringsShorterThan(list []string, length int) []string {
	var total []string
	for i := range list {
		if len(list[i]) < length {
			total = append(total, list[i])
		}
	}
	return total
}

// StringsBeginningWith returns a slice containing all strings
// in a given list that begin with a given prefix. Case insensitive.
func StringsBeginningWith(list []string, prefix string) []string {
	var total []string
	for i := range list {
		if strings.HasPrefix(list[i], prefix) {
			total = append(total, list[i])
		}
	}
	return total
}

// ContainsString returns true if a given slice contains a target
// string. Case insensitive.
func ContainsString(list []string, target string) bool {
	for i := range list {
		if strings.Contains(list[i], target){
			return true
		}
	}
	return false
}

// GetUnique returns a slice containing only non-duplicate strings
// from a given list. (HINT: use ContainsString as a helper)
func GetUnique(list []string) []string {
	var total []string
	for _, num := range list{
		if !ContainsString(total, num){
			total = append(total, num)
		}
	}
	return total
}

// LengthOfShortest returns the length of the shortest string in a
// given list of strings.
func LengthOfShortest(list []string) int {
	total := 20
	for i := range list {
		if len(list[i]) <= total{
			total = len(list[i])
		}
	}
	return total
}

// LengthOfLongest returns the length of the longest string in a
// given list of strings.
func LengthOfLongest(list []string) int {
	total := 0
	for i := range list {
		if len(list[i]) >= total{
			total = len(list[i])
		}
	}
	return total
}

// ListOfShortest returns a slice containing all strings in a given
// list whose length matches the shortest string in the list.
//  (HINT: use LengthOfShortest as a helper)
func ListOfShortest(list []string) []string {
	var total []string
	for i, num:= range list {
		if len(list[i]) == LengthOfShortest(list) {
			total = append(total, num)
		}
	}
	return total
}

// ListOfLongest returns a slice containing all strings in a given
// list whose length matches the longest string in the list.
//  (HINT: use LengthOfLongest as a helper)
func ListOfLongest(list []string) []string {
	var total []string
	for i, num:= range list {
		if len(list[i]) == LengthOfLongest(list) {
			total = append(total, num)
		}
	}
	return total
}

func main() {
}
