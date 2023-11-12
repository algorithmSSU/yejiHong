#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 위위옆
 * 위옆옆
 * 밑옆옆
 * 밑밑옆
*/


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N,M;
  cin >> N >> M;

  // N: 세로
  // M: 가로
  

  //세로 길이가 1일때는 방문 가능 최대 칸 수는 1칸이다.
  if(N==1){
    cout << 1 << endl;
  }else if(N==2){ // 세로 길이가 2일 때는 오른쪽 2칸만 가능
    cout << min(4,(M+1)/2); // 최대 4칸 이동이고 (M==7일때) 아니면 M+1/2개
  }else if(M<=6){ // 모든 방법 이용 불가능, 4번이 넘더라도 4번까지만 이동
    cout << min(4,M); // 최대 4번
  }else{ // 2만큼 2번 움직이고 나머지는 다 1칸씩만 이동
    cout << M-2 << '\n'; // M이 7 이상일 때부터는 모든 방법을 최소1번씩은 사용, 가로 한칸씩만 이동했으니 앞에서 가로로 2칸씩 이동하면서 한개씩 기록해줬던 2만큼을 빼주면 답이 나옴
  }
  return 0;







}