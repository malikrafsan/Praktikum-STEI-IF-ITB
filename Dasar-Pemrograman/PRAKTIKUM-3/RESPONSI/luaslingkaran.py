# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: luaslingkaran.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program menerima masukan sebuah bilangan real r yang merepresentasikan jari-jari sebuah lingkaran 
#           (asumsikan  r > 0) dan menghasilkan luas lingkaran berdasarkan rumus: luas = 3.1415 * r * r.
#           Catatan: output ditulis dengan 4 angka di belakang koma.

# KAMUS
# r, luas : float

# ALGORITMA
pi = 3.1415
r = float(input())

luas = pi*r*r

print ("%.4f" % luas)