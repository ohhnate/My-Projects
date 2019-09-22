// Project 3 -- array/slice-based spreadsheet
//
// Programmer name: Samuel Fuller
// Date completed: 26 April 2019

package main

import (
	"fmt"
	"math/rand"
	"os"
	"os/exec"
	"runtime"
	"time"
)

// ClearScreen clears the screen.
func ClearScreen() {
	cmd := exec.Command("cmd", "/c", "cls")
	switch runtime.GOOS {
	case "linux":
		cmd = exec.Command("clear")
	case "darwin":
		cmd = exec.Command("clear")
	}
	cmd.Stdout = os.Stdout
	cmd.Run()
}
// Your functions as needed to organize the program.
// top banner and column labels
func Banner() {
	fmt.Printf("                      ____________________________________\n")
	fmt.Printf("                     |                                    |\n")
	fmt.Printf("                     |          Sams Supersheet           |\n")
	fmt.Printf("                     |____________________________________|\n")
	fmt.Printf("\nRow Number | Cell 1 | Cell 2 | Cell 3 | Cell 4 | Cell 5 | Calculations | Operations |\n")
	fmt.Printf("\n-------------------------------------------------------------------------------------\n")
}
// function generating random float up to 200
func RandomF() float64 {
	rF := rand.Float64()
	rI := rand.Intn(200)
	randy := float64(rI) + rF
	return randy
}
// function for random operation mainly for testing purposes and fun
func RandomS() string {
	rstring := "empty"
	rI := rand.Intn(4)
	if rI == 0 {
		rstring = "(AVG)"
	} else if rI == 1 {
		rstring = "(SUM)"
	} else if rI == 2 {
		rstring = "(MIN)"
	} else if rI == 3 {
		rstring = "(MAX)"
	} 
	return rstring
}

// function that fills all cells with random float value. Also calculates after randomization
func RandomFill(rowNum int, row [] float64, calculations[] float64, operations[] string){
	for i := 0; i <= 4; i++ {
		row[i] = RandomF()
	}
	operations[rowNum] = RandomS()
	if operations[rowNum] == "(SUM)"{
		calculations[rowNum] = Sum(row)
	} else if operations[rowNum] == "(AVG)"{
		calculations[rowNum] = Avg(row)
	} else if operations[rowNum] == "(MIN)"{
		calculations[rowNum] = Min(row)
	} else if operations[rowNum] == "(MAX)"{
		calculations[rowNum] = Max(row)
	} 	
}

// function that allows individual cell editing
func EditCell(rowSelection int, newCell float64, cellSelection int, row []float64, calculations[] float64, operations[] string) {
	row[cellSelection-1] = newCell
		if operations[rowSelection-1] == "(SUM)" {
			calculations[rowSelection-1] = Sum(row)
		}
		if operations[rowSelection-1] == "(AVG)" {
			calculations[rowSelection-1] = Avg(row)
		}
		if operations[rowSelection-1] == "(MIN)" {
			calculations[rowSelection-1] = Min(row)
		}
		if operations[rowSelection-1] == "(MAX)" {
			calculations[rowSelection-1] = Max(row)
		}			
}
// function that clears all rows or individual rows.
func ClearRows(rowNum int, row [] float64, calculations[] float64, operations[] string) {
		for i := 0; i <= 4; i++ {
			row[i] = 0.00
			}
		operations[rowNum] = "(SUM)"
		calculations[rowNum] = 0.00	
}
// function to calculate sum of values in a given row
func Sum(row [] float64) float64 {
	sum := 0.00
	for i := range row {
		sum += row[i]
	}
	return sum
}
// function to calculate the average of values in a given row
func Avg(row [] float64) float64 {
	avg := 0.00
	total := 0.00
	for i := range row {
		avg += row[i]
	}
	total = avg / float64(len(row))
	return total
}
// function that returns smallest value in a given row
func Min(row [] float64) float64 {
	min := row[0]
	for i := range row {
		if row[i] <= min {
			min = row[i]
		}
	}
	return min
}
// function that returns largest value in a given row
func Max(row [] float64) float64 {
	max := row[0]
	for i := range row {
		if row[i] >= max {
			max = row[i]
		}
	}
	return max
}
// this function prints out the rows and contains all of the formatting
func Rows(rowNum int, row int, rowPick[]float64, calculation []float64, operationSelect []string) {
	fmt.Printf("\n%5d.%13.2f |%6.2f |%8.2f |%7.2f |%7.2f |",rowNum, rowPick[0], rowPick[1], rowPick[2], rowPick[3], rowPick[4])
	fmt.Printf("%12.2f  |", calculation[row])
	fmt.Printf("%9v    |", operationSelect[row]) 
}

func main() {
	rand.Seed(time.Now().UnixNano())
	// created slices and filled default values
	calculations :=[]float64{0.00, 0.00, 0.00, 0.00, 0.00}
	operations := []string {"(SUM)", "(SUM)", "(SUM)", "(SUM)", "(SUM)"}
	row1 := make([]float64, 5)
	row2 := make([]float64, 5)
	row3 := make([]float64, 5)
	row4 := make([]float64, 5)
	row5 := make([]float64, 5)
	// MAIN PROGRAM LOOP
	for {
	// - clear the screen
		ClearScreen()
		Banner()
		// - display all rows, calculated values, and operations
		Rows(1, 0, row1, calculations, operations)
		Rows(2, 1, row2, calculations, operations)
		Rows(3, 2, row3, calculations, operations)
		Rows(4, 3, row4, calculations, operations)
		Rows(5, 4, row5, calculations, operations)
		
		// - display menu
		fmt.Printf("\n\n\n[1] Edit Cell")
		fmt.Printf("\n[2] Change Operation For Row")
		fmt.Printf("\n[3] Clear A Row Or Rows")
		fmt.Printf("\n[4] Randomly Fill Cells")
		fmt.Printf("\n[5] Exit Program")
		// - act on menu choice, 5 switch cases for each menu choice with var choice controlling selections
		var choice int
		fmt.Printf("\n\nYour Choice: ")
		fmt.Scanln(&choice)
		// rowSlice is used to turn integer choices back into the rowSlices. ie 1 == row1, 2 == row2 etc..
		rowSlice := row1
		switch choice {
		case 1:
			for {
				fmt.Printf("\nEnter Row Number  (1 to 5): ")
				fmt.Scanln(&choice)
				if choice < 1 || choice > 5 {
					fmt.Printf("Not a valid selection. Enter again.")
				} else {
					break
				}
			}
			//variable used to determine index value of selected row to change in the EditCell function
			var cellSelection int
			for {
				fmt.Printf("Enter Cell Number (1 to 5): ")
				fmt.Scanln(&cellSelection)
				if cellSelection < 1 || cellSelection > 5 {
					fmt.Printf("Not a valid selection. Enter again.\n")
				} else {
					break
				}
		}
			// the below conditional I used multiple times in this program. I tried
			// throwing it into a function for reuse but kept getting errors. will try again.
			if choice == 1 {
				fmt.Printf("\nCurrent Value: %.2f", row1[cellSelection-1])
				} else if choice == 2 {
					fmt.Printf("\nCurrent Value: %.2f", row2[cellSelection-1])
					rowSlice = row2
				} else if choice == 3 {
					fmt.Printf("\nCurrent Value: %.2f", row3[cellSelection-1])
					rowSlice = row3
				} else if choice == 4 {
					fmt.Printf("\nCurrent Value: %.2f", row4[cellSelection-1])
					rowSlice = row4
				} else if choice == 5 {
					fmt.Printf("\nCurrent Value: %.2f", row5[cellSelection-1])
					rowSlice = row5
				} 
			// variable that overwrites current cell value	 
			var newCell float64	
			for {
			fmt.Printf("\nEnter A New Value: ")
			fmt.Scanln(&newCell)
			if newCell > 9999 || newCell < -9999 {
				fmt.Printf("Not a valid selection. Please enter a number less than 5 digits.")
			} else {
				break
			}
		}
			EditCell(choice, newCell, cellSelection, rowSlice, calculations, operations)
		case 2:
			var opChoice int
			for {
			fmt.Printf("Which rows' operation would you like to change: ")
			fmt.Scanln(&choice)
			if choice < 1 || choice > 5 {
				fmt.Printf("Not a valid selection. Enter again.\n")
			} else {
				break
			}
		}
			if choice == 1 {
				rowSlice = row1
			} else if choice == 2 {
				rowSlice = row2
			} else if choice == 3 {
				rowSlice = row3
			} else if choice == 4 {
				rowSlice = row4
			} else if choice == 5 {
				rowSlice = row5
			}
			for {
			fmt.Printf("[1] SUM\n")
			fmt.Printf("[2] AVG\n")
			fmt.Printf("[3] MIN\n")
			fmt.Printf("[4] MAX\n")
			fmt.Printf("Select new operation: ")
			fmt.Scanln(&opChoice)
			if opChoice < 1 || opChoice > 4 {
				fmt.Printf("Not a valid selection. Enter again.\n")
			} else {
				break
			}
		}
			if opChoice == 1 {
				operations[choice-1] = "(SUM)"
				calculations[choice-1] = Sum(rowSlice)
			}else if opChoice == 2 {
				operations[choice-1] = "(AVG)"
				calculations[choice-1] = Avg(rowSlice)
			} else if opChoice == 3 {
				operations[choice-1] = "(MIN)"
				calculations[choice-1] = Min(rowSlice)
			} else if opChoice == 4 {
				operations[choice-1] = "(MAX)"
				calculations[choice-1] = Max(rowSlice)
			} 
		case 3:
			for {
			fmt.Printf("[1] Clear All Rows")
			fmt.Printf("\n[2] Select Row To Clear")
			fmt.Printf("\nClear all rows or specific row? ")
			fmt.Scanln(&choice)
			if choice < 1 || choice > 2 {
				fmt.Printf("Not a valid selection. Enter again.\n")
			} else {
				break
			}
		}
			if choice == 1 {
				ClearRows(0, row1, calculations, operations)
				ClearRows(1, row2, calculations, operations)
				ClearRows(2, row3, calculations, operations)
				ClearRows(3, row4, calculations, operations)
				ClearRows(4, row5, calculations, operations)
			} else if choice == 2 {
				for {
				fmt.Printf("Which row would you like to clear? ")
				fmt.Scanln(&choice)
				if choice < 0 || choice > 5 {
					fmt.Printf("Not a valid selection. Enter again.\n")
				} else {
					break
				}
			}
				if choice == 1 {
					rowSlice = row1
				} else if choice == 2 {
					rowSlice = row2
				} else if choice == 3 {
					rowSlice = row3
				} else if choice == 4 {
					rowSlice = row4
				} else if choice == 5 {
					rowSlice = row5
				}
				ClearRows(choice-1, rowSlice, calculations, operations)
			}
		case 4:
			RandomFill(0, row1, calculations, operations)
			RandomFill(1, row2, calculations, operations)
			RandomFill(2, row3, calculations, operations)
			RandomFill(3, row4, calculations, operations)
			RandomFill(4, row5, calculations, operations)			
		case 5:
			fmt.Printf("\nGoodbye!\n")
			os.Exit(1)
		}
	}
}
