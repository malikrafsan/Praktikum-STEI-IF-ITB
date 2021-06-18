# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 21 Oktober 2020
# Deskripsi : Program yang menentukan 2 input persamaan garis apakah sejajar, tegak lurus, atau tidak keduanya

# KAMUS
# a1_value, b1_valur, c1_value  : integer
# a2_value, b2_valur, c2_value  : integer
# gradien1, gradien2            : float

# Melakukan input nilai persamaan garis
a1_value = int(input("Masukkan a1: "))
b1_value = int(input("Masukkan b1: "))
c1_value = int(input("Masukkan c1: "))
a2_value = int(input("Masukkan a2: "))
b2_value = int(input("Masukkan b2: "))
c2_value = int(input("Masukkan c2: "))

# Menentukan gradien masing-masing persamaan garis
try:
    gradien1 = -(a1_value/b1_value)
except: # Ketika b1_value bernilai 0, maka program akan error sehingga harus diatasi
    ZeroDivisionError
    gradien1 = 0.1
try:
    gradien2 = -(a2_value/b2_value)
except: # Ketika b2_value bernilai 0, maka program akan error sehingga harus diatasi
    ZeroDivisionError
    gradien2 = 0.9

# Melakukan percabangan untuk menentukan apakah kedua garis sejajar, tegak lurus, atau tidak keduanya
if (gradien1==gradien2):
    print("Kedua garis sejajar.")
elif (b1_value==0 and b2_value==0):
    print("Kedua garis sejajar.")
elif (a1_value==0 and a2_value==0):
    print("Kedua garis sejajar.")
elif (gradien1*gradien2==-1):
    print("Kedua garis tegak lurus.")
elif (b1_value==0 and a2_value==0):
    print("Kedua garis tegak lurus.")
elif (b2_value==0 and a1_value==0):
    print("Kedua garis tegak lurus.")
else: # Ketika input tidak memenuhi kondisi di atas
    print("Kedua garis tidak sejajar dan tidak tegak lurus.")