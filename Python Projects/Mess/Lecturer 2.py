#Add or update student grades for a specific module
def recordgrades():
    while True:
        try:
            data = [['TPNumber','Name', 'Module', 'Grade']]
            filename = 'studentgrades.csv'
            with open(filename, 'r') as file:
                lists =[]
                for line in file:
                    line = line.strip().split(',')
                    lists.append(line)
                print("Please enter the TPNumber(eg: TP123456)")
                tpnumberinput = input('>')
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
                    if studentdata[i][0] == tpnumberinput and studentdata[i][2] == moduleinput:
                        studentdata[i][1] = nameinput
                        studentdata[i][3] = gradeinput
                        student_existed = True

                if student_existed == False:
                    new_data = [tpnumberinput, nameinput, moduleinput, gradeinput]
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
            tpnumber = input(">")
            print("Enter the module")
            module = input(">")
            print("What is the date today?")
            tarikh = input(">")
            print("Is the student present or absent? Enter 1 if present and 0 if absent")
            confirmation=int(input(">"))
            filename = 'attds.csv'
            if confirmation==1:
                status = 'Present'
                new_data = [[tpnumber, module, tarikh, status]]
                with open(filename,'a') as file:
                    for line in new_data:
                        file.write(','.join(line))
                    print("You have successfully entered the attendance. :)")
                break

            elif confirmation==0:
                status = 'Absent'
                new_data = [[tpnumber, module, tarikh, status]]
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
    tpnumber = input('>')
    while True:
        try:
            with open(filename,'r') as file:
                for line in file:
                    statuscheck = []
                    statuscheck.append(','.join(line))
                    tpnumbercheck = statuscheck[0]
                    status = statuscheck[3]
                    if tpnumbercheck == tpnumber:
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