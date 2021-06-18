# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: air.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 2 April 2021
# Deskripsi	: Program membaca sebuah nilai T, suatu bilangan integer yang menyatakan temperatur air 
#           dalam derajat celcius untuk kondisi tekanan 1 atm.  Program menuliskan apakah kondisi air 
#           tersebut tergantung kepada temperaturnya.


# KAMUS
# T : float

#ALGORITMA

T = float(input())

if T > 100:
    print("GAS")
elif T == 100:
    print("ANTARA CAIR-GAS")
elif T > 0:
    print("CAIR")
elif T == 0:
    print("ANTARA PADAT-CAIR")
else:
    print("PADAT")