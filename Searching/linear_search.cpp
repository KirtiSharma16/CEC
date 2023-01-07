#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int key;
    cin>>key;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
        cout<<"Key found at index "<<i;
        flag=true;
        }
    }
    if(flag==false)
    cout<<"Key not found";
    return 0;
}
