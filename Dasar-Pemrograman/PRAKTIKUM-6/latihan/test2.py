import csv

mark = ("999999",99)
def EOP(rekMHS):
    if rekMHS[0] == mark[0] and rekMHS[1] == mark[1]:
        return True
    else:
        return False

ArsipMHS = open ("MHS2.csv",'w',newline='')
writer = csv.writer(ArsipMHS,delimiter=',')
# baca masukan dari user dan bentuk menjadi tuple
nim = input()
nilai = int(input())
rekMHS = (nim,nilai)
while (not(EOP(rekMHS))):
    writer.writerow(rekMHS) # tulis rekMHS ke file
    nim = input()
    nilai = int(input())
    rekMHS = (nim,nilai)
# tulis mark
writer.writerow(mark)
ArsipMHS.close()