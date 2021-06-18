# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 2 Desember 2020
# Deskripsi : Program menerima input sebuah matriks dan menghitung banyak simetri putar dan simetri lipat

# KAMUS
# baris, kolom, putar, lipat, i, j  : integer
# Mat : matriks

# ALGORITMA

# Menerima input baris dan kolom
baris = int(input("Masukkan baris: "))
kolom = int(input("Masukkan kolom: "))

# Inisialisi matriks
Mat = [["*" for i in range(kolom)] for j in range(baris)]

# Mengisi matriks
for i in range(baris):
    for j in range(kolom):
        Mat[i][j] = input("Masukkan Elemen baris " + str(i+1)  + " kolom " + str(j+1) + ": ")

# inisialisasi nilai putar 1
putar = 1

# matriks persegi
if baris == kolom:
    bisaPutar = True
    for i in range(baris):
        for j in range(kolom):
            if Mat[i][j] != Mat[j][i]:
                bisaPutar = False                
    if bisaPutar:
        putar += 1
#else:
#    bisaPutar = True
#    for i in range(baris):
#        for j in range(kolom):
            

# menghitung simetri lipat
lipat = 0

lipathori = True
for i in range(baris):
    for j in range(kolom):
        if (baris%2 == 0):
            if Mat[i][j] != Mat[baris-1-i][j]:
                lipathori = False
        else:
            if Mat[i][j] != Mat[baris-1-i][j] and i != (baris//2):
                lipathori = False
if lipathori:
    lipat += 1

lipatveri = True
for i in range(baris):
    for j in range(kolom):
        if (kolom%2 == 0):
            if Mat[i][j] != Mat[i][kolom-1-j]:
                lipatveri = False
        else:
            if Mat[i][j] != Mat[i][kolom-1-j] and j != (kolom//2):
                lipatveri = False
if lipatveri:
    lipat += 1

# lipatdia1
# lipatdia2

# mencetak hasil ke layar
print("Simetri lipat: " + str(lipat))
print("Simetri putar: " + str(putar))