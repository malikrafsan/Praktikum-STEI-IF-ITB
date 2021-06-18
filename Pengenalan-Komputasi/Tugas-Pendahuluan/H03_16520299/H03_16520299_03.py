# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 16 November 2020
# Deskripsi : Program menerima input sebuah string lalu menentukan apakah string tersebut palindrom atau tidak. Asumsi string terdiri huruf kecil

# KAMUS
# leng, i : integer
# kata : string
# Palindrom : boolean
# tes : float

# ALGORITMA

# Menerima input panjang dan string tersebut
leng = int(input("Masukkan panjang string: "))
kata = input("Masukkan string: ")

i = 0
Palindrom = True
tes = leng//2

# Mengecek apakah huruf sama dari bagian depan dan bagian belakang
# Ketika jumlah huruf ganjil kita tidak perlu mengecek huruf di tengah
# Sehingga kita membagi dua panjang string dengan pembulatan
while (i < tes and Palindrom):
    if (kata[i] != kata[leng-(i+1)]):
        Palindrom = False
    i += 1

if Palindrom:
    print(kata + " adalah palindrom")
else: # Palindrom = False
    print(kata + " bukan palindrom")