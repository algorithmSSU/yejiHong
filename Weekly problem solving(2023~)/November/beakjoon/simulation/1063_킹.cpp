#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define EC 0
#define DC 1

string K, S;
int N;

pair<int,int> A;
pair<int,int> B;

bool isRight(int y,int x){
    if(y>0 && x>0 && y<=8 && x<=8){
        return true;
    }
    return false;
}

bool isStone(int y,int x){
    if(y==B.first && x==B.second){
        return true;
    }
    return false;
}

pair<char,char> converter(string s,int version){
    
    pair<char,char> answer;

    char char_list[8]={'A','B','C','D','E','F','G','H'};
    int num_list[8]={1,2,3,4,5,6,7,8};


    // 인코딩
    if(version == EC){
        for(int i=0;i<8;i++){
        // first
            if(s[1]-'0'==num_list[i]){
                int num = s[1]-'0';
                //cout << num << endl;
                num = 9-num;
                char temp = num + '0';
                answer.first = temp;
            }
        // second
            if(s[0]==char_list[i]){
                char temp = num_list[i] + '0';
                answer.second = temp;
            }
        
        }
    }

    // 디코딩
    if(version == DC){
        for(int i=0;i<8;i++){
            int row = s[0]-'0';
            int row_ = 9-row;
            answer.second = row_+'0';
            int col = s[1]-'0';
            if(num_list[i] == col){
                answer.first = char_list[i];
            }

        }
    }


    return answer;
}
void move(vector<string> order){
    int dy[8]={0, 0, 1, -1, -1, -1, 1, 1};
    int dx[8]={1, -1, 0, 0, 1, -1, 1, -1};
    string ct[8]={"R","L","B","T","RT","LT","RB","LB"};
    int ty, tx, sy, sx;
    
    ty = A.first;
    tx = A.second;
    sy = B.first;
    sx = B.second;


    for(auto it : order){
        // ty = A.first;
        // tx = A.second;
        // sy = B.first;
        // sx = B.second;
        for(int k=0;k<8;k++){
            int y,x;
            int y_,x_;
            if(ct[k] == it){
                y = ty+dy[k];
                x = tx+dx[k];
                y_= sy+dy[k];
                x_= sx+dx[k];
                if(isRight(y,x) && !isStone(y,x)){ // 킹의 길이있고, 돌이없는경우
                    ty+=dy[k];
                    tx+=dx[k];
                }else if(isRight(y,x) && isStone(y,x) && isRight(y_,x_)){ // 킹의 길이 있고, 돌이있고, 돌의 길도 있는 경우
                    //cout << "ok" << endl;
                    ty+=dy[k];
                    tx+=dx[k];
                    sy+=dy[k];
                    sx+=dx[k];
                }else{
                    continue;// 무시 
                }
            }
        }
        A.first = ty;
        A.second = tx;
        B.first = sy;
        B.second = sx;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> S;
    cin >> N;
    vector<string> control;
    

    pair<char,char> temp = converter(K,EC);
    A.first = temp.first - '0';
    A.second = temp.second - '0';

    pair<char,char> temp_ = converter(S,EC);
    B.first = temp_.first - '0';
    B.second = temp_.second - '0';


    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        control.emplace_back(s);
    }


    move(control);


    char a_first = A.first+'0';
    char a_second = A.second+'0';
   
    char b_first = B.first+'0';
    char b_second = B.second+'0';
    

    string K_pos;
    string S_pos;

    K_pos+=a_first;
    K_pos+=a_second;

    S_pos+=b_first;
    S_pos+=b_second;

    pair<char,char> resA = converter(K_pos,DC);
    pair<char,char> resB = converter(S_pos,DC);

    cout  << resA.first << resA.second << endl;
    cout  << resB.first << resB.second << endl;

}