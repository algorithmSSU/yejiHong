#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){

    set<int> s;
    vector<int>a={1,3,2,3,2,3,1,2};

    
    // set 은 완전이진트리(red-black tree) 구조로 이루어져 있음
    // 따라서 어떤 숫자를 삽입하면 오름차순으로 바로 정렬이 되어져서 저장



    for(int i=0;i<a.size();i++){
        s.insert(a[i]);
    };

    cout << s.size() << endl;

    // set 은 순서가 없기 때문에, index로 접근 불가능
    // iterator 사용해야함!
    // iterator 사용 시 맨 끝이 아닌 경우까지 포인터를 이동시키면서 접근/출력
    for(auto it=s.begin();it!=s.end();it++){
        cout << *it<< " ";

    }
    return 0;


}