// Lab 4 -- C++ (re)fresher, pt 4
//
// Programmer name: Samuel Fuller
// Date completed:  12 Sep 2019

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <string>
using namespace std;

struct Item {
  string name;
  double price;
  unsigned int quantity;
};

// Initialize an Item with values for its fields.
void initItem(Item &i, string name, double price, unsigned int quantity) {
  i.name = name;
  i.price = price;
  i.quantity = quantity;
}

// Compute the total value of an item (price * quantity)
double totalValue(const Item &i) {
  return i.price * i.quantity;
}

// Reduce the quantity of an Item.
// If amount > Item.quantity, set Item.quantity to 0.
void reduceQuantity(Item &i, unsigned int amount) {
  if (amount >= i.quantity) {
    i.quantity = 0;
  }
  else {
    i.quantity = i.quantity - amount;
  }
}

// Increase the quantity of an Item.
void increaseQuantity(Item &i, unsigned int amount) {
  i.quantity = i.quantity + amount;
}

// Example: "Apples (price: $0.99, quantity: 3)"
// Use the "magic formula" to format the price.
string toString(const Item &i) {
  string total
  cout << i.name + " (price: " + to_string(i.price) +", quantity: " + to_string(i.quantity) + ")" << endl;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  return total;
}

/*
 * Unit test.
 */

TEST_CASE("struct and helper functions") {
  //Item initialization
  Item cake;
  Item chips;
  Item soda;
  Item juice;
  initItem(cake, "Cake", 3.00, 5);
  initItem(chips, "Chips", 1.00, 6);
  initItem(soda, "Soda", 1.50, 7);
  initItem(juice, "Juice", 1.90, 8);
  
  //initial total value checks
  CHECK(totalValue(cake) == 15.00);
  CHECK(totalValue(chips) == 6.00);
  CHECK(totalValue(soda) == 10.50);
  CHECK(totalValue(juice) == 15.20);
  
  //reduce quantity checks
  reduceQuantity(cake, 3);
  reduceQuantity(chips, 6);
  reduceQuantity(soda, 10);
  reduceQuantity(juice, 0);
  CHECK(cake.quantity == 2);
  CHECK(chips.quantity == 0);
  CHECK(soda.quantity == 0);
  CHECK(juice.quantity == 8);
  
  //increase quantity checks
  increaseQuantity(cake, 10);
  increaseQuantity(chips, 100);
  increaseQuantity(soda, 1);
  increaseQuantity(juice, 0);
  CHECK(cake.quantity == 12);
  CHECK(chips.quantity == 100);
  CHECK(soda.quantity == 1);
  CHECK(juice.quantity == 8);
  
  //toString checks
  CHECK(toString(cake) == "Cake (price: 3.00, quantity: 12)");
  CHECK(toString(chips) == "Chips (price: 1.00, quantity: 100)");
  CHECK(toString(soda) == "Soda (price: 1.50, quantity: 1)");
  CHECK(toString(juice) == "Juice (price: 1.90, quantity: 8)");
}
