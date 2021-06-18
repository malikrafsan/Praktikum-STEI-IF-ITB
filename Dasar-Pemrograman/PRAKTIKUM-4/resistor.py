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

# PROCEDURE DAN FUNCTION
def InputValidasi(r1,r2,r3,jenis):
# memvalidasi input r1,r2,r3,jenis sesuai ketentuan yang ada

    # KAMUS LOKAL
    # r1,r2,r3 : integer
    # jenis : char
    # cons : boolean
    # benar : array of char
    
    # ALGORITMA
    cons = True
    benar = ['s','S', 'p', 'P']

    if (r1 <= 0) or (r2 <= 0) or (r3 <= 0):
        cons = False
    if not (jenis in benar):
        cons = False
         
    if not cons:
        print("Masukan salah")
        return False
    else: # cons
        return True

def HasilHitung(r1,r2,r3,jenis):
# mengembalikan nilai perhitungan rangkaian dari r1,r2,r3 sesuai jenis (hanya 2 digit setelah koma)

    # KAMUS LOKAL
    # r1,r2,r3  : int
    # jenis     : char
    # hasil     : float
    
    # ALGORITMA 
    if (jenis == 's') or (jenis == 'S'):
        hasil = r1 + r2 + r3
        return ("%.2f" % hasil)
    else: # (jenis == 'p') or (jenis == 'P')
        hasil = 1/((1/r1) + (1/r2) + (1/r3))
        return ("%.2f" % hasil)

# ALGORITMA PROGRAM UTAMA

lanjut = False
while not lanjut:
    r1 = float(input())
    r2 = float(input())
    r3 = float(input())
    jenis = input()

    lanjut = InputValidasi(r1,r2,r3,jenis)

print(HasilHitung(r1,r2,r3,jenis))
    



