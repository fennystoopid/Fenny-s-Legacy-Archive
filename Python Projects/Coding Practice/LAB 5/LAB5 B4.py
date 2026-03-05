num = int(input("Please enter a number: "))
reverse = 0


while num:
    digit = num % 10
    reverse = reverse * 10 + digit
    num //= 10

print(f"Reverse number: {reverse}")