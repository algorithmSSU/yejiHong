#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void ac(string func, int n, vector<int> arr);
int main(){

    /*더 수정 ..*/
    int n;
    vector<int> arr;
    cin >> n;


    for (int i = 0; i < n;i++){
        string f, a;
        int freq;
        cin >> f;
        cin >> freq;
        cin >> a;
        
        for (int i = 0; i < a.length(); i++)
        {
            char temp;
            int tonum;
            temp = a[i];
            if(temp!='['&& temp!=',' && temp!=']'){
                tonum = temp - '0';
                cout <<"tonum: "<< tonum;
                arr.push_back(tonum);
            };
        };
        ac(f,freq,arr);
        
    }
};

void ac(string func, int n, vector<int> arr){
    int dc, rc = 0;
    for (int i = 0; i < func.length();i++){
        char temp;
        temp = func[i];
        if(temp == 'R'){
            rc++;
        };
        if(temp == 'D'){
            dc++;
        };
    };
    if(rc%2==1){
        reverse(arr.begin(), arr.end());
    };
    for (int i = 0; i < dc;i++){
        arr.erase(arr.begin()+0);
    };
    cout << '[';
    for (int i = 0; i < arr.size();i++){
        if(i!=arr.size()-1){
            cout << arr[i] << ",";
        }else{
            cout << arr[i];
        };
    };
    cout << ']';
};
