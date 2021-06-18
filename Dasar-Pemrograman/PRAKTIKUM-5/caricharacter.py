# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: penduduk.py
# Topik		: Pengulangan dan Pemrosesan Array
# Tanggal	: 9 April 2021
# Deskripsi	: Program digunakan untuk membaca masukan jumlah penduduk desa dari sebuah kecamatan di suatu kota 
#           dan menghitung jumlah penduduk kecamatan (total penduduk desa).

N = int(input())

while (N <= 0) or (N > 100):
    print("Masukan salah. Ulangi!")
    N = int(input())

arr = ["*" for i in range(N)]

for i in range(N):
    arr[i] = ord(input())

CC = input()

if (CC == 's') or (CC == 'S'):
    ketemu = False
    i = 0
    while not (ketemu) and (i < N):
        if (arr[i] >= 97) and (arr[i] <= 122):
            ketemu = True
            print(i+1, chr(arr[i]))
        i += 1
    if i == N:
        print("Tidak ada huruf kecil")
elif (CC == 'L') or (CC == 'l'):
    ketemu = False
    i = 0
    while not (ketemu) and (i < N):
        if (arr[i] >= 65) and (arr[i] <= 90):
            ketemu = True
            print(i+1, chr(arr[i]))
        i += 1
    if i == N:
        print("Tidak ada huruf besar")
elif (CC == 'x') or (CC == 'X'):
    ketemu = False
    i = 0
    while not (ketemu) and (i < N):
        if not ((arr[i] >= 97) and (arr[i] <= 122)) or not ((arr[i] >= 65) and (arr[i] <= 90)):
            ketemu = True
            print(i+1, chr(arr[i]))
        i += 1
    if i == N:
        print("Semua huruf")
else:
    print("Tidak diproses")
