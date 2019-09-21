package main

import (
	"bufio"
	"os"
	"testing"
)

func loadFile(t *testing.T, path string) []string {
	file, err := os.Open(path)
	if err != nil {
		t.Fatal(err)
	}
	defer file.Close()

	var lines []string
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return lines
}

func TestReadFile(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	if len(fruits) != 90 {
		t.Error("Expected 90 strings, got ", len(fruits))
	}
}

func TestStringsOfLength(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	results := StringsOfLength(fruits, 10)
	if len(results) != 17 {
		t.Error("Expected 17 results, got ", len(results))
	}
}

func TestStringsLongerThan(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	results := StringsLongerThan(fruits, 10)
	if len(results) != 8 {
		t.Error("Expected 8 results, got ", len(results))
	}
}

func TestStringsShorterThan(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	results := StringsShorterThan(fruits, 10)
	if len(results) != 65 {
		t.Error("Expected 65 results, got ", len(results))
	}
}

func TestStringsBeginningWith(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	results := StringsBeginningWith(fruits, "S")
	if len(results) != 10 {
		t.Error("Expected 10 results, got ", len(results))
	}
	results = StringsBeginningWith(fruits, "Ki")
	if len(results) != 3 {
		t.Error("Expected 3 results, got ", len(results))
	}
}

func TestContainsString(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	result := ContainsString(fruits, "apple")
	if result != true {
		t.Error("Expected true, got ", result)
	}
	result = ContainsString(fruits, "shoe")
	if result != false {
		t.Error("Expected false, got ", result)
	}
}

func TestGetUnique(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	results := GetUnique(fruits)
	if len(results) != 51 {
		t.Error("Expected 51 results, got ", len(results))
	}
}

func TestLengthOfShortest(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	shortest := LengthOfShortest(fruits)
	if shortest != 4 {
		t.Error("Expected length 4, got ", shortest)
	}
}

func TestLengthOfLongest(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	longest := LengthOfLongest(fruits)
	if longest != 12 {
		t.Error("Expected length 12, got ", longest)
	}
}

func TestListOfShortest(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	results := ListOfShortest(fruits)
	if len(results) != 7 {
		t.Error("Expected 7 results, got ", len(results))
	}
}

func TestListOfLongest(t *testing.T) {
	fruits := loadFile(t, "fruits.txt")
	results := ListOfLongest(fruits)
	if len(results) != 2 {
		t.Error("Expected 2 results, got ", len(results))
	}
}
