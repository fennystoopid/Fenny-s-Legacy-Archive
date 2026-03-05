def readline_file(file):
    textfile = open(file , "r")
    Lines = textfile.readlines()
    for line in Lines:
        print(line.strip())
    textfile.close()

readline_file("python.txt")