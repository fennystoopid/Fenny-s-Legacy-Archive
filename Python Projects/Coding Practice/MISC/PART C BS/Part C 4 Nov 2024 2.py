#Obtaining input
YearExp = int(input("Enter number of years of experience: "))
Age = int(input("Enter age: "))
Qualified = int(input("Qualified (1 - Yes, 0 - No): "))

#First 
if Qualified == 1 and YearExp > 5 and Age > 30:
    print("Decision: Call for Interview")
#Second
elif Qualified == 1 and YearExp > 5 and Age < 30:
    print("Decision: Called for Interview")
#Third condition
elif Qualified == 1 and YearExp < 5 and Age > 30:
    print("Decision: Rejected")
#Fourth condition
elif Qualified == 1 and YearExp < 5 and Age < 30:
    print("Decision: Record kept for later notice")
#Fifth Condition
elif Qualified == 0 and YearExp > 5 and Age > 30:
    print("Decision: Called for Interview")
#Sixth Condition
elif Qualified == 0 and YearExp > 5 and Age < 30:
    print("Decision: Record kept for later notice")
#Seventh Condition
elif Qualified == 0 and YearExp < 5 and Age > 30:
    print("Decision: Rejected")
else:
    print("Decision: Rejected")    