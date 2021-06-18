# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: jumlahderet.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program yang membaca sebuah integer N (asumsi N > 0 dan ganjil), 
#           dan menuliskan hasil perhitungan deret: 1+3+ ... +N.

# KAMUS
# N : integer

# ALGORITMA
def deret(N):
    if N == 1:
        return 1
    else:
        return (N + deret(N-2))

N = int(input())

print(deret(N))
