# NIM/NAMA  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 21 Oktober 2020
# Deskripsi : Program yang menguraikan input warna menjadi nyala RGBnya

# KAMUS
# color_input : string

# Melakukan input warna yang ingin dicari RGBnya
color_input = input("Masukkan sebuah warna: ")

# Menggunakan percabangan untuk menentukan nyala RGBnya
if (color_input=="Red"):
    print("Warna RGB yang menyala: ")
    print("- Red")
elif (color_input=="Blue"):
    print("Warna RGB yang menyala: ")
    print("- Blue")
elif (color_input=="Green"):
    print("Warna RGB yang menyala: ")
    print("- Green")
elif (color_input=="Cyan"):
    print("Warna RGB yang menyala: ")
    print("- Green")
    print("- Blue")
elif (color_input=="Magenta"):
    print("Warna RGB yang menyala: ")
    print("- Red")
    print("- Blue")
elif (color_input=="Yellow"):
    print("Warna RGB yang menyala: ")
    print("- Red")
    print("- Green")
elif (color_input=="White"):
    print("Warna RGB yang menyala: ")
    print("- Red")
    print("- Green")
    print("- Blue")
else: # color_input=="Black"
    print("Warna RGB yang menyala: ")