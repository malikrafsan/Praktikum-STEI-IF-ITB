# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 29 November 2020
# Deskripsi : Program menerima input A dan  lalu menuliskan semua nilai dar f(A), f(A+1),...,f(B)
#             f(x) = x^2 -2x + 5

# KAMUS
# A, B, i : integer

# Definisi fungsi f
def f(x):
    # Mengitung nilai fungsi f(x)
    
    # KAMUS LOKAL
    # hasil : integer

    # ALGORITMA
    hasil =  x**2 - 2*x + 5
    return hasil

# ALGORITMA PROGRAM UTAMA

# Menerima input batas pencarian
A = int(input("Masukkan A: "))
B = int(input("Masukkan B: "))

# Mencetak nilai fungsi f dari A sampai B
for i in range(A,B+1):
    print("f(" + str(i) + ") = " + str(f(i)))