module GabungList where

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

-- ==========================================================================

--FUNGSI ANTARA
--DEFINISI DAN SPESIFIKASI
masukkan :: Int -> [Int] -> [Int] --fungsi antara dari listSort, untuk memasukkan elemen sesuai urutan
listSort :: [Int] -> [Int] --Mengurutkan list
satukanList :: [Int] -> [Int] -> [Int] --Menyatukan l1 dan l2

--REALISASI
masukkan x li =
    if isEmpty li then [x]
    else if x <= head li then [x] ++ li
    else konso (head li) (masukkan x (tail li))
listSort li =
    if isEmpty li then []
    else masukkan (head li) (listSort (tail li))
satukanList l1 l2 =
    if isEmpty l1 then l2
    else konso (head l1) (satukanList (tail l1) l2)


--DEFINISI DAN SPESIFIKASI
gabungList :: [Int] -> [Int] -> [Int]
-- gabungList menerima masukan dua buah list of integer l1 dan l2 dan mengembalikan
-- sebuah list of integer l3. l1 adalah list dengan bilangan sembarang dan l2 adalah
-- list yang sudah terurut serta l3 adalah gabungan dari kedua list dengan isi dari
-- list tersebut sudah terurut tidak mengecil (membesar atau sama).

--REALISASI

gabungList l1 l2 =
    let
        l3 = satukanList l1 l2
        hasil = listSort l3
    in
        hasil

--APLIKASI
{-
1.	gabungList [1,3,0,4] [-9,-1,4]	[-9,-1,0,1,3,4,4]
2.	gabungList [] [2,3,4,5]	[2,3,4,5]
3.	gabungList [3,7,2] []	[2,3,7]
-}