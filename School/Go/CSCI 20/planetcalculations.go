// Lab 14 -- structs
//
// Programmer name: Samuel Fuller
// Date completed:  27 April 2019

package main

import "fmt"

// For use in the CalculateWeight function.
const earthGravity = 32.1

// Planet represents a planet in our solar system.
type Planet struct {
	// Add fields Name (string), Gravity (float64), MeanTemperature (float64),
	// NumberOfMoons (int)
		name string
		gravity float64
		meanTemperature float64
		numberOfMoons int
}

// Describe accepts a planet and "pretty prints" the name, mean temperature,
// and number of moons for the planet.
// (EXAMPLE: "Mars: mean temperate -85.0F, 2 moons")
func (p Planet) Describe() {
	fmt.Printf("%s: mean temp= %.2f degrees, with %d moons.\n", p.name, p.meanTemperature, p.numberOfMoons)
}

// MostMoons accepts a slice of planets. Computes and displays the planet
// with the largest number of moons.
func MostMoons(planets []Planet) {
	largest := planets[0].numberOfMoons
	mostP := planets[0].name
	for i := range planets {
		if planets[i].numberOfMoons >= largest {
			largest = planets[i].numberOfMoons
			mostP = planets[i].name
		}
	}
	fmt.Printf("Most Moons: %s", mostP)
}

// ColdestPlanet accepts a slice of planets. Computes and displays the planet
// that is the coldest.
func ColdestPlanet(planets []Planet) {
	coldest := planets[0].meanTemperature
	coldestP := planets[0].name
	for i := range planets {
		if planets[i].meanTemperature <= coldest {
			coldest = planets[i].meanTemperature
			coldestP = planets[i].name
		}
	}
	fmt.Printf("Coldest Planet: %s", coldestP)
}

// HottestPlanet accepts a slice of planets. Computes and displays the planet
// that is the hottest.
func HottestPlanet(planets []Planet) {
	hottest := planets[0].meanTemperature
	hottestP := planets[0].name
	for i := range planets {
		if planets[i].meanTemperature >= hottest {
			hottest = planets[i].meanTemperature
			hottestP = planets[i].name
		}
	}
	fmt.Printf("Hottest Planet: %s", hottestP)
}

// CalculateWeight accepts a planet and a person's weight on Earth.
// Computes and returns the person's weight on the given planet.
// weightOnOtherPlanet = weightOnEarth * (planetGravity / earthGravity)
func CalculateWeight(p Planet, earthWeight float64) float64 {
	weightOnOtherPlanet := 0.0
	weightOnOtherPlanet = earthWeight *(p.gravity / earthGravity)
	return weightOnOtherPlanet
}

// LeastWeight accepts a slice of planets and a person's weight on Earth.
// Computes and displays the planet on which the person would weigh the least.
// (HINT: use CalculateWeight as a helper)
func LeastWeight(planets []Planet, earthWeight float64) {
	leastName := planets[0].name
	leastWeight := CalculateWeight(planets[0], earthWeight)
	for i := range planets {
		if CalculateWeight(planets[i], earthWeight) < leastWeight {
			leastWeight = CalculateWeight(planets[i], earthWeight)
			leastName = planets[i].name
		}
	}
	fmt.Printf("You would weigh the least on: %s, weighing a total of: %.2f lbs", leastName, leastWeight)
}

// MostWeight accepts a slice of planets and a person's weight on Earth.
// Computes and displays the planet on which the person would weigh the most.
// (HINT: use CalculateWeight as a helper)
func MostWeight(planets []Planet, earthWeight float64) {
	mostName := planets[0].name
	mostWeight := CalculateWeight(planets[0], earthWeight)
	for i := range planets {
		if CalculateWeight(planets[i], earthWeight) > mostWeight {
			mostWeight = CalculateWeight(planets[i], earthWeight)
			mostName = planets[i].name
		}
	}
	fmt.Printf("You would weigh the most on: %s, weighing a total of: %.2f lbs", mostName, mostWeight)
}

func main() {
	// Create a slice of Planets containing data for Mercury, Venus, Mars, Jupiter, 
	// Saturn, Uranus, Neptune, Pluto
	// Data source: https://nssdc.gsfc.nasa.gov/planetary/factsheet/planet_table_british.html
	planets := make([]Planet, 8) 
	planets[0] = Planet{name: "Mercury", gravity: 12.1, meanTemperature: 333, numberOfMoons: 0} 
	planets[1] = Planet{name: "Venus", gravity: 29.1, meanTemperature: 867, numberOfMoons: 0}
	planets[2] = Planet{name: "Mars", gravity: 12.1, meanTemperature: -85, numberOfMoons: 2}
	planets[3] = Planet{name: "Jupiter", gravity: 75.9, meanTemperature: -166, numberOfMoons: 79}
	planets[4] = Planet{name: "Saturn", gravity: 29.4, meanTemperature: -220, numberOfMoons: 62}
	planets[5] = Planet{name: "Uranus", gravity: 28.5, meanTemperature: -320, numberOfMoons: 27}
	planets[6] = Planet{name: "Neptune", gravity: 36, meanTemperature: -330, numberOfMoons: 14}
	planets[7] = Planet{name: "Pluto", gravity: 2.3, meanTemperature: -375, numberOfMoons: 5}

	// Use a "range" loop to Describe each of the planets
	for _, p := range planets {
		p.Describe()
	}

	fmt.Printf("\n")
	// call HottestPlanet -- pass planets
	HottestPlanet(planets)

	fmt.Printf("\n")
	// call ColdestPlanet -- pass planets
	ColdestPlanet(planets)

	fmt.Printf("\n")
	// call MostMoons -- pass planets
	MostMoons(planets)

	fmt.Printf("\n")
	// prompt for and read in a person's weight in lbs
	var weight float64
	fmt.Printf("How much do you weigh? ")
	fmt.Scanln(&weight)

	fmt.Printf("\n")
	// call LeastWeight -- pass planets and person's weight
	LeastWeight(planets, weight)

	fmt.Printf("\n")
	// call MostWeight -- pass planets and person's weight
	MostWeight(planets, weight)
}
