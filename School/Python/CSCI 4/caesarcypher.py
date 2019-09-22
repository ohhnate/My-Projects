#Samuel Fuller
#9 Oct 2018
#This program asks for a user to input a message and select a number to encrypt by using the caesar cipher. It will then call a function to encrypt the input message and also allow the user to decrypt a message given a shift value.



def main():        #main function containing output messages 
    text = str(input("Enter a message to encrypt: "))        #input text for encryption
    shift = int(input("Enter amount to shift message: "))       #shift amount for encryption
    print("Your encrypted message is: ",encrypt(text, shift))
    text2 = str(input("Enter a message to decrypt: "))        #input text for decryption
    shift2 = int(input("How many shifts to decrypt: "))         #shift amount for decryption
    print("Your decrypted message is: ",decrypt(text2,shift2))

def encrypt(text, shift):        #encryption function encrypting a user input message
    letters = "abcdefghijklmnopqrstuvwxyz"        #stored alphabet in a variable to pick out from user input 
    encryption = ''        #blank variable to store the final encryption
    for x in text:        #for loop that will check the entire string user inputs
        if x in letters:        #if/else statement that was only used to keep any white spaces or special characters the user inputs
            loc = letters.find(x)        
            enc = (loc + shift) % 26        #caesar cipher formula housed within enc variable
            encrypted = letters[enc]        #variable that uses the enc variable to take characters from the letters variable
            encryption += encrypted         #overwrites the aforementioned encryption variable with new formula information so its no longer blank
        else:
            encryption += x        #used for blank spaces
    return encryption        #returns the final encryption
    
def decrypt(text2, shift2):        #decryption function which is mostly the same as the encryption function minus variable names and formula change
    letters2 = "abcdefghijklmnopqrstuvwxyz"
    decryption = ''
    for y in text2:
        if y in letters2:
            loc2 = letters2.find(y)
            dec = (loc2 - shift2) % 26        #used subtraction instead of addition in the formula in order to decrypt
            decrypted = letters2[dec]
            decryption += decrypted
        else:
            decryption += y
    return decryption

main()        #calls main function to run all cipher
    
