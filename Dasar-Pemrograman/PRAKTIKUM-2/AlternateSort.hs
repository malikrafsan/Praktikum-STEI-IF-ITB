module AlternateSort where

-- DEFINISI DAN SPESIFIKASI LIST
{- type List of Int: [ ] atau [e o List] atau [List o e]  
   Definisi type List of Int
   Basis: List of Int kosong adalah list of Int 
   Rekurens: 
   List tidak kosong dibuat dengan menambahkan sebuah elemen bertype Int di awal 
   sebuah list atau
   dibuat dengan menambahkan sebuah elemen bertype Int di akhir sebuah list -}

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: Int -> [Int] -> [Int]
{- konso e li menghasilkan sebuah list of integer dari e (sebuah integer) dan li 
   (list of integer), dengan e sebagai elemen pertama: e o li -> li' -}
-- REALISASI
konso e li = [e] ++ li

konsDot :: [Int] -> Int -> [Int]
{- konsDot li e menghasilkan sebuah list of integer dari li (list of integer) dan 
   e (sebuah integer), dengan e sebagai elemen terakhir: li o e -> li' -}
-- REALISASI
konsDot li e = li ++ [e]

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- last :: [Int] -> Int
-- last l menghasilkan elemen terakhir list l, l tidak kosong

-- init :: [Int] -> [Int]
-- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Int] -> Bool
-- isEmpty l  true jika list of integer l kosong
-- REALISASI
isEmpty l = null l

isOneElmt :: [Int] -> Bool
-- isOneElmt l true jika list of integer l hanya mempunyai satu elemen
-- REALISASI
isOneElmt l = (length l) == 1 

-- ================================================================================

--FUNGSI ANTARA
--DEFINISI DAN SPESIFIKASI
masukkan :: Int -> [Int] -> [Int]
listSort :: [Int] -> [Int]
bagi1 :: [Int] -> [Int]

masukkan x li =
    if isEmpty li then [x]
    else if x <= head li then [x] ++ li
    else konso (head li) (masukkan x (tail li))

listSort li =
    if isEmpty li then []
    else masukkan (head li) (listSort (tail li))

bagi1 lst =
    if isEmpty lst then []
    else if isOneElmt lst then lst
    else konso (head lst) (bagi1 (tail (init lst)))

bagi2 :: [Int] -> [Int]
bagi2 lst =
    if isEmpty lst then []
    else if isOneElmt lst then []
    else konsDot (bagi2 (init (tail lst))) (last lst)

urut :: [Int] -> [Int] -> [Int]
urut l1 l2 =
    if isEmpty l2 && not (isEmpty l1) then l1
    else if isEmpty l1 && isEmpty l2 then []
    else konso (head l1) (konso (last l2) (urut (tail l1) (init l2)))

--DEFINISI DAN SPESIFIKASI
alternateSort :: [Int] -> [Int]
{-
fungsi alternateSort mengembalikan list sedemikian rupa seperti yang pada aturan
-}

--REALISASI
alternateSort lst =
    let
        listurut = listSort lst
        l1 = bagi1 listurut
        l2 = bagi2 listurut
        hasil = urut l1 l2
    in
        hasil
