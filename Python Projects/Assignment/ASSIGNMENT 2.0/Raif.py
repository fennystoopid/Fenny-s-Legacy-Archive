import os

# Identification of the file names
MODULES_FILE = "modules.txt"
STUDENTS_FILE = "students.txt"
ENROLLMENTS_FILE = "enrollments.txt"
GRADES_FILE = "grades.txt"
ATTENDANCE_FILE = "attendance.txt"

def create_file(file):
    textfile = open(file, "x")
    textfile.close()

create_file(MODULES_FILE)

def load_modules():
    """Provide existing available modules from the modules file."""
    try:
        with open(MODULES_FILE, "r+") as file:  # "r" for read mode
            modules = [line.strip() for line in file]
            print(f"Modules loaded: {modules}")
            return modules
    except FileNotFoundError:
        print(f"File not found: {modules}")
        return []

def load_enrollment(student_id):
    """Provide enrollments to a specific student."""
    try:
        with open(ENROLLMENTS_FILE, "r") as file:
            return [line.strip() for line in file if line.startswith(student_id)]
    except FileNotFoundError:
        return[]

def enroll_in_module(student_id, module):  # student_id can be int/str
    """Enroll students to their desired module."""
    try:
        with open(ENROLLMENTS_FILE, "a") as file:  # "a" for append mode
            file.write(f"Student {student_id} has been enrolled in {module} and recorded\n")
    except FileNotFoundError:
        return[]

def unenroll_from_module(student_id, module):
    """Unenroll students from the selected module."""
    try:
        enrollments = load_enrollment(student_id)
        updated_enrollments = [enrollment for enrollment in enrollments if enrollment.split(",")[1].strip() != module]

        with open(ENROLLMENTS_FILE, "w") as file:  # "w" for write mode
            for enrollment in updated_enrollments:  # iterate over each enrollment in the updated list
                file.write(enrollment + "\n")
    except FileNotFoundError:
        return[]

def view_grades(student_id):
    """View students grades"""
    try:
        with open(GRADES_FILE, "r") as file:
            found = False
            for line in file:
                if line.startswith(student_id):  # Check if the line starts with the student_id
                    print(line.strip())  # Print the grade line
                    found = True
            if found:
                print("Grades displayed above.")
            else:
                print(f"No grades found for student ID: {student_id}")
    except FileNotFoundError:
        print("Grades file does not exist.")

def access_attendance_records(student_id):
    """Access students' attendance records."""
    try:
        with open(ATTENDANCE_FILE, "r") as file:
            found = False
            for line in file:
                if line.startswith(student_id):
                    print(line.strip())  # Print the attendance record line
                    found = True
            if found:
                print("Attendance records displayed above.")
            else:
                print(f"No attendance records found for student ID: {student_id}")
    except FileNotFoundError:
        print("Attendance record does not exist.")

def menu():
    student_id = input("Enter your Student ID: ")
    while len(student_id) < 8:
        print("Invalid input. Student ID must be 8 characters long. Please try again.... ")
        student_id = input("Please enter your Student ID again: ")
    print(f"Student ID acepted: {student_id}")
    while True: #Start an infinite loop
        try:
            choice = int(input("""
1. View Available Modules
2. Enroll in Module
3. View Grades
4. Access Attendance Record
5. Unenroll from Module
6. Exit
                     ~~~~~~~~~~PLEASE SELECT YOUR CHOICE OF MENU~~~~~~~~~~
Enter your desired menu number: """))

            match choice:
                case 1:
                    modules = load_modules()
                    print("\nAvailable Modules:")
                    if modules:
                        for module in modules:
                            print(module)
                    else:
                        print("No modules available.")

                case 2:
                    module = input("Enter the module you desire to enroll in: ").title()
                    enroll_in_module(student_id, module)
                    print(f"You have successfully enrolled in {module}. Have fun and good luck studying the module!")

                case 3:
                    print("\nYour Grades are:")
                    view_grades(student_id)

                case 4:
                    print("\nYour Attendance Records are:")
                    access_attendance_records(student_id)

                case 5:
                    module = input("Enter the module you would like to unenroll from: ")
                    unenroll_from_module(student_id, module)
                    print(f"You have successfully unenrolled from {module}. Thank you!")

                case 6:
                    print("You have decided to exit. Exiting the program..... \nThank you!")
                    break
                case _:
                    print("Invalid choice! Please select a number from 1 to 6.")
        except ValueError:
            print("Invalid input! Please enter a number.")
        except:
            print(f"An unexpected error occurred.....")
menu()