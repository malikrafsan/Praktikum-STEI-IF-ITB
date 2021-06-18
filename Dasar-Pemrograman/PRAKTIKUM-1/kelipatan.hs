module Kelipatan where

isKelipatan c x = 
    if mod c x == 0 then True 
    else False

kelipatan m n x
    | m == n = if isKelipatan n x then 1 else 0
    | isKelipatan m x = 1 + kelipatan (m+1) n x
    | otherwise = kelipatan (m+1) n x