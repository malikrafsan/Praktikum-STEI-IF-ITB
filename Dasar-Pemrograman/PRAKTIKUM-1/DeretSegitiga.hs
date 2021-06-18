module DeretSegitiga where

--DERETSEGITIGA             deretSegitiga(n)

--DEFINISI DAN SPESIFIKASI
deretSegitiga :: Int -> Int
-- deretSegitiga(n) menghasilkan nilai bilangan ke-n pada deret segitiga
-- prekondisi: n > 0

--REALISASI
deretSegitiga n =
    if n == 1 then 1
    else n + deretSegitiga (n-1)

--APLIKASI
--deretSegitiga 1
--deretSegitiga 5
--deretSegitiga 100
--deretSegitiga 20