#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<string> box;

    while(n--){
        string s;
        getline(cin, s, '\n');
        stringstream ss(s);

        stack<string> st;

        string word;
        while (ss >> word)
        {
            st.push(word);
        };
        string new_str;
        while (!st.empty())
        {
            new_str += st.top();
            new_str += " ";
            st.pop();
        };
        box.emplace_back(new_str);
    }

    for(int i=0;i<box.size();i++){
        cout << "Case #" << i+1 << ": " << box[i] << '\n';
    }
    

}