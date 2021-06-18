module TesSyarat where

--TESSYARAT         tesSyarat(ip,pot)

--DEFINISI DAN SPESIFIKASI
tesSyarat :: Float -> Float -> Int 
{-Fungsi tesSyarat ip pot menerima input 2 buah bilangan riil (float), ip dan pot, dengan ip mewakili IP mahasiswa (bernilai 0..4) 
dan pot mewakili pendapatan orang tua (dalam juta rupiah, bernilai >= 0) dan menghasilkan kategori beasiswa (bernilai 0..4) 
yang berhak didapatkan oleh mahasiswa tersebut sesuai ketentuan
Asumsi pot >= 0, 0 <= ip <= 4
-}

--REALISASI
tesSyarat ip pot
    | ip >= 3.5 = 4
    | pot < 1 = 1
    | pot < 5 = if ip >= 2 then 3 else 2
    | otherwise = 0

--APLIKASI
--tesSyarat 3.51 1.5
--tesSyarat 2.01 1.5
