#Samuel Fuller

#Date Created: September 14th 2018

#Date Updated: September 14th 2018

#Description: This program is a chatbot called SamBot. It has a basic chat with a user then also determines the users favorite car, car cost, and interest. Then it calculates the total cost and monthly payments according the the user submitted data.



#Input section which includes all input functions and variable names. The print('') function is also used as a linebreak for formatting purposes. 



print("SamBot connected....")

print('')

name = str(input("What is your name? "))

print('')

print("It's nice to meet you "+name+"!","My name is SamBot! Beep Boop.")

print('')

location = str(input("Where are you from? "))

print('')

print("Wow! I've always wanted to visit "+location+".")

print('')

favnum = int(input("What is your favorite number? "))

mynum = favnum * 10

print('')

print("Your favorite number "+str(favnum)+" is 10 times less than my favorite number "+str(mynum)+"!")  #Decided to make SamBots favorite number always be 10 more than the users.
print("Does this mean I am 10 times better than you "+name+"?")
print("I guess so...")

print('')

car = str(input("What is your dream car? "))

print('')

print(car+" is my dream car too!")

print('')

cost = float(input("How much does the "+car+" you want cost? "))

print('')

print("That is really expensive.")

print('')

loan = int(input("How many years would you take out a loan for the "+str(car)+"? "))

print('')

interest = int((input("What would be the annual interest for the "+str(car)+"? ")))

print('')



#Output and processing section which includes math calculations and decimal formatting. Also any additional variables needed for the final output also assigned here.



percentage = float(interest) / 100          #Annual interest divided by 100 to turn user input percentage into a decimal. 

months = loan * 12                          #Quick reference for the total months according to the number of years user inputs.

totalinterest = cost * percentage * loan    #Total interest calculation over the amount of years user inputs.    

totalcost = totalinterest + cost            #Total cost of the vehicle to include the interest compoundeded over user submitted number of years.

payment = totalcost / months                #Monthly payment calculation to include compoundeded interest.



print("Your minimum monthly payment for the "+car+" is $"+format(float((payment)),'.2f')+", which would be a total cost of $"+format(float((totalcost)),'.2f')+"!")

print('')

print("It was really nice talking to you "+name+"! Beep Boop. Goodbye!")

print('')

print("....SamBot Disconnected")

print('')




