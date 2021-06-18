module UkuranBaju where

ukuranBaju :: Int -> Int -> Int 

ukuranBaju t b
    | t <= 150 = 1
    | t > 170 && b > 60 && b <= 80 = 3
    | t > 150 && t <= 170 && b <= 80 = 2
    | t > 150 && t <= 170 && b > 80 = 3
    | t > 170 && b <= 60 = 2
    | otherwise = 4 