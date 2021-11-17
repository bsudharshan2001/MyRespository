import timeit
setup_code = "from math import factorial"
statement="""
steps=0
def coinChange(amt,lst):
    count=amt
    global steps
    steps+=1
    if(amt==0 or amt<0):
        return
    elif(amt in lst):
        return 1
    else:
        for i in range(0,len(lst)):
            coin=lst[i]
            if(amt>coin):
                denom=coinChange(amt-coin,lst)+1
                count=denom+1
                if(denom<count):
                    count=denom
    return count


amt=int(input())
lst=list(map(int,input().split()))
minimum=coinChange(amt,lst)
print(minimum)
print('steps: ',steps)"""
print('time: ',timeit.timeit(setup=setup_code,stmt=statement,number=10000000))