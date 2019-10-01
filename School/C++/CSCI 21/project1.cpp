// Project1
//Item purchaser
// Programmer name: Samuel Fuller
// Last modified:  25 Sep 2019

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
  void clearScreen() {
    system("cls");
  }
#else
  #include <unistd.h>
  void sleep(unsigned milliseconds) {
    usleep(milliseconds * 1000); //* 1000 b/c unix usleep() takes microseconds
  }
  void clearScreen() {
    system("clear");
  }
#endif

using namespace std;

CinReader c;

//Shop is the driver for when the program exits loop or not
struct Shop {
  bool running = true;
};

//Item is an object of items created for the machine
struct Item {
  string name;
  double price;
  int quantity;
  int amountInCart;
  bool addedToCart;
};

//Cart is users cart of items for purchase
struct Cart {
  vector<Item> item;
  double price;
  int amountInCart;
};

//Machine contains list of items the machine offers
struct Machine {
  vector<Item> menu;
};

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

//menu displays menu and format below the banner
void menu(string view) {
  cout << right << setw(56) << "|------------------------------------------------------|\n";
  cout << right << setw(56) << "| Type the below commands for the corresponding action |\n";
  cout << right << setw(56) << "|------------------------------------------------------|\n";
  cout << right << setw(35) << "[ COMMAND LIST ]\n";
  if (view == "main") {
    cout << right << setw(43) << "|-------------------------------|\n";
    cout << right << setw(43) << "| Type item name to select item |\n";
    cout << right << setw(43) << "| Type 'cart' to view your cart |\n";
    cout << right << setw(43) << "| Type 'exit' to leave the shop |\n";
    cout << right << setw(43) << "|-------------------------------|\n";
    cout << setw(34) << "[ SHOP ITEMS ]\n";
    cout << right << setw(47) << "|--------------------------------------|\n";
    cout << right << setw(12) << "| Item";
    cout << right << setw(17) << "Price";
    cout << right << setw(18) << "Stock  |\n";
    cout << right << setw(47) << "|--------------------------------------|\n";
  } else if (view == "cart") {
    cout << right << setw(43) << "|-------------------------------|\n";
    cout << right << setw(43) << "| 'back' to go to previous menu |\n";
    cout << right << setw(43) << "| 'checkout' to pay for items   |\n";
    cout << right << setw(43) << "| Type 'exit' to leave the shop |\n";
    cout << right << setw(43) << "|-------------------------------|\n";
    cout << setw(37) << "[ YOUR CART ITEMS ]\n";
    cout << right << setw(47) << "|--------------------------------------|\n";
    cout << right << setw(12) << "| Item";
    cout << right << setw(17) << "Price";
    cout << right << setw(18) << "Amount |\n";
    cout << right << setw(47) << "|--------------------------------------|\n";
  }
}

//menuRow displays each row of the menu with each item
void menuRow(Machine &machine) {
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  for (Item i : machine.menu) {
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

//stringToItem converts a string into item equivalent
Item stringToItem(string item, Machine machine) {
  Item empty;
  for (Item i : machine.menu) {
    if (item == i.name) {
      return i;
    }
  }
  return empty;
}

//initItem initializes shop items
void initItem(Item &item, string name, double price, int quantity,
              int amountInCart, bool addedToCart) {
  item.name = name;
  item.price = price;
  item.quantity = quantity;
  item.amountInCart = amountInCart;
  item.addedToCart = addedToCart;
}

void increaseQuantity(Machine &machine, Item &item, int amount) {
  for (Item &i : machine.menu) {
    if (item.name == i.name) {
      item.quantity = item.quantity + amount;
      i.quantity = i.quantity + amount;
    } 
  }
}

void removeItem(Machine &machine, Cart &cart) {
  int index = 0;
  string removeItem;
  Item item;
  int removeAmount = 0;
  
  cout << "Which item would you like to remove?";
  removeItem = c.readString();
  transform(removeItem.begin(), removeItem.end(), removeItem.begin(), ::tolower);
  
  item = stringToItem(removeItem, machine);
  
  for (Item &i : cart.item) {
    index ++;
    if (item.name == i.name) {
      if (i.amountInCart >= 1) {  
        cout << "How many would you like to remove?";
        removeAmount = c.readInt(1, i.amountInCart); 
        if (i.amountInCart == removeAmount) {
          cart.price = cart.price - (i.price * removeAmount);
          cart.amountInCart = cart.amountInCart - removeAmount;
          i.amountInCart = i.amountInCart - removeAmount;
          i.addedToCart == false;
          cart.item.erase(cart.item.begin() + index - 1);
        } else if (i.amountInCart > removeAmount) {
          cart.price = cart.price - (i.price * removeAmount);
          cart.amountInCart = cart.amountInCart - removeAmount;
          i.amountInCart = i.amountInCart - removeAmount;
          i.addedToCart == false;
       }
      } else {
        cout << "That item isn't in the cart to remove. :(";
        sleep(1500);
      }
      increaseQuantity(machine, i, removeAmount);    
    }
  }
  for (Item &j : machine.menu) {
    if (item.name == j.name) {
      j.addedToCart == false;
    } 
  }
}

//showCart displays the users current cart with or without items
void showCart(Shop &shop, Machine machine, Cart &cart, string view) {
  // calculateCart(cart);
  string view2;
  if (view == "cart") {
    clearScreen();
    banner();
    menu(view);
    for (int i = 0; i < cart.item.size(); i++) {
      cout << itemToString(cart.item[i]);
      cout << "\n";
      cout << right << setw(47) << "|--------------------------------------|\n";
    }
    cout << right << setw(7) <<  "|";
    cout << left << setw(17) << " Total: ";
    cout << left << "$" << left << setw(17) << cart.price;
    cout << left << setw(3) << cart.amountInCart;
    cout << left << "|\n";
    // cout << right << setw(16) << "| Total: $" << cart.price << "\n";
    cout << right << setw(47) << "|--------------------------------------|\n";
    cout << "\nInput a command: ";
    view2 = c.readString();
    transform(view.begin(), view.end(), view.begin(), ::tolower);
  }
  if (view2 == "back") {
  } else if (view2 == "remove") {
    removeItem(machine, cart);
  } else if (view2 == "exit") {
    shop.running = false;
  } else if (view2 == "checkout") {
  } else {
    cout << "That is an invalid entry. Please enter again.";
    sleep(1500);
  }
}

//reduceQuantity reduces quantity of shop inventory when added to users cart
void reduceQuantity(Machine &machine, Item &item, int amount) {
  for (Item &i : machine.menu) {
    if (item.name == i.name) {
      if (amount >= i.quantity) {
        i.quantity = 0;
        item.quantity = 0;
      } else {
        item.quantity = item.quantity - amount;
        i.quantity = i.quantity - amount;
      }
    }
  }
}

//addToCartAmount asks user how many of each item should be added to cart
//and adds the corresponding amount
int addToCartAmount(Cart &cart, Item &item) {
  int itemAmount;
  cout << "How many would you like to purchase: ";
  itemAmount = c.readInt(0, item.quantity);
  for (int i = 0; i < cart.item.size(); i++) {
    if (cart.item[i].name == item.name) {
      cart.item[i].amountInCart += itemAmount;
    }
  }
  cart.amountInCart += itemAmount;
  item.amountInCart += itemAmount;
  cart.price = cart.price + (item.price * itemAmount);
  return itemAmount;
}

//addToCartItem adds slected item to the cart and updates menu/cart values
void addToCartItem(Machine &machine, Cart &cart, Item &item) {
  int itemAmount;
  for (Item &i : machine.menu) {
    if (item.name == i.name) {
      if (i.addedToCart == false) {
        cart.item.push_back(item);
        itemAmount = addToCartAmount(cart, item);
        if (itemAmount > 0) {
          reduceQuantity(machine, item, itemAmount);
          cout << "Added " << itemAmount << " " << item.name << " to your cart.";
          i.addedToCart = true;
          sleep(1000);
        } else {
          cout << "Nothing has been added :(";
          sleep(1000);
        }
      } else {
        itemAmount = addToCartAmount(cart, item);
          if (itemAmount > 0) {
            reduceQuantity(machine, item, itemAmount);
            cout << "Added another " << itemAmount << " " << item.name << " to your cart.";
            sleep(1000);
        } else {
          cout << "Nothing has been added :(";
          sleep(1000);
        }
      }
    }
  }
}

//quantityCheck checks if an item can be purchased based on inventory
bool quantityCheck(Machine &machine, Item &item) {
  for (Item i : machine.menu) {
    if (i.name == item.name) {
      if (item.quantity < 1) {
        cout << "Sorry there aren't any left choose again or proceed to checkout.";
        return false;
      }
    }
  }
  return true;
}

//selectItem asks user to select an item for purchase, this is sort of the
//primary program driver and includes recursive call for loop
void selectItem(Shop &shop, Machine &machine, Cart &cart) {
  string itemChoice;
  Item item;
  cout << "\nInput a command: ";
  itemChoice = c.readString();
//transform to iterate over the string 'itemChoice' to change each character
//to lowercase for multiple input variations
  transform(itemChoice.begin(), itemChoice.end(), itemChoice.begin(), ::tolower);
  
  item = stringToItem(itemChoice, machine);
  
  if (itemChoice == "cake" || itemChoice == "fruit" || itemChoice == "chips"
  || itemChoice == "soda" || itemChoice == "juice") {
    for (Item &i : machine.menu) {
      if (item.name == i.name) {
        if (quantityCheck(machine, item)) {
          addToCartItem(machine, cart, item);
        } else {
          selectItem(shop, machine, cart);
          }
        } 
      }
    } else if (itemChoice == "cart") {
      showCart(shop, machine, cart, itemChoice);
    } else if (itemChoice == "exit") {
      shop.running = false;
    } else {
      cout << "That is an invalid selection please choose again.";
      selectItem(shop, machine, cart);
  }
}

main(){
  clearScreen();
  Shop shop;
  Item cake;
  Item fruit;
  Item chips;
  Item soda;
  Item juice;
  Cart cart;
  initItem(cake, "cake", 3.00, 5, 0, false);
  initItem(fruit, "fruit", 4.20, 15, 0, false);
  initItem(chips, "chips", 1.00, 6, 0, false);
  initItem(soda, "soda", 1.50, 7, 0, false);
  initItem(juice, "juice", 1.90, 10, 0, false);

  Machine machine;
  machine.menu.push_back(cake);
  machine.menu.push_back(fruit);
  machine.menu.push_back(chips);
  machine.menu.push_back(soda);
  machine.menu.push_back(juice);

  double money = 10.00;
  while(shop.running == true){
    clearScreen();
    banner();
    menu("main");
    menuRow(machine);
    selectItem(shop, machine, cart);
  }
  cout << "\n\n";
  fancyDelay("Goodbye...", 150);
  clearScreen();
  exit(0);
  return 0;
}
