package main

import (
	"math"
	"testing"
)

func TestDistanceBetween(t *testing.T) {
	distance := DistanceBetween(0, 0, 5, 5)
	roundedDistance := math.Floor(distance*100) / 100
	if roundedDistance != 7.07 {
		t.Error("Expected 7.07, got ", roundedDistance)
	}
}

func TestAreaOfCircle(t *testing.T) {
	area := AreaOfCircle(5.0)
	roundedArea := math.Floor(area*100) / 100
	if roundedArea != 78.53 {
		t.Error("Expected 78.53, got ", roundedArea)
	}
}

func TestAreaOfRectangle(t *testing.T) {
	area := AreaOfRectangle(1.5, 2.5)
	roundedArea := math.Floor(area*100) / 100
	if roundedArea != 3.75 {
		t.Error("Expected 3.75, got ", roundedArea)
	}
}

func TestVolumeOfCylinder(t *testing.T) {
	volume := VolumeOfCylinder(5.0, 7.5)
	roundedVolume := math.Floor(volume*100) / 100
	if roundedVolume != 589.04 {
		t.Error("Expected 589.04, got ", roundedVolume)
	}
}

func TestVolumeOfBox(t *testing.T) {
	volume := VolumeOfBox(1.5, 2.5, 3.5)
	roundedVolume := math.Floor(volume*100) / 100
	if roundedVolume != 13.12 {
		t.Error("Expected 13.12, got ", roundedVolume)
	}
}

func TestHoursMinutesSeconds(t *testing.T) {
	hours, minutes, seconds := HoursMinutesSeconds(9999)
	if hours != 2 || minutes != 46 || seconds != 39 {
		t.Errorf("Expected 2 h/46 m/39 s, got %d h/%d m/%d s",
			hours, minutes, seconds)
	}
}
