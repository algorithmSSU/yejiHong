#include <iostream>
#include <vector>

using namespace std;

vector<int> answer(2);

// 현재 공간이 0또는 1로 채워져 있는 지 확인 하기 위한 함수
bool is_sector(const vector<vector<int>> &input_data, int y, int x, int size)
{
    int sum = 0;
    for (size_t i = y; i < y + size; i++)
    {
        for (size_t j = x; j < x + size; j++)
        {
            sum += input_data[i][j];
        }
    }

    if (sum == 0 || sum == size * size)
        return true;
    else
        return false;
};

// 나누어진 공간에서 탐색(재귀)
void make_quardTree(const vector<vector<int>> &input_data, int y, int x, int size)
{
    if (is_sector(input_data, y, x, size))
    {
        answer[input_data[y][x]]++;
        return;
    }

    // 나누어진 공간이 0또는 1로 채워지지 않았다면, 다시 섹터를 나누어서 탐색을 해야함
    // 현재 공간을 또 4등분으로 쪼개기
    make_quardTree(input_data, y, x, size / 2);
    make_quardTree(input_data, y, x + size / 2, size / 2);
    make_quardTree(input_data, y + size / 2, x, size / 2);
    make_quardTree(input_data, y + size / 2, x + size / 2, size / 2);
}

vector<int> solution(vector<vector<int>> arr)
{
    make_quardTree(arr, 0, 0, arr.size()); // quardTree 탐색 함수 호출
    return answer;
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}};
    vector<int> ans = solution(arr);
    cout << ans[0] << ' ' << ans[1];
    return 0;
}