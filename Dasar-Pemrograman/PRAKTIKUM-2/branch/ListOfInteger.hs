module ListOfInteger where

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
satukanList :: [Int] -> [Int] -> [Int] --menggabungkan 2 list menjadi 1
isGanda :: Int -> [Int] -> [Int] --menghilangkan duplicate element
makeUnique :: [Int] -> [Int] --menjadikan list menjadi list dengan elemen yang unik
masukkan :: Int -> [Int] -> [Int] --memasukkan elemen sesuai dengan urutan
listSort :: [Int] -> [Int] --mengurutkan list

--REALISASI
satukanList l1 l2 =
    if isEmpty l1 then l2
    else konso (head l1) (satukanList (tail l1) l2)
isGanda x lst =
   if isOneElmt lst then if x == head lst then [] else lst
   else if x == head lst then isGanda x (tail lst)
   else konso (head lst) (isGanda x (tail lst))

makeUnique lst =
   if isEmpty lst then []
   else konso (head lst) (makeUnique (isGanda (head lst) lst))

masukkan x li =
    if isEmpty li then [x]
    else if x <= head li then [x] ++ li
    else konso (head li) (masukkan x (tail li))

listSort li =
    if isEmpty li then []
    else masukkan (head li) (listSort (tail li))

--DEFINISI DAN SPESIFIKASI
setUnion :: [Int] -> [Int] -> [Int]
{-
fungsi setUnion menerima masukan dua buah list of integer (l1 dan l2) dengan elemen unik dan terurut membesar 
dan mengembalikan sebuah list of integer yang elemennya adalah semua elemen yang muncul di l1 dan/atau l2. 
List hasil tetap unik dan terurut membesar.
-}

--REALISASI
setUnion l1 l2 =
   let
      satu = satukanList l1 l2
      unik = makeUnique satu
      hasil = listSort unik
   in
      hasil

--APLIKASI
{-
setUnion [2,4,6,8,10] [3,4,5,6]
[2,3,4,5,6,8,10]
setUnion [] [2,3,4,5]
[2,3,4,5]
setUnion [4,6,8,13,26] []
[4,6,8,13,26]
-}