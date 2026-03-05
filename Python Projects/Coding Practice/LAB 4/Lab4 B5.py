n1 = int(input("Enter number 1: "))
n2 = int(input("Enter number 2: "))


try:
    print(f"Division is {n1//n2}")
except ZeroDivisionError:
    print("Any number cant be zero")
    

