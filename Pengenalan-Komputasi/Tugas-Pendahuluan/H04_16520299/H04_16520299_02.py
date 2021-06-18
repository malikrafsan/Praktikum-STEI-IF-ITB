# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 29 November 2020
# Deskripsi : Program menerima input N dan M lalu membaca matriks A ukuran NxM dan 
#             menuliskan berapa bilangan positif di dalam matriks serta mencetak matriks

# KAMUS
# N, M, Pos : integer
# Mat : Matriks

# Definisi fungsi isiMatrix
def isiMatrix(N, M):
    # Inisialisasi dan pengisian elemen matriks

    # KAMUS LOKAL
    # Mat : matriks
    # i,j : integer

    # ALGORITMA
    Mat = [[0 for i in range(M)] for j in range(N)]
    for i in range(N):
        for j in range(M):
            Mat[i][j] = int(input("Masukkan nilai A[" + str(i+1) + "][" + str(j+1) + "]: "))
    return Mat

# Definisi fungsi cariPositif
def cariPositif(Mat, N, M):
    # Menghitung berapa banyak bilangan positif di dalam matriks

    # KAMUS LOKAL
    # count, i, j : integer

    # ALGORITMA
    count = 0
    for i in range(N):
        for j in range(M):
            if Mat[i][j] > 0:
                count += 1
    return count

# Definisi prosedur cetakMatrix
def cetakMatrix(Mat, N, M):
    # Mencetak matriks ke layar

    # KAMUS LOKAL
    # i, j : integer

    # ALGORITMA
    for i in range(N):
        for j in range(M):
            print(Mat[i][j], end=" ")
        print()

# ALGORITMA PROGRAM UTAMA

# Menerima input N dan M
N = int(input("Masukkan N: "))
M = int(input("Masukkan M: "))

# Inisialisasi dan mengisi matriks
Mat = isiMatrix(N,M)

# Menghitung berapa banyak bilangan positif di dalam matriks
Pos = cariPositif(Mat, N, M)

# Mencetak hasil perhitungan bilangan positif
print("Ada " + str(Pos) + " bilangan positif di matriks.")

# Mencetak matriks ke layar
cetakMatrix(Mat, N, M)