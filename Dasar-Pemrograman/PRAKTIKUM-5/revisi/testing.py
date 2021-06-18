masukan = input()

ketemu = False

if not (ord(masukan) >= 97 and ord(masukan) <= 122):
    print("Bukan huruf kecil")

if not (ord(masukan) >= 65 and ord(masukan) <= 90):
    print("Bukan huruf besar")

if (not (ord(masukan) >= 65 and ord(masukan) <= 90)) and (not (ord(masukan) >= 97 and ord(masukan) <= 122)):
    print("Bukan huruf")

if ((not (ord(masukan) >= 65 and ord(masukan) <= 90)) and (not (ord(masukan) >= 97 and ord(masukan) <= 122))) and (not ketemu):
    print("Bukan huruf yang sudah")