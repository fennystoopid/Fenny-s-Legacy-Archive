Word =  "I am a good boy/girl but my parents always scold me"

print(f"The length of string = {len(Word)}")

print(Word[0:21])

newWord = Word.replace("parents", "lecturers")
print(newWord)

Addition = "because I just pretend to be good, HAHAHA" 
print(newWord + " " + Addition)

print(Word[0:7] + Word[7:11].upper() + Word[11:])

print(newWord + " " + Addition[0:35] + Addition[35:].lower())