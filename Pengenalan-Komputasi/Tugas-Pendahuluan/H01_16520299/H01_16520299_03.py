# NIM/NAMA    : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal     : 18 Oktober 2020
# Deskripsi   : Program yang menentukan input bilangan adalah bilangan positif ganjil, positif genap, ganjil, atau nol
 
# KAMUS
# X : integer

# Melakukan input bilangan yang akan ditentukan
bilangan_input = int(input("Masukkan X: "))

if (bilangan_input>0) :
    if (bilangan_input % 2 == 1):
        print("X adalah bilangan positif ganjil")
    else: # bilangan_input % 2 == 0
        print("X adalah bilangan positif genap")
elif (bilangan_input < 0):
    print("X adalah bilangan negatif")
else:
    print("X adalah bilangan nol")