original = open("original.txt", "r")

copy = open("copy.txt", "w")

copy.write(original.read())

original.close()
copy.close()
print("Successfully copied")