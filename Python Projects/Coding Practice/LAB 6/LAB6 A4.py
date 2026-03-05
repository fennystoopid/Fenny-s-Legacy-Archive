def Outer(y,z):
    def Inner(a,b):
        return a+b
    
    return Inner(y,z) + 5

result = Outer(10,20)

print(result)