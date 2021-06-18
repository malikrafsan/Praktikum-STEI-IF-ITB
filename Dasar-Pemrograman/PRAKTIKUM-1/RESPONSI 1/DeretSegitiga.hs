module DeretSegitiga where

deretSegitiga :: Int -> Int 

deretSegitiga n =
    if n == 1 then 1
    else n + deretSegitiga (n-1)