number = []

for i in range(20):
    num = int(input(f"Input the {i + 1} of the number in the list:"))
    number.append(num)

smallest = min(number)
highest = max(number)
total = sum(number)
average = total / 20

print(f"""
    Smallest number: {smallest}
    Highest number: {highest}
    Total: {total}
    Average: {average}""")
