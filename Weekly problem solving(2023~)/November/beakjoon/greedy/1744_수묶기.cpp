#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> positive;
    vector<int> negative;
    int result = 0;
    int zerocnt = 0;


    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num>1){
            positive.emplace_back(num);
        }else if(num == 1){
            result++;
        }else if(num == 0){
            zerocnt++;
        }else{
            negative.emplace_back(num);
        }
    }


    sort(positive.begin(),positive.end(),greater<>());
    sort(negative.begin(),negative.end(),less<>());


    for(int i=0;i<positive.size()-(positive.size()%2); i+=2){
        result+=positive[i]*positive[i+1];
    }
    if(positive.size()%2 == 1){ // 홀수개면 맨 마지막거 안더해줬을거기때문
        result+=positive.back();
    }
    for(int i=0;i<negative.size()-(negative.size()%2);i+=2){
            result+=negative[i]*negative[i+1];
    }
    if(negative.size()%2 == 1){
        if(zerocnt == 0){
            result += negative.back();
        }
    }
    cout << result << endl;

}