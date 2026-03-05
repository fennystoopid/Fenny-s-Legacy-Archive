from pathlib import Path
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

#View the modules assigned to each lecturer
def viewmodlect():
    while True:
        try:
            filename = "lecturer's module.csv"
            with open(filename,'r') as lectview:
                display = lectview.readlines()

                for line in display:
                    print(line)
            break

        except:
            print("Error occurred somewhere. Please make sure you entered the correct input :)")

#Add or update student grades for a specific module
def recordgrades():
    while True:
        try:
            data = [['StudentID', 'Module Code', 'Grade']]
            filename = 'grades.txt'
            with open(filename, 'r') as file:
                lists =[]
                for line in file:
                    line = line.strip().split()
                    lists.append(line)
                print("Please enter the StudentID(eg: TP123456)")
                student_idinput = input('>')
                print("Please enter the module code")
                moduleinput = input(">")
                print("Please enter the grade")
                gradeinput = input(">")
                header = lists[0]
                studentdata = lists[1:]

                student_existed = False
                for i in range(len(studentdata)):
                    if studentdata[i][0] == student_idinput and studentdata[i][1] == moduleinput:
                        studentdata[i][2] = gradeinput
                        student_existed = True

                if student_existed == False:
                    new_data = [student_idinput, moduleinput, gradeinput]
                    lists.append(new_data)


            with open(filename, 'w') as file:
                for i in lists:
                    file.write(' '.join(i) + '\n')

            break
        except:
            print("Please check with the administrator what went wrong.")



#Display the list of students enrolled in each assigned module
def viewstudent():
    while True:
        try:
            filename = 'enrollments.txt'
            with open(filename,'r') as lectview:
                display = lectview.readlines()
                for line in display:
                    print(line.strip())
            break

        except:
            print("Error occurred somewhere. Please make sure you entered the correct input :)")

#Mark attendance for students
def attendance():
    while True:
        try:
            print("Enter the StudentID")
            student_id = input(">")
            print("Enter the module")
            module = input(">")
            print("What is the date today?(YYYY-MM-DD)")
            tarikh = input(">")
            print("Is the student present or absent? Enter 1 if present and 0 if absent")
            confirmation=int(input(">"))
            filename = 'attds.csv'
            if confirmation==1:
                status = 'Present'
                new_data = [[student_id, module, tarikh, status]]
                with open(filename,'a') as file:
                    for line in new_data:
                        file.write(' '.join(line) + '\n')
                    print("You have successfully entered the attendance. :)")
                break

            elif confirmation==0:
                status = 'Absent'
                new_data = [[student_id, module, tarikh, status]]
                with open(filename,'a') as file:
                    for line in new_data:
                        file.write(" ".join(line) + '\n')
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
    print("Please enter StudentID")
    tpnumber = input('>')
    while True:
        try:
            with open(FindFilePath(filename),'r') as file:
                perc = file.readlines()
                statuscheck = []
                for line in perc:
                    line = line.strip().split(', ')
                    statuscheck.append(line)
                    for i in range(len(statuscheck)):
                        tpnumbercheck = statuscheck[i][0]
                        status = statuscheck[i][3]
                        if tpnumbercheck == tpnumber:
                            mcount += 1
                            if status == 'Present': #to get the total modules the student should have attended
                                acount += 1

            if mcount > 0:
                studpercentage = acount/mcount * 100
                print(f"Your attendance percentage is {studpercentage}%")
                break
            else:
                print("No records ever been recorded '-'")
            break

        except:
            print("Your data doesn't exist. Please check your input again.")
            break

#Access grades for students in each of the lecturer's modules.
def viewgradelect():
    while True:
        try:
            filename = 'grades.txt'
            with open(filename,'r') as lectview:
                display = lectview.readlines()
                for line in display:
                    print(line.strip())
            break

        except:
            print("Error occurred somewhere. Please make sure you entered the correct input :)")

# ------ End Of Lecturer Functions ---------

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


attdspercentage()