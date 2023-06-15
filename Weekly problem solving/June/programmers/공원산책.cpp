#include <string>
#include <vector>
#include <algorithm>
using std::pair;
using namespace std;
char map[51][51];
pair<int, int> start;

void make_map(vector<string> park)
{
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].length(); j++)
        {
            if (park[i][j] == 'S')
            {
                start.first = i;
                start.second = j;
            }
            map[i][j] = park[i][j];
        }
    }
}

vector<pair<int, int>> mov;

void make_routes(vector<string> routes)
{
    // 공백 제거
    for (int i = 0; i < routes.size(); i++)
    {
        remove(routes[i].begin(), routes[i].end(), ' ');
    };

    for (int i = 0; i < routes.size(); i++)
    {
        if (routes[i][0] == 'E')
        { // 동쪽
            int dist = routes[i][1] - '0';
            mov.emplace_back(make_pair(0, dist));
        }
        else if (routes[i][0] == 'S')
        { // 남쪽
            int dist = routes[i][1] - '0';
            mov.emplace_back(make_pair(dist, 0));
        }
        else if (routes[i][0] == 'W')
        { // 서쪽
            int dist = routes[i][1] - '0';
            mov.emplace_back(make_pair(0, -dist));
        }
        else if (routes[i][0] == 'N')
        { // 북쪽
            int dist = (int)routes[i][1] - '0';
            mov.emplace_back(make_pair(-dist, 0));
        }
    }
}
vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    make_map(park);
    int r, c;

    r = park.size();
    c = park[0].length();

    make_routes(routes);

    int row, col = 0;
    for (int i = 0; i < mov.size(); i++)
    {
        row = start.first + mov[i].first;   // 이동해야할 y
        col = start.second + mov[i].second; // 이동해야할 x

        // 가려는 위치가 범위 안에 드는지 확인
        if (row >= r || row < 0 || col >= c || col < 0)
        {
            row = start.first;
            col = start.second;
        }
        int init_first = start.first;
        int init_second = start.second;

        if (start.first != row)
        {
            int step = start.first < row ? start.first : row; // 시작 좌표
            int end = start.first < row ? row : start.first;  // 끝 좌표
            for (step; step <= end; step++)
            {
                if (map[step][start.second] == 'X')
                {
                    start.first = init_first;
                    break;
                }
                else
                {
                    start.first = row;
                }
            }
        };
        if (start.second != col)
        {
            int step = start.second < col ? start.second : col;
            int end = start.second < col ? col : start.second;
            for (step; step <= end; step++)
            {
                if (map[start.first][step] == 'X')
                {
                    start.second = init_second;
                    break;
                }
                else
                {
                    start.second = col;
                }
            }
        }
    };

    answer.emplace_back(start.first);
    answer.emplace_back(start.second);

    return answer;
}