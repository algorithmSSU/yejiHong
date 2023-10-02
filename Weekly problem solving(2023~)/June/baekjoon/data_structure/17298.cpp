#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n = 0;
    vector<int> v;
    vector<int> answer;
    vector<int>::iterator p;

    stack<int> s;
    stack<int> second;


    std::cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        std::cin >> temp;
        s.push(temp);
    };
    
    //s 이 비어있을 때까지
    while(!s.empty()){
        if(second.empty()){
            second.push(s.top());
            answer.emplace_back(-1);
            s.pop();
        }else{ // second stack 이 비어있지 않을때
            if(s.top()<second.top()){
                answer.emplace_back(second.top());
                second.push(s.top());
                s.pop();

            }else if(s.top()>=second.top()){
                bool flag = true;
                for(p=answer.end();p>=answer.begin();p--){
                    if(*p>s.top()){
                        answer.emplace_back(*p);
                        flag = false;
                        break;
                    }
                };
                if(flag){
                    answer.emplace_back(-1);};
                second.push(s.top());
                s.pop();
            };
        };
    };


    //std::cout << answer.size() << endl;
    for(int i=answer.size()-1;i>=0;i--){
        std::cout << answer[i] << " ";
    }
    std:: cout << '\n';


}