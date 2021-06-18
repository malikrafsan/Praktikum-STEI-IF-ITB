# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 4 November 2020
# Deskripsi : Menerima input bilangan N dan menguji apakah X bilangan prima

# KAMUS
# angka, i : integer
# kata_kata : string
# prime : boolean

# ALGORITMA
prime = True                            # Inisialisasi
kata_kata = " adalah bilangan prima"

angka = int(input("Masukkan X: "))      # Menerima input bilangan yang akan diuji

if (angka >= 2):
    while prime:
        for i in range (2, angka):
            if (angka%i == 0): # Jika bilangan tersebut habis dibagi bilangan lain di antara 1 dan bilangan itu sendiri maka bukan prima
                kata_kata = " bukan bilangan prima"
                prime = False
        prime = False
    # Terminasi
    print(str(angka) + kata_kata)

else:   # (angka < 2)
    print(str(angka) + " bukan bilangan prima")