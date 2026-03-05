List = [65, 75, 85, 95, 105]
validNumbers = []

while True:
    num = int(input("Insert a number:"))

    if int(num) > 0 and int(num) < 100:
        validNumbers.append(num)
    else:
        print("Invalid range")

    sum = 0
    for i in validNumbers:
        sum = sum + i
    print(sum)

    multi = 1
    for i in validNumbers:
        multi = multi * i
    print(multi)