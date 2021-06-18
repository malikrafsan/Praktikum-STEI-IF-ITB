beasiswa gaji ip
    | ip >= 3.5 = 4
    | gaji < 1 = 1
    | gaji < 5 = if ip >= 2 then 3 else 2
    | otherwise = 0