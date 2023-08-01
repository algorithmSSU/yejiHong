#include <iostream>
#include <vector>
#include <string>

using namespace std;



void dial(string number);
char char_alpha['Z' - 'A' + 1];
const int LENGTH = 26;
int main(){

    for (int i = 0; i < LENGTH; i++)
    {
        char_alpha[i] = 'A' + i;
    };
    

    string text;
    cin >> text;

    dial(text);
};


void dial(string number){
    int size = number.length();
    vector<char> arr[11];
    int num = 0;
    int sum = 0;

    for (int i = 2; i < 11;i++){
        
        if (i == 7 || i == 9)
        {
            for (int j = 0; j < 4;j++){
            arr[i].push_back(char_alpha[num+j]);}
            num = num + 4;

        }
        else
        {   
            for (int j = 0; j < 3;j++){
            arr[i].push_back(char_alpha[num+j]);
        }
            num = num + 3;
        }
    };

    
    /*
    for (int i = 0; i < 10;i++){
        cout << "<" << i << ">" << endl;
        for (int j = 0; j < arr[i].size();j++){
            cout << arr[i][j];
        };
        cout << "\n";
    };
    */

    for (int i = 0; i < size;i++){
        for (int j = 0; j < 11;j++){
            for (int k = 0; k < arr[j].size();k++){
                if(number[i]==arr[j][k]){
                    sum += j + 1;
                }
            }
        }
    }
    cout << sum;
}