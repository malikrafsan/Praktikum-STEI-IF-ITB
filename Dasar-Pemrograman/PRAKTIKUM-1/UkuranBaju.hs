module UkuranBaju where

--UKURANBAJU            ukuranBaju(t,b)

--DEFINISI DAN SPESIFIKASI
ukuranBaju :: Int -> Int -> Int
{-Fungsi ukuranBaju t b menerima masukan 2 buah integer positif, t (tinggi badan dalam cm) dan b (berat badan dalam kg) 
dan menghasilkan kode ukuran baju (1 adalah M, 2 adalah L, 3 adalah XL) atau kode 4 adalah untuk yang tidak mendapatkan kaos.
-}

--REALISASI
ukuranBaju t b
    | t <= 150 = 1
    | (t > 170) && (b > 60) && (b <= 80) = 3
    | (t > 150) && (t <= 170) && (b <= 80) = 2
    | (t > 150) && (t <= 170) && (b > 80) = 3
    | (t > 170) && (b <= 60) = 2
    | otherwise = 4

--APLIKASI
--ukuranBaju 160 75
--ukuranBaju 145 45
--ukuranBaju 190 85