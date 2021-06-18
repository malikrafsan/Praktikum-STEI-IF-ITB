# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: sort.py
# Topik		: Sorting dan Pemrosesan File
# Tanggal	: 23 April 2021
# Deskripsi	: program yang menerima input bilangan, misalnya N dan menerima N buah input bilangan yang disimpan di sebuah array. 
#           Lalu, implementasikan algoritma sorting, yaitu selection sort untuk mengurutkan bilangan dalam array tersebut 
#           dari besar ke kecil. Kemudian, print array yang telah diurutkan ke layar (langsung print(array)) saja. 
#           Asumsikan input valid, yaitu bilangan integer dan N > 0.

# Program Sort
# Menerima input bilangan, misalnya N dan menerima N buah input bilangan yang disimpan di sebuah array. 
# Lalu, implementasikan algoritma sorting, yaitu selection sort untuk mengurutkan bilangan dalam array tersebut 
# dari besar ke kecil. Kemudian, print array yang telah diurutkan ke layar

# KAMUS
# N : integer
# arr : array of integer

# FUNCTION
def get_max(arr, index_start):
  # mendapatkan maksimum array dari indeks indeks_start sampai selesai
  maxi = arr[index_start]
  for i in range(index_start+1,len(arr)):
      if maxi < arr[i]:
          maxi = arr[i]
  return maxi      

def get_idx(arr, number):
   # mendapatkan index dari suatu angka dalam array
   for i in range(len(arr)):
       if arr[i] == number:
           return i

def swap(array, indeks_1, indeks_2):
  # swap elemen array indeks 1 dengan indeks 2
  array[indeks_1], array[indeks_2] = array[indeks_2], array[indeks_1]

def sort(arr):
  for i in range(len(arr)):
    maxArr = get_max(arr, i)
    maxIdx = get_idx(arr, maxArr)
    swap(arr, i, maxIdx)
  print(arr)

# MAIN PROGRAM

N = int(input())
arr = [0 for i in range(N)]

for i in range(N):
    arr[i] = int(input())    

sort(arr)