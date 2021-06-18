# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 18 November 2020
# Deskripsi : Program menerima input N banyak garis dan menerima input Q buah titik lalu 
#             menentukan apakah titik tersebut berada di dalam garis. Asumsi batas titik dari 0 sampai 100
#             Asumsi garis garis tidak beririsan

# KAMUS
# N, i, j, Q, X : integer
# freq, L, R : array

# Menerima input banyak garis
N = int(input("Masukkan N: "))

# Inisialisasi list frekuensi, L, dan R
freq = [0 for i in range(100+1)]
L = [0 for i in range(N)]
R = [0 for i in range(N)]

# Menerima input titik L dan R lalu memasukkan ke list
for i in range(N):
    L[i] = int(input("Masukkan L[" + str(i+1) + "]: "))
    R[i] = int(input("Masukkan R[" + str(i+1) + "]: "))

# Mengubah elemen pada frekuensi, jika titik berada di garis, maka frekuensinya menjadi 1
for i in range(N):
    if L[i] < R[i]:
        for j in range(L[i], R[i]+1):
            freq[j] = 1
    else: # L[i] >= R[i]
        for j in range(R[i], L[i]+1):
            freq[j] = 1

# Menerima input banyaknya titik yang diuji
Q = int(input("Masukkan Q: "))

# Menentukan titik yang diuji apakah di dalam garis atau tidak
for i in range(Q):
    X = int(input("Masukkan X ke-" + str(i+1) + ": "))
    if freq[X] == 1: # Jika frekuensi titik tersebut 1 maka titik tersebut di dalam garis
        print("Titik ke " + str(i+1) + " ada di garis.")
    else: # freq[X] != 1
        print("Titik ke " + str(i+1) + " tidak ada di garis.")