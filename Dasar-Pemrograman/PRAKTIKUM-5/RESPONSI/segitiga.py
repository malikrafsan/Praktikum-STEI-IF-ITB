alas, tinggi = map(int, input().split())

if alas > 0 and tinggi > 0:
    luas = round(0.5 * alas * tinggi)
    print(luas)
else:
    print("Alas dan tinggi harus > 0")