
file = open("test.txt", "x") 

file.writelines(["Hello world", "I’m Python", "Don’t afraid to use me\n"]) 

print(file.readline())