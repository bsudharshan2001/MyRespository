def calc(a,b,n):
    max_deadline=max(a)
    jobs=[0]*max_deadline

    for i in range(n):
        m=i
        for j in range(i+1,n):
            if b[m]>b[j]:
                m=j
        a[i],a[m]=a[m],a[i]
        b[i],b[m]=b[m],b[i]
    a=a[::-1]
    b=b[::-1]
    for i in range(0,n):
        if jobs[a[i]-1]==0:
            jobs[a[i] - 1]=b[i]
        else:
            filled=0
            for j in range(a[i]-1,-1,-1):
                if jobs[j]==0 and filled==0:
                    jobs[j]=b[i]
                    filled=1
    return sum(jobs)



def main():
    n=int(input())
    A=list(map(int,input().strip(' ').strip('[').strip(']').split(',')))
    B=list(map(int,input().strip(' ').strip('[').strip(']').split(',')))
    print(calc(A,B,n))
if name=='main':
    main(