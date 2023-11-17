#include <iostream>
#include <vector>
using namespace std;


// 스터디원 코드 레퍼런스

int main() {
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++)
      cin>>arr[i];
   vector<int> ans(14,0);
   int cnt = 0;
   bool check = false;
   vector<int> a;
   for(int i=0;i<n;i++)
   {
      if(a.empty())
         a.push_back(arr[i]);
      else if(a.back() == arr[i] + 1 || a.back() == arr[i] -1)
         a.push_back(arr[i]);
      else if(a.size() >= 2)
      {
         cnt++;
         while(!a.empty())
         {
            ans[a.back()]++;
            a.pop_back();
         }
         a.push_back(arr[i]);
      }
      else
      {
         while(!a.empty())
            a.pop_back();
         a.push_back(arr[i]);
      }
   }
   if(a.size()>=2)
   {
      cnt++;
      while(!a.empty())
      {
         ans[a.back()]++;
         a.pop_back();
      }
   }
   cout<<cnt<<'\n';
   for(int i=1;i<=13;i++)
      cout<<ans[i]<<' ';
}