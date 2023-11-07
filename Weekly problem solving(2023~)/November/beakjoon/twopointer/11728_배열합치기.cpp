#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void solution(vector<int> &a, vector<int> &b){

  // 정렬을 한번 한 상태로
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  int ptra = 0;
  int ptrb = 0;

  vector<int> answer(N+M);
  int idx= 0;
  while(ptra < N && ptrb < M){
    if(a[ptra] < b[ptrb]){
      answer[idx++] = a[ptra++];
    }
    else if(a[ptra] >= b[ptrb]){
      answer[idx++] = b[ptrb++];
    }
  }

  // 포인터 끝까지
  while(ptra < N){
    answer[idx++] = a[ptra++];
  }


  // 포인터 끝까지
  while(ptrb < M){
    answer[idx++] = b[ptrb++];
  }
  
  for(auto it : answer){
    cout << it << " ";
  }
}





int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  vector<int> a(N);
  vector<int> b(M);

  for(int i=0;i<N;i++){
    cin >> a[i];
  }

  for(int j=0;j<M;j++){
    cin >> b[j];
  }

  solution(a,b);

  return 0;

}