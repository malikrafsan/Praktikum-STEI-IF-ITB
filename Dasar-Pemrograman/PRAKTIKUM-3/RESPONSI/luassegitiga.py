# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: luassegitiga.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program menerima masukan 2 buah bilangan real a dan t dengan a = alas segitiga dan t = tinggi segitiga 
#           (asumsikan: a > 0, t > 0) dan menghasilkan luas segitiga berdasarkan rumus: luas = ½ * a * t.
#           Catatan: output dituliskan dengan 3 angka di belakang koma.

# KAMUS
# a,t,luas : float

# ALGORITMA
a = float(input())
t = float(input())

luas = 0.5 * a * t

print("%.3f" % luas)