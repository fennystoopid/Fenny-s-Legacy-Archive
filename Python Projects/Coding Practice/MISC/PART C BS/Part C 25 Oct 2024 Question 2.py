#input the fahrenheit
Fah = float(input("Enter Fahrenheit Temperature: "))

#calculation
Cel = 5.0 / 9.0 * (Fah - 32)

#rounding up the number, for cleaner output
#print results
print(f"{Fah} Fahrenheit is equals to {"%.3f" % Cel}\nSee you again\n")