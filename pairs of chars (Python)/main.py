# Deletes all of identical characters from an input string

string = "aaabbcda"
lastChar = ""
printStr = ""
counter = 0

for char in string:
    counter += 1
    if lastChar == "":
        lastChar = char
    else:
        if char == lastChar:
            lastChar = ""
        else:
            printStr += lastChar
            lastChar = char
            if len(string) == counter:
                printStr += lastChar

print(printStr)
quit()