konso :: Int -> [Int] -> [Int]
konso e l = [e] ++ l
--konso :: Char -> [Char] -> [Char]
--konso e l = [e] ++ l

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

masukan x li =
    if isEmpty li then [x]
    else if x <= head li then konso x li
    else konso (head li) (masukan x (tail li))
sorting li =
    if isEmpty li then []
    else masukan (head li) (sorting (tail li))
