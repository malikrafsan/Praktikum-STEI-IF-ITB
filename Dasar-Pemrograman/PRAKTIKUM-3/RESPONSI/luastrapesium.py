# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: luastrapesium.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program menerima masukan 3 buah bilangan real t, s1, s2 dengan t = tinggi trapesium, 
#           s1 = panjang sisi sejajar 1, dan s2 = panjang sisi sejajar 2 (asumsikan: t > 0, s1 > 0, s2 > 0, dan s1 tidak sama dengan s2) 
#           dan menghasilkan luas trapesium berdasarkan rumus: luas = ½ * t * (s1 + s2)
#           Catatan: output ditulis dengan 2 digit angka di belakang koma

# KAMUS
# t,s1,s2, luas : float

# ALGORITMA
t = float(input())
s1 = float(input())
s2 = float(input())

luas = 0.5 * t * (s1 + s2)

print ("%.2f" % luas)