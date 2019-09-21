// Lab 6 -- functions, pt 2
//
// Programmer name: Samuel Fuller
// Date completed: 16 Feb 2019

package main

// MilesPerGallon computes and returns gas mileage.
func MilesPerGallon(milesDriven, gallonsUsed float64) float64 {
	MPG := milesDriven / gallonsUsed
	return MPG
}

// TotalWithTip computes and returns a check total including a tip.
// Gratuity is expected to be a value between 0 and 100%.
func TotalWithTip(total, gratuity float64) float64 {
	final := total*(gratuity*0.01) + total
	return final
}

// MaxCanPurchase computes and returns the maximum (whole) number of
// an item that can be purchased with a given amount of money at a
// given price per item.
func MaxCanPurchase(amountOfMoney, pricePerItem float64) int {
	var purchase = int(amountOfMoney / pricePerItem)
	return purchase
}

// ConvertToCelsius converts a Fahrenheit temperature to Celsius
// and returns the Celsius value.
func ConvertToCelsius(fahrenheit float64) float64 {
	fConverted := (fahrenheit - 32) / 1.8
	return fConverted
}

// ConvertToFahrenheit converts a Celsius temperature to Fahrenheit
// and returns the Fahrenheit value.
func ConvertToFahrenheit(celsius float64) float64 {
	cConverted := (celsius * 1.8) + 32
	return cConverted
}

func main() {
}
