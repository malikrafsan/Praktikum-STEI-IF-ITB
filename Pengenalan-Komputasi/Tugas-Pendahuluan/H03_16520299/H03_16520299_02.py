# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 16 November 2020
# Deskripsi : Menerima input dua array A dan B lalu memeriksa apakah B anagram dari A. Asumsi elemen pada array A dan B maksimal 10

# KAMUS
# lengA, lengB, a, b, c, d, e, masukanA, masukanB : integer
# freqA, freqB : array
# isAnagram : boolean

# ALGORITMA

lengA = int(input("Masukkan banyaknya elemen A: "))

# Deklarasi array frekuensi kemunculan elemen array A
# Asumsi elemen pada array hanya bisa 0 sampai 9
freqA = [0 for a in range(10)]

for b in range(lengA):
    masukanA = int(input("Masukkan elemen A ke-" + str(b+1) + ": "))
    freqA[masukanA] += 1

lengB = int(input("Masukkan banyaknya elemen B: "))

# Deklarasi array frekuensi kemunculan elemen array B
# Asumsi elemen pada array hanya bisa 0 sampai 9
freqB = [0 for c in range(10)]

for d in range(lengB):
    masukanB = int(input("Masukkan elemen B ke-" + str(d+1) + ": "))
    freqB[masukanB] += 1

# Memeriksa apakah frekuensi kemunculan elemen array A sama dengan array B
# Array A dan B akan anagram jika frekuensi kemunculan elemennya semua sama
e = 0
isAnagram = True
while (e < 10 and isAnagram):
    if (freqA[e] != freqB[e]):
        isAnagram = False
    e += 1

if isAnagram:
    print("B adalah anagram dari A")
else: # isAnagram == False
    print("B bukan anagram dari A")