# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 21 Oktober 2020
# Deskripsi : Program yang dapat menentukan indeks yang didapat berdasarkan input nilai yang diberikan

# KAMUS
# nilai_pengkom : float

# Melakukan input nilai
nilai_pengkom = float(input("Masukkan nilai akhir Tuan Mor: "))

# Menggunakan percabangan untuk menentukan indeks yang didapat
if (nilai_pengkom>=80):
    print("Tuan Mor mendapatkan indeks A.")
elif (nilai_pengkom>=75):
    print("Tuan Mor mendapatkan indeks AB.") 
elif (nilai_pengkom>=70):
    print("Tuan Mor mendapatkan indeks B.") 
elif (nilai_pengkom>=60):
    print("Tuan Mor mendapatkan indeks BC.") 
elif (nilai_pengkom>=50):
    print("Tuan Mor mendapatkan indeks C.") 
elif (nilai_pengkom>=40):
    print("Tuan Mor mendapatkan indeks D.") 
else: # (nilai_pengkom<40)
    print("Tuan Mor mendapatkan indeks E.")