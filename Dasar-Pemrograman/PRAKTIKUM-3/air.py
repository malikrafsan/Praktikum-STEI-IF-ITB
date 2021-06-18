# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: air.py
# Topik		: Review Prosedural dengan Bahasa Python
# Tanggal	: 19 Maret 2021
# Deskripsi	: Program membaca sebuah nilai T, suatu bilangan integer yang menyatakan temperatur air dalam derajat 
#           celcius untuk kondisi tekanan 1 atm.  Program menuliskan apakah kondisi air tersebut tergantung 
#           kepada temperaturnya.

T = int(input())

if T < 0:
    print("PADAT")
elif T == 0:
    print("ANTARA PADAT-CAIR")
elif T < 100:
    print("CAIR")
elif T == 100:
    print("ANTARA CAIR-GAS")
else:
    print("GAS")