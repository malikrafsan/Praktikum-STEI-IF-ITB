# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: max3bil.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 19 Maret 2021
# Deskripsi	: Program membaca 3 buah integer berturut-berturut, misalnya A, B, C, dan menghasilkan bilangan 
#           yang terbesar di antara ketiganya. Asumsikan A, B, C adalah bilangan yang berbeda.

A = int(input())
B = int(input())
C = int(input())

max = A
if B > max:
    max = B
if C > max:
    max = C

print(max)