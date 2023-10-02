#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;




bool cmp(pair<string,int>& a,pair<string,int>&b){
    return a.first < b.first;
}

string sort(map<string, int>& map) {
	vector<pair<string, int> > vec;
    string ans="";
	for (auto& it : map) {
		vec.emplace_back(it);
	}

	// 우리가 위에서 정의한 cmp
	sort(vec.begin(), vec.end(), cmp);

    
    string target="";
    int start=0;
    target= vec[0].first;
    start = vec[0].second;
    for (auto& it : vec){
        if(start<it.second){
            target = it.first;
            start= it.second;
        };
    };
    ans = target;
        
   return ans;
}


int main(){
    // 책 이름만 저장해두는
    // 책이름, 숫자

    map<string,int> book;
    vector<string> info;

    int n=0;
    cin >> n;

    for(int i=0;i<n;i++){
        string input;
        cin >> input;

        auto it = find(info.begin(),info.end(),input);
        if(it==info.end()){
            info.emplace_back(input);
            book[input]++;
        }else{
            book[input]++;
        }
    };

    map<string,int>::iterator p;
    map<string,int>::iterator res;
    
    cout << sort(book) << endl;
    



};