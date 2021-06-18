# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 4 November 2020
# Deskripsi : Menerima input bilangan X dan mengembalikan angka cantik terkecil yang habis dibagi X

# KAMUS
# num, number, numX : interger
# lanjut : Boolean

# ALGORITMA

# Inisialisasi
number = 1
count = 0
lanjut = True
hitung = 0
pembagi = 1

numX = int(input("Masukkan X: "))

for i in str(numX):
    count = count + 1   # Menghitung digit X

if (count==1):
    num = numX
else:
    while lanjut:
        while (number%numX != 0):
            number = number + 1
        for j in str(number):
            hitung = hitung + 1
        for k in range (1, hitung+1):
            pembagi = pembagi + 10**k
        if (number % (pembagi)==0): # Digitnya sama atau angka cantik
            lanjut = False
            num = number
        print(number)
        number = number + 1
# Mencetak hasil ke layar
print("Bilangan cantik terkecil yang habis dibagi " + str(numX) + " ialah " + str(num))