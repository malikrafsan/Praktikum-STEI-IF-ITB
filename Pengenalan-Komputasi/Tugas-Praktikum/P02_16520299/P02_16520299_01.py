# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 4 November 2020
# Deskripsi : Menerima input banyaknya ronde dan gerakan permainan batu gunting kertas dari Tuan Mor dan Tuan Vin 
# lalu menentukan siapa yang menang atau seri

# KAMUS
# scoreMor, scoreVin, jumlah, i : integer
# Mor, Vin : string

# ALGORITMA

# Inisialisasi
scoreMor = 0
scoreVin = 0

# Menerima input banyaknya ronde
jumlah = int(input("Masukkan banyaknya ronde: "))

# Melakukan looping sebanyak input banyak ronde
for i in range(1, jumlah+1):
    Mor = input("Masukkan gerakan Tuan Mor ke " + str(i) + ": ")
    Vin = input("Masukkan gerakan Tuan Vin ke " + str(i) + ": ")
    if (Mor=="P" and Vin=="R") or (Mor=="S" and Vin=="P") or (Mor=="R" and Vin=="S"):
        scoreMor = scoreMor + 1
    if (Mor=="R" and Vin=="P") or (Mor=="P" and Vin=="S") or (Mor=="S" and Vin=="R"):
        scoreVin = scoreVin + 1

# Terminasi
if (scoreMor > scoreVin):
    print("Pemenangnya adalah Tuan Mor.")
elif (scoreMor < scoreVin):
    print("Pemenangnya adalah Tuan Vin.")
else:
    print("Permainan berakhir seri.")