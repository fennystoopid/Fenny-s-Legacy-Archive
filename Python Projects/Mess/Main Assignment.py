import datetime
import os
## Pathlib library, modern way for file handling python 3 and up.
from pathlib import Path
#import admin_func (THIS is previously used for admin.. i can explain later) 
 
# Identification of the file names
MODULES_FILE = "modules.txt"
STUDENTS_FILE = "students.txt"
ENROLLMENTS_FILE = "enrollments.txt"
GRADES_FILE = "grades.txt"
ATTENDANCE_FILE = "attendance.txt"
TRANSCRIPT_FILE = "transcripts.txt"
FEEDBACK_FILE = "feedback.txt"
TUITION_FILE = "tuitionRec.txt"

student_records = {}

# ------ Admin Functions ---------
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

# ------ End Of Admin Functions ---------

# ------ Lecturer Functions ---------
#Add or update student grades for a specific module
def recordgrades():
    while True:
        try:
            data = [['student_id','Name', 'Module', 'Grade']]
            filename = 'studentgrades.csv'
            with open(filename, 'r') as file:
                lists =[]
                for line in file:
                    line = line.strip().split(',')
                    lists.append(line)
                print("Please enter the TPNumber(eg: TP123456)")
                student_idinput = input('>')
                print("Please enter the student name")
                nameinput = input(">")
                print("Please enter the module")
                moduleinput = input(">")
                print("Please enter the grade")
                gradeinput = input(">")
                header = lists[0]
                studentdata = lists[1:]

                student_existed = False
                for i in range(len(studentdata)):
                    if studentdata[i][0] == student_idinput and studentdata[i][2] == moduleinput:
                        studentdata[i][1] = nameinput
                        studentdata[i][3] = gradeinput
                        student_existed = True

                if student_existed == False:
                    new_data = [student_idinput, nameinput, moduleinput, gradeinput]
                    lists.append(new_data)


            with open(filename, 'w') as file:
                for i in lists:
                    file.write(','.join(i) + '\n')

            with open(filename, 'w') as file:
                for i in lists:
                    file.write(','.join(i))
                    file.write('\n')
            break
        except:
            print("Please check with the administrator what went wrong.")



#Display the list of students enrolled in each assigned module
def viewstudent(modules2): #variable ni akan keluarkan student on each module, maybe pakai variable yang sama untuk student register module
    while True:
        with open(modules2, 'r') as studlist:
            print(studlist.read())
            if modules2 is True:
                break

#Mark attendance for students
def attendance():
    while True:
        try:
            print("Enter the student's TPNumber")
            student_id = input(">")
            print("Enter the module")
            module = input(">")
            print("What is the date today?")
            tarikh = input(">")
            print("Is the student present or absent? Enter 1 if present and 0 if absent")
            confirmation=int(input(">"))
            filename = 'attds.csv'
            if confirmation==1:
                status = 'Present'
                new_data = [[student_id, module, tarikh, status]]
                with open(filename,'a') as file:
                    for line in new_data:
                        file.write(','.join(line))
                    print("You have successfully entered the attendance. :)")
                break

            elif confirmation==0:
                status = 'Absent'
                new_data = [[student_id, module, tarikh, status]]
                with open(filename,'a') as file:
                    for line in new_data:
                        file.write(",".join(line))
                    print("You have successfully entered the attendance. Someone skipped their class :|")
                break

            else:
                print("That is cap. You didn't follow what I said, so prepare to get bongus\n")

        except ValueError:
            print("You didn't enter the correct value\n")

#Counting attendance percentage
def attdspercentage(): #this is for calculating the percentage of the student's attendance
    filename = 'attds.csv'
    acount=0
    mcount=0
    print("Please enter student's TPNumber")
    student_id = input('>')
    while True:
        try:
            with open(filename,'r') as file:
                for line in file:
                    statuscheck = []
                    statuscheck.append(','.join(line))
                    tpnumbercheck = statuscheck[0]
                    status = statuscheck[3]
                    if tpnumbercheck == student_id:
                        mcount += 1
                        if status == 'Present': #to get the total modules the student should have attended
                            acount += 1

            if mcount > 0:
                studpercentage = acount/mcount * 100
                print(f"Your attendance percentage is {studpercentage}%")
                break
            else:
                print("Either no records ever been recorded or you skipped all your classes '-' ")

        except:
            print("Your data doesn't exist. Please check your input again.")

#Access grades for students in each of the lecturer's modules.
def viewgradelect():
    while True:
        try:
            filename = 'studentgrades.csv'
            with open(filename,'r') as lectview:
                display = lectview.readlines()
                for line in display:
                    print(line.strip())
            break

        except:
            print("Error occurred somewhere. Please make sure you entered the correct input :)")
# ------ End Of Lecturer Functions ---------

# ------ Registrar Functions ---------
def read_file(file_path):
    try:
        with open(file_path, "r") as file:
            return [line.strip() for line in file]
    except FileNotFoundError:
        return []

def write_file(file_path, data):
    with open(file_path, "w") as file:
        file.write("\n".join(data) + "\n")

def append_file(file_path, line):
    with open(file_path, "a") as file:
        file.write(line + "\n")

def get_record(file_path, key):
    records = read_file(file_path)
    for record in records:
        if record.startswith(key):
            return record
    return None

def validate_student_id(student_id):
    while len(student_id) != 8:
        print("Student ID must be exactly 8 characters long.")
        student_id = input("Enter student ID (8 characters): ")
    return student_id

def register_student():
    student_id = validate_student_id(input("Enter student ID (8 characters): "))
    if get_record(STUDENTS_FILE, student_id):
        print("Student already exists.")
    else:
        name = input("Enter student name: ")
        program = input("Enter program: ")
        append_file(STUDENTS_FILE, f"{student_id},{name},{program}")
        print("Student registered.")

def update_student():
    student_id = validate_student_id(input("Enter student ID to update: "))
    students = read_file(STUDENTS_FILE)
    updated = []
    for student in students:
        if student.startswith(student_id):
            name = input("New name (leave blank to keep current): ")
            program = input("New program (leave blank to keep current): ")
            parts = student.split(",")
            updated.append(f"{student_id},{name or parts[1]},{program or parts[2]}")
        else:
            updated.append(student)
    write_file(STUDENTS_FILE, updated)
    print("Student record updated.")

def manage_enrollment():
    student_id = validate_student_id(input("Enter student ID: "))
    module = input("Enter module: ")
    enrollments = read_file(ENROLLMENTS_FILE)
    if f"{student_id},{module}" in enrollments:
        print("Student already enrolled.")
    else:
        append_file(ENROLLMENTS_FILE, f"{student_id},{module}")
        print("Enrollment updated.")

def issue_transcript():
    student_id = validate_student_id(input("Enter student ID: "))
    student = get_record(STUDENTS_FILE, student_id)
    if not student:
        print("Student not found.")
        return
    enrollments = [line.split(",")[1] for line in read_file(ENROLLMENTS_FILE) if line.startswith(student_id)]
    transcript = f"Transcript for {student.split(',')[1]}:\n" + "\n".join(enrollments)
    print(transcript)
    append_file(TRANSCRIPT_FILE, transcript)

def record_feedback():
    student_id = validate_student_id(input("Enter student ID: "))
    feedback = input("Enter feedback: ")
    append_file(FEEDBACK_FILE, f"{student_id},{feedback}")
    print("Feedback recorded.")

def view_feedback():
    student_id = validate_student_id(input("Enter student ID: "))
    feedbacks = [line.split(",", 1)[1] for line in read_file(FEEDBACK_FILE) if line.startswith(student_id)]
    if feedbacks:
        print("\n".join(feedbacks))
    else:
        print("No feedback found.")

def view_student_information():
    student_id = validate_student_id(input("Enter student ID to view: "))
    student = get_record(STUDENTS_FILE, student_id)
    if student:
        parts = student.split(",")
        print(f"Student ID: {parts[0]}\nName: {parts[1]}\nProgram: {parts[2]}")
    else:
        print("Student not found.")

def view_module_students():
    module = input("Enter module name: ")
    enrollments = read_file(ENROLLMENTS_FILE)
    if not any(module in line for line in enrollments):
        print("Module does not exist or has no enrollments.")
        return
    students = [line.split(",")[0] for line in enrollments if line.split(",")[1] == module]
    if students:
        print(f"Students enrolled in {module}:")
        for student_id in students:
            student = get_record(STUDENTS_FILE, student_id)
            if student:
                print(f"- {student.split(',')[1]} (ID: {student_id})")
    else:
        print("No students found for this module.")
# ------ End Of Registrar Functions ---------

# ------ Bursary Functions ---------
# Function to load student tuition records from text file
def load_tuition_records(TUITION_FILE):
    try:
        with open(TUITION_FILE, 'r') as file:
            for row in TUITION_FILE:
                student_id = row['student_id']
                student_records[student_id] = {
                    "name": row['name'],
                    "tuition_fee": float(row['tuition_fee']),
                    "paid_amount": float(row['paid_amount']),
                    "payment_history": eval(row['payment_history'])
                }
    except FileNotFoundError:
        print(f"File {TUITION_FILE} not found. Starting with an empty tuition record.")

# Function to save student tuition records to text file
def save_tuition_records(TUITION_FILE):
    with open(TUITION_FILE,'w', newline='') as file:
        TUITION_FILE.write(file, fieldnames=['student_id', 'name', 'tuition_fee', 'paid_amount', 'payment_history'])
        TUITION_FILE.writeheader()
        for student_id, data in student_records.items():
            TUITION_FILE.writerow({
                "student_id": student_id,
                "name": data["name"],
                "tuition_fee": data["tuition_fee"],
                "paid_amount": data["paid_amount"],
                "payment_history": data["payment_history"]
            })

# Function to record tuition fees
def record_tuition(student_id, name, tuition_fee):
    student_records[student_id] = {
        "name": name,
        "tuition_fee": tuition_fee,
        "paid_amount": 0,
        "payment_history": []
    }
    print(f"Tuition fees recorded for {name} (ID: {student_id}).")

# Function to view outstanding fees
def view_outstanding_fees(student_id):
    if student_id in student_records:
        record = student_records[student_id]
        outstanding = record["tuition_fee"] - record["paid_amount"]
        print(f"Outstanding Fees for {record['name']} (ID: {student_id}): {outstanding}")
    else:
        print(f"No record found for Student ID: {student_id}.")

# Function to update payment records
def update_payment(student_id, amount):
    if student_id in student_records:
        record = student_records[student_id]
        record["paid_amount"] += amount
        record["payment_history"].append({
            "date": datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
            "amount": amount
        })
        print(f"Payment of {amount} recorded for {record['name']} (ID: {student_id}).")
    else:
        print(f"No record found for Student ID: {student_id}.")

# Function to issue fee receipts
def issue_receipt(student_id):
    with open ('text.txt', 'r') as file: 
        filecontent = file.readlines()
        print(filecontent)
        if student_id in student_records:
            record = student_records[student_id]
            print("\n--- Fee Receipt ---")
            print(f"Student ID: {student_id}")
            print(f"Name: {record['name']}")
            print(f"Total Tuition Fee: {record['tuition_fee']}")
            print(f"Paid Amount: {record['paid_amount']}")
            print(f"Outstanding: {record['tuition_fee'] - record['paid_amount']}")
            print("-------------------\n")
        else:
            print(f"No record found for Student ID: {student_id}.")

# Function to view financial summary
def view_financial_summary():
    print("\n--- Financial Summary ---")
    for student_id, record in student_records.items():
        print(f"Student ID: {student_id}")
        print(f"Name: {record['name']}")
        print(f"Total Tuition Fee: {record['tuition_fee']}")
        print(f"Paid Amount: {record['paid_amount']}")
        print(f"Outstanding: {record['tuition_fee'] - record['paid_amount']}")
        print("-------------------------")
    print()
# ------ End Of Bursary Functions ---------

# ------ Student Functions ---------
def load_modules():
    """Provide existing available modules from the modules file."""
    try:
        with open(MODULES_FILE, "r") as file:  # "r" for read mode
            return [line.strip() for line in file]
    except FileNotFoundError:
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
# ------ End Of Student Functions ---------

# ------ Main Menu Functions ---------
def load_users(filename):
    users = {}
    admins = []
    try:
        with open(filename,'r') as file:
            for row in filename:
                users[row['username']] = row['password']
                if row.get('role') == 'admin':
                    admins.append(row['username'])
    except FileNotFoundError:
        print(f"File {filename} not found. Starting with an empty user database.")
    return users, admins

def save_users(users, admins, filename):
    with open(filename,'w', newline='') as file:
        filename.write(file, fieldnames=['username', 'password', 'role'])
        filename.writeheader()
        for username, password in users.items():
            role = 'admin' if username in admins else 'user'
            filename.writerow({'username': username, 'password': password, 'role': role})

def logreq(users):
    while True:
        choice = input("""
        Welcome to MyUniSpace!
        Please log in or register to continue:
        
        1. Register
        2. Login
        3. Exit

        Choose an option: """).strip()

        if choice == '1':
            register(users)
        elif choice == '2':
            username = login(users)
            if username:
                return username  # Login successful
        elif choice == '3':
            print("Exiting.....")
            exit()
        else:
            print("Invalid choice. Please try again.")

def menu(users, admins, current_user, filename):
    while True:
        try:
            print(f"\nWelcome, {current_user}!")
            menu_choice = int(input("""
            Main Menu:
            1. Administration
            2. Staff Portal
            3. Registrar Office
            4. Bursary Office
            5. Students Portal
            6. Log Out
            7. Exit

            Enter your choice: """))
        except ValueError:
            print("Error occurred. Please input a valid number.")
            continue

        match menu_choice:
            case 1:
                if current_user in admins:
                    admin()
                else:
                    print("Access denied. You are not authorized to access the Administration menu.")
            case 2:
                staff()
            case 3:
                registrar()
            case 4:
                bursary()
            case 5:
                student()
            case 6:
                print("Logging out...")
                return  # Return to the login menu
            case 7:
                save_users(users, admins, filename)
                print("Exiting......")
                exit()
            case default:
                print("Invalid choice. Please try again.")

def register(users):
    print("\n -Register- ")
    username = input("Enter a username: ").strip()
    if username in users:
        print("Username already exists. Please try another one.")
        return
    password = input("Enter a password: ").strip()
    role = input("Enter role (admin/user): ").strip().lower()

    if role == 'admin':
        admins.append(username)

    users[username] = password
    print("Registration completed successfully!")

def login(users):
    print("\n -Login- ")
    username = input("Enter your username: ").strip()
    password = input("Enter your password: ").strip()
    if users.get(username) == password:
        print(f"Welcome, {username}! You are now logged in.")
        return username
    else:
        print("Invalid username or password. Please try again.")
        return None

def admin():
    #Admin File Startup, making sure the text file exist, else create
    FirstTimeStart()

    while True:
     #main menu
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

        if num == 1:
            course_mainmenu()
        elif num == 2:
            student_mainmenu()
        elif num == 3:
            lecturer_mainmenu()
        elif num == 4:
            report()
        elif num == 5:
            viewalldata()
        elif num == 6:
            print("Thank you and have a nice day.")
            break
        else:
            print("Invalid option")

    
def staff():
    while True:
        stamenu = input("""
        -Staff Portal-
    Welcome to the Staff Portal!
        
        1. View Student List For Each Assigned Module
        2. Record Grades
        3. Mark Attendace
        4. View Attendance Percentage
        5. View Student Grades
        6. Back

        Choose an option: """).strip()

        if stamenu == "1":
           viewstudent()
        elif stamenu == "2":
            recordgrades()
        elif stamenu == "3":
            attendance()
        elif stamenu == "4":
            attdspercentage()
        elif stamenu == "5":
            viewgradelect()
        elif stamenu == "6":
            break
        else:
            print("Invalid option.")

def registrar():
    while True:
        choice = input("""
        -Registrar Office-
    Welcome to the Registrar Office!
        
        1. Register New Students
        2. Update Student Records
        3. Manage Enrolments
        4. Issue Transcripts
        5. Record Feedback
        6. View Feedback               
        7. View Student Information
        8. View Students Module
        9. Back

        Choose an option: """).strip()

        if choice == "1":
            register_student()
        elif choice == "2":
            update_student()
        elif choice == "3":
            manage_enrollment()
        elif choice == "4":
            issue_transcript()
        elif choice == "5":
            record_feedback()
        elif choice == "6":
            view_feedback()
        elif choice == "7":
            view_student_information()
        elif choice == "8":
            view_module_students()
        elif choice == "9":
            break
        else:
            print("Invalid option.")

# Bursary Office Menu
def bursary():
    tuition_file = "tuitionRec.txt"
    load_tuition_records(tuition_file)  # Load tuition records from CSV

    while True:
        burmenu = input("""
        -Bursary Office-
    Welcome to the Bursary Office!
        
        1. Record Tuition Fees
        2. View Outstanding Fees
        3. Update Payment Records
        4. Issue Fee Receipts
        5. View Financial Summary
        6. Back

        Choose an option: """).strip()

        if burmenu == '1':
            student_id = input("Enter Student ID: ").strip()
            name = input("Enter Student Name: ").strip()
            tuition_fee = float(input("Enter Tuition Fee: ").strip())
            record_tuition(student_id, name, tuition_fee)

        elif burmenu == '2':
            student_id = input("Enter Student ID: ").strip()
            view_outstanding_fees(student_id)

        elif burmenu == '3':
            student_id = input("Enter Student ID: ").strip()
            amount = float(input("Enter Payment Amount: ").strip())
            update_payment(student_id, amount)

        elif burmenu == '4':
            student_id = input("Enter Student ID: ").strip()
            issue_receipt(student_id)

        elif burmenu == '5':
            view_financial_summary()

        elif burmenu == '6':
            save_tuition_records(tuition_file)  # Save tuition records before exiting
            print("Returning to the main menu...")
            break

        else:
            print("Invalid choice. Please try again.")

def student():
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

# Main Execution
users, admins = load_users(TUITION_FILE)
while True:
    current_user = logreq(users)  # Ensure login first
    menu(users, admins, current_user, TUITION_FILE)  # Show main menu after login

'''
studgrade = [['TPNumber','Name', 'Module', 'Grade']]
filename = 'studentgrades.csv'
with open(filename, 'w') as file:
   for line in studgrade:
        itemlist = ''
        for i in range(len(line)):
            itemlist += str(line[i])
            if i < len(line) - 1:
                itemlist += ','
        itemlist += '\n'
        file.write(itemlist)
'''

'''
attdsheader = [['TPNumber', 'Module', 'Date', 'Status']]
filename = 'attds.csv'


with open(filename, 'w') as file:
    for line in attdsheader:
        file.write(','.join(line) + '\n')
'''