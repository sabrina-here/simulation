#include<bits/stdc++.h>
using namespace std;
  
int main()
{
   vector<int> forward = {1,5,3,9};
   auto it = find(forward.begin(),forward.end(),2);
   if(!it) cout<<"not"<<endl;

   return 0;
}