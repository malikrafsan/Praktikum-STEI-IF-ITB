# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 29 November 2020
# Deskripsi : Program menerima input N dan mencetak matriks berisi segitiga Pascal berukuran NxN

# KAMUS
# N : integer

# Definisi prosedur Pascal
def Pascal(N):
    # Mencetak matriks berisi segitiga Pascal berukuran NxN
    
    # KAMUS LOKAL
    # M : matriks
    # i, j : integer

    # ALGORITMA
    M = [[1 for i in range(N)] for j in range(N)]
    for i in range(1, N):
        for j in range(1, N):
            M[i][j] = M[i-1][j] + M[i][j-1]
    for i in range(N):
        for j in range(N):
            print(M[i][j], end=" ")
        print()

# ALGORITMA PROGRAM UTAMA

# Menerima input N
N = int(input("Masukkan N: "))

# Pemanggilan fungsi Pascal untuk mencetak matriks berisi segitiga Pascal berukuran NxN
Pascal(N)