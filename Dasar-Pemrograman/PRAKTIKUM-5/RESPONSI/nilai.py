nilai = int(input())


if nilai == -9999:
    print("Data nilai kosong")
else:
    mhs = 0
    lulus = 0
    notlulus = 0
    sumN = 0
    while nilai != -9999:
        if nilai >= 0 and nilai <= 100:
            mhs += 1
            sumN += nilai
            if nilai >= 40:
                lulus += 1
            else:
                notlulus += 1
        nilai = int(input())
    if mhs == 0:
        print(0)
    else:
        print(mhs)
        print(lulus)
        print(notlulus)
        rata = sumN / mhs
        print ("%.2f" % rata)  
                