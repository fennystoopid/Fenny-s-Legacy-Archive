## Pathlib library, modern way for file handling python 3 and up.
from pathlib import Path

import os

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

#append existing text file
def append_file(file, data):
    textfile = open(file , "a")
    textfile.write(data)
    textfile.close()


## First Time startup
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

#main menu
def MainMenu():
    print("""
    -[UMS ADMINISTRATOR MENU]-
        [1]Add Courses
        [2]Add/Remove Students
        [3]Manage Lecturers
        [4]Generate Report
        [5]View All Data
        [6]Terminate/Exit
    """)
    num = int(input("Please input option: "))
    
    # match case main menu, like break case thing
    match num:
        # pattern 1
        case 1:
            add_course()
            return True
        # pattern 2
        case 2:
            add_student()
            return True
        # pattern 3
        case 3:
            add_lecturer()
            return True
        # pattern 4
        case 4:
            report()
            return True
        # pattern 5
        case 5:
            print("Five")
            return True
        # pattern 6
        case 6:
            print("Program terminated. Thank you and have a nice day.")
            return False
        # default pattern
        case _:
            print("Invalid option")

## Add Course function
def add_course():
    try:
        course_code, course_name, course_credit = input("""
        Please insert course code, name and credit respectively.
        Must be seperated by spaces : 
        """).split()
        append_file(FindFilePath('Courses.txt'), f"\n{course_code} {course_name} {course_credit}")

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_course()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        add_course()

## Add Students function
def add_student():
    try:
        student_id, name, student_class, department = input("""
        Please insert student ID, student name, student class and department respectively.
        Must be seperated by spaces :
        """).split()
        append_file(FindFilePath('Student.txt'), f"\n{student_id} {name} {student_class} {department}")

    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_student()

    except:
        print("An error occured.. Please try again.")
        add_student()

## Add lecturer function
def add_lecturer():
    try:
        lec_name, department = input("""
        Please insert lecturer name and department respectively.
        Must be seperated by spaces :
        """).split()
        append_file(FindFilePath('Lecturer.txt'), f"\n{lec_name} {department}")

    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_lecturer()

    except:
        print("An error occured.. Please try again.")
        add_lecturer()    

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

while MainMenu() == True:
    MainMenu()
