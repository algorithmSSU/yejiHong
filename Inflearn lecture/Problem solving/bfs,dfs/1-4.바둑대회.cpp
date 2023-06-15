// 조합문제 ..
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    vector< pair<int,int>> v;
    cin >> n;

    

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }





}

/*
6
87 84 
66 78
94 94
93 87
72 92
78 63


두 수의 차와 인덱스를 함께 저장..하면 되지 않을까?
+3 : 0
-12 : 1
+0 : 2
+6 : 3
-20 : 4
+15 : 5

(66) 78 -12
(72) 92 -20
(94) 94 +0

87 (84) -3
93 (87) -5
78 (63) -15



*/