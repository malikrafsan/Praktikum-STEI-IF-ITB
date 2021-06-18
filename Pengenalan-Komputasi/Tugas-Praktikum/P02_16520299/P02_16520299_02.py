# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 4 November 2020
# Deskripsi : Mengubah suatu bilangan dengan N buah digit dari basis K ke basis 10.

# KAMUS
# base, N, K, pangkat, i, masukan, digit : integer

# ALGORITMA

# Inisialisasi
base = 0

# Menerima input banyak digit dan basis bilangan
N = int(input("Masukkan nilai N: "))
K = int(input("Masukkan nilai K: "))

pangkat = N - 1

for i in range (1, N+1):
    masukan = int(input("Masukkan digit ke " + str(i) + ": "))
    digit = (masukan*(K**pangkat)) # Menghitung nilai basis 10 setiap digit
    base = base + digit
    pangkat = pangkat - 1

# Terminasi
# Mencetak nilai bilangan pada basis 10
print("Bilangan dalam basis 10 adalah " + str(base))
