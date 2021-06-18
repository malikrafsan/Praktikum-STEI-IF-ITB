module KonversiSuhu where

--KONVERSISUHU          konversiSuhu(t,k)

--DEFINISI DAN SPESIFIKASI
konversiSuhu :: Float -> Char -> Float
{-Fungsi konversiSuhu t k menghasilkan suhu dalam satuan k yang merupakan konversi suhu t derajat Celcius.
Asumsi input k hanya R atau K atau F
-}

--REALISASI
konversiSuhu t k
    | k == 'R' = 4 / 5 * t
    | k == 'K' = t + 273.15
    | k == 'F' = (9 / 5 * t) + 32

--APLIKASI
{- 
konversiSuhu 25 'R'
konversiSuhu 37 'F'
-}