def mergeSort(arr):
    if(len(arr) > 1):
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]
        mergeSort(L)
        mergeSort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
        
n=int(input())
i=0
temp=[]
while(i<n):
  t=[]
  array = list(map(int, input().split())) 
  k=int(input())
  t.append(array)
  t.append(k) #[2,3,4,5,k]
  temp.append(t) #[[2,3,4,5,k][6,7,8,9,k]]
  i=i+1
	
for i in temp:
  anotherTemp=i[0]
  temp=anotherTemp.copy()
  mergeSort(i[0])
  no=i[0][i[1]-1]
  pos=temp.index(no)
  print(i[0][i[1]-1],', ',pos)