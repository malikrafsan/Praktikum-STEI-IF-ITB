# NIM/NAMA    : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal     : 18 Oktober 2020
# Deskripsi   : Program kalkulator sederhana yang menerima 2 input angka dan 1 input operator
 
# KAMUS
# ang1, ang2    : integer
# opr           : string

# Melakukan input kedua angka dan operator
ang1 = int(input("Masukkan angka pertama: "))
ang2 = int(input("Masukkan angka kedua: "))
opr = input("Masukkan operator: ")

# Melakukan percabangan sesuai dengan input operator dan mem-print persamaan dan hasilnya
if (opr=="+"):
    print(str(ang1) + " " + opr + " " + str(ang2) + " = " + str(ang1 + ang2))
elif (opr=="-"):
    print(str(ang1) + " " + opr + " " + str(ang2) + " = " + str(ang1 - ang2))
elif (opr=="/"): # Operator "/" disini kita gunakan sebagai pembagian dibulatan ke bawah
    print(str(ang1) + " " + opr + " " + str(ang2) + " = " + str(ang1 // ang2))
elif (opr=="*"):
    print(str(ang1) + " " + opr + " " + str(ang2) + " = " + str(ang1 * ang2))
elif (opr=="%"):
    print(str(ang1) + " " + opr + " " + str(ang2) + " = " + str(ang1 % ang2))
else: # Bila input operator tidak ada dalam percabangan di atas
    print("Operator tidak dapat teridentifikasi oleh program ini")