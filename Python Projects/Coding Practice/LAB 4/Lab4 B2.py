yearinp = int(input(f"Please input the year to check\n>"))

Check1 = yearinp % 4 == 0
Check2 = yearinp % 100 == 0
Check3 = yearinp % 400 == 0

if Check1 == True and Check2 == False or Check3 == True:
    print(f"{yearinp} is 99.9% leap year")
else:
    print(f"{yearinp} is not a leap year")

