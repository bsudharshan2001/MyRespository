#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,freq=0,len;
    string ch;
    getline(cin, ch);
    istringstream is(ch);
    is>>n;
    while()
    {
        freq=-1;
        vector<int> a;
        int i=0;
        getline(cin, ch);
        istringstream is(ch);
        int num;
        while(is>>num)
        { 
            a.push_back(num);
        }
        map<int,int> x;
        len=a.size();
        for(i=0;i<a.size();i++)
        {
            x[a[i]]++;
            if(x[a[i]]>(len/2))
            {
                freq=a[i];
            }
        }
        cout<<freq<<endl;
    }
}