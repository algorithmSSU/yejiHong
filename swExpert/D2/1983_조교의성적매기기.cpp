#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


string SCORE[10] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"}; 

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  

  
  int test_case;
  int T;
  cin >> T;

  

  for(test_case =1; test_case <=T; ++test_case){
    int n, target;
    cin >> n >> target;

    double sum[100];

    for(int i=0;i<n;i++){
      double total = 0;
      int mid, end, assign;
      cin  >> mid >> end >> assign;

      total = mid*0.35 + end*0.45 + assign*0.2;
      sum[i]=total;
    }

    int res = 0;
    for(int i=0;i<n;i++){
      if(sum[i] > sum[target-1]){
        res++;
      }
    }

    cout << "#" << test_case << " " << SCORE[res/(n/10)] << endl;
    
  }
  return 0;

}