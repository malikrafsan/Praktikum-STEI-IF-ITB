# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 4 November 2020
# Deskripsi : Menerima input bilangan N dan mencetak bilangan 10**x terkecil yang lebih dari N

# KAMUS
# batas, pangkat, dipangkat : integer

# ALGORITMA
pangkat = -1                        # Inisialisasi
dipangkat = -1

batas = int(input("Masukkan N: "))  # First-Elmt
while (batas >= dipangkat):
    pangkat = pangkat + 1           # Aksi
    dipangkat = 10**pangkat
# batas < dipangkat

# Terminasi
print(10**pangkat)