# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: bujursangkar.py
# Topik		: Pengulangan dan Pemrosesan Array
# Tanggal	: 9 April 2021
# Deskripsi	: Program yang digunakan untuk menghitung luas bujur sangkar (persegi). 
#           Apabila sisi yang dimasukkan <= 0, program akan mengeluarkan pesan error.

# KAMUS
# sisi : integer

# ALGORITMA
sisi = int(input()) # menerima input

if sisi > 0:
    print(sisi*sisi)
else:
    print("Sisi harus > 0") # pesan error