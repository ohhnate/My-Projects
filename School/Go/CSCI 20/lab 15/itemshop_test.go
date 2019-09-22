package main

import (
	"testing"
)

func makeItem() *Item {
	return NewItem("apple", 0.58, 10)
}

func TestNewItem(t *testing.T) {
	i := makeItem()
	if i.Name != "apple" {
		t.Error("Expected apple, got ", i.Name)
	}
	if i.Price != 0.58 {
		t.Error("Expected 0.58, got ", i.Price)
	}
	if i.InStock != 10 {
		t.Error("Expected 10, got ", i.InStock)
	}
}

func TestSoldOut(t *testing.T) {
	i := makeItem()
	if i.SoldOut() == true {
		t.Error("Expected false, got ", i.SoldOut())
	}
}

func TestAdjustStock(t *testing.T) {
	i := makeItem()
	i.AdjustStock(-9)
	if i.InStock != 1 {
		t.Error("Expected 1, got ", i.InStock)
	}
	i.AdjustStock(-1)
	if i.InStock != 0 {
		t.Error("Expected 0, got ", i.InStock)
	}
	i.AdjustStock(1)
	if i.InStock != 1 {
		t.Error("Expected 1, got ", i.InStock)
	}
	i.AdjustStock(-2)
	if i.InStock != 0 {
		t.Error("Expected 0, got ", i.InStock)
	}
}

func TestChangePrice(t *testing.T) {
	i := makeItem()
	i.ChangePrice(1.99)
	if i.Price != 1.99 {
		t.Error("Expected 1.99, got ", i.Price)
	}
}

func TestToString(t *testing.T) {
	i := makeItem()
	iStr := i.ToString()
	expStr := "apple, $0.58, 10 in stock"
	if iStr != expStr {
		t.Errorf("Expected %s, got %s", expStr, iStr)
	}
}
