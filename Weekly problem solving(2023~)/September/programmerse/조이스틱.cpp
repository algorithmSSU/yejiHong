#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int sol(char start, char target)
{
    int mini = 0;
    int am = abs('A'-target);
    int zm = abs('Z'-target);
    
    mini = min(am,zm);
    return mini;
}

int solution(string name)
{
    int answer = 0;
    char start = 'A';
    for (int i = 0; i < name.length(); i++)
    {
        answer += sol(start, name[i]);
        //start = name[i];
    }

    return answer;
}
int main(){
  string str = "JEROEN";
  for(int i='A';i<'Z'+1;i++){
    cout << i << endl;
  }


}