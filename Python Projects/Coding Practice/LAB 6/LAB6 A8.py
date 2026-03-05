def max(num1,num2):
    if num1 > num2:
        print(num1)
    elif num2 > num1:
        print(num2)

def info():
    val1, val2 = input("Insert two num").split()
    biggest = max(int(val1),int(val2))

    print(biggest)

info()
