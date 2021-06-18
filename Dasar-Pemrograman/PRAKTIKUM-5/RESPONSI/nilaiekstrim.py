N = int(input())
lst = []

for i in range(N):
    lst += [int(input())]

X = int(input())
ada = False

maxi = lst[0]
mini = lst[0]
if lst[0] == X:
    ada = True

for i in range(1,N):
    if lst[i] == X:
        ada = True
    if maxi < lst[i]:
        maxi = lst[i]
    if mini > lst[i]:
        mini = lst[i]

if ada:
    printed = False
    if X == maxi:
        print("maksimum")
        printed = True
    if X == mini:
        print("minimum")
        printed = True
    if not printed:
        print("N#A")
else:
    print(X,"tidak ada")
