import random
import time
import matplotlib.pyplot as plt

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i + 1


def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quicksort(arr, low, pi-1)
        quicksort(arr, pi+1, high)


sizes = [100, 500, 1000, 2000, 5000]
times = []

for n in sizes:
    arr = [random.randint(1,100000) for _ in range(n)]

    start = time.perf_counter()

    quicksort(arr,0,len(arr)-1)

    end = time.perf_counter()

    times.append((end-start)*1000)

print("Input Size\tTime (ms)")
for s,t in zip(sizes,times):
    print(s,"\t\t",round(t,4))

plt.figure(figsize=(8,5))
plt.plot(sizes,times,marker='o',linewidth=2)

plt.title("Quick Sort Performance")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Execution Time (ms)")
plt.grid(True)

plt.savefig("graph.png",dpi=300)

plt.show()