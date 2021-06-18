konso :: Int -> [Int] -> [Int]
--konso :: Char -> [Char] -> [Char]
konso e l = [e] ++ l

konsDot :: [Int] -> Int -> [Int]
konsDot l e = l ++ [e]
--konsDot :: [Char] -> Char -> [Char]
--konsDot l e = l ++ [e]

isEmpty :: [Int] -> Bool
--isEmpty :: [Char] -> Bool
isEmpty l = null l

isOneElmt :: [Int] -> Bool
--isOneElmt :: [Char] -> Bool
isOneElmt l = (length l) == 1

pisahDua :: [Int] -> Int -> ([Int],[Int])
{-
Fungsi pisahDua menerima masukan sebuah list of
integer, misalnya L, dan sebuah integer n, dan
digunakan untuk membentuk pasangan nilai berupa
dua buah list baru L1 dan L2.
L1 terdiri atas elemen-elemen list awal (dengan urutan
yang sama) yang nilainya lebih kecil atau sama dengan n
L2 berisi elemen list awal yang nilainya lebih besar dari n.
List kosong akan menghasilkan dua buah list kosong.
-}

pisahDua l n =
    let
        (x,y) = pisahDua (tail l) n
    in
        if isEmpty l then ([],[])
        else if (head l) <= n then (konso (head l) x,y)
        else (x,konso (head l) y)

