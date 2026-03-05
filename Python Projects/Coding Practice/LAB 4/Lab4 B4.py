Num1 = int(input("Enter Number 1:"))
Num2 = int(input("Enter Number 2:"))

if Num1 > Num2:
    print(f"{Num1} is greater than {Num2}")
elif Num2 > Num1:
    print(f"{Num2} is greater than {Num1}")
elif Num1 == Num2:
    print(f"{Num1} and {Num2} is both equal")
else:
    print("Either you entered the number wrong or you're dumb")
