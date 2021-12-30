n=int(input())
for i in range(0,n):
    len=int(input())
    str=input()
    flag=0
    for i in range(len):
        if(str[i]=='c' and str[i+1]=='o' and str[i+2]=='d' and str[i+3]=='e' and str[i+4]=='c' and str[i+5]=='h' and str[i+6]=='e' and str[i+7]=='f'):
            flag=0
        if(i==len and flag==0):
            flag=1
    if(flag==1):
        print('WA')
    else:
        print('AC')
    