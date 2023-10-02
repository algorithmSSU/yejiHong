#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,string> a, pair<int, string> b)
{
    return a.first < b.first;
};

int main(){

    int n;
    vector<pair<int ,string> > v;
    std::cin >> n;

    for(int i=0;i<n;i++){
        int age;
        string name;
        std::cin >> age >> name;
        v.emplace_back(age,name);
    };

    // 💡₩원래 순서를 손상시키지 않으면서 정렬하는 것을 stable sort 
    stable_sort(v.begin(),v.end(),compare);

    for(int i=0;i<v.size();i++){
        std::cout << v[i].first << " " << v[i].second << '\n';
    }
}