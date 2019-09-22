package sensor

import "fmt"

// A PlantSensor represents a sensor used to monitor moisture
// level in a houseplant. The trigger is the moisture level
// (between 0.0 and 1.0) below which the plant should be watered.
// The stop is the moisture level at or above which plant watering 
// should stop.
type PlantSensor struct {
	identifier    string
	state         string
	moistureLevel float64
	waterTrigger  float64
	waterStop     float64
}

// NewPlantSensor accepts an identifier, moisture level, water
// trigger and water stop value. Returns a PlantSensor initialized with
// the given values. Moisture level, water trigger and water stop
// values should be between 0 and 100.
func NewPlantSensor(id string, level, trigger, stop float64) *PlantSensor {
	sensor := PlantSensor{identifier: id, moistureLevel: level, waterTrigger: trigger, waterStop: stop}
	return &sensor
}

// ChangeMoistureLevel accepts a moisture level and updates
// the moisture level to that value. If the moisture level is
// below the water trigger value, changes the state to "watering".
// If the moisture level is at or above the water stop value,
// changes the state to "monitoring".
func (ps *PlantSensor) ChangeMoistureLevel(ml float64) {
	ps.moistureLevel = ml
	if ps.moistureLevel < ps.waterTrigger {
		ps.state = "watering"
	} else if ps.moistureLevel >= ps.waterStop {
			ps.state = "monitoring"
	}
}

// ChangeState accepts a state and updates the state to that
// value.
func (ps *PlantSensor) ChangeState(state string) {
	ps.state = state
}

// ChangeTriggerLevel accepts a trigger and updates the water trigger
// level to that value.
func (ps *PlantSensor) ChangeTriggerLevel(tl float64) {
	ps.waterTrigger = tl
}

// Describe "pretty prints" information about a PlantSensor.
// "[PlantSensor] hanging plant: state=monitoring, moisture=80.0%, trigger=20.0%, stop=40.0%"
func (ps *PlantSensor) Describe() {
	fmt.Printf("[%s] hanging plant: state=%s, moisture=%.2f, trigger=%.2f, stop=%.2f\n", ps.identifier, ps.state, ps.moistureLevel, ps.waterTrigger, ps.waterStop)
}

// GetMoistureLevel returns the moisture level of the sensor.
func (ps *PlantSensor) GetMoistureLevel() float64 {
	return ps.moistureLevel
}

// GetState returns the state of the sensor.
func (ps *PlantSensor) GetState() string {
	return ps.state
}
