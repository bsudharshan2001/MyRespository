#include<bits/stdc++.h>
typedef long long int a;
using namespace std;
map<a,vector<vector<a> > >maps;
int calculate(a id,a count,vector<vector<a> >&v,vector<vector<a> >&arr)
{
    if(id<=0){
     maps[count]=arr;
      return 0;
    }
    for(auto&i:v)
        if(i[1]==id){
            arr.push_back(i);
            if(i[0]!=i[1])calculate(i[0],count+1,v,arr);
             arr.pop_back();
        }
  	return 0;
}
int main()
{
    a p;a e1,e2,n,m;
  	cin>>p;
   while(p--){
    vector<vector<a> >v;
    cin>>n>>m;
    a mx=INT_MIN;
    while(m--){
        cin>>e1>>e2;
        mx=max(mx,e2);
        vector<a>arr={e1,e2};
        v.push_back(arr);
    }
    maps.clear();
    for(int j=n;j<=mx;j++){
       vector<vector<a> >arr; 
       calculate(j,0,v,arr);
    }
    if(!maps.size())
        cout<<"0\n";
    else{
       auto i=maps.begin();
       cout<<i->first<<"\n";
       vector<vector<a> >b;
       for(auto&x:i->second)
           b.push_back(x);
       reverse(b.begin(),b.end());
       for(int i=0;i<b.size();i++)
           cout<<b[i][0]<<" "<<b[i][1]<<"\n";
     }
   }
}
