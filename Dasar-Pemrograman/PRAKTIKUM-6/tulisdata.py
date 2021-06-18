# Module untuk menulis data file keperluan praktikum

# type dataSaham  : <IdPemilik : string, IdPT : string, Nilai : integer> 

def TulisDataSaham(namafile):
    # Menulis data kepemilikan saham ke file namafile
    # Kamus
    # f : file teks
    # Algoritma
    f = open(namafile,'w')
    row1 = input().rstrip() # IdPemilik
    # simpan sampai teks = 99999999
    while (row1 != "99999999"):
        # asumsikan selalu tulis 3 data
        f.write(row1 + "\n") # write IdPemilik
        row2 = input() # KdKul
        f.write(row2 + "\n") # write IdPT
        row3 = input() # nilai
        f.write(row3 + "\n") # write Nilai
        # simpan ke file
        row1 = input().rstrip() # next-IdPemilik
    # tulis mark
    f.write(row1) # mark
    f.close()
    return