Characters = []

sizing = int(input("Input the character amount: "))

def combine(size):
    for i in range(1,size+1):
        data = input(f"Insert the {i} of the characters:")
        Characters.append(data)

    print(''.join(Characters))

        
combine(sizing)