import csv

filename = "grade.csv"

#studDict = [

 #   {'Name' : 'Billy', 'Assignment' : 40,
  #  'Final Exam' :  30, 'Final Grade' : 70},
   # {'Name' : 'Angel', 'Assignment' : 35,
    #'Final Exam' :  45, 'Final Grade' : 80},
    #{'Name' : 'Tommy', 'Assignment' : 45,
    #'Final Exam' :  47, 'Final Grade' : 92},
    #{'Name' : 'Archie', 'Assignment' : 48,
    #'Final Exam' :  48, 'Final Grade' : 96},
    #{'Name' : 'Jonathon', 'Assignment' : 48,
    #'Final Exam' :  49, 'Final Grade' : 97},

#]

fields = ['Name', 'Assignment', 'Final Exam', 'Final Grade']
rows = [
    ['Billy', '40', '30', '70'],
    ['Angel', '35', '45', '80'],
    ['Tommy', '45', '47', '92'],
    ['Archie', '48', '48', '96'],
    ['Jonathon', '48', '49', '97']
]

with open(filename, 'w') as gradefile:
    #create csv reader object
    writer = csv.writer(gradefile)

    #write headers
    writer.writerow(fields)

    #writing data row
    writer.writerows(rows)

rows[0][2] = '25'
append = open(filename, 'a')

    