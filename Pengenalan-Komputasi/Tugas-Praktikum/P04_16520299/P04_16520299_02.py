# NIM/Nama  : 16520299/Malik Akbar Hashemi Rafsanjani
# Tanggal   : 2 Desember 2020
# Deskripsi : Program menerima input pesan dan berapa banyak perubahan.
#             Program lalu mengubah setiap huruf menjadi huruf selanjutnya sebanyak perubahan.

# KAMUS
# Pesan, has : string
# N          : integer

# Definisi fungsi enkrip
def enkrip(S):
    # Menerima input pesan lalu mengubah setiap huruf menjadi huruf selanjutnya

    # KAMUS LOKAL
    # huruf     : matriks
    # hasil     : string
    # i,j       : integer

    # ALGORITMA

    # Membuat matriks yang berisi semua huruf
    # Asumsi semua pesan berisi huruf kecil
    huruf = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
    
    # Inisialisasi hasil perubahan
    hasil = ""
    for i in range(len(S)):
        for j in range(26):
            # Mencari huruf yang bersesuaian dengan setiap huruf pesan
            if S[i] == huruf[j]:
                # Jika bertemu huruf z maka indeks akan diubah -1
                if j == 25:
                    j = -1
                # Mengubah huruf pesan menjadi huruf berikutnya
                hasil += huruf[j+1]
    # Mengembalikan hasil perubahan
    return hasil

# ALGORITMA UTAMA

# Menerima input pesan dan banyak perubahan
Pesan = input("Masukkan pesan awal: ")
N = int(input("Masukkan nilai N: "))

# Melakukan perubahan sebanyak yang diinginkan
for i in range(N):
    has = enkrip(Pesan)
    Pesan = has

# Mencetak hasil pesan ke layar
print(Pesan)