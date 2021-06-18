# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 2 Desember 2020
# Deskripsi : Program menerima input ukuran papan catur dan posisi ratu dan setiap benteng.
#             Program lalu mencetak apakah ratu aman dari serangan benteng

# KAMUS
# jumlah    : integer

# Definisi prosedur Aman
def Aman(N):
    # Menerima input posisi setiap bidak catur dan mencetak apakah ratu aman

    # KAMUS LOKAL
    # Mat       : matriks
    # i,j,x,y   : integer
    # aman      : boolean

    # ALGORITMA

    # Program menginisalisasi matriks
    Mat = [["*" for i in range(N)] for j in range(N)]

    # Program menerima input setiap bidak catur
    for i in range(N):
        for j in range(N):
            Mat[i][j] = input("Masukkan elemen baris " + str(i+1) + " kolom " + str(j+1) + ": ")
            if Mat[i][j] == "R":
                # Menyimpan posisi ratu
                x = i
                y = j

    # Mengecek apakah ratu aman dengan looping                
    aman = True
    for i in range(N):
        for j in range(N):
            if Mat[i][j] == "B":
                # Jika posisi baris atau kolom ratu sama dengan (salah satu antara) baris atau kolom benteng
                if x == i:
                    aman = False
                if y == j:
                    aman = False

    # Mencetak ke layar apakah ratu aman
    if aman == True:
        print("Ratu aman dari serangan benteng.")
    else:   # aman == False
        print("Ratu tidak aman dari serangan benteng.")
    return

# ALGORITMA UTAMA

# Menerima input ukuran papan catur
jumlah = int(input("Masukkan nilai N: "))

# Memanggil prosedur Aman
Aman(jumlah)