#simple bubble sort implementation
def bubble_sort(arr):
    def swap(i, j):
        arr[i], arr[j] = arr[j], arr[i]

    n = len(arr)
    
    for i in range(1, n):
        if arr[i - 1] > arr[i]:
            swap(i - 1, i)
              
    return arr

print(bubble_sort([21,13,41,35]))
