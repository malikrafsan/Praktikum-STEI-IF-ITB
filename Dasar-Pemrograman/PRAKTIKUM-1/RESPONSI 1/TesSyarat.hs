module TesSyarat where

tesSyarat :: Float -> Float -> Int 

tesSyarat ip pot
    | ip >= 3.5 = 4
    | ip < 3.5 && pot < 1 = 1
    | pot >= 1 && pot < 5 && ip < 3.5 =
        if ip >= 2 then 3
        else 2
    | otherwise = 0