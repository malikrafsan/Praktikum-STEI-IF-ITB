nilai = int(input())


if nilai == -999:
    print("Data kosong")
else:
    mhs = 0
    tinggi = 0
    pendek = 0
    sumN = 0
    while nilai != -999:
        if nilai >= 100 and nilai <= 300:
            mhs += 1
            sumN += nilai
            if nilai >= 170:
                tinggi += 1
            elif nilai <= 150:
                pendek += 1
        nilai = int(input())
    if mhs == 0:
        print("Data kosong")
    else:
        print(mhs)
        print(pendek)
        print(tinggi)
        print(round(sumN / mhs))  
                