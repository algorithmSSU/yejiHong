#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<int> result;

    for (int i = 0; i <= 12; ++i) {
        result.push_back(pow(2, i));
    }

    cout << result.size() << endl;

    // for (int i : result) {
    //     std::cout << i << " ";
    // }

    return 0;
}
