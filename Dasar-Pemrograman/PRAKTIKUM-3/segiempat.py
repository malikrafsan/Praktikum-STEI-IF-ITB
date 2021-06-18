# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: segiempat.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 19 Maret 2021
# Deskripsi	: Program akan membaca N (sebuah integer) berikut C1 dan C2 (dua buah karakter), dan kemudian 
#           menuliskan suatu bentuk dengan syarat N>0 dan C1 tidak sama dengan C2. 
#           Jika syarat tidak dipenuhi, diberikan pesan kesalahan. 

s = int(input())
C1 = input()
C2 = input()

if (s <= 0) or (C1==C2):
    print("Masukan tidak valid")
else:
    if s <= 2:
        for i in range(s):
            for j in range(s):
                print(C1,end='')
            print()
    else:
        print(C1*s)
        for i in range(s-2):
            print(C1 + C2*(s-2) + C1)
        print(C1*s)