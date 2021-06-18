lanjut = False
benar = ['s','S','p','P']

while not lanjut:
    lanjut = True
    
    masukan = input().split()
    
    lst = [0,0,0]
    for i in range(3):
        lst[i] = float(masukan[i])
        if lst[i] <= 0:
            lanjut = False
            
    jenis = masukan[3]    
    if not (jenis in benar):
        lanjut = False

    if not lanjut:
        print("Masukan salah")


if jenis in benar[0:1]:
    hasil = lst[0] + lst[1] + lst[2]
    print("%.2f" % hasil)
else:
    hasil = 1/((1/lst[0]) + (1/lst[1]) + (1/lst[2]))
    print("%.2f" % hasil)