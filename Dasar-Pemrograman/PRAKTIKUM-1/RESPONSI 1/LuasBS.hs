module LuasBS where

luasBS :: Int -> Int 

luasBS s =
    if s == 1 then 1
    else 2*s - 1 + luasBS (s-1)
