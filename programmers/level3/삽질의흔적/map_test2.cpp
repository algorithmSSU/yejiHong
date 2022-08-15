#include <iostream>
#include <queue>
#include <map>

using std::pair;

using namespace std;

struct compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main()
{

    map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, compare>> m;

    m["apple"].push(make_pair(100, 9));
    m["apple"].push(make_pair(500, 7));
    m["apple"].push(make_pair(500, 8));
    m["apple"].push(make_pair(500, 2));

    while (m["apple"].size() != 0)
    {
        int temp;

        temp = m["apple"].top().second;
        cout << temp << endl;
        m["apple"].pop();
    };
};

/*
priority는 디폴트가 first 기준으로 정렬이니께
first값이 같으면 second값이 작은 거 부터 정렬되게끔
second를 기준으로 다시 정렬

*/