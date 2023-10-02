#include <iostream>
#include <vector>
#include <algorithm>


/*

예제 입력은 제대로 나오는데..
왜... 문의 답변 기다리기


*/


using namespace std;
int solution();
vector<int> j;
int child, color;
int main(){
    cin >> child >> color;

    for (int i = 0; i < color; i++){
        int temp;
        cin >> temp;
        j.push_back(temp);
    }

    sort(j.begin(), j.end());

    cout << solution() << endl;
};
int solution(){
    int min = 1;
    int max = j.back();
    int mid;
    int ans = 300000;
    while (min <= max){
        mid = (min + max) / 2;
        int cnt = 0;
        for (int i = 0; i < color;i++){
            if (j[i] / mid > 0)
            {
                cnt += j[i] / mid;
                if (j[i] % mid != 0)
                {
                    cnt++;
                }
            }
            else
            {
                cnt++;
            };
        };

        

        if (cnt <= child)
        { // 범위 더 늘려줘야

            max = mid - 1;
            ans = ans < mid ? ans : mid;
            //cout << "mid: " << mid;
        }
        else
        {
            //ans = ans < mid ? ans : mid;
            min = mid + 1;
        };
    };
    return ans;
}
/*





max7 min1 mid 4


vector<int> bag;

while(min<max){
int cnt=0;
if(j[i]/mid > 0){
    cnt += j[i]/mid
    if(j[i]%mid!=0){
        cnt++;
    }
}else{
    cnt++;
};

if(cnt<child){ // 범위 더 늘려줘야

    max= mid-1;

}else{
    ans = ans < mid ? ans : mid;
    min = mid+1;
}


};




*/