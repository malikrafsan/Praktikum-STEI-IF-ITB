def insertionSort(arr):
    for Pass in range(1, len(arr)):
        Temp = arr[Pass]
        i = Pass-1
        while i >=0 and Temp[0] < arr[i][0]:
            arr[i+1] = arr[i]
            i -= 1
        arr[i+1] = Temp

def insertion_sort(array):
    for i in range(1, len(array)):
        currValue = array[i]
        currentPosition = i
        while currentPosition > 0 and array[currentPosition - 1] > currValue:
            array[currentPosition] = array[currentPosition -1]
            currentPosition = currentPosition - 1
        array[currentPosition] = currValue

def insertionSort2(arr):
    for Pass in range(1, len(arr)):
        Temp = arr[Pass][0]
        T1 = arr[Pass][1]
        T2 = arr[Pass][2]
        i = Pass-1
        while i >=0 and Temp < arr[i][0] :
            arr[i+1][0] = arr[i][0]
            i -= 1
        arr[i+1] = (Temp,T1,T2)
            
arr = [(1,2,3), (3,2,1),(100,100,100),(0,0,0), (2,3,1)]
arr2 = [2,41,1,5,78,4,8,10]
insertion_sort(arr)
#arr.sort(key=lambda tup: tup[0])
print(arr)