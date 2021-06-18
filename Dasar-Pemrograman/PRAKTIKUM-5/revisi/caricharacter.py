# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: penduduk.py
# Topik		: Pengulangan dan Pemrosesan Array
# Tanggal	: 9 April 2021
# Deskripsi	: Program digunakan untuk membaca masukan jumlah penduduk desa dari sebuah kecamatan di suatu kota 
#           dan menghitung jumlah penduduk kecamatan (total penduduk desa).

N = int(input())

benar = False
while not (benar):
    if (N > 0) and (N <= 100):
        benar = True
    else:
        print("Masukan salah. Ulangi!")
        N = int(input())

arr = ["*" for i in range(N)]

ketemuKecil = False
ketemuBesar = False
ketemuSimbol = False

for i in range(N):
    masukan = input()
    arr[i] = masukan
    if (ord(masukan) >= 97) and (ord(masukan) <= 122) and (not ketemuKecil):
        ketemuKecil = True
        kecil = i
    if (ord(masukan) >= 65) and (ord(masukan) <= 90) and (not ketemuBesar):
        ketemuBesar = True
        besar = i
    if ((not (ord(masukan) >= 65 and ord(masukan) <= 90)) and (not (ord(masukan) >= 97 and ord(masukan) <= 122))) and (not ketemuSimbol):    
        ketemuSimbol = True
        simbol = i

CC = input()

if (CC == 's') or (CC == 'S'):
    if ketemuKecil:
        print(kecil+1, arr[kecil])
    else:
        print("Tidak ada huruf kecil")
elif (CC == 'l') or (CC == 'L'):
    if ketemuBesar:
        print(besar+1,arr[besar])
    else:
        print("Tidak ada huruf besar")
elif (CC == 'x') or (CC == 'X'):
    if ketemuSimbol:
        print(simbol+1, arr[simbol])
    else:
        print("Semua huruf")
else:
    print("Tidak diproses")