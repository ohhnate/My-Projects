#Samuel Fuller

#Date Created: September 11th 2018

#Date Updated:

#Description: This program allows for users to choose fruit they would like to purchase from a menu. The user can input how many they would like based on a price and after purchasing a receipt will be printed with the quantity, taxes, and total cost.




# Welcome greeting

print("")
print("")

print("Welcome to Sam's Fruit Stand!")

print("")
print("")

#The input section containing a menu for customers and customer item selection/quantity.

print("""We currently have the following available for you to choose from:

1. Apples..........................$0.50/each
2. Oranges.........................$0.60/each
3. Bananas.........................$0.40/each
4. Grapes..........................$0.10/each
5. Melons..........................$1.00/each""")

print("")
print("")

apples = int(input("How many apples would you like? "))

oranges = int(input("How many oranges would you like? "))

bananas = int(input("How many bananas would you like? "))

grapes = int(input("How many grapes would you like? "))

melons = int(input("How many melons would you like? "))

print("")


#The output section for the customers receipt containing the total cost for each item, quantity purchased, taxes, and the final cost.

apples_total = format((apples)*float(.50), '.2f')
oranges_total = format((oranges)*float(.60), '.2f')
bananas_total = format((bananas)*float(.40), '.2f')
grapes_total = format((grapes)*float(.10), '.2f')
melons_total = format((melons)*float(1.00), '.2f')
quantity = int(apples)+int(oranges)+int(bananas)+int(grapes)+int(melons)
sub_cost = format(float((apples_total))+float((oranges_total))+float((bananas_total))+float((grapes_total))+float((melons_total)), '.2f')
taxes = format(float((sub_cost))*0.08, '.2f')
total_cost = format(float(sub_cost)+float((taxes)), '.2f')

print("")
print("You purchased " + str((apples)) + " apples for: " + "$" + str((apples_total)))
print("You purchased " + str((oranges)) + " oranges for: " + "$" + str((oranges_total)))
print("You purchased " + str((bananas)) + " bananas for: " + "$" + str((bananas_total)))
print("You purchased " + str((grapes)) + " grapes for: " + "$" + str((grapes_total)))
print("You purchased " + str((melons)) + " melons for: " + "$" + str((melons_total)))
print("Quantity purchased: " + str((quantity)) + " total fruits")
print("Taxes(8%):","$" + str((taxes)))
print("Total cost:","$" + str((total_cost)))

print("")
print("")

print("Thank you for shopping at Sam's Fruit Stand!")






