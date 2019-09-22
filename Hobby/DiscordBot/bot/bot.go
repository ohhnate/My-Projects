package bot

import (
	"fmt"
	"math/rand"
	"strconv"

	"strings"

	"../config"
	"github.com/bwmarrin/discordgo"
)

var BotID string
var goBot *discordgo.Session

func Start() {
	goBot, err := discordgo.New("Bot " + config.Token)

	if err != nil {
		fmt.Println(err.Error())
		return
	}

	u, err := goBot.User("@me")

	if err != nil {
		fmt.Println(err.Error())
	}

	BotID = u.ID

	goBot.AddHandler(messageHandler)
	err = goBot.Open()

	if err != nil {
		fmt.Println(err.Error())
		return
	}

	fmt.Println("RTSI Bot is running!")

}

// func commandHandler(s *discordgo.Session, m *discordgo.MessageCreate, keyword, text string){
// 	_, _ = s.ChannelMessageSend(m.ChannelID, "Enter a keyword:")
// 	fmt.Scanln(&keyword)
// 	_, _ = s.ChannelMessageSend(m.ChannelID, "Enter command text:")
// 	fmt.Scanln(&text)
// 
// }

//Message handler with command statements

func messageHandler(s *discordgo.Session, m *discordgo.MessageCreate) {

	// if m.ChannelID == "548654319130509323" {
	// 	if m.Author.ID == "142542227133038592" {
	// 		_, _ = s.ChannelMessageSend("135692305934843905", m.Content)
	// 	}
	// }

	if strings.HasPrefix(m.Content, config.BotPrefix) {
		user := m.Author
    if user.ID == BotID || user.Bot {
        //Do nothing because the bot is talking
        return
    }
		content := m.Content
		channel := m.ChannelID
		if content == "!!commands" {
			_, _ = s.ChannelMessageSend(channel, "!!roll, !!roll20, !!dre, !!ratzpig, !!kraftysk, !!efrt, !!ponderna, !!rock, !!paper, !!scissors, !!pasta")
		}
		
		var keyword string
		var text string
		
		if channel == "614244156528918550" {
			if content =="!!newcommand" {
				_, _ = s.ChannelMessageSend(channel, "Enter a keyword\n")
				fmt.Scanln(&keyword)
				_, _ = s.ChannelMessageSend(channel, "Enter command text\n")
				fmt.Scanln(&text)
			}
		}
		
		if content == "!!"+keyword {
			_, _ = s.ChannelMessageSend(channel, text)
		}

		if content == "!!roll" {
			userRoll := rand.Intn(6) + 1
			rollString := strconv.Itoa(userRoll)
			chanceRoll := rand.Intn(1000) + 1
			if chanceRoll == 420 {
				_, _ = s.ChannelMessageSend(channel, user.Username+" roll is OVER 9000 (.1% CHANCE POGGERS)")
			} else {
				_, _ = s.ChannelMessageSend(channel, user.Username+" rolls a "+rollString)
			}
		}

		if content == "!!roll20" {
			userRoll20 := rand.Intn(20) + 1
			rollString20 := strconv.Itoa(userRoll20)
			_, _ = s.ChannelMessageSend(channel, user.Username+" rolls a "+rollString20)
		}

		computerPlay := rand.Intn(3)
		if content == "!!rock" {

			switch computerPlay {
			case 0:
				_, _ = s.ChannelMessageSend(channel, "It's a draw! Try again!")
			case 1:
				_, _ = s.ChannelMessageSend(channel, "Rock smashes scissors "+user.Username+" wins!")
			case 2:
				_, _ = s.ChannelMessageSend(channel, "Paper covers Rock! RTSI Bot wins!")

			}
		} else if content == "!!scissors" {

			switch computerPlay {
			case 0:
				_, _ = s.ChannelMessageSend(channel, "Rock smashes Scissors! RTSI Bot wins!")
			case 1:
				_, _ = s.ChannelMessageSend(channel, "It's a draw! Try again!")
			case 2:
				_, _ = s.ChannelMessageSend(channel, "Scissors cuts Paper "+user.Username+" wins!")
			}
		} else if content == "!!paper" {

			switch computerPlay {
			case 0:
				_, _ = s.ChannelMessageSend(channel, "Paper covers Rock "+user.Username+" wins!")
			case 1:
				_, _ = s.ChannelMessageSend(channel, "Scissors cuts Paper! RTSI Bot wins!")
			case 2:
				_, _ = s.ChannelMessageSend(channel, "It's a draw! Try again!")
			}
		}

		if content == "!!dre" {
			_, _ = s.ChannelMessageSend(channel, "He is a standup individual. ")
		}
		if content == "!!pasta" {
			copypasta := rand.Intn(6)
			switch copypasta {
			case 0:
				_, _ = s.ChannelMessageSend(channel, "So you're going by @ponderNA now nerd? Haha whats up fool, it's Tanner from Highschool. Remember me? Me and the guys used to give you a hard time in school. Sorry you were just an easy target lol. I can see not much has changed. Remember Sarah the girl you had a crush on? Yeah we're married now. I make over 200k a year and drive a mustang GT. I guess some things never change huh loser? Nice catching up lol. Pathetic..")
			case 1:
				_, _ = s.ChannelMessageSend(channel, "LETS GO Austin!! (btw Austin is @ratzpig, I can use his first name because we are tight like that. Yeah I know some top players but its not a big deal to me lol)")
			case 2:
				_, _ = s.ChannelMessageSend(channel, "H-hey @ponderNA, do you remember me from Biology class? Freshman year? It's Laura. I just wanted to stop by since you missed the last reunion, I was looking for you. I always thought you were really smart and talented, but I could never work up the nerve to tell you. Anyway, I hope you're doing well...HAHA Just kidding, it's still Tanner you gullible fool lmfao. Anyway, the gym awaits, see ya man good talk.")
			case 3:
				_, _ = s.ChannelMessageSend(channel, "Hey @Kraftysk! Thanks for the quality league of legends games. I'm spectating with my son and you have become his mentor. He is going into baseball this year so he's learning how to throw just like a pro from you! Thanks again!")
			case 4:
				_, _ = s.ChannelMessageSend(channel, "i think its hilarious u kids on discord talking crap about @Dr4y and his gameplays. u wouldnt say this shit to him irl, hes so jacked. not only that but he wears the freshest clothes, eats at the chillest restaurants and hangs out with the hottest dudes. yall are pathetic lol.")
			case 5:
				_, _ = s.ChannelMessageSend(channel, "Hey guys. This is first copy pasta and I am nervous about pasting. if it does not get pasta then I will much embarrassment. I've have think about it for a couple nights now, but here goes!.")
			}
		}

		if content == "!!krafty" {
			_, _ = s.ChannelMessageSend(channel, ":poop: canadian :poop: ")
		}
		
		if content == "!!tezrik" {
			_, _ = s.ChannelMessageSend(channel, "I want lasaga ")
		}
		
		if content == "!!apple" {
			_, _ = s.ChannelMessageSend(channel, "Hey Dre. :) ")

		if content == "!!ponderna" {
			_, _ = s.ChannelMessageSend(channel, "<:BabyRage:549376941614956545>")
		}
		
		if content == "!!orc" {
			_, _ = s.ChannelMessageSend(channel, "12 btw <:LUL:549388319176523813>")
		}

		if content == "!!efrt" {
			_, _ = s.ChannelMessageSend(channel, "insha allah habibi. <:ANELE:549376956651536384>")
		}
		if user.ID == "135692210015305728" || user.ID == "135964815536422912" || user.ID == "142542227133038592" || user.ID == "135692429968932864" {
			if content == "!!live" {
				_, _ = s.ChannelMessageSend("546051639182884870", "@everyone We are live! Come hang at https://www.twitch.tv/ponderna")
			} else if content == "!!camk" {
				_, _ = s.ChannelMessageSend("546051639182884870", "@everyone We are live. Come checkout some Canadian shananigans at https://www.twitch.tv/camkraft")
			}
		}
	}
}
