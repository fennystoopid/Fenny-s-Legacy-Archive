#Obtaining input
print("Please enter your credentials")
EmpName = input("Name: ")
HourWorked = int(input("Total number of hours worked: "))
WageRate = int(input("Hourly wage rate: RM"))

#Calculation, if the Hour worked is over 40 (Overtime)
if HourWorked > 40:
    RlrHour = 40 * WageRate
    OTHour = (HourWorked - 40) * WageRate * 1.5
    WeeklyPay = RlrHour + OTHour
#Calculation, if the hour worked is less or equal 40 (not overtime)
elif HourWorked <= 40:
    RlrHour = HourWorked * WageRate
    WeeklyPay = RlrHour

print(f"\n{EmpName}, your weekly pay would be RM{WeeklyPay:.2f}\nHave a nice day.")