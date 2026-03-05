## Pathlib library, modern way for file handling python 3 and up.
from pathlib import Path

## Relative path file system
def FindFilePath(filename):
    ## Get the current working directory
    cwd = Path.cwd()

    ## Get the directory of the executing script
    mod_path = Path(__file__).parent  

    ## Define your relative path
    relative_path_1 = filename

    # Outputs an absolute path to the target directory
    src_path_1 = (mod_path / relative_path_1).resolve()
    return src_path_1

#create new text file
def create_file(file):
    textfile = open(file, "x")
    textfile.close()

#append existing text file/editing text file without overwriting it, just adding more.
def append_file(file, data):
    textfile = open(file , "a")
    textfile.write(data)
    textfile.close()

#delete existing file.
#def delete_file(file, data):
 #   textfile = open(file , "a")
  #  textfile.write(data)
   # textfile.close()###

## First Time startup, since no text file is created during your first time :3
def FirstTimeStart():
    try:
        #Create Course Text File
        create_file(FindFilePath('Courses.txt'))
        #Create Student Text file
        create_file(FindFilePath('Student.txt'))
        #Create Lecturer file
        create_file(FindFilePath('Lecturer.txt'))
        print("First time startup complete!")
    except FileExistsError:
        print("File exist! Continuing program..")

## COURSES ##
def course_mainmenu():
    try:
        choice = int(input("""\n
        Do you like to add a new course or remove existing courses?
        [1] Add
        [2] Remove
        [3] Update
        [0] Back to main menu
        
        Please input option:
        """))
        if choice == 1:
            add_course()
        elif choice == 2:
            remove_course()
        elif choice == 3:
            update_course()
        elif choice == 0:
            return
        else:
            ValueError
    except ValueError:
        print("Invalid input. Try again..")
        course_mainmenu()
    except:
        print("An error have occurred..")
        course_mainmenu()


## Add Course function
def add_course():
    try:
        #Determine the amount of courses based on number of lines
        with open(FindFilePath('Courses.txt')) as f:
            Courses_count = sum(1 for _ in f if _.rstrip('\n'))

        course_code, course_name, course_credit = input("""
                                                        
        Please insert course code, name and credit respectively.
        Must be seperated by spaces : 
        """).split()

        #Putting those bullet point number thingmagiggy
        if Courses_count == 0:
            append_file(FindFilePath('Courses.txt'), f"{course_code} {course_name} {course_credit}")
        else:
            append_file(FindFilePath('Courses.txt'), f"\n{course_code} {course_name} {course_credit}")


    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_course()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        add_course()

#remove courses
def remove_course():
    try:
        course_removal = input("""
                               
        Please input the course ID you want to remove: 
        """)
        with open(FindFilePath('Courses.txt'),"r+") as f:
            new_f = f.readlines()
            f.seek(0)
            for line in new_f:
                if course_removal not in line:
                    f.write(line)
            f.truncate()
            

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        remove_course()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        remove_course()

def update_course():
    try:
        course_query = input("""    
        Please input the course info you want to update.
        Include name, code and credit seperated by spaces: 
        """)
        course_code, course_name, course_credit= input("""
        Please insert the new student info respectively to replace.
        Must be seperated by spaces, okay!:
        """).split()
        with open(FindFilePath('Courses.txt'),"r+") as f:
            new_f = f.read()
            f.seek(0)
            f.truncate()
            f.write(new_f.replace(course_query,f'{course_code} {course_name} {course_credit}'))

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        update_course()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        update_course()

## STUDENTS ##
def student_mainmenu():
    try:
        choice = int(input("""\n
        Do you like to add a new student or remove existing students?
        [1] Add
        [2] Remove
        [3] Update
        [0] Back to main menu
        
        Please input option:
        """))
        if choice == 1:
            add_student()
        elif choice == 2:
            remove_student()
        elif choice == 3:
            update_student()
        elif choice == 0:
            return
        else:
            ValueError
    except ValueError:
        print("Invalid input. Try again..")
        student_mainmenu()
    except:
        print("An error have occurred..")
        student_mainmenu()

## Add Students function
def add_student():
    try:
        #Determine the amount of students based on number of lines
        with open(FindFilePath('Student.txt')) as f:
            Stud_count = sum(1 for _ in f if _.rstrip('\n'))

        #Input data
        student_id, name, student_class, department = input("""
                                                            
        Please insert student ID, student name, student class and department 
        respectively.
        Must be seperated by spaces :
        """).split()

        #Putting those bullet point number thingmagiggy
        if Stud_count == 1:
            append_file(FindFilePath('Student.txt'), f"{student_id} {name} {student_class} {department}")
        else:
            append_file(FindFilePath('Student.txt'), f"\n{student_id} {name} {student_class} {department}")

    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_student()

    except:
        print("An error occured.. Please try again.")
        add_student()

##Remove Student
def remove_student():
    try:
        student_removal = input("""
                                
        Please input the student ID you want to remove: 
        """)
        with open(FindFilePath('Student.txt'),"r+") as f:
            new_f = f.readlines()
            f.seek(0)
            for line in new_f:
                if student_removal not in line:
                    f.write(line)
            f.truncate()

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        remove_student()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        remove_student()

def update_student():
    try:
        student_query = input("""    
        Please input the student info you want to update.
        Include name, department, etc seperated by spaces: 
        """)
        student_id, name, student_class, department = input("""
        Please insert the new student info respectively to replace.
        Must be seperated by spaces, okay!:
        """).split()
        with open(FindFilePath('Student.txt'),"r+") as f:
            new_f = f.read()
            f.seek(0)
            f.truncate()
            f.write(new_f.replace(student_query,f'{student_id} {name} {student_class} {department}'))

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        update_student()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        update_student()

## LECTURERS ##
def lecturer_mainmenu():
    try:
        choice = int(input("""\n
        Do you like to add a new lecturer or remove existing lecturers??
        [1] Add
        [2] Remove
        [3] Update
        [0] Back to main menu
        
        Please input option:
        """))
        if choice == 1:
            add_lecturer()
        elif choice == 2:
            remove_lecturer()
        elif choice == 3:
            update_lecturer()
        elif choice == 0:
            return
        else:
            ValueError
    except ValueError:
        print("Invalid input. Try again..")
        lecturer_mainmenu()
    except:
        print("An error have occurred..")
        lecturer_mainmenu()

## Add lecturer function
def add_lecturer():
    try:
        #Determine the amount of lecturers based on number of lines
        with open(FindFilePath('Lecturer.txt')) as f:
            Lec_count = sum(1 for _ in f if _.rstrip('\n'))

        lec_name, department = input("""
                                     
        Please insert lecturer name and department respectively.
        Must be seperated by spaces :
        """).split()

        #Putting those bullet point number thingmagiggy
        if Lec_count == 0:
            append_file(FindFilePath('Lecturer.txt'), f"{lec_name} {department}")
        else:
            append_file(FindFilePath('Lecturer.txt'), f"\n{lec_name} {department}")

    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_lecturer()

    except:
        print("An error occured.. Please try again.")
        add_lecturer()    

##Remove Lecturer
def remove_lecturer():
    try:
        lecturer_removal = input("""
                                 
        Please input the lecturer name you want to remove: 
        """)
        with open(FindFilePath('Lecturer.txt'),"r+") as f:
            new_f = f.readlines()
            f.seek(0)
            for line in new_f:
                if lecturer_removal not in line:
                    f.write(line)
            f.truncate()

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        remove_lecturer()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        remove_lecturer()

def update_lecturer():
    try:
        lecturer_query = input("""    
        Please input the lecturer info you want to update.
        Include name and department, seperated by spaces: 
        """)
        name, department = input("""
        Please insert the new lecturer info respectively to replace.
        Must be seperated by spaces:
        """).split()
        with open(FindFilePath('Lecturer.txt'),"r+") as f:
            new_f = f.read()
            f.seek(0)
            f.truncate()
            f.write(new_f.replace(lecturer_query,f'{name} {department}'))

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        update_lecturer()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        update_lecturer()

## REPORT ##
## producing a simple report
def report():
    #Total Students 
    with open(FindFilePath('Student.txt')) as f:
        Stud_count = sum(1 for _ in f if _.rstrip('\n'))

    #Active Courses
    with open(FindFilePath('Courses.txt')) as f:
        Courses_count = sum(1 for _ in f if _.rstrip('\n'))

    #Faculty
    with open(FindFilePath('Lecturer.txt')) as f:
        Lec_count = sum(1 for _ in f if _.rstrip('\n'))

        print(f"""
        [REPORT]
        Total student = {Stud_count}
        Active courses = {Courses_count}
        Faculty = {Lec_count}
        """)

##View ALL DATA##
def viewalldata():
    #Total Students 
    with open(FindFilePath('Student.txt'), 'r') as f:
        #Read the lines of the file
        f_l = f.readlines()
        Bil = 0

        print("\nSTUDENTS")
        #print each lines
        for line in f_l:
            Bil = Bil + 1
            print(f"{Bil}. {line.strip()}")

    #Active Courses
    with open(FindFilePath('Courses.txt'), 'r') as f:
        #Read the lines of the file
        f_l = f.readlines()
        Bil = 0

        print("\nCOURSES")
        #print each lines
        for line in f_l:
            Bil = Bil + 1
            print(f"{Bil}. {line.strip()}")

    #Faculty
    with open(FindFilePath('Lecturer.txt'), 'r') as f:
        #Read the lines of the file
        f_l = f.readlines()
        Bil = 0

        if f_l:
            print("\nLECTURERS")
            #print each lines
            for line in f_l:
                Bil = Bil + 1
                print(f"{Bil}. {line.strip()}")


#main menu
def MainMenu():
    print("""
    -[UMS ADMINISTRATOR MENU]-
        [1]Add/Remove Courses
        [2]Add/Remove Students
        [3]Add/Remove Lecturers
        [4]Generate Report
        [5]View All Data
        [6]Terminate/Exit
    """)
    num = int(input("Please input option: "))

    # match case main menu, like break case thing
    match num:
        # pattern 1
        case 1:
            course_mainmenu()
        # pattern 2
        case 2:
            student_mainmenu()
        # pattern 3
        case 3:
            lecturer_mainmenu()
        # pattern 4
        case 4:
            report()
        # pattern 5
        case 5:
            viewalldata()
        # pattern 6
        case 6:
            print("Program terminated. Thank you and have a nice day.")
            return 6
        # default pattern
        case _:
            print("Invalid option")
