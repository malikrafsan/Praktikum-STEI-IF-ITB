berat = int(input())

if berat == -999:
    print("Data kosong")
else:
    mhs = 0
    ringan = 0
    gendud = 0
    sumN = 0
    while berat != -999:
        if berat >= 30 and berat <= 200:
            mhs += 1
            sumN += berat
            if berat <= 50:
                ringan += 1
            elif berat >= 100:
                gendud += 1
        berat = int(input())
    if mhs == 0:
        print("Data kosong")
    else:
        print(mhs)
        print(ringan)
        print(gendud)
        print(round(sumN/mhs))