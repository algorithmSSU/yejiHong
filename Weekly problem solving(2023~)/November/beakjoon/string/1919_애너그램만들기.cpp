#include <iostream>
#include <string>


using namespace std;

int main(){
    string s1;
    string s2;

    cin >> s1 >> s2;

    int alphbet1[26]={};
    int alphbet2[26]={};

    for(int i=0;i<s1.length();i++){
        alphbet1[s1[i]-'a']++;
    }

    for(int i=0;i<s2.length();i++){
        alphbet2[s2[i]-'a']++;
    }
    
    int ans = 0;

    for(int i=0;i<26;i++){
        if(alphbet1[i]!=alphbet2[i]){
            ans+= abs(alphbet1[i]-alphbet2[i]);
        }
    }
    cout << ans << endl;
    return 0;


}