# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: max3bil
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program membaca 3 buah integer berturut-berturut, misalnya A, B, C, 
#           dan menghasilkan bilangan yang terbesar di antara ketiganya. 
#           Asumsikan A, B, C adalah bilangan yang berbeda.

#KAMUS
# A,B,C : integer

# ALGORITMA
# menerima input dari user
A = int(input())
B = int(input())
C = int(input())

# mencari nilai paling tinggi
maxbil = A
if B > maxbil:
    maxbil = B
if C > maxbil:
    maxbil = C

# output
print(maxbil)
