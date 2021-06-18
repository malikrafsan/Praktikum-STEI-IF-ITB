# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: countvocal.py
# Topik		: Sorting dan Pemrosesan File
# Tanggal	: 23 April 2021
# Deskripsi	: Sebuah program yang menulis dan membaca ke sebuah file teks bernama dataku.txt. File dataku.txt berisi deretan karakter, 
#           diakhiri karakter titik '.' sebagai mark. Program menghasilkan keluar berupa berapa banyak huruf hidup (vokal) yang ada 
#           dalam teks tersebut. Huruf hidup adalah ['A','a','I','i','U','u','E','e','O','o'].

# Program HitungVokal
# Membaca masukan sejumlah karakter dan menyimpannya ke file data.txt
# Membaca isi file data.txt, menghitung dan menampilkan ada berapa
# banyak karakter huruf hidup dalam file

# KAMUS
mark = '.' # constant mark : character = '.'

def TulisTeks():
# Membaca kalimat (kumpulan karakter) diakhiri mark dari keyboard
# dan menyimpannya ke file data.txt
    # KAMUS LOKAL
    # f : SEQFILE of char
    # kalimat
    # ALGORITMA
    f = open("dataku.txt",'w')
    kalimat = input() # Baca sebuah kalimat dari keyboard
                      # diakhiri mark '.'
                      # Kalimat kosong hanya ada mark
    f.write(kalimat)  # Menuliskan kalimat ke file
    f.close()

# ALGORITMA PROGRAM UTAMA
TulisTeks()
f = open("dataku.txt",'r')
c1 = f.read(1) # lengkapi program utama

lst = ['A','a','I','i','U','u','E','e','O','o']
count = 0
while c1 != mark:
    if c1 in lst:
        count += 1
    c1 = f.read(1)

print (count)