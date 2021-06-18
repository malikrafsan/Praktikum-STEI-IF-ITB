# Tuliskan identitas di sini
# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: pita.py
# Topik		: Dekomposisi Algoritmik
# Tanggal	: 2 April 2021
# Deskripsi	: Program menerima masukan sebuah bilangan bulat, misal N dan kemudian menampilkan gambar pita bintang, 
#           jika N adalah bilangan bulat ganjil (N > 0). Jika N bukan positif dan/atau bukan ganjil, maka diberikan pesan kesalahan.


# Program GambarPita
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar pita sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarPita(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar pita dengan lebar sebesar N sesuai spesifikasi soal
# Lengkapilah kamus lokal dan algoritma prosedur di bawah ini
    if N == 1:
        print("*")
    else:
        print("*"*N)
        for i in range(1, N//2 + 1):
            print(" "*i + "*"*(N - 2*i))
        for j in range(N//2 - 1,0,-1):
            print(" "*j + "*" * (N - 2*j))
        print("*"*N)

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
# Lengkapilah kamus lokal dan algoritma fungsi di bawah ini
    if (N > 0) and (N % 2 == 1):
        return True
    else:
        return False

# ALGORITMA PROGRAM UTAMA
N = int(input())
if (IsValid(N)):  # lengkapi dengan pemanggilan fungsi IsValid
    GambarPita(N)    # lengkapi dengan pemanggilan prosedur GambarPita
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")