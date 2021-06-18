# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 18 November 2020
# Deskripsi : Program menerima input string sepanjang N lalu menghitung berapa 
#             banyak kemunculan kata 'tuan' muncul sebagai subsequence dari string tersebut

# KAMUS
# N, i, j, k, l, ada: integer
# string : string

# ALGORITMA

# Menerima input panjang string
N = int(input("Masukkan nilai N: "))

# Menerima input string
string = input("Masukkan string: ")

# Menghitung banyak kemunculan dengan nested loop. Jika ditemui huruf yang sama dengan 't' 
# program akan lanjut mencari 'u', dan seterusnya hingga 'n'. Jika berhasil maka jumlah kemunculan ditambah 1
ada = 0
for i in range(N):
    if string[i] == "t":
        # Program menemukan huruf 't'
        for j in range(i, N):
            if string[j] == "u":
                # Program menemukan huruf 'u'
                for k in range(j, N):
                    if string[k] == "a":
                        # Program menemukan huruf 'a'
                        for l in range(k, N):
                            if string[l] == "n":
                                # Program menemukan huruf 'n'
                                # Menambah 1 banyak kemunculan
                                ada += 1

# Mencetak hasil ke layar
print("Ada " + str(ada) + " buah kemunculan.")