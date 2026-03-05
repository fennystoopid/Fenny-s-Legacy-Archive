import admin_func

admin_func.FirstTimeStart()
while True:
    try:
        if admin_func.MainMenu() == 6:
            break
        admin_func.MainMenu()
    except ValueError:
        print("Invalid input format. Please try again..")
        continue
    except:
        print("An error have occured. Please try again..")
        continue


