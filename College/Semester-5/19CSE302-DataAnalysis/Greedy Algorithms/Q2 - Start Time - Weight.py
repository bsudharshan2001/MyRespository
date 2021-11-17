#Activity Selection Problem - Greedy (Using Finishing Time)
#Taking Job Weight into account
def activitySelectionTime(s , f , w):
    n = len(f)
    total=0
    print("The following activities are selected")
    i = 0
    print(i),
    for j in range(n):
        if(s[j] >= f[i]):
            total+=w[j]
            print(j)
            i = j
    print('Total Cost of the Job: '+str(total))


s=list(map(int, input().split()))
f=list(map(int, input().split()))
w=list(map(int, input().split()))
activitySelectionTime(s , f)
#0 12 3 10 2 6 16 7 19 20
#1 16 5 12 4 9 19 10 24 22