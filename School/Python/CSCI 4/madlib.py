#Samuel Fuller

#Date Created: 4 September 2018
#Date Updated: 6 September 2018

#This is a program that requests input from a user to be included into a short story.
#The user will be prompted to enter information and once all of the prompts are answered the answers will autofill into the story for the users viewing pleasure.
#Also known as a madlib.




#All of my variables holding user submitted information to be autofilled into the madlib. (Input)

age = int(input("Enter your age: "))
noun = str(input("Enter a thing: "))
adjective = str(input("Enter an adjective: "))
noun2 = str(input("Enter a person: "))
noun3 = str(input("Enter a thing: "))
noun4 = str(input("Enter a thing: "))
noun5 = str(input("Enter a place: "))
food = str(input("Enter a food: "))
money = float(input("Enter any decimal: "))



#Printed strings of the madlib sentences containing the user submitted information. (Output)

print('')
print('')
print("One summer day I was hanging out talking on the " + (noun) + ".")
print("Suddenly, I heard a " + (adjective) + " sound from the " + (noun5) + ".")
print("I ran into the " + (noun5) + " and saw " + (noun2) + " eating out of the " + (noun3) +".")
print("I grabbed my " + (noun4) + " and managed to chase it out of the house.")
print("I can't believe this has happened " + str(age) + " times!")
print("Luckily it didn't eat the " + (food) + " or my parents would have been furious!")
print("This whole ordeal ended up costing me $" + str(format(money, '.2f')) +".")
print("The End!")




