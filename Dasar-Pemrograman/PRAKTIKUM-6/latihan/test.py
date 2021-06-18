def EOP(c):
    if c == '.':
        return True
    else:
        False    

f = open("test.txt",'r')
c1 = f.read(1)

if EOP(c1):
    print("File kosong")
else:
    while True:
        print(c1,end='')
        c1 = f.read(1)
        if EOP(c1):
            print()
            break

f.close()