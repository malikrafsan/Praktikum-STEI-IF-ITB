# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: sortsaham.py
# Topik		: Sorting dan Pemrosesan File
# Tanggal	: 23 April 2021
# Deskripsi	: Program yang membaca data kepemilikan saham sebuah perusahaan dari suatu file teks dan 
#           mengurutkan data tersebut ke layar berdasarkan IdPemilik secara terurut membesar serta menuliskan kembali 
#           data tersebut dalam keadaan terurut ke layar.

# Program SortSaham
# Spesifikasi : 
# Program yang membaca data kepemilikan saham sebuah perusahaan dari suatu file teks dan 
# mengurutkan data tersebut ke layar berdasarkan IdPemilik secara terurut membesar serta menuliskan kembali 
# data tersebut dalam keadaan terurut ke layar.
import tulisdata

# KAMUS
# namafile: string
# lst : array of tuple
# line1,line2,line3 : string
# i : integer

# FUNCTION        
def insertionSort(arr):
    # Mengurutkan array dengan insertion sort
    for Pass in range(1, len(arr)):
        Temp = arr[Pass]
        i = Pass-1
        while i >=0 and Temp[0] < arr[i][0]:
            arr[i+1] = arr[i]
            i -= 1
        arr[i+1] = Temp

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataSaham(namafile)

f = open(namafile,'r')
lst = []

line1 = f.readline()
if line1 == "99999999":
    print("File kosong")
else:
    while line1 != "99999999":
        line2 = f.readline()
        line3 = f.readline()
        tup = (int(line1),line2,int(line3))
        lst.append(tup)
        line1 = f.readline()

    insertionSort(lst)
    for i in range(len(lst)):
        print(lst[i][0],end=",")
        print(lst[i][1].rstrip(),end=',')
        print(lst[i][2])
        
f.close()

