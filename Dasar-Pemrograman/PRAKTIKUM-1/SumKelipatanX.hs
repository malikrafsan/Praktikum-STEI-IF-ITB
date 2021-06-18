module SumKelipatanX where

--SUMKELIPATANX         sumKelipatanX(m,n,x)

--DEFINISI DAN SPESIFIKASI
sumKelipatanX :: Int -> Int -> Int -> Int
--Fungsi sumKelipatanX m n x menghasilkan jumlah total bilangan kelipatan x di antara m dan n (m dan n termasuk) 
--dengan menggunakan ekspresi rekursif.
--Prekondisi/syarat/asumsi yang berlaku adalah m <= n dan x <= n juga m, n, dan x integer positif.

--REALISASI
sumKelipatanX m n x
    | m > n = 0
    | mod m x == 0 = m + sumKelipatanX (m+1) n x
    | otherwise = sumKelipatanX (m+1) n x

--APLIKASI
--sumKelipatan 1 1 1
--sumKelipatan 1 10 2
--sumKelipatan 5 14 3