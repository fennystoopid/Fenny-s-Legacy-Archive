while True:
    print(f"i. Calculate the area of rectangle.\nii. Check entered character is vowel or consonant.\niii. Find smallest of three numbers.\nEnter -1 to terminate")
    Select = int(input(">"))

    if Select == 1:
        print("\n--Area Rectangle--")
        leng = input("Input the length of the rectangle: ")
        width = input("Input the width of the rectangle: ")
        area = int(leng) * int(width)
        print(f"The area is {area}\n--End of execution--\n")

    elif Select == 2:
        print("\n--Character vowel or consonant--")
        ch = input("Enter a word: ")
        if ch in 'aeiou':
            print(f"{ch} is vowel\n--End of execution--")
        else:
            print(f"{ch} is consonant\n--End of execution--")

    elif Select == 3:
        print("\n--Find smallest of three num--")
        n1,n2,n3 = input("Input three different numbers, seperated by spaces")
        if n1 < n2 and n1 < n3:
            print(f"{n1} is the smallest")
        elif n2 < n1 and n2 < n3:
            print(f"{n2} is the smallest")
        elif n3 < n1 and n3 < n2:
            print(f"{n3} is the smallest")
        else:
            print("bruh")
        print("--End of execution--")        

    elif Select == -1:
        print("Program terminated, thank you for using.")
        break
