jamal = [1,2,3,4,5]
jamal3 = [1,2,3,4,5]
jamal2 = ['ad','fd','gh','ho','ko']

print(jamal is jamal2)
print(jamal == jamal2)
jamal = jamal2
print(jamal is jamal2)
print(jamal == jamal2)
print(jamal is jamal3)


print(jamal[:-3])
print(jamal[0:-2])

x = ['xy','ab']
for i in x:
    i.upper()
    
print(x)

caplist = [word.upper() for word in x]
print(caplist)
