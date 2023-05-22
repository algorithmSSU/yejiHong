#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

vector<int> change(string skip)
{
    vector<int> ans;
    for (int i = 0; i < skip.length(); i++)
    {
        int temp;
        temp = skip[i];
        ans.emplace_back(temp);
    };
    sort(ans.begin(), ans.end());
    return ans;
}


//97~123 까지니 124
int main(){
    std::stringstream ss;

    string input;
    cin >> input;

    vector<int> a;
    a = change(input);

    for(auto i : a){
        cout << i << endl;
    }

    


}