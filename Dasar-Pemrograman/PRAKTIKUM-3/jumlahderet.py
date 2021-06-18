# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: jumlahderet.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 19 Maret 2021
# Deskripsi	: Program membaca sebuah integer N (asumsi N > 0 dan ganjil), 
#           dan menuliskan hasil perhitungan deret: 1+3+ ... +N.

N = int(input())

i = 1
sum = 0

while (i <= N):
    sum += i
    i += 2

print(sum)
