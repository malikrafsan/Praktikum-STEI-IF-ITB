# NIM/Nama	: 16520299/Malik Akbar Hashemi Rafsanjani
# Nama file	: ratamhs.py
# Topik		: Sorting dan Pemrosesan File
# Tanggal	: 23 April 2021
# Deskripsi	: Sebuah program yang membaca data mahasiswa dari suatu file teks dan menuliskan nilai rata-rata yang diperoleh 
#           oleh setiap mahasiswa. Data nilai rata-rata ditampilkan terurut berdasarkan NIM mahasiswa.

# Program RataRataNilaiMahasiswa
# Spesifikasi : ....
import tulisdata

# KAMUS
# namafile: string
# lst : array of tuple
# tup : tuple
# currNim, CurrSum, CurrCount, rata : integer

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataMhs(namafile)

f = open(namafile,'r')
lst = []

line1 = f.readline()
if line1 == "99999999":
    print("File kosong")
else:
    while line1 != "99999999":
        line2 = f.readline()
        line3 = f.readline()
        tup = (int(line1),line2,int(line3))
        lst.append(tup)
        line1 = f.readline()

    lst.sort(key=lambda tup: tup[0]) # Tidak disebutkan harus menggunakan algoritma sorting sendiri
    lst.append("mark")
    i = 0
    while lst[i] != "mark":
        currNim = lst[i][0]
        CurrSum = 0
        CurrCount = 0
        while True:
            CurrSum += lst[i][2]
            CurrCount += 1
            i += 1
            if currNim != lst[i][0]:
                break
        rata = round(CurrSum / CurrCount)
        print(str(currNim) + "=" + str(rata))

f.close()