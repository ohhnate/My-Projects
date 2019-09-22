// Lab 7 -- functions, pt 3
//
// Programmer name: Samuel Fuller
// Date completed:  16 Feb 2019

package main

import (
	"math"
)

// AreaOfCircle computes the area of a circle.
func AreaOfCircle(radius float64) float64 {
	area := math.Pi * (radius * radius)
	return area
}

// AreaOfRectangle computes the area of a rectangle.
func AreaOfRectangle(width, height float64) float64 {
	area := width * height
	return area
}

// VolumeOfCylinder computes the volume of a cylinder.
func VolumeOfCylinder(radius, height float64) float64 {
	volume := math.Pi * (radius * radius) * height
	return volume
}

// VolumeOfBox computes the volume of a cube.
func VolumeOfBox(length, width, height float64) float64 {
	volume := length * width * height
	return volume
}

// DistanceBetween computes the distance between points x1,y1 and x2,y2.
// HINT: use the Pythagorean Theorem.
func DistanceBetween(x1, y1, x2, y2 float64) float64 {
	distance := math.Sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
	return distance
}

// HoursMinutesSeconds computes the number of hours, minutes,
// and seconds given a number of seconds.
// EXAMPLE: 3661 seconds is 1 hours, 1 minutes, 1 seconds
func HoursMinutesSeconds(seconds int) (int, int, int) {
	tHours := seconds / 3600
	seconds2 := seconds % 3600
	tMinutes := seconds2 / 60
	seconds3 := seconds2 % 60
	return tHours, tMinutes, seconds3
}

func main() {
}
