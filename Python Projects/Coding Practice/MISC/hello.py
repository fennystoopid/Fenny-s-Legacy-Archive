weight = float(input("enter weight mf in kg: "))

if weight <= 2.5:
    delCost = weight * 6
elif weight > 2.5 and weight <= 5:
    delCost = weight * 5.50
elif weight > 5:
    delCost = weight * 5
else:
    print("Stupid")

print("delCost")    

