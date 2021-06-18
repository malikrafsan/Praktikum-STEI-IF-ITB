# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: penduduk.py
# Topik		: Pengulangan dan Pemrosesan Array
# Tanggal	: 9 April 2021
# Deskripsi	: Program digunakan untuk membaca masukan jumlah penduduk desa dari sebuah kecamatan di suatu kota 
#           dan menghitung jumlah penduduk kecamatan (total penduduk desa).

N = int(input())
arr = [0 for i in range(N)]

for i in range(N):
    masukan = int(input())
    arr[i] = masukan

maxi = arr[i]
mini = arr[i]

X = int(input())

X_ada = False

for i in range(N):
    if maxi < arr[i]:
        maxi = arr[i]
    if mini > arr[i]:
        mini = arr[i]
    if X == arr[i]:
        X_ada = True

ekstrim = False

if X_ada:
    if X == maxi:
        print("maksimum")
        ekstrim = True
    if X == mini:
        print("minimum")
        ekstrim = True
    if not (ekstrim):
        print("N#A")
else:
    print(X, "tidak ada")