sumKelipatan a b x
    | a > b = 0
    | mod a x == 0 = a + sumKelipatan (a+1) b x
    | otherwise = sumKelipatan (a+1) b x