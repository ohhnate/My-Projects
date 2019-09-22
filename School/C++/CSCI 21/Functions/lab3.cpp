// Lab 3 -- C++ (re)fresher, functions and testing
//
// Programmer name: Samuel Fuller
// Date completed:  5 Sep 2019

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
using std::string;

// COMPLETE EACH OF THE FOLLOWING FUNCTIONS

// Return a greeting: "Nice to meet you, NAME."
// If name param is empty string, return "Nice to meet you."
string greet(string name) {
  string greeting;
  if (name == "") {
    greeting = "Nice to meet you.";
  } else {
    greeting = "Nice to meet you " + name + ".";
  }
  return greeting;
}

// Return true if denominator is a factor of numerator.
// Return false otherwise.
bool isFactor(int numerator, int denominator) {
  bool factor = false;
  if (numerator % denominator == 0) {
    factor = true;
  } else {
    factor = false;
  }
  return factor;
}

// Given an initial value, compute how many quarters, dimes, nickels, and
// pennies would be given as change.
void makeChange(unsigned int initialValue, unsigned int &quarters,
                unsigned int &dimes, unsigned int &nickels,
                unsigned int &pennies) {

// Convert a Celsius temperature to a Fahrenheit temperature.
double celsiusToFahrenheit(double celsiusTemp) {
  double fahrenheit = 0.0;
  fahrenheit = (celsiusTemp * 1.8) + 32;
  return fahrenheit;
}

// Convert a Fahrenheit temperature to a Celsius temperature.
double fahrenheitToCelsius(double fahrenheitTemp) {
  double celsius = 0.0;
  celsius = (fahrenheitTemp - 32) / 1.8;
  return celsius;
}

/*
 * Unit test.
 */

TEST_CASE("Function implementations") {
  //Greet
  CHECK(greet("John") == "Nice to meet you John.");
  CHECK(greet("") == "Nice to meet you.");
  
  //Factors
  CHECK(isFactor(12, 2) == true);
  CHECK(isFactor(19, 5) == false);
  
  //change
  // CHECK(makeChange(41, 25, 10, 5, 1) == "You have 1 quarters, 1 dimes, 1 nickels, and 1 pennies.");
  // REQUIRE(makeChange(99, 25, 10, 5, 1));
  
  //convert to fahrenheit
  CHECK(celsiusToFahrenheit(30) == 86);
  CHECK(celsiusToFahrenheit(1) == 33.8);
  
  //convert to celsius
  CHECK(fahrenheitToCelsius(32) == 0);
  CHECK(fahrenheitToCelsius(212) == 100);
}
