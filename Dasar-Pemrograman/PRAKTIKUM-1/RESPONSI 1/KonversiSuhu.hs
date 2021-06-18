module KonversiSuhu where

konversiSuhu :: Float -> Char -> Float 

konversiSuhu t k
    | k == 'R' = t * 4 / 5
    | k == 'F' = (9/5 * t) + 32
    | k == 'K' = t + 273.15