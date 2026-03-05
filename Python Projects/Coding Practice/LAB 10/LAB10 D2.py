#test tuple
test_tup =(1,2,3,4)

#input number to check if the inputted number is in the tuple
number = int(input("Input a number to check:"))

#checking if num in the tuple, returns True if there is, False if nope
check = number in test_tup

#prints out ther results based on the check
if check == True:
    print("This number is in the tuple")
elif check == False:
    print("This number is not in tuple")

