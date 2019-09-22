package main

import (
	"fmt"
	"math/rand"
	"time"

	"./bot"
	"./config"
)

func main() {
	err := config.ReadConfig()

	if err != nil {
		fmt.Println(err.Error())
		return
	}
	rand.Seed(time.Now().UnixNano())
	bot.Start()

	<-make(chan struct{})
	return
}
