#include <bits/stdc++.h>

using namespace std;

int gcd(int s, int l)
{
    //cout <<s <<" "<<l<<endl;
    if (s == l) return s;
    if (s == 0) return l;
    return gcd(l%s, s);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout << gcd(min(a,b),max(a,b))<<endl;
    return 0;
}
