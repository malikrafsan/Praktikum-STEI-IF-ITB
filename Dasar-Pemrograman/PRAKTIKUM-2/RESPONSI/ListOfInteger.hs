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

-- ===================================================================================

{-
Buatlah fungsi isMember yang menerima masukan sebuah list of integer, misalnya l, 
dan sebuah integer, misalnya x, dan menghasilkan true jika x adalah salah satu member (anggota) 
dalam list l. Menghasilkan false jika tidak, atau jika list l kosong.

Aplikasi

Hasil

isMember [] 5

False

isMember [1,2] 5

False

isMember [1,2,3] 1

True
-}

isMember :: [Int] -> Int -> Bool
isMember lst x =
    if isEmpty lst then False
    else if x == head lst then True
    else isMember (tail lst) x

hapusTakUnik :: Int -> [Int] -> [Int]
hapusTakUnik x lst =
    if isOneElmt lst then if x == head lst then [] else lst
    else if x == head lst then hapusTakUnik x (tail lst)
    else konso (head lst) (hapusTakUnik x (tail lst))

makeUnique :: [Int] -> [Int]
makeUnique lc =
    if isEmpty lc then []
    else konso (head lc) (makeUnique (hapusTakUnik (head lc) lc))

merge :: [Int] -> [Int] -> [Int]
merge l1 l2 =
    if isEmpty l1 then l2
    else konso (head l1) (merge (tail l1) l2)

masukkan :: Int -> [Int] -> [Int]
masukkan x lst =
    if isEmpty lst then [x]
    else if x <= head lst then konso x lst
    else konso (head lst) (masukkan x (tail lst))
sorting :: [Int] -> [Int]
sorting lst =
    if isEmpty lst then []
    else masukkan (head lst) (sorting (tail lst))

setUnion l1 l2 =
    let
        gabungan = merge l1 l2
        urut = sorting (gabungan)
    in
        makeUnique (urut)



