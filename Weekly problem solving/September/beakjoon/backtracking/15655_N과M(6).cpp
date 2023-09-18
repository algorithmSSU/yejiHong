#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[11] = {
    false,
};
int arr[10];
int Arr[10];
int n, m;

void BT(int idx, int cnt)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << Arr[i] << " ";
    }
    cout << '\n';
    return;
  }
  else
  {
    for (int i = idx; i < n; i++)
    {
      if (!visited[i])
      {
        visited[i] = true;
        Arr[cnt] = arr[i];
        BT(i + 1, cnt + 1);
        visited[i] = false;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  BT(0, 0);
}