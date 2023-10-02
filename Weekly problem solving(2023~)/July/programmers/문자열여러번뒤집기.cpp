#include <iostream>
#include <string>
#include <vector>

using namespace std;

string magic(string &str, int start, int end)
{
    
    while(start != end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    };
    cout << str << endl;
    return str;
}

string solution(string my_string, vector<vector<int> > q)
{
    string answer = "";

    for (int i = 0; i < q.size(); i++)
    {
        my_string = magic(my_string, q[i][0], q[i][1]);
        cout << my_string << endl;
    };

    answer = my_string;

    return answer;
};

int main(){

    string mst= "rermgorpsam";

    vector<vector<int> > q= {{2,3},{0,7},{5,9},{6,10}};
    string result = "";
    result = solution(mst,q);
    cout << result << endl;
}