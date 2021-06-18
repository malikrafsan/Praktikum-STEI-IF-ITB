# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: segiempat.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program akan membaca N (sebuah integer) berikut C1 dan C2 (dua buah karakter), 
#           dan kemudian menuliskan bentuk sebagai berikut dengan syarat N>0 dan C1 tidak sama dengan C2. 
#           Jika syarat tidak dipenuhi, diberikan pesan kesalahan.


# KAMUS
# N,i,j : integer
# C1, C2 : char

# ALGORITMA

N = int(input())
C1 = input()
C2 = input()

if (N>0) and (C1 != C2):
    if N <= 2:
        for i in range(N):
            for j in range(N):
                print(C1,end="")
            print()
    else:
        print(C1*N)
        for i in range(N-2):
            print(C1 + C2*(N-2) + C1)
        print(C1*N)
else:
    print("Masukan tidak valid")