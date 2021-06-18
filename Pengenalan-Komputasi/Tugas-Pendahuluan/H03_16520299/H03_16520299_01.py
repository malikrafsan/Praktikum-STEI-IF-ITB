# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 16 November 2020
# Deskripsi : Program menerima N buah angka lalu mencetak kembalik dalam urutan terbalik

# KAMUS
# N, i, j, k : integer
# arrayN : array

# ALGORITMA

N = int(input("Masukkan N: "))

# Deklarasi array
arrayN = [0 for i in range (N)]

# Menginput elemen pada array
for j in range(N):
    arrayN[j] = int(input())

print("Hasil dibalik: ")

# Mencetak elemen dari array secara terbalik
for k in range(N):
    print(arrayN[N-k-1])