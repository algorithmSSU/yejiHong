#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int* card;
    vector<int> answer;
    cin >> N;
    card = new int[N];

    for(int i=0;i<N;i++){
        cin >> card[i];
    }

    sort(card,card+N);

    cin >> M;
    for(int i=0;i<M;i++){
        int num;
        cin >> num;
        bool ch = binary_search(card,card+N,num);
        if(ch==true){
            answer.emplace_back(1);
        }else{
            answer.emplace_back(0);
        }
    }
    for(auto it : answer){
        cout << it << " ";
    }
    cout <<'\n';
}