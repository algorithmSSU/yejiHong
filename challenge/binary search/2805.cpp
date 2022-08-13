#include <iostream>
#include <vector>
#include <algorithm>



/*아직 미해결*/

using namespace std;
vector<long long> trees;

int binarysearch(int low, int high, int target);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;

    cin >> n >> m;

    int mid = 0;

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        trees.push_back(temp);
        mid += temp;
    };

    mid = mid / n; // 평균

    //cout << "mid: "<< mid << endl;

    sort(trees.begin(), trees.end());

    int index = upper_bound(trees.begin(), trees.end(), mid) - trees.begin();

    cout << index << endl;

    /*
    while(1){
        int answer = 0;
        long long ch = 0;
        for (int i = index; i < n;i++){
            long long temp;
            temp = trees[i] - mid;
            ch += temp;
        };
        //cout <<"ch:" << ch << endl;
        if(ch == m)
        {
            break;
        };


        if(ch!=m){
            mid++;
        }
    };

    */
    cout << mid << endl;

    
};





/*
20 15 10 17
10 15 17 20
평균: 15.2
2 5


4 26 40 42 46
평균: 31.6
빼기 31
9 11 15 = 35
빼기 32
8 10 14 = 32
빼기 33
7 9 13 = 29
빼기 34
6 8 12 = 26
빼기 35
5 7 11 = 23
빼기 36
4 6 10 = 20

1 1 5 14
평균: 7


반례(해결하기)
3 1
10 10 10
평균 : 10



*/
