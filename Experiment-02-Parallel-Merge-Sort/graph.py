import random
import time
import matplotlib.pyplot as plt

def merge(arr):
    if len(arr)>1:

        mid=len(arr)//2

        L=arr[:mid]
        R=arr[mid:]

        merge(L)
        merge(R)

        i=j=k=0

        while i<len(L) and j<len(R):
            if L[i]<R[j]:
                arr[k]=L[i]
                i+=1
            else:
                arr[k]=R[j]
                j+=1
            k+=1

        while i<len(L):
            arr[k]=L[i]
            i+=1
            k+=1

        while j<len(R):
            arr[k]=R[j]
            j+=1
            k+=1

sizes=[100,500,1000,2000,5000]
times=[]

for n in sizes:

    arr=[random.randint(1,100000) for _ in range(n)]

    start=time.perf_counter()

    merge(arr)

    end=time.perf_counter()

    times.append((end-start)*1000)

print("Size\tTime(ms)")

for s,t in zip(sizes,times):
    print(s,"\t",round(t,4))

plt.plot(sizes,times,marker='o')

plt.title("Parallel Merge Sort Performance")
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ms)")
plt.grid(True)

plt.savefig("graph.png",dpi=300)

plt.show()