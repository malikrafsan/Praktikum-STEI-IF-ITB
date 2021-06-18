# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: penduduk.py
# Topik		: Pengulangan dan Pemrosesan Array
# Tanggal	: 9 April 2021
# Deskripsi	: Program digunakan untuk membaca masukan jumlah penduduk desa dari sebuah kecamatan di suatu kota 
#           dan menghitung jumlah penduduk kecamatan (total penduduk desa).

# KAMUS
# N, sumPen, penduduk, i : integer

# ALGORITMA
N = int(input()) # menerima input N

sumPen = 0 # inisialisasi

# Menghitung jumlah
for i in range(N):
    penduduk = int(input())
    sumPen += penduduk 

print(sumPen)