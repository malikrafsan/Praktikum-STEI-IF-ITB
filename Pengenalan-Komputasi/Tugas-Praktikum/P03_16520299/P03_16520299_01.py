# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 18 November 2020
# Deskripsi : Program menerima input N buah harga dan persentase diskonnya, lalu program 
#             akan mencetak besar diskon harga terbesar dan barang keberapa barang tersebut

# KAMUS
# banyak, i, index : integer
# list_harga, list_diskon, list_akhir : array
# max : float

# ALGORITMA

# Menerima input banyaknya barang
banyak = int(input("Masukkan banyaknya barang: "))

# Deklarasi list harga, list persentase diskon, dan list besar diskon harga
list_harga = [0 for i in range(banyak)]
list_diskon = [0 for i in range(banyak)]
list_akhir = [0 for i in range(banyak)]

# Mengisi list harga dan list persentase diskon sesuai input user
for i in range(banyak):
    list_harga[i] = int(input("Masukkan harga barang ke-" + str(i+1) + ": "))
for i in range(banyak):
    list_diskon[i] = int(input("Masukkan besar diskon (dalam persen) barang ke-" + str(i+1) + ": "))

# Menghitung besar diskon harga dan dimasukkan ke list_akhir
for i in range(banyak):
    list_akhir[i] = (list_harga[i]*list_diskon[i])/100

# Inisialisasi besar diskon harga terbesar sebagai elemen pertama
max = list_akhir[0]

# Menentukan besar diskon harga terbesar dan indeksnya
index = 0
for i in range(1, banyak):
    if max < list_akhir[i]:
        max = list_akhir[i]
        index = i

# Mencetak hasil ke layar
print("Barang " + str(index+1) + " memiliki diskon paling besar yaitu " + str(max) + ".")