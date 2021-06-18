def validasi(masukan):
    hasil = True
    
    masuk = masukan.split()
    r1,r2,r3 = map(float, masuk[0:2])
    
    benar = ['s','S','p','P']
    if (masuk[3] in benar):
        hasil = False
    for i in range(3):
        if 

def perhitungan(a,b,c,char):
    if (char == 's') or (char == 'S'):    
        return a + b + c
    else:
        return 1/((1/a) + (1/b) + (1/c))

# MAIN

takcocok = True
while takcocok:
    masukan = input()
    cocok = validasi(masukan)