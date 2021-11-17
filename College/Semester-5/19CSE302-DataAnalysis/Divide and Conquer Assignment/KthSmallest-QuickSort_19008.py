def partition(begin, end, array):
	pivot_index = begin
	pivot = array[pivot_index]	
	while(begin < end):
		while(begin < len(array) and array[begin] <= pivot):
			begin += 1		
		while(array[end] > pivot):
			end -= 1		
		if(begin < end):
			array[begin], array[end] = array[end], array[begin]	
	array[end], array[pivot_index] = array[pivot_index], array[end]
	return end

def quick_sort(begin, end, array,k):
	if (begin < end):
		p = partition(begin, end, array)
		if(k>p):
			quick_sort(p + 1, end, array,k)	
		else:		
			quick_sort(begin, p - 1, array,k)

	
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
  quick_sort(0, len(i[0])-1, i[0],i[1])
  no=i[0][i[1]-1]
  pos=temp.index(no)
  print(i[0][i[1]-1],', ',pos)