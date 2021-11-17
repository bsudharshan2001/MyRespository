def distinctIndex(arr):
    l=len(arr)
    for i in range(0,l):
        if arr[i]==i:
            return i
    return -1

n = int(input())
while n>0 :
    arr = list(map(int, input().split()))
    temp=distinctIndex(arr)
    if temp==-1:
        print("False"+', '+'-1')
    else:
        print("True"+', '+str(temp))
    n -= 1
