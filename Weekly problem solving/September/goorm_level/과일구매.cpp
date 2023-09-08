#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long int n, k;
  cin >> n >> k;

  vector<pair<long long int, long long int>> input;
  for (int i = 0; i < n; i++)
  {
    long long int price, full;
    cin >> price >> full;
    input.emplace_back(full, price); // 포만감,가격
  }

  map<int, long long int, greater<int>> cnt; // key값 기준 내림차순으로정렬
  map<int, long long int, greater<int>>::iterator p;
  // 단위당 포만감 = 포만감 / 가격
  for (int i = 0; i < n; i++)
  {
    int piece_full = input[i].first / input[i].second; // 단위당포만감 = 포만감/가격
    cnt[piece_full] += input[i].second;                // 단위당포만감 : 갯수(가격)
  };
  cout << "=======================" << endl;
  for (p = cnt.begin(); p != cnt.end(); p++)
  {
    cout << p->first << " : " << p->second << endl;
  }

  // 조각내면 개당 가격이 1이니까 갯수로 치환
  // 가격1 == 갯수1

  long long int buy_full = 0;
  for (p = cnt.begin(); p != cnt.end(); p++)
  {
    long long int get = min(p->second, k); // min 써줄때 안에값들 데이터타입이 동일해야함.
    k -= get;
    buy_full += get * p->first;
  }
  cout << buy_full << endl;
}