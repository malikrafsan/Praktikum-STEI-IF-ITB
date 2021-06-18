# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: resistor.py
# Topik		: Dekomposisi Algoritmik
# Tanggal	: 26 Maret 2021
# Deskripsi	: Program yang menerima 3 (tiga) bilangan riil yang merepresentasikan  nilai resistor R1, R2, dan R3, 
#           berupa bilangan rill > 0, dan menghitung nilai resistansi total, tergantung dihubungkan secara serial atau paralel 
#           (asumsikan tidak ada jenis hubungan lain)

# Program Resistor
# Input: r1,r2,r3   : integer
#        jenis      : char
# Output: Jika r1,r2,r3 <= 0, dan jenis sesuai ketentuan, outputnya hasil rangkaian sesuai input jenis
#         Jika tidak, tampilkan pesan kesalahan: 


# KAMUS
# r1,r2,r3  : integer
# lanjut    : boolean
# benar     : array of char
# hasil     : float

# ALGORITMA
lanjut = False
benar = ['s','S', 'p', 'P']

while not lanjut:
    lanjut = True
    
    r1 = float(input())
    r2 = float(input())
    r3 = float(input())
    jenis = input()

    if (r1 <= 0) or (r2 <= 0) or (r3 <= 0):
        lanjut = False
    if not (jenis in benar):
        lanjut = False
    
    if not lanjut:
        print("Masukan salah")
    
if jenis in benar[0:2]:
    hasil = r1 + r2 + r3
    print("%.2f" % hasil)
else:
    hasil = 1/((1/r1) + (1/r2) + (1/r3))
    print("%.2f" % hasil)