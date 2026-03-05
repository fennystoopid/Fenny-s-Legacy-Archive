print("[Please type in your info]")
Name = input("Name: ")
Marital = input("Marital status ('M'arried/'S'ingle): ")

if Marital == "M":
    print("You're insured yippie!")
elif Marital == "S":
    Gender = input("Gender ('M'ale/'F'emale): ")
    Age = int(input("Age: "))
    if Gender == "M" and Age > 30:
        print("You're insured yippie! Sad")
    elif Gender == "F" and Age > 25:
        print("You're insured yippie! You single wanna miggle?")
    else:
        print("You're not insured..")