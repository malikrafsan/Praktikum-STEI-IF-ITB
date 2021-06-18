# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: berat.py
# Topik		: Pengulangan dan Pemrosesan Array
# Tanggal	: 9 April 2021
# Deskripsi	: Program yang digunakan untuk membaca masukan berat tubuh mahasiswa dan menampilkan beberapa statistik

# KAMUS
# total, N, i, kurang, lebih : integer
# arr : array of integer

# ALGORITMA
arr = []
total = 0

N = int(input())
if (N >= 30) and (N <= 200):
    arr += [N]
    total += N
    
while N != (-999):
    N = int(input())
    if (N >= 30) and (N <= 200):
        arr += [N]
        total += N

if (len(arr) > 0):   
    print(len(arr))

    kurang = 0
    for i in range(len(arr)):
        if arr[i] <= 50:
            kurang += 1
    print(kurang)

    lebih = 0
    for i in range(len(arr)):
        if arr[i] >= 100:
            lebih += 1
    print(lebih)

    print(round(total/len(arr)))
else:
    print("Data kosong")