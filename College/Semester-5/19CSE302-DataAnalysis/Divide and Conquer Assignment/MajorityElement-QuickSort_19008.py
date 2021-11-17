def divide(begin, end, array):  
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
      
def quick_sort(begin, end, array):
    if (begin < end):         
        p = divide(begin, end, array)
        quick_sort(begin, p - 1, array)
        quick_sort(p + 1, end, array)
          

n=int(input())
while(n>0):
    array= list(map(int, input().split()))
    n=len(array)    
    quick_sort(0, len(array) - 1, array)
    temp=array[0]
    f=0
    freq=1
    max=-1 
    for i in range(1, n) :
        if(temp==array[i]) : freq+=1
        else:
            freq=1
            temp=array[i]
        if(max<freq) :
            max = freq
            x=array[i] 
        if(max>(n/2)) :
            f=1
            break
    if(f==1):
        print(x)
    else:
        print(-1)    
    n=n-1