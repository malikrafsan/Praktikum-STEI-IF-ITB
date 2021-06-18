# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: jumlahderet.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program membaca sebuah integer N (asumsi N > 0), 
#           dan menuliskan hasil perhitungan deret: 1+2+3+ ... +N.

# KAMUS
# N : integer

# ALGORITMA
N = int(input())
sumbil = 0

for i in range(1,N+1):
    sumbil += i

print(sumbil)