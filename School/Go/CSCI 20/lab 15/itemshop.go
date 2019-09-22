// Lab 15 -- structs/pointers/methods
//
// Programmer name: Samuel Fuller
// Date completed:  __________

package main

import "fmt"

// Item represents an item being sold in a store.
type Item struct {
	// Add Name (string), Price (float64), and InStock (int) fields
	Name string
	Price float64
	InStock int
}

// NewItem creates an Item with its Name, Price, and InStock
// properties initialized with the given parameters.
func NewItem(name string, price float64, inStock int) *Item {
	var item Item
	item = Item{Name: name, Price: price, InStock: inStock}
	return &item
}

// SoldOut returns true if the item has 0 left in stock. Otherwise
// returns false.
func (i *Item) SoldOut() bool {
	if i.InStock == 0 {
		return true
	}
	return false
}

// AdjustStock adjusts the stock by the given quantity (can be positive
// or negative). Does not allow the item's in stock value to go below 0.
func (i *Item) AdjustStock(amount int) {
	var stock int
	stock = i.InStock + amount
	if stock < 0 {
		i.InStock = 0 
	} else {
		i.InStock = stock 
	}
}

// ChangePrice changes an item's price to the given value. If the given
// value is negative, the item's price remains unchanged.
func (i *Item) ChangePrice(price float64) {
	if price < 0 {
		i.Price = i.Price
	} else {
		i.Price = price
	}
}

// ToString returns a string representation of an item.
// Example: "apple, $0.58, 10 in stock" (no newline)
func (i *Item) ToString() string {
	stringN := i.Name
	stringP := fmt.Sprintf("%.2f", i.Price)
	stringI := fmt.Sprintf("%d", i.InStock)
	stringS := stringN+", $"+stringP+", "+stringI+" in stock"
	return stringS
}

func main() {
}
