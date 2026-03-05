word_to_remove =  ['like', 'whatever', 'lol', 'yep', 'totally'] 

def createTextFile():
    textfile = open("cool_text.txt", "x")
    textfile.close()

def removeWords(textfile, word_to_remove):
    with open(textfile, 'r') as f:
        txtfile_to_list = f.read().replace('\n','').replace(' ',',').split(",")
        for word in txtfile_to_list:
            if word in word_to_remove:
                txtfile_to_list.remove(word)
        print(txtfile_to_list)
    
removeWords("cool_text.txt", word_to_remove)
