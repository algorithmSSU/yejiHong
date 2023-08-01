#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int,vector<int>,less<int> > pq;
vector<int> result;
vector<int> seek(int n,int m,vector<int> v,vector<int>w){
    vector<int> ans;
    for(int i=0;i<=v.size();i++){
        for(int j=0;j<=w.size();j++){
            int temp = v[i]*w[j];
            if(temp<m){
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

int solution(int n, int v, vector<int> A, vector<int> B, vector<int> C) {
    int answer = 0;

    vector<int> first;
    vector<int> second;
    first = seek(n,v,B,C);
    if(first.size()==0){
        answer = -1;
        return answer;
    }else{
        second = seek(n, v, first, A);
        if (second.size() == 0)
        {
            answer = -1;
            return answer;
        }
        else
        {
            for (int i = 0; i < second.size(); i++)
            {
                pq.push(second[i]);
            }
        }
    }
    
    
    answer = pq.top();

    return answer;
}


int main(){
    int n =3;
    int v = 101;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    vector<int> b;
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);

    vector<int> c;
    c.push_back(10);
    c.push_back(11);
    c.push_back(12);

    int ret = solution(n,v,a,b,c);
    cout << ret << endl;


}