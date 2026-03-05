def countline_file(file):
    Tline_count = 0
    with open(file, 'r', encoding= 'utf-8') as f:
        alllines = f.readlines()
        alllinestotal = len(alllines)
        print(f'Total lines = {alllinestotal}')

        for line in alllines:
            if not 'T' in line:
               Tline_count += 1
        print(f"Line not starting with T = {Tline_count}")


countline_file("story.txt")