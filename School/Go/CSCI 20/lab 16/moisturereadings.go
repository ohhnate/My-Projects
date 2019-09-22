// Lab 16 -- structs/pointers/methods
//
// Programmer name: __________
// Date completed:  __________

package main

import (
	"fmt"
	"math/rand"
	"time"
	"./sensor"
)

const (
	maxMoistureChange float64 = 5.0
	minMoistureChange float64 = 1.0
)

func simulateMoistureReading(ps *sensor.PlantSensor) {
	change := minMoistureChange + rand.Float64()*(maxMoistureChange-minMoistureChange)

	if ps.GetState() == "watering" {
		// moisture level should go up
		ps.ChangeMoistureLevel(ps.GetMoistureLevel() + change)
	} else {
		// moisture level should go down
		ps.ChangeMoistureLevel(ps.GetMoistureLevel() - change)
	}
}

func main() {
	rand.Seed(time.Now().UTC().UnixNano())

	plants := []*sensor.PlantSensor{ 
		// Fill in with at least 5 plant sensors to simulate
		}
	plants[0] = sensor.NewPlantSensor("Plant1",0.0,0.0,0.0)
	plants[1] = sensor.NewPlantSensor("Plant2",0.0,0.0,0.0)
	plants[2] = sensor.NewPlantSensor("Plant3",0.0,0.0,0.0)
	plants[3] = sensor.NewPlantSensor("Plant4",0.0,0.0,0.0)
	plants[4] = sensor.NewPlantSensor("Plant5",0.0,0.0,0.0)
	

		
	var watering int
	// simulate a 24-hour period, readings taken each minute
	for i := 1; i <= 1440; i++ {
		fmt.Printf("\nTIME: %04d\n", i)

		// Use a "range" loop to:
		// - pass each plant sensor to the simulateMoistureReading function
		// - increment the watering counter if a plant sensor enters the watering state 
		// - Describe each plant sensor
	for i := range plants {
		simulateMoistureReading(plants[i])
		if plants[i].GetState() == "watering"{
			watering += 1	
		}
		plants[i].Describe()
	}

		fmt.Printf("\n")
	}

	fmt.Printf("\nFINAL STATISTICS\n\n")
	// Print the number of "minutes" that plants were in the watering state
}
