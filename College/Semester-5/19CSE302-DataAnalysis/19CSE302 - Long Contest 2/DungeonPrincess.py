m=int(input())
n=int(input())
arr=[]
for i in range(m):
    a =[]
    for j in range(n):  
         a.append(int(input()))
    arr.append(a)
i=j=0
sum=arr[0][0]
print(sum)
while(True):
    if(j!=(n-1)):
        if(arr[i][j+1]<arr[i+1][j]):
            sum+=arr[i][j+1]
            j+=1
        else:
            sum+=arr[i+1][j]
            i+=1
    else:
        sum+=arr[i+1][j]
        i+=1
    if(i==(m-1) and j==(n-1)):
        break
print(sum)

    