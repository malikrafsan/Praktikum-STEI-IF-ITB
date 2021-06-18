module TesKategori where

tesKategori :: Int -> Int -> Int -> Bool

tesKategori t b k
    |t > 100 && b <= 150 = (k == 2) || (k == 3) ||(k == 4)
    |t <= 100 && b <= 150 = (k == 1) || ((b > 30) && (k == 2))
    |b > 150 && t <= 100 = k == 2
    |b > 150 && t > 100 && t <= 200 = k == 2 || k == 3
    |otherwise = k == 0
