#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M,K;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    /**
     * 1팀 구성에 필요한 여학생과 남학생의 비율은 2:1
     * K 가 없는 경우  min(여학생수/2, 남학생수)
     * K 가 있는 경우  min(여학생수 + 남학생수 - 인턴쉽에 필요한 인원수)/3
     *              1팀 구성에 필요한 총 인원이 3명 이니까
     *              인턴쉽에 필요한 인원수를 (여학생이든 남학생이든) 전체 인원에서 빼준다.
     *              인턴쉽인원으로 꼭 K명을 보내주어야 하므로 애초에 K명은 없는 가정 하에 팀을 꾸려야함
    */


    cout << min(min(N/2,M),(N+M-K)/3) << '\n';

    
}