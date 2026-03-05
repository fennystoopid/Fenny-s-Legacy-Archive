def append_file(file, data):
    textfile = open(file , "a")
    textfile.write(data)
    textfile.close()

append_file("my.txt", "Cat\nBanana\nMalaysia")

