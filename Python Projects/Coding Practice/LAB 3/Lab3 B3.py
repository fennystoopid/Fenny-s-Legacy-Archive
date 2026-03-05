# input two numbers
one, two = input("Input two numbers: ").split()

#using temp variable to swap both inputs GENERAL WAY I LOVE I"M SO GENERIC
temp = one
one = two
two = temp

#second way, boo python lamee
#one, two = two, one

#prints it out
print(f"The first num swapped is {one}.\nThe second num swapped is {two}.")