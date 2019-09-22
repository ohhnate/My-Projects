#Samuel Fuller
#Date Created: 1 November 2018
#Last Updated: 23 November 2018
#Game of Pig. The user rolls dice versus the AI. The user can choose to hold points for the next turn or roll again. User or CPU first to 100 wins. The CPU's turn is all automated (behind the scenes)

import random
   
#function that just prints out the rules for the game
def rules():
    print("The rules are as follows: ")
    print("You will play 1v1 against a computer player. You or the cpu will roll 1 die.")
    print("If the die lands on 1 you will get 0 points and it is the other players turn.")
    print("If the die lands on any other number you can hold the points and give the other player a turn by pressing h.")
    print("Or you can roll again to increase your point total by pressing r.\nHowever, if you roll a 1 your points for your turn will be 0.")
    print("The first player to 100 points or more will be the winner.\n")

#function that roles any amount of dice you want. Only 1 needed for this Game of Pig
def dice(amnt):
    rolls = []
    for x in range(0,amnt):
        r = random.randint(1,6)
        rolls.append(r)
        roll = str(rolls)[1:-1]
    return roll

#function that determines if the player or CPU will go first
def selection(user):
    select = ''
    random_turn = random.randint(1,2)
    if random_turn == 1:
        select = user
    elif random_turn == 2:
        select = 'The CPU'
    return select

#function for the players dice roll
def user_Turn():
    user_Points = 0
    user_Roll = int(dice(1))
    if user_Roll != 1:
        user_Points += user_Roll
    else: user_Points == 0
    return user_Points

#function for the computers entire turn
def cpu_Turn(Cpu_Points):
    turn_Points = 0        #variable holds the points the CPU has earned this turn
    roll_Again = 0         #variable that determines if the CPU will roll again or end its turn
    roll_Counter = 0       #variable that keeps track of how many times the CPU has rolled which is used to determine when the CPU will hold its points or roll again
    
    while roll_Again == 0 and Cpu_Points <= 99:               #added 'and Cpu_Points' so the CPU will end its  turn once it exceeds 99 points total    
        cpu_Roll = int(dice(1))
        roll_Counter += 1
        
        if cpu_Roll != 1:
            turn_Points = cpu_Roll + turn_Points
            Cpu_Points = turn_Points + Cpu_Points
        
            if roll_Counter > 3 and roll_Counter <= 6:        #if statement if the counter is greater than 3 but less than 6 it will make a little higher chance the computer will end its turn (needs adjusting for better odds)
                roll_Check = random.randint(1,2)
            
                if roll_Check == 1:
                    roll_Again = 1
            
            if roll_Counter > 6 and roll_Counter <= 10:       #if statement that runs when the counter is greater than 6 and makes it much more likely the computer will end its turn opposed to rolling again (needs adjusting)
                roll_Check2 = random.randint(1,3)
            
                if roll_Check2 == 1:
                    roll_Again = 1
                      
        if cpu_Roll == 1:                                     #if the computer rolls a 1 its turn will end and will get 0 points
            Cpu_Points = Cpu_Points - turn_Points
            turn_Points = 0
            roll_Again = 1
              
    return turn_Points

#calling the main function
     
def main():
    print("Welcome to the game of Pig!\n")
    
    rules()
    
    user = input("Enter your name to begin a game: ")
    
    print("")
    choice = selection(user)
    print(choice,"has been randomly chosen to go first.")

    game_Win = 0                 #when variable changed from 0 it should end the game and select a winner
    Cpu_Points = 0               #variable that holds the CPU total accumulated points
    User_Points = 0              #variable that holds the players total accumulated points
    current_Turn = 0             #used for the players turn in the while loop. need to work around ways to remove this variable for efficiency 
    turn_Number = 1              #variable that just shows the current turn number
    
    while game_Win == 0:         #this is the main "game is in progress" loop. it will continue to loop until someone reaches 100 points
        
        while choice == user:                                                                                       #this while loop will run as long as it is the players turn
            
            if User_Points < 100 and Cpu_Points < 100:                                                              
                rollU = user_Turn() 
                user_Rolls = input("Press and enter r to roll the dice or h to hold and end your turn: ")           #allows the user to hold their points or roll again
                
                if user_Rolls == 'r':                                                                               #when the user decides to roll again
                    this_Turn = rollU + current_Turn
                    current_Turn = this_Turn
                    
                    if rollU == 0:                                                                                  #its not 1 because in the player turn function it is just reading the total points accumulated which would be 0
                        print("Sorry you rolled a 1 and get 0 points for turn number " + str(turn_Number) + ".")
                        User_Points = User_Points - current_Turn
                        current_Turn = 0
                        print("You have a total of " + str(User_Points) + " points.")
                        turn_Number += 1
                        choice = 'The CPU'                                                                           #changes the turn from users turn to CPUs turn
                    
                    if rollU > 0:                                                                                    #if the user gets any points from their turn it will be added to the users total accumulated points
                        totalU = rollU + User_Points
                        User_Points = totalU
                        print("You rolled a: " + str(rollU)+".")
                        print("You now have a total of " + str(User_Points)+ " points.")
                        
                if user_Rolls == 'h':                                                                                #when the user decides to hold their points
                    print("You end turn number " + str(turn_Number) + " with " + str(User_Points) + " points.")
                    current_Turn = 0
                    turn_Number += 1
                    choice = 'The CPU'
                    
            elif User_Points >= 100:                                                                                  #supposed to break the while game_Win loop when the user reaches 100 points, currently broken
                game_Win = 1
                choice = "gameover"
    
        
        while choice == 'The CPU':                                                                                    #while loop for when it is the CPUs turn
            
            if Cpu_Points < 100 and User_Points < 100:
                rollC = cpu_Turn(Cpu_Points)
                totalC = rollC + Cpu_Points
                Cpu_Points = totalC
                print("The CPU ended its turn with " + str(rollC) + " points for a total of " + str(Cpu_Points) + " total points.")
                choice = user
                
            if Cpu_Points >= 100:                                                                                   #supposed to break the wihle game_Win loop when the CPU reaches 100 points, currently broken
                 game_Win = 1
                 choice = "gameover"
                 

    if User_Points >= 100:                                                                                            #supposed to print once the CPU or player reaches 100 points, also currently broken
        print("\nCongratulations "+user+"! You win!")
        
    if Cpu_Points >= 100:
        print("\nYou lose! Try again!\n")

    input("Press any key to exit")

main()
        
 
