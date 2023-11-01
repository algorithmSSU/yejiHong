#include <iostream>
#include <vector>        //vector 위한 헤더
#include <algorithm>    //min max 위한 헤더
 
using namespace std;
 
enum MAPS { BLANK = 0, CORE = 1, LINE = 2 };
enum DIRS { EAST = 0, SOUTH = 1, WEST = 2, NORTH = 3, OFF = 4 };
 
int N;
int map[12][12];    //맵
int tmp[12][12];    //임시맵
int Answer;            //정답
int max_power_cnt;    //최대로 연결된 코어 갯수
vector < pair < int, int > > v;    //벡터 x,y좌표저장
int dx[] = { 0,1,0,-1 };        //상하좌우
int dy[] = { 1,0,-1,0 };
int core_cnt;                    //코어 갯수 체크
 
bool check(int cur_x, int cur_y, int dir)//라인 놓을수 있는지 체크해준다
{
    int new_x = cur_x + dx[dir];
    int new_y = cur_y + dy[dir];
    switch (dir) {
    case EAST:
        for (int i = new_y; i < N; i++)
            if (0 <= new_x&&new_x < N && 0 <= i && i < N && map[new_x][i] != BLANK)
                return false;
        break;
    case SOUTH:
        for (int i = new_x; i < N; i++)
            if (0 <= i && i < N && 0 <= new_y && new_y < N && map[i][new_y] != BLANK)
                return false;
        break;
    case WEST:
        for (int i = new_y; i >= 0; i--)
            if (0 <= new_x && new_x < N && 0 <= i && i < N && map[new_x][i] != BLANK)
                return false;
        break;
    case NORTH:
        for (int i = new_x; i >= 0; i--)
            if (0 <= i && i < N && 0 <= new_y && new_y < N && map[i][new_y] != BLANK)
                return false;
        break;
    }
    //여기까지오면 조건 통과. 따라서 라인 놓을수 있게 됨
    return true;
}
 
void dfs(int index, int power_cnt)
{


    /*🏁 종료조건*/
    
    
    // 1. 현재 연결된 코어수 + (총 코어수 - 현재 인덱스) < 최대 파워수  이면 종료
    
    if (power_cnt + (core_cnt - index) < max_power_cnt)    //현재연결된 코어수 + (총코어수 - 현재인덱스) < 최대 파워수보다 작으면 패스
        return;                                            //총코어수 - 현재인덱스 = 연결가능한 코어 갯수.
    //시간줄여주기 위함. 만약 다 돌려서 전원을 들어오게 해도 현재 최대 연결된 수보다 작으면 걍 안해봄
 

    // 2. 마지막 코어 좌표까지 다 탐색했으면 종료
    if (index == core_cnt) {                //마지막 까지 다 돌았으면 
        if (power_cnt >= max_power_cnt) {    //최대 연결됬던 코어수보다 현재 연결된 코어수가 크거나 같으면
            int tmp_answer = 0;                //임시정답(라인수)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (map[i][j] == LINE)
                        tmp_answer++;        //라인수 세어줌
            if (power_cnt > max_power_cnt)    //연결된 코어수가 최대 코어수보다 크면
                Answer = tmp_answer;        //걍 지금꺼 넣어줌
            else
                Answer = min(tmp_answer, Answer);    //같으면 라인수가 더 작은거 넣어줌
            max_power_cnt = power_cnt;        //최대 연결된 코어수에 지금 코어수를 넣어줌
        }
        return;
    }





    /*🏁 종료 조건에 해당되지 않으면 달려라*/

    int tmp[12][12];                //임시맵 -> 나중에 원복해줄용
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[i][j] = map[i][j];    //현재맵 저장해놓음




    int cur_x = v[index].first;        //현재 index의 코어 좌표저장
    int cur_y = v[index].second;



    for (int dir = 0; dir < 4; dir++) {    //상하좌우방향으로 체크해봄

        if (check(cur_x, cur_y, dir)) {    //라인 놓을수 있으면
            int new_x = cur_x + dx[dir];
            int new_y = cur_y + dy[dir];
            
            while (0 <= new_x && new_x < N && 0 <= new_y && new_y < N) {
                map[new_x][new_y] = LINE;    //라인 놓자
                new_x += dx[dir];
                new_y += dy[dir];
            }

            // 만약 시작 좌표에서 라인을 놓을 수 있다면 연결된 코어수 + 1 을 해주고, 시작 좌표 다음부터 연결 탐색
            dfs(index + 1, power_cnt + 1);    //놓았으니까 다음으로 들어감. 연결된 코어수 +1 해줌



            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    map[i][j] = tmp[i][j];    //나왔으면 다시 맵 원상복구 시켜주자.
        }
    }
    dfs(index + 1, power_cnt);    //이번꺼 연결안하고 패스하고 다음거 체크하러 감.
}
 
int main()
{
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        Answer = 987654321;    //정답 초기화
        max_power_cnt = 0;    //최대 코어 카운트 초기화
        v.clear();            //벡터 초기화
        cin >> N;            //입력받기
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                if (map[i][j] == CORE && !(i == 0 || i == N - 1 || j == 0 || j == N - 1))
                    v.push_back(make_pair(i, j));    //가장자리는 어차피연결. 따라서 안연결된것만 체크. 벡터에 코어 좌표 넣어줌
            }
        core_cnt = v.size();//코어카운트를 벡터의 갯수로 설정
        dfs(0, 0);            //dfs함수 호출
        cout << "#" << test_case << " " << Answer << endl;    //정답출력
    }
 
    return 0;
}