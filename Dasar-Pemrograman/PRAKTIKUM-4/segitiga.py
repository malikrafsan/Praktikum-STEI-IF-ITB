# Tuliskan identitas di sini
# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: segitiga.py
# Topik		: Dekomposisi Algoritmik
# Tanggal	: 26 Maret 2021
# Deskripsi	: Program yang menerima masukan sebuah bilangan bulat, misal N dan kemudian menampilkan gambar huruf segitiga 
#           dari karakter bintang, jika N adalah bilangan bulat ganjil (N > 0). Jika N bukan positif dan/atau bukan ganjil, 
#           maka diberikan pesan kesalahan.


# Program GambarSegitiga
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar segitiga sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarSegitiga(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar segitiga dengan tinggi sebesar N sesuai spesifikasi soal
# Lengkapilah kamus lokal dan algoritma prosedur di bawah ini

    # KAMUS LOKAL
    # awal, akhir : int
    # i, j : int
    
    # ALGORITMA
    awal = (N//2) + 1
    akhir = (N//2)
    
    for i in range(awal):
        print(" "*((awal - i - 1) * 2) + "*"*((i+1)*2 - 1) )
    for j in range(akhir):
        print(" "*((j+1)*2) + "*"*(N - ((j+1)*2)))
    
def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
# Lengkapilah kamus lokal dan algoritma fungsi di bawah ini

    # KAMUS
    # N : int

    # ALGORITMA
    if (N > 0) and (N % 2 == 1):
        return True
    else: # (N <= 0) or (N % 2 != 1)
        return False

# ALGORITMA PROGRAM UTAMA
N = int(input())
if IsValid(N):              # lengkapi dengan pemanggilan fungsi IsValid
    GambarSegitiga(N)       # lengkapi dengan pemanggilan prosedur GambarSegitiga
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")