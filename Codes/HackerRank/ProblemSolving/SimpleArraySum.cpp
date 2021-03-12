#include<iostream>
using namespace std;
int simpleArraySum(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int sum=simpleArraySum(ar,n);
    cout<<sum;
    return 0;
}  
