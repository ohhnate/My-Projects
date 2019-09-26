// Project1
//Item purchaser
// Programmer name: Samuel Fuller
// Date completed:  12 Sep 2019

#include "cinreader.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

#ifdef _WIN32
  #include <windows.h>
  void sleep(unsigned milliseconds){
        Sleep(milliseconds);
    }
#else
  #include <unistd.h>
  void sleep(unsigned milliseconds) {
    usleep(milliseconds * 1000); //* 1000 b/c unix usleep() takes microseconds
  }
#endif

using namespace std;

//Shop is the driver for when the program exits loop or not
struct Shop {
  bool running = true; 
};

//Item is an object of shops items
struct Item {
  string name;
  double price;
  unsigned int quantity;
  unsigned int amountInCart;
  bool addedToCart;
};

//Cart is users cart of items for purchase
struct Cart {
  vector<Item> item;
  double price;
};

//clearScreen refreshes the screen when called
void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

//fancyDelay simulates "typed text" of a given text and speed
void fancyDelay(string text, int duration) {
  for (char const &letter: text) {
      cout << letter;
      sleep(duration);
    }
}

//banner displays the program banner
void banner() {
  cout << "    _              _            _                      _          \n";
  cout << "   | |            ( )          | |                    | |         \n";
  cout << "    \\ \\   ____ ___|/  ___       \\ \\  ____   ____  ____| |  _  ___ \n";
  cout << "     \\ \\ / _  |    \\ /___)       \\ \\|  _ \\ / _  |/ ___) | / )/___)\n";
  cout << " _____) | ( | | | | |___ |   _____) ) | | ( ( | ( (___| |< (|___ |\n";
  cout << "(______/ \\_||_|_|_|_(___/   (______/|_| |_|\\_||_|\\____)_| \\_|___/ \n\n";
}

//commands displays list of commands below the banner 
void commands(string view) {
  if (view == "main") {
    cout << right << setw(56) << "|------------------------------------------------------|\n";
    cout << right << setw(56) << "| Type the below commands for the corresponding action |\n";
    cout << right << setw(56) << "|------------------------------------------------------|\n";
    cout << right << setw(35) << "| COMMAND LIST |\n";
    cout << right << setw(43) << "|-------------------------------|\n";
    cout << right << setw(43) << "| Type item name to select item |\n";
    cout << right << setw(43) << "| Type 'cart' to view your cart |\n";
    cout << right << setw(43) << "| Type 'exit' to leave the shop |\n";
    cout << right << setw(43) << "|-------------------------------|\n";
  } else if (view == "cart") {
    cout << right << setw(56) << "|------------------------------------------------------|\n";
    cout << right << setw(56) << "| Type the below commands for the corresponding action |\n";
    cout << right << setw(56) << "|------------------------------------------------------|\n";
    cout << right << setw(35) << "| COMMAND LIST |\n";
    cout << right << setw(43) << "|-------------------------------|\n";
    cout << right << setw(43) << "| 'back' to go to previous menu |\n";
    cout << right << setw(43) << "| 'checkout' to view your cart  |\n";
    cout << right << setw(43) << "| Type 'exit' to leave the shop |\n";
    cout << right << setw(43) << "|-------------------------------|\n";
  }
}

//menuStatic displays the static top portion of hte menu
void menuStatic() {
  cout << right << setw(47) << "|--------------------------------------|\n";
  cout << right << setw(12) << "| Item";
  cout << right << setw(17) << "Price";
  cout << right << setw(18) << "Amount |\n";
  cout << right << setw(47) << "|--------------------------------------|\n";
}

//menu displays each row of the menu with each item 
void menu(Item &i) {
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << right << setw(8) <<  "| ";
  cout << left << setw(17) << i.name; 
  cout << left << setw(16) << i.price; 
  cout << left << setw(4) << i.quantity;
  cout << setw(5) << "|";
  cout << setw(7);
  cout << "\n";
  cout << "|--------------------------------------|";
  cout << "\n";
}


//itemToString converts an item object to a string for menu/cart display
string itemToString(Item &i) {
  stringstream strout;
  strout.setf(ios::fixed);
  strout.setf(ios::showpoint);
  strout.precision(2);
  strout << right << setw(8) << "| " << left << setw(17) << i.name << setw(17) 
         << i.price << setw(3) << i.amountInCart << left << "|";
  return strout.str();
}

//initItem initializes shop items
void initItem(Item &i, string name, double price, unsigned int quantity, 
              unsigned int amountInCart, bool addedToCart) {
  i.name = name;
  i.price = price;
  i.quantity = quantity;
  i.amountInCart = amountInCart;
  i.addedToCart = addedToCart;
}

//showCart displays the users current cart with or without items
void showCart(Shop &shop, Cart &cart, string view, CinReader c) {
  string view2;
  if (view == "cart") {
    clearScreen();
    banner();
    commands(view);
    cout << setw(34) << "[ CART ITEMS ]\n";
    menuStatic();
    for (int i = 0; i < cart.item.size(); i++) {
    
      cout << itemToString(cart.item[i]);
      cout << "\n";
      cout << right << setw(47) << "|--------------------------------------|\n";
  
    }
    cout << "\n" << setw(34) << "[ CART ITEMS ]\n";
    cout << "\nInput a command: ";
    view2 = c.readString();
    transform(view.begin(), view.end(), view.begin(), ::tolower);
  } 
  if (view2 == "back") {
    
  } else if (view2 == "exit") {
    shop.running = false;
  } else if (view2 == "checkout") {
    
  } else {
    cout << "That is an invalid entry. Please enter again.";
    sleep(2000);
  }
}

//reduceQuantity reduces quantity of shop inventory when added to users cart
void reduceQuantity(Item &i, unsigned int amount) {
  if (amount >= i.quantity) {
    i.quantity = 0;
  }
  else {
    i.quantity = i.quantity - amount;
  }
}

//addToCartAmount asks user how many of each item should be added to cart
//and adds the corresponding amount
int addToCartAmount(Cart &cart, Item &item, CinReader c) {
  int itemAmount;
  cout << "How many would you like to purchase: ";
  itemAmount = c.readInt(0, item.quantity);
  for (int i = 0; i < cart.item.size(); i++) {
    if (cart.item[i].name == item.name) {
      cart.item[i].amountInCart += itemAmount;
    }
  }
  return itemAmount;
}


//addToCartItem adds users selected item to users cart or provides error
void addToCartItem(Cart &cart, Item &cake, Item &fruit, Item &chips, Item &soda, 
                   Item &juice, string &item, CinReader c) {
  int itemAmount;
  if (item == "cake"){
    if (cake.addedToCart == false) {
      cart.item.push_back(cake);
      cart.price = cart.price + cake.price;
      itemAmount = addToCartAmount(cart, cake, c);
      reduceQuantity(cake, itemAmount);
      cout << "Added " << cake.name << " to your cart.";
      cake.addedToCart = true;
    } else {
      itemAmount = addToCartAmount(cart, cake, c);
      reduceQuantity(cake, itemAmount);
      cout << "Added " << itemAmount << cake.name << " to your cart.";
    }  
  } else if (item == "fruit"){
      if (fruit.addedToCart == false) {
        cart.item.push_back(fruit);
        cart.price = cart.price + fruit.price;
        itemAmount = addToCartAmount(cart, fruit, c);
        reduceQuantity(fruit, itemAmount);
        cout << "Added " << fruit.name << " to your cart.";
        fruit.addedToCart = true;
      } else {
        itemAmount = addToCartAmount(cart, fruit, c);
        reduceQuantity(fruit, itemAmount);
        cout << "Added " << itemAmount << fruit.name << " to your cart.";
      }
  } else if (item == "chips"){
      if (chips.addedToCart == false) {
        cart.item.push_back(chips);
        cart.price = cart.price + chips.price;
        itemAmount = addToCartAmount(cart, chips, c);
        reduceQuantity(chips,itemAmount);
        cout << "Added " << chips.name << " to your cart.";
        chips.addedToCart = true;
      } else {
        itemAmount = addToCartAmount(cart, chips, c);
        reduceQuantity(chips, itemAmount);
        cout << "Added " << itemAmount << chips.name << " to your cart.";
      }
  } else if (item == "soda"){
      if (soda.addedToCart == false) {
        cart.item.push_back(soda);
        cart.price = cart.price + soda.price;
        itemAmount = addToCartAmount(cart, soda, c);
        reduceQuantity(soda, itemAmount);
        cout << "Added " << soda.name << " to your cart.";
        soda.addedToCart = true;
      } else {
        itemAmount = addToCartAmount(cart, soda, c);
        reduceQuantity(soda, itemAmount);
        cout << "Added " << itemAmount << soda.name << " to your cart.";
      }
  } else if (item == "juice"){
      if (juice.addedToCart == false) {
        cart.item.push_back(juice);
        cart.price = cart.price + juice.price;
        itemAmount = addToCartAmount(cart, juice, c);
        reduceQuantity(juice, itemAmount);
        cout << "Added " << juice.name << " to your cart.";
        juice.addedToCart = true;
      } else {
        itemAmount = addToCartAmount(cart, juice, c);
        reduceQuantity(juice, itemAmount);
        cout << "Added " << itemAmount << juice.name << " to your cart.";
      }
  }
}

//quantityCheck checks if an item can be purchased based on inventory
bool quantityCheck(Cart &cart, Item &cake, Item &fruit, Item &chips, Item &soda, 
                   Item &juice, string item, CinReader c) {
  if (item == "cake") {
    if (cake.quantity < 1){
      cout << "Sorry there aren't any left choose again or proceed to checkout.";
      return false;
    }
  } else if (item == "fruit") {
      if (fruit.quantity < 1){
        cout << "Sorry there aren't any left choose again or proceed to checkout.";
        return false;
    }
  } else if (item == "chips") {
      if (chips.quantity < 1){
        cout << "Sorry there aren't any left choose again or proceed to checkout.";
        return false;
    }
  } else if (item == "soda") {
      if (soda.quantity < 1){
        cout << "Sorry there aren't any left choose again or proceed to checkout.";
        return false;
    }
  } else if (item == "juice") {
      if (juice.quantity < 1){
        cout << "Sorry there aren't any left choose again or proceed to checkout.";
        return false;
    }
  }
  return true;
}

//selectItem asks user to select an item for purchase, this is sort of the
//primary program driver and includes recursive call for loop
void selectItem(Shop &shop, Cart &cart, Item &cake, Item &fruit, Item &chips, 
               Item &soda, Item &juice, CinReader c) {
  string itemChoice;
  cout << "\nInput a command: ";
  itemChoice = c.readString();
  transform(itemChoice.begin(), itemChoice.end(), itemChoice.begin(), ::tolower);
  
  if (itemChoice == "cake" || itemChoice == "fruit" || itemChoice == "chips"
  || itemChoice == "soda" || itemChoice == "juice"){
    if (quantityCheck(cart, cake, fruit, chips, soda, juice, itemChoice, c) == true){
      addToCartItem(cart, cake, fruit, chips, soda, juice, itemChoice, c); 
    } else {
      selectItem(shop, cart, cake, fruit, chips, soda, juice, c);
    }
  } else if (itemChoice == "cart") {
    showCart(shop, cart, itemChoice, c);
  } else if (itemChoice == "exit") {
    shop.running = false;
  } else {
    cout << "That is an invalid selection please choose again.";
    selectItem(shop, cart, cake, fruit, chips, soda, juice, c);
  }
}

main(){
  clearScreen();
  CinReader cinreader;
  
  Shop shop;
  
  Item cake;
  Item fruit;
  Item chips;
  Item soda;
  Item juice;
  Cart cart;
  initItem(cake, "Cake", 3.00, 5, 0, false);
  initItem(fruit, "Fruit", 4.20, 15, 0, false);
  initItem(chips, "Chips", 1.00, 6, 0, false);
  initItem(soda, "Soda", 1.50, 7, 0, false);
  initItem(juice, "Juice", 1.90, 10, 0, false);
  
  double money = 10.00;
  while(shop.running == true){
    clearScreen();
    banner();
    commands("main");
    menuStatic();
    menu(cake);
    menu(fruit);
    menu(chips);
    menu(soda);
    menu(juice);
    selectItem(shop, cart, cake, fruit, chips, soda, juice, cinreader);
    
    
  }
  fancyDelay("\n\nGoodbye...", 150);
  clearScreen();
  exit(0);
  return 0;
}
