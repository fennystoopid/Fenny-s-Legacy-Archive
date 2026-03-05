def Find_Total():
    File_Name = input("Insert file name to access:")
    foodcount = {
                    "Apple" : 0,
                    "Carrot" : 0,
                    "Radish" : 0
                }
    with open(File_Name, "r") as file:
        rlines = file.readlines()
        if rlines:
            for lines in rlines:
                if "Apple" in lines:
                    foodcount["Apple"] += 1
                elif "Carrot" in lines:
                    foodcount["Carrot"] += 1
                elif "Radish" in lines:
                    foodcount["Radish"] += 1

    return foodcount["Apple"], foodcount["Carrot"], foodcount["Radish"]

Apple, Carrot, Radish = Find_Total()

print(f"{Apple} Apple\n{Carrot} Carrot\n{Radish} Radish")