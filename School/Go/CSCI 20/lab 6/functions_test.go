package main

import (
	"math"
	"testing"
)

func TestMilesPerGallon(t *testing.T) {
	mileage := MilesPerGallon(350.0, 15.0)
	roundedMileage := math.Floor(mileage*100) / 100
	if roundedMileage != 23.33 {
		t.Error("Expected 23.33, got ", roundedMileage)
	}
}

func TestTotalWithTip(t *testing.T) {
	total := TotalWithTip(25.00, 15.00)
	if total != 28.75 {
		t.Error("Expected 28.75, got ", total)
	}
}

func TestConvertToFahrenheit(t *testing.T) {
	var freezing, boiling float64

	freezing = ConvertToFahrenheit(0.0)
	if freezing != 32.0 {
		t.Error("[C2F Freezing] expected 32.0, got ", freezing)
	}

	boiling = ConvertToFahrenheit(100.0)
	if boiling != 212.0 {
		t.Error("[C2F Boiling] expected 212.0, got ", freezing)
	}
}

func TestConvertToCelsius(t *testing.T) {
	var freezing, boiling float64

	freezing = ConvertToCelsius(32.0)
	if freezing != 0.0 {
		t.Error("[F2C Freezing] expected 0.0, got ", freezing)
	}

	boiling = ConvertToCelsius(212.0)
	if boiling != 100.0 {
		t.Error("[F2C Boiling] expected 100.0, got ", freezing)
	}
}

func TestMaxCanPurchase(t *testing.T) {
	var max int

	max = MaxCanPurchase(20, 1.90)

	if max != 10 {
		t.Error("Expected 10, got ", max)
	}
}
