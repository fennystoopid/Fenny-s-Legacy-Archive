user_list = []

sizing = int(input("Input the size of list: "))

def list(size):
    for i in range(1,size+1):
        data = int(input(f"Insert the {i} of the data:"))
        user_list.append(data)

    ans = sum(user_list)
    print(f"Total is {ans}")
    print(user_list)
        
list(sizing)
