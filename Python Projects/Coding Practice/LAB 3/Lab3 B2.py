#input two numbers
one, two = input("Two numbers to operate:").split()

#operational stuff
ans1 = int(one) + int(two)
ans2 = int(one) - int(two)
ans3 = int(one) * int(two)
ans4 = int(one) / int(two)
ans5 = int(one) % int(two)
ans6 = int(one) ** int(two)

print(f"{one} + {two} = {ans1}\n{one} - {two} = {ans2}\n{one} * {two} = {ans3}\n{one} / {two} = {ans4}\n{one} % {two} = {ans5}\n{one} ** {two} = {ans6}")