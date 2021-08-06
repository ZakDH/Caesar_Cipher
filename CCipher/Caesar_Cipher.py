def getMode():
    while True:
        choice = input("1. Encryption\n2. Decryption\n3. Brute Force\nEnter your choice(1, 2 or 3)\n")
        if choice == "1" or choice == "2" or choice == "3":
            return choice
        else:
            print("Please enter a valid option\n")
def getMessage():
    while True:
        msg = input("Enter a message:\n")
        return msg
def getKey():
    while True:
        key = 0
        key = int(input("What key (1-26) do you want to use?:\n"))
        if key >= 1 and key <= 26:
            return key

def translateText(choice, message, key):
    translated = ''
    for symbol in message:
        if symbol.isalpha():
            num = ord(symbol)
            num += key
            if symbol.isupper():
                if num > ord('Z'):
                    num -=26
                elif num < ord('A'):
                    num += 26
            elif symbol.islower():
                if num > ord('z'):
                    num -=26
                elif num < ord('a'):
                    num += 26
            translated += chr(num)
        else:
            translated += symbol
    return translated

choice = getMode()
message = getMessage()
if choice != "3":
    key = getKey()
print('Your translated text is:')
if choice != "3":
    print(translateText(choice, message, key))
else:
    for key in range(1, 26 + 1):
        print(key, translateText('3', message, key))

k = input("Please close to exit")

