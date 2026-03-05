import csv

filename = "grade.csv"

fields = ['Name', 'Assignment', 'Final Exam', 'Final Grade']
rows = [
    ['Billy', '40', '30', '70'],
    ['Angel', '35', '45', '80'],
    ['Tommy', '45', '47', '92'],
    ['Archie', '48', '48', '96'],
    ['Jonathon', '48', '49', '97']
]

studDict = []

with open(filename, 'r') as gradefile:
    #create csv reader object
    DictReader = csv.DictReader(gradefile)

    for line in DictReader:
        studDict.append(line)
        print(studDict)

