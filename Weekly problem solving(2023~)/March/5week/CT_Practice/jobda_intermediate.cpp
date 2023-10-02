#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using std::pair;

using namespace std;

bool visited[100000]={0,};
vector<int> ret;
vector<priority_queue<int> > v;
priority_queue<int> q[1000];


struct info{
    int start;
    int end;
    int time;
};



bool comp_time(info &x,info &y){
    if(x.time==y.time){
        if(x.start<y.start){
            return true;
        }// x,y가 같다면, 시작이 더 큰게 뒤에오도록
    }else if(x.time<y.time){
        return true;
    }else{
        return false;
    }// 시간이 같지 않으면 시간이 큰게 뒤에 오도록
    return true;
}


vector<info> zip;

void fill(vector<int> x, vector<int> y, vector<int> z){
    for(int i=0;i<x.size();i++){
        info information;
        information.start = x[i];
        information.end = y[i];
        information.time = z[i];
        zip.push_back(information);
    };

    sort(zip.begin(),zip.end(),comp_time);
    /*
    for(int i=0;i<zip.size();i++){
        cout << zip[i].start << "," << endl;
    }
    */
};



void seek(int n){
    bool visited[1000]={false,};
    vector<int> path;
    for(int i=0;i<zip.size();i++){
        int s = zip[i].start;
        int e = zip[i].end;
        if(!visited[s]){
            visited[s]=1;
            path.push_back(s);
        }
        if(!visited[e]){
            visited[e]=1;
            path.push_back(e);
        }
    };
    for(int i=0;i<path.size();i++){
        cout << path[i] << " ";
    }

}





vector<int> solution(int n, int m, vector<int> x, vector<int> y, vector<int> z)
{
    vector<int> answer;
    fill(x,y,z);

    //answer = seek(n);
    seek(n);

    return answer;
};

int main(){

    int n = 3;
    int m = 3;
    vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    vector<int> y;
    y.push_back(3);
    y.push_back(2);
    y.push_back(3);
    vector<int> z;
    z.push_back(1);
    z.push_back(5);
    z.push_back(2);
    vector<int> ans;
    ans = solution(n,m,x,y,z);
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    };
    cout << endl;
}