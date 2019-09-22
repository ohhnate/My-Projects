// Project 4 -- The Sewer
//
// 17 May 2019
// Samuel Fuller
// Derek Bergman

package main

import (
        "fmt"
        "os"
        "os/exec"
        "math/rand"
        "runtime"
        "strings"
        "time"
      )

//Room holds room objects
type Room struct {
  Exit bool
  Empty bool
  Chest bool
  OpenChest bool
  Enemy bool
  Boss bool
  Heal bool
  X int
  Y int
}

//Dungeon is whole dungeon with all the rooms
type Dungeon struct {
  Room []Room
  Boss bool
}

//Player is player and character stats
type Player struct {
  Name string
  MaxHealth int
  Health int
  Armor int
  Attack int
  Gold int
  Key bool
  Inventory []*Item
  MaxWeight int
  X int
  Y int
}

//Death type for when player dies
type Death struct {
  Val int
}

//Item with an items values
type Item struct {
  Name string
  Weight int
}

//Enemy with enemies stats
type Enemy struct {
  Name string
  MaxHealth int
  Health int
  Armor int
  Attack int
  Gold int
  X int
  Y int
}

//Chest for chests
type Chest struct {
  Gold int
  Trap int
  Heal int
  Empty bool
}

//Log is action log
type Log struct {
  Action []string
  MaxSize int
}

//ClearScreen clears and refreshes the screen
func ClearScreen() {
	cmd := exec.Command("cmd", "/c", "cls")
	switch runtime.GOOS {
	case "linux":
		cmd = exec.Command("clear")
	case "darwin":
		cmd = exec.Command("clear")
	}
	cmd.Stdout = os.Stdout
	cmd.Run()
}

//RandomNumber give a random int
func RandomNumber (num int) int{
  return rand.Intn(num) + 1
}

//WrongDirection chooses a random string for a wrong direction selection
func (l *Log) WrongDirection (p *Player) {
  t := time.Now()
  roll := RandomNumber(5)
  if roll == 1 {
    l.AddAction(t.Format("3:4:05 ")+p.Name+" attempts to open a door but it seems permanently sealed. Try another direction.")
  } else if roll == 2 {
    l.AddAction(t.Format("3:4:05 ")+p.Name+" walks into a wall... Try another direction...")
  } else if roll == 3 {
    l.AddAction(t.Format("3:4:05 ")+"The path is blocked by a ceiling collapse. Try another direction.")
  } else if roll == 4 {
    l.AddAction(t.Format("3:4:05 ")+"Looks boring. Try another direction.")
  } else if roll == 5 {
    l.AddAction(t.Format("3:4:05 ")+"A loud growl comes from deep down the hall.\nTry another direction because "+p.Name+" is a coward. :)")
  }
}

//Move controls player navigation
func (p *Player) Move (direction string, l *Log) int{
  t := time.Now()
  moved := 0
  name := p.Name
  switch direction {
  case "a":
    if p.X == 1 {
      l.WrongDirection(p)
    } else if p.X > 1 {
      p.X = p.X - 1
      moved = moved + 1
      l.AddAction(t.Format("3:04:05 ")+ name +" moves West.")
    }
  case "s":
    if p.Y == 5 {
      l.WrongDirection(p)
    } else if p.Y < 5 {
      p.Y = p.Y + 1
      moved = moved + 1
      l.AddAction(t.Format("3:04:05 ")+ name +" moves South.")
    }
  case "d":
    if p.X == 5 {
      l.WrongDirection(p)
    } else if p.X < 5 {
      p.X = p.X + 1
      moved = moved + 1
      l.AddAction(t.Format("3:04:05 ")+ name +" moves East.")
    }
  case "w":
    if p.Y == 1 {
      l.WrongDirection(p)
    } else if p.Y > 1 {
      p.Y = p.Y - 1
      moved = moved + 1
      l.AddAction(t.Format("3:04:05 ")+ name +" moves North.")
    }
  case "x":
    os.Exit(1)
    }
  return moved
}

//Title shows game title screen
func Title(){
    fmt.Printf("\n\n\n\n\n")

    fmt.Printf("    ████████╗██╗  ██╗███████╗    ███████╗███████╗██╗    ██╗███████╗██████╗\n")
    fmt.Printf("    ╚══██╔══╝██║  ██║██╔════╝    ██╔════╝██╔════╝██║    ██║██╔════╝██╔══██╗\n")
    fmt.Printf("       ██║   ███████║█████╗      ███████╗█████╗  ██║ █╗ ██║█████╗  ██████╔╝\n")
    fmt.Printf("       ██║   ██╔══██║██╔══╝      ╚════██║██╔══╝  ██║███╗██║██╔══╝  ██╔══██╗\n")
    fmt.Printf("       ██║   ██║  ██║███████╗    ███████║███████╗╚███╔███╔╝███████╗██║  ██║\n")
    fmt.Printf("       ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝╚══════╝ ╚══╝╚══╝ ╚══════╝╚═╝  ╚═╝\n")


}

//MiniMap displays player minimap and location
func MiniMap(mini []string){
  fmt.Printf("Mini Map: \n")
  fmt.Printf("   1    2    3    4    5 \n")
  for i := 0; i <= 4; i ++ {
    fmt.Printf("%d",(i+1))
    for j := 0; j <= 4; j ++ {
      fmt.Printf(" %s ", mini[i*5+j])
    }
    fmt.Printf("\n")
  }
  fmt.Printf("*****************************************************************************\n")
}

//PlayerHud shows the players heads up display
func PlayerHud(p *Player, name string, mini []string) {
  ClearScreen()
  keyFound := 0
	p.Name = name
	empty := " "
  fmt.Printf("****************************************************************************\n")
  fmt.Printf("Name:              ♥:     Armor:     Attack:     Gold:     Key:      [X],[Y]:\n")
  fmt.Printf("%s", p.Name)
	for i := 0; i < 19 - len(p.Name); i++ {
		fmt.Printf("%s", empty)
	}
  if p.Key == true {
    keyFound = 1
  }
	fmt.Printf("%d%9d%12d%11d%8d        [%d],[%d]\n", p.Health, p.Armor, p.Attack, p.Gold, keyFound, p.X, p.Y)
  fmt.Printf("****************************************************************************\n\n")

 y := p.Y
 if y == 1 {
   mini[p.X - 1] = "[O]"
 } else if y == 2 {
   mini[4 + p.X] = "[O]"
 } else if y == 3 {
   mini[9 + p.X] = "[O]"
 } else if y == 4 {
   mini[14 + p.X] = "[O]"
 } else if y == 5 {
   mini[19 + p.X] = "[O]"
 }

 MiniMap(mini)

 if y == 1 {
   mini[p.X - 1] = "[X]"
 } else if y == 2 {
   mini[4 + p.X] = "[X]"
 } else if y == 3 {
   mini[9 + p.X] = "[X]"
 } else if y == 4 {
   mini[14 + p.X] = "[X]"
 } else if y == 5 {
   mini[19 + p.X] = "[X]"
 }
}

//AddAction adds an action to the Log.
func (l *Log) AddAction (action string) {
  action = strings.TrimSpace(action)
  if len(l.Action) < l.MaxSize {
    l.Action = append(l.Action, action)
  } else {
    l.Action = append(l.Action[1:], action)
  }
}

//ShowLog shows last actions
func (l Log) ShowLog () {
  fmt.Printf("\n\n----------------------------------------------------------------------------\n")
  fmt.Printf("                                  ACTIVITY LOG                              \n")
  for i := range l.Action {
    fmt.Printf("%s\n", l.Action[i])
  }
  fmt.Printf("____________________________________________________________________________\n")
}

//UserAttack controls users attacks
func (p *Player) UserAttack (e *Enemy, l *Log){
  roll := RandomNumber(20)
  fmt.Printf("Rolling for attack")
  TypedText("...", 300)
  fmt.Printf("%s rolled a %d \n", p.Name, roll)
	if roll >= e.Armor {
		damage := RandomNumber(p.Attack)
    e.Health -= damage
    fmt.Printf("%ss attack dealt %d damage to the %s! ♥:%d \n", p.Name, damage, e.Name, e.Health)
	} else {
    fmt.Printf("%ss attack missed!\n", p.Name)
	}
}

//MobAttack controls enemies attacks
func (p *Player) MobAttack(e *Enemy, l *Log){
  fmt.Printf("The %s is attempting to attack", e.Name)
  TypedText("...", 300)
  roll := RandomNumber(20)
  if roll > p.Armor {
    damage := RandomNumber(e.Attack)
    p.Health -= damage
    fmt.Printf("The attack lands and %s takes %d damage! ♥:%d \n", p.Name, damage, p.Health)
	} else {
    fmt.Printf("%s managed to defend the attack!\n", p.Name)
  }
}

//Death is called when players health hits 0 or below
func (d *Death) Death() {
  fmt.Printf("You have died...\n")
  var choice int
  fmt.Printf("Would you like to try again[1] or exit game[2] ")
  fmt.Scanln(&choice)
  switch choice {
  case 1:
    d.Val = 1
  case 2:
    os.Exit(1)
  }
}

// EnemyHud pretty prints the enemy's stats
func (e *Enemy)EnemyHud() {
  fmt.Printf("%s   ♥: %d   Attack: %d   Armor: %d \n\n", e.Name, e.Health, e.Attack, e.Armor)
}
//Battle controls the random battle scenarios and calculations
func (p *Player) Battle(e *Enemy, l *Log, i *Item, d *Death) int {
  t := time.Now()

  fmt.Printf("%s encountered an enemy!\n\n", p.Name)
  e.EnemyHud()
  fmt.Printf("Would you like to try and escape[1] or fight[2]? ")

  var choice string
  fmt.Scanln(&choice)

  switch choice{
  case "1":
    roll := RandomNumber(20)
    fmt.Printf("Rolling a d20 in attempt to escape")
    TypedText("...", 300)
    if roll > 5 {
      sucessString := fmt.Sprintf("%s successfully escaped from a %s unscathed.", p.Name, e.Name)
      l.AddAction(t.Format("3:04:05 ")+sucessString)
    } else {
      damage := RandomNumber(e.Attack)
      p.Health -= damage
      l.AddAction(t.Format("3:04:05 ") +p.Name+" failed a clean getaway.")
      failString := fmt.Sprintf("The %s dealt %d damage during the escape.", e.Name, damage)
      l.AddAction(t.Format("3:04:05 ")+failString)
    }
    return 1
  default:
    TypedText("You failed to select one of the options given to you.\n", 50)
    TypedText("You're just going to have to fight it", 50)
    TypedText("...\n", 200)
    fallthrough

  case "2":
    var simulate int
    fmt.Printf("Would you like to view battle[1] or simulate[2]? ")
    fmt.Scanln(&simulate)

    if simulate == 1 {
      userI := RandomNumber(20)
      compI := RandomNumber(20)

      fmt.Printf("Rolling for initiative")
      TypedText("...", 300)

      fmt.Printf("%s rolled a %d\n", p.Name, userI)
      fmt.Printf("The %s rolled a %d\n", e.Name, compI)

      var first bool
      if compI > userI {
        fmt.Printf("The %s rolled higher, they will attack first.\n", e.Name)
      } else {
        fmt.Printf("%s rolled higher, %s will attack first.\n", p.Name, p.Name)
        first = true
      }

      for p.Health > 0 && e.Health > 0 {
        if first == true {
          p.UserAttack(e, l)
          if e.Health > 0 {
            p.MobAttack(e, l)
            time.Sleep(2500 * time.Millisecond)
          } else {
            break
          }
        } else {
          p.MobAttack(e, l)
          time.Sleep(2500 * time.Millisecond)
          if p.Health > 0 {
            p.UserAttack(e, l)
            time.Sleep(2500 * time.Millisecond)
          } else {
            break
          }
        }
      }
    } else {
      userI := RandomNumber(20)
      compI := RandomNumber(20)
      fmt.Printf("Rolling for initiative...\n")

      fmt.Printf("%s rolled a %d\n", p.Name, userI)
      fmt.Printf("The %s rolled a %d\n", e.Name, compI)

      var first bool
      if compI > userI {
        fmt.Printf("The %s rolled higher, they will attack first.\n", e.Name)
      } else {
        fmt.Printf("%s rolled higher, %s will attack first.\n", p.Name, p.Name)
        first = true
      }

      for p.Health > 0 && e.Health > 0 {
        if first == true {
          p.UserAttack(e, l)
          if e.Health > 0 {
            p.MobAttack(e, l)
          } else {
            break
          }
        } else {
          p.MobAttack(e, l)
          if p.Health > 0 {
            p.UserAttack(e, l)
          } else {
            break
          }
        }
      }
    }
  }
  if p.Health <= 0 {
    d.Death()
  }
  if e.Health <= 0 && p.Health >= 0 {
    winString := fmt.Sprintf("%s successfully defeated a %s!", p.Name, e.Name)
    l.AddAction(t.Format("3:04:05 ")+winString)
    fmt.Printf("The %s dropped gold.", e.Name)
    p.Gold += e.Gold
    lootRoll := RandomNumber(100)
//25% item drop chance currently
    if lootRoll <= 25 {
      loot := RandomItem(p, i)
      if loot == "none" {
        fmt.Printf("The %s dropped an item.", e.Name)
        heavyString := fmt.Sprintf("%s found an item but is already carrying max weight limit so %s left it behind.", p.Name, p.Name)
        l.AddAction(t.Format("3:04:05 ")+heavyString)
      } else {
        fmt.Printf("The %s dropped loot [%s].", e.Name, loot)
        itemString := fmt.Sprintf("%s obtained a %s and %d gold from a %s.", p.Name, loot, e.Gold, e.Name)
        l.AddAction(t.Format("3:04:05 ")+itemString)
      }
    } else {
      goldString := fmt.Sprintf("%s gained %d gold from a %s.", p.Name, e.Gold, e.Name)
      l.AddAction(t.Format("3:04:05 ")+goldString)
    }
    if lootRoll == 9 && p.Key == false {
      p.Key = true
      fmt.Printf("The %s dropped a giant key. Wonder what it is for...", e.Name)
      lootKey := fmt.Sprintf("%s found a giant key dropped by a %s", p.Name, e.Name)
      l.AddAction(t.Format("3:04:05 ")+lootKey)
    }
    fmt.Printf("\nPosting results")
    TypedText("...", 300)
  }
  return 2
}

// BossBattle plays out a boss battle
func (p *Player) BossBattle(e *Enemy, l *Log, item *Item, d *Death) int {
    t := time.Now()
    fmt.Printf("%s has encountered a strong foe!\n\nName:%s\n♥:%d\nAtk:%d\nDef:%d \n\nIt doesn't seem to notice. Want to come back another time[1] or fight[2]? ", p.Name, e.Name, e.Health, e.Attack, e.Armor)
    var choice int
    fmt.Scanln(&choice)
    var first bool
    switch choice {
    case 1:
        sucessString := fmt.Sprintf("%s snuck away from a %s without it noticing.", p.Name, e.Name)
        l.AddAction(t.Format("3:04:05 ") + sucessString)
    default:
      TypedText("You failed to select one of the options given to you.\n", 50)
      TypedText("You're just going to have to fight it", 50)
      TypedText("...\n", 200)
      fallthrough
    case 2:
      var simulate int
      fmt.Printf("Would you like to view battle[1] or simulate[2]? ")
      fmt.Scanln(&simulate)
      switch simulate {
      case 1:
        userI := RandomNumber(20)
        compI := RandomNumber(20)
        fmt.Printf("Rolling for initiative")
        TypedText("...", 300)
        fmt.Printf("%s rolled a %d\n", p.Name, userI)
        fmt.Printf("The %s rolled a %d\n", e.Name, compI)
        if compI > userI {
          fmt.Printf("The %s rolled higher, they will attack first.\n", e.Name)
        } else {
          fmt.Printf("%s rolled higher, %s will attack first.\n", p.Name, p.Name)
          first = true
        }
        for p.Health > 0 && e.Health > 0 {
          if first == true {
            p.UserAttack(e, l)
            time.Sleep(2500 * time.Millisecond)
            if e.Health > 0 {
              p.MobAttack(e, l)
              time.Sleep(2500 * time.Millisecond)
            } else {
              break
            }
          } else {
            p.MobAttack(e, l)
            time.Sleep(2500 * time.Millisecond)
            if p.Health > 0 {
              p.UserAttack(e, l)
            } else {
              break
            }
          }
        }
      default:
          TypedText("Since you didn't enter a valid selection the battle will be simulated.", 50)
          fallthrough
      case 2:
        userI := RandomNumber(20)
        compI := RandomNumber(20)
        fmt.Printf("Rolling for initiative")
        fmt.Printf(".")
        fmt.Printf(".")
        fmt.Printf(".\n")
        fmt.Printf("%s rolled a %d\n", p.Name, userI)
        fmt.Printf("The %s rolled a %d\n", e.Name, compI)
        if compI > userI {
          fmt.Printf("The %s rolled higher, they will attack first.\n", e.Name)
        } else {
          fmt.Printf("%s rolled higher, %s will attack first.\n", p.Name, p.Name)
          first = true
        }
        for p.Health > 0 && e.Health > 0 {
          if first == true {
            p.UserAttack(e, l)
            if e.Health > 0 {
              p.MobAttack(e, l)
            } else {
              break
            }
          } else {
            p.MobAttack(e, l)
            if p.Health > 0 {
              p.UserAttack(e, l)
            } else {
              break
            }
          }
        }
      } 
    }
    if p.Health <= 0 {
      d.Death()
    } else if e.Health <= 0 && p.Health >= 0 {
      winString := fmt.Sprintf("%s successfully defeated a %s!", p.Name, e.Name)
      l.AddAction(t.Format("3:04:05 ")+winString)
      fmt.Printf("The %s dropped gold.", e.Name)
      p.Gold += e.Gold
      lootRoll := RandomNumber(100)
      if lootRoll <= 25 {
        loot := RandomItem(p, item)
        fmt.Printf("The %s dropped loot [%s].", e.Name, loot)
        itemString := fmt.Sprintf("%s obtained a %s and %d gold from a %s.", p.Name, loot, e.Gold, e.Name)
        l.AddAction(t.Format("3:04:05 ")+itemString)
      } else {
        goldString := fmt.Sprintf("%s gained %d gold from a %s.", p.Name, e.Gold, e.Name)
        l.AddAction(t.Format("3:04:05 ")+goldString)
      }
      if p.Key == false {
        fmt.Printf("The %s dropped a giant key.", e.Name)
        l.AddAction(t.Format("3:04:05 ")+p.Name+" found a giant key.")
        p.Key = true
      }
      fmt.Printf("\nPosting results")
      TypedText("...", 300)
    }
        return choice
}

// RoomContent contains or will contain the actions from entering a room. asside from battles/combat.
func (p *Player) RoomContent(r *Room, c *Chest, d *Dungeon, witch *Enemy, ghoul *Enemy, slime *Enemy, goblin *Enemy, gator *Enemy, boss *Enemy, l *Log, item *Item, death *Death) int{
  t := time.Now()
  name := p.Name
  mob := RandomMob(witch, ghoul, slime, goblin, gator)
  var escaped int
  var choice int
  for i := 0; i < 25; i++ {
    if d.Room[i].X == p.X && d.Room[i].Y == p.Y {
      if d.Room[i].Empty == false {
        if d.Room[i].Chest == true {
          TypedText("The room contains a chest!\nWould you like to open[1] or leave[2]? ", 50)
          fmt.Scanln(&choice)
          if choice == 1 {
            p.Chest(*c, l, item, death)
            d.Room[i].Chest = false
            d.Room[i].OpenChest = true
          } else if choice == 2 {
            l.AddAction(t.Format("3:04:05 ") +name+" finds a chest but leaves it unopened. ")
          } else {
            TypedText("Since you can't hit the right button, you leave the chest alone", 50)
            TypedText("...", 200)
          }
        } else if d.Room[i].OpenChest == true {
          TypedText("This room only contains an empty chest. Nothing else to see. ", 50)
            l.AddAction(t.Format("3:04:05 ") +"The room contained an empty chest. ")
          }
        if d.Room[i].Enemy == true {
          if p.Battle(mob, l, item, death) == 2 {
            d.Room[i].Enemy = false
            d.Room[i].Empty = true
          } else {
            d.Room[i].Enemy = true
          }
        }
        if d.Room[i].Boss == true {
          if p.BossBattle(boss, l, item, death) == 2 {
            d.Room[i].Boss = false
            d.Room[i].Empty = true
          }
        }
      }  else if d.Room[i].Empty == true && d.Room[i].Exit == true {
          TypedText("You find a potential exit in this room! ", 50)
          TypedText("Would you like to attempt to open the door[1] or [2]backaway? ", 50)
          fmt.Scanln(&choice)
          if choice == 1 {
            if p.Gold >= 200 && p.Key == true {
              TypedText("\nThe door opens.", 50)
              time.Sleep(2 * time.Second)
              escaped = 1
              break
            } else if p.Gold < 200 && p.Key == true {
              none := fmt.Sprintf("\n%s notices a coin slot labeled (200) and a giant key hole. The door won't budge.\n\nEnter any key to continue ", p.Name)
              TypedText(none, 50)
              fmt.Scanln(&choice)
              l.AddAction(t.Format("3:04:05 ") +"Escape failed as "+name+" does not have the required gold amount.")
            } else if p.Gold >= 200 && p.Key == false {
              goldOnly := fmt.Sprintf("\n%s notices a coin slot labeled (200) and a giant key hole. The door won't budge.\n\nEnter any key to continue ", p.Name)
              TypedText(goldOnly, 50)
              fmt.Scanln(&choice)
              l.AddAction(t.Format("3:04:05 ") +"Escape failed as "+name+" has not found the key.")
            } else if p.Gold < 200 && p.Key == false {
              keyOnly := fmt.Sprintf("\n%s notices a coin slot labeled (200) and a giant key hole. The door won't budge.\n\nEnter any key to continue ", p.Name)
              TypedText(keyOnly, 50)
              fmt.Scanln(&choice)
              l.AddAction(t.Format("3:04:05 ") +"Escape failed as "+name+" does not meet the requirements. (200 gold and a giant key)")
            }
          } else if choice == 2 {
              l.AddAction(t.Format("3:04:05 ") +name+" found the exit in a room but didn't attempt to leave.")
          } else {
            TypedText("Since you didn't enter a valid selection you backaway.", 50)
            l.AddAction(t.Format("3:04:05 ") +name+" found the exit in a room but didn't attempt to leave.")
          }
      } else if d.Room[i].Heal == true {
        goddess := fmt.Sprintf("As %s enters the room %s notice a strange statue depicting a Goddess. \n", p.Name, p.Name)
        TypedText(goddess, 50)
        time.Sleep(1 * time.Second)
        reborn := fmt.Sprintf("Upon approaching the statue %s feels reborn. \n", p.Name)
        TypedText(reborn, 50)
        time.Sleep(1 * time.Second)
        l.AddAction(t.Format("3:04:05 ") +name+" has been blessed by the Under Goddess. Health restored.")
        p.Health = p.MaxHealth
      } else {
          l.AddAction(t.Format("3:04:05 ") +"The room is empty. ")
      }
    }
  }
  return escaped
}

//Chest contains content and randomization within chests
func (p *Player) Chest(c Chest, l *Log, item *Item, death *Death) {
  t := time.Now()
  roll := RandomNumber(36)
  name := p.Name
    if roll > 0 && roll <= 6 {
      gold := roll * 10
      goldText := fmt.Sprintf("%s found %d gold.", p.Name, gold)
      l.AddAction(t.Format("3:04:05 ")+goldText)
      p.Gold = p.Gold + gold
    } else if roll > 6 && roll < 13 {
      p.Health = p.Health - roll
        loseHealth := fmt.Sprintf("It contained a trap! %s lost %d HP.", p.Name, roll)
        l.AddAction(t.Format("3:04:05 ")+loseHealth)
        if p.Health <= 0 {
          death.Death()
        }
    } else if roll >= 13 && roll < 20 {
      if p.Health + roll >= p.MaxHealth {
        p.Health = p.MaxHealth
      } else {
        p.Health = p.Health + roll
      }
      gainHealth := fmt.Sprintf("%s found a healing potion and restored %d HP.", p.Name, roll)
      l.AddAction(t.Format("3:04:05 ")+gainHealth)
    } else if roll >= 20 && roll <= 31 {
      loot := RandomItem(p, item)
      if loot == "none" {
        heavyString := fmt.Sprintf("%s found an item inside a chest. But already at max weight limit so %s leaves it behind.", p.Name, p.Name)
        l.AddAction(t.Format("3:04:05 ")+heavyString)
      } else {
        itemString := fmt.Sprintf("%s found loot [%s] inside a chest.", p.Name, loot)
        l.AddAction(t.Format("3:04:05 ")+itemString)
      }
      } else if roll > 32 {
        c.Empty = true;
        l.AddAction(t.Format("3:04:05 ")+name+" found just a dusty old chest :( ")
  }
  if roll == 32 && p.Key == false {
    p.Key = true
    l.AddAction(t.Format("3:04:05 ")+name+" found a giant key! Wonder what it is for...")
  }
}

//NewItem creates a new item when called
func NewItem(name string, weight int) *Item {
  return &Item{name, weight}
}

//AddItem adds an item to players inventory if carry weight doesn't exceed limit
func (p *Player) AddItem(item *Item) bool {
  var totalWeight int
  totalWeight += item.Weight
  if totalWeight + item.Weight > p.MaxWeight {
    return false
  }
  p.Inventory = append(p.Inventory, item)
  if item.Name == "Rusty Sword" {
    p.Attack += 2
  }
  if item.Name == "Small Shield" {
    p.Armor += 2
  }
  if item.Name == "Battle Armor" {
    p.Attack += 2
    p.Armor ++
  }
  if item.Name == "Heavy Armor" {
    p.Attack ++
    p.Armor += 3
  }
  if item.Name == "Lost Sword" {
    p.Attack += 4
  }
  if item.Name == "Large Shield" {
    p.Armor += 4
  }
  return true
}

//RandomItem chooses a random item to add to players inventory
func RandomItem (p *Player, item *Item) string{
    switch RandomNumber(6) {
    case 1:
        item.Name = "Rusty Sword"
      if p.AddItem(NewItem("Rusty Sword", 3)) == false {
        return "none"
      }
    case 2:
        item.Name = "Small Shield"
        if p.AddItem(NewItem("Small Shield", 3)) == false {
          return "none"
      }
    case 3:
        item.Name = "Battle Armor"
        if p.AddItem(NewItem("Battle Armor", 3)) == false {
          return "none"
      }
    case 4:
        item.Name = "Heavy Armor"
        if p.AddItem(NewItem("Heavy Armor", 5)) == false {
          return "none"
      }
    case 5:
        item.Name = "Lost Sword"
        if p.AddItem(NewItem("Lost Sword", 5)) == false {
          return "none"
      }
    case 6:
        item.Name = "Large Shield"
        if p.AddItem(NewItem("Large Shield", 5)) == false {
          return "none"
      }
    }
    return item.Name
}

//Inventory displays inventory
func Inventory (item Item, p Player) {
  display := "Inventory:"
  for i := range(p.Inventory) {
    display = display + " [" + p.Inventory[i].Name +"]"
    }
  fmt.Printf(display)
}

// WorldGenerator fills the "dungeon rooms" with chests or enemies or whatever else we add.
func (d *Dungeon) WorldGenerator(p *Player){
  for i := 0; i < 25; i++ {
    roll := RandomNumber(100)
    if roll <= 20 {
      d.Room[i].Empty = false
      d.Room[i].Chest = true
    } else if roll >= 21 && roll <= 60 {
      d.Room[i].Empty = false
      d.Room[i].Enemy = true
    } else {
      d.Room[i].Empty = true
    }
  }
//ExitRoom places dungeon exit in a random room
//If/else statement to prevent exit from being placed in player spawn room
  ExitRoom := RandomNumber(24)
  if d.Room[ExitRoom].X != p.X && d.Room[ExitRoom].Y != p.Y {
     d.Room[ExitRoom].Empty = true
     d.Room[ExitRoom].Exit = true
  } else {
    ExitRoom = RandomNumber(24)
    if d.Room[ExitRoom].X != p.X && d.Room[ExitRoom].Y != p.Y {
      d.Room[ExitRoom].Chest = false
      d.Room[ExitRoom].Empty = true
      d.Room[ExitRoom].Exit = true
    }
  }
  HealRoom := RandomNumber(24)
  if d.Room[HealRoom].X != p.X && d.Room[HealRoom].Y != p.Y && d.Room[HealRoom] != d.Room[ExitRoom] {
     d.Room[HealRoom].Empty = true
     d.Room[HealRoom].Heal = true
  } else {
    HealRoom = RandomNumber(24)
    d.Room[HealRoom].Empty = true
    d.Room[HealRoom].Heal = true
  }
//  this exit location and heal location print is only used for testing purposes to locate exit spawn  
//   fmt.Printf("\nHeal located at [%d][%d]",d.Room[HealRoom].X, d.Room[HealRoom].Y)
//   time.Sleep(1 * time.Second)
//   fmt.Printf("\nExit located at [%d][%d]",d.Room[ExitRoom].X, d.Room[ExitRoom].Y)
//   time.Sleep(1 * time.Second)
//loop empties player spawn room
  for i := 0; i < 25; i++ {
    if d.Room[i].X == p.X && d.Room[i].Y == p.Y {
      d.Room[i].Empty = true
    }
  }
}

//MobSpawner potentially randomly fills empty rooms with mobs after initial generation
func (d *Dungeon) MobSpawner(l *Log, p *Player) {
  t := time.Now()
  roll := RandomNumber(100)
  for i :=0; i < 25; i++ {
    if d.Room[i].Exit == false && d.Room[i].Heal == false {
      if d.Room[i].Empty == true && d.Room[i].Boss == false {
        if roll < 45 && roll > 30 {
          d.Room[i].Empty = false
          d.Room[i].Enemy = true
        }
        if roll >= 75 && d.Boss == false && d.Room[i].Chest == false && d.Room[i].OpenChest == false && d.Room[i].Exit == false && d.Room[i].X != p.X && d.Room[i].Y != p.Y {
          d.Room[i].Empty = false
          d.Room[i].Enemy = false
          d.Room[i].Boss = true
          d.Boss = true
          spawn := fmt.Sprintf("A strong enemy just appeared somewhere on the map. Maybe he has something neat.")
          l.AddAction(t.Format("3:04:05 ")+spawn)
        }
      }
    }
  }
}

//RandomMob chooses a random mob to spawn
func  RandomMob(witch *Enemy, ghoul *Enemy, slime *Enemy, goblin *Enemy, gator *Enemy) *Enemy {
  roll := RandomNumber(5)
  mob := ghoul
 if roll == 3 {
   mob = witch
 } else if roll == 2 {
   mob = ghoul
 } else if roll == 1 {
   mob = slime
 } else if roll == 4 {
   mob = goblin
 } else if roll == 5 {
   mob = gator
 }
 mob.Health = mob.MaxHealth
 return mob
}

//TypedText emulates "typed text" for input string with the duration of milliseconds in between
func TypedText(text string, duration int) {
  for i := range text {
    fmt.Printf(string(text[i]))
    time.Sleep(time.Duration(duration) * time.Millisecond)
  }
}
//Tutorial shows basic tutorial
func Tutorial(p *Player, name string, mini []string, item Item, l *Log) {
  PlayerHud(p, name, mini)
  TypedText("\nHey gamer!",80)
  time.Sleep(1 * time.Second)
  TypedText(" It's me! Super tutorial!\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("I will be explaining each individual section of the user interface one by one so be ready!\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("The panel at the top of the screen is your HUD.\n",80)
  time.Sleep(1 * time.Second)
  TypedText("It contains a variety of useful information including player name and current map coordinates.\n",80)
  time.Sleep(1 * time.Second)
  TypedText("The grid looking thing below the HUD is the mini map!",80)
  time.Sleep(1 * time.Second)
  TypedText(" The 'O' shows current location while the 'X' is visited rooms.", 80)
  time.Sleep(1 * time.Second)
  ClearScreen()
  fmt.Printf("\n\n\n\n\n\n\n\n\n\n\n\n\n")
  Inventory(item, *p)
  TypedText("\nYour inventory will be located below the mini map and will show any picked up items you have gathered.", 80)
  time.Sleep(1 * time.Second)
  ClearScreen()
  fmt.Printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
  l.ShowLog()
  TypedText("This next area is the activity log. It is located under the mini map.\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("This log will store your 10 most recent actions such as 'player found new item'.", 80)
  time.Sleep(1 * time.Second)
  ClearScreen()
  fmt.Printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
  TypedText("The last item is the navigation panel.\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("It will be directly under the activity log and is displayed like:\n",80)
  TypedText("'Choose a direction to move with WASD:' \n", 1)
  time.Sleep(1 * time.Second)
  TypedText("You will navigate the map using the WASD keys in a North, East, South, West type of fashion.\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("Also the players current activity such as battle text will show here prior to being sent to the activity log.\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("Finally if you put it all together it looks like this!", 80)
  time.Sleep(1 * time.Second)
  ClearScreen()
  PlayerHud(p, name, mini)
  Inventory(item, *p)
  l.ShowLog()
  time.Sleep(1 * time.Second)
  TypedText("\nOkay I think you are finally ready...\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("Now get out there and show me what you got gamer!\n", 80)
  time.Sleep(1 * time.Second)
  TypedText("Yes... I'm using 'gamer' unironically... what about it? bye.", 80)
  time.Sleep(1 * time.Second)
}

//Intro shows intro text
func Intro() string {
  var name string
  TypedText("\n\nYou wake up in a cold dark room", 50)
  TypedText("...", 300)
  TypedText("\n\nYou can't remember much", 50)
  TypedText("...", 300)
  TypedText("\n\nOnly that your name is: ", 50)
  fmt.Scanln(&name)
  if len(name) < 1 || len(name) > 16 {
    fmt.Printf("\nPlease enter a name between 1 and 16 characters.")
    time.Sleep(3 * time.Second)
    ClearScreen()
    Intro()
  } else {
    TypedText("\nYou don't know how or why you are here", 50)
    TypedText("...", 300)
    TypedText("\n\nYou just have a strong urge to escape", 50)
    TypedText("...", 300)
  }
  
  return name
}

//Outro contains ending outro
func Outro(name string) {
  ClearScreen()
  fmt.Printf("\n\n")
  TypedText(name+" walks through the door into a long tunnel.\n", 80)
  time.Sleep(500 * time.Millisecond)
  TypedText("\n\nAfter walking what seems like an eternity "+name+ " approaches a ladder.\n", 80)
  time.Sleep(500 * time.Millisecond)
  TypedText("\n\nTrudging up the ladder step by step "+name+" comes face to face with an iron plate.\n", 80)
  time.Sleep(500 * time.Millisecond)
  TypedText("\n\nBestowing all inner strength "+name+" lifts the iron plate and is hit with bright light and a breath of fresh air.\n", 80)
  time.Sleep(500 * time.Millisecond)
  fmt.Printf("\n")
  TypedText(name+" has escaped.\n", 80)
  time.Sleep(2 * time.Second)
}

func main() {
  for {
    rand.Seed(time.Now().UnixNano())
    ClearScreen()
    Title()
    fmt.Printf("\n\n                            <Press Enter to Begin>\n\n                                        ")
    var button string
    fmt.Scanln(&button)
    ClearScreen()
    name := Intro()

  // initialization for all chests, rooms, player, enemies etc. Rooms need reworked or consolidated if possible.
    chest := Chest{0, 0, 0, true}
    log := &Log{[]string{""}, 10}
    death := Death{0}

    var rooms []Room
    for i := 1; i <= 5; i++ {
     for j := 1; j <= 5; j++ {
       rooms = append(rooms, Room{false, true, false, false, false, false, false, i, j})
     }
   }
    dungeon := Dungeon{rooms, false}
    mini := make([]string, 25)
    for i := range(mini){
      mini[i] = "[ ]"
    }
    X := RandomNumber(5)
    Y := RandomNumber(5)
    player := Player{"nameless test", 99, 99, 10, 10, 100, false, nil, 50, X, Y}
    item := Item{"Sword", 5}
    witch := Enemy{"Witch", 20, 20, 8, 8, 8, 1, 1}
    ghoul := Enemy{"Ghoul", 17, 17, 7, 7, 8, 1, 1}
    slime := Enemy{"Slime", 16, 16, 5, 5, 8, 1, 1}
    gator := Enemy{"Gator", 19, 19, 7, 7, 7, 1, 1}
    goblin := Enemy{"Goblin", 18, 18, 6, 6, 6, 1, 1}
    boss := Enemy{"Deep Beast", 75, 75, 15, 15, 100, 1, 1}

    // runs generator that creates world.
    dungeon.WorldGenerator(&player)
    var tutorial int
    TypedText("\n\nWould you like view the tutorial? Yes[1] or No[Enter] ", 50)
    fmt.Scanln(&tutorial)
    if tutorial == 1 {
      Tutorial(&player, name, mini, item, log)
    }
    for death.Val == 0 {
      PlayerHud(&player, name, mini)
      Inventory(item, player)
      log.ShowLog()
      var movement string
      fmt.Printf("Press 'x' to exit game.\n\n")
      fmt.Printf("Choose a direction to move with WASD: ")
      fmt.Scanln(&movement)
      if player.Move(movement, log) == 1 {
        PlayerHud(&player, name, mini)
        Inventory(item, player)
        log.ShowLog()
        TypedText("Searching room", 80)
        TypedText("... ", 300)
        if player.RoomContent(&rooms[0], &chest, &dungeon, &witch, &ghoul, &slime, &goblin, &gator, &boss, log, &item, &death) == 1 {
          break
          }
        dungeon.MobSpawner(log, &player)
      }
    }
    if death.Val == 1 {
      player.Health = player.MaxHealth
    } else {
      Outro(name)
    }
  }
}
