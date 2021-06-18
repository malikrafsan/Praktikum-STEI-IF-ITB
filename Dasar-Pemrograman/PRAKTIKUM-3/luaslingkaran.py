# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: luaslingkaran.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 19 Maret 2021
# Deskripsi	: Program menerima masukan sebuah bilangan real r yang merepresentasikan jari-jari sebuah lingkaran 
#           (asumsikan  r > 0) dan menghasilkan luas lingkaran berdasarkan rumus: luas = 3.1415 * r * r.
#           Catatan: output ditulis dengan 4 angka di belakang koma.


r = float(input())

luas = 3.1415 * r * r

print ("%.4f" % luas)