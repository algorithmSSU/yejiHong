#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(vector<int>& current, int start, int n, int r) {
    if (r == 0) {
        // 현재 조합 출력 또는 처리
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        generateCombinations(current, i + 1, n, r - 1);
        current.pop_back();
    }
}

int main() {
    int n = 4; // 전체 원소의 개수
    int r = 3;  // 선택할 원소의 개수

    vector<int> currentCombination;
    generateCombinations(currentCombination, 1, n, r);

    return 0;
}
