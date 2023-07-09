#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> make_list(string str)
{
    vector<string> op;
    int len = str.length();
    

    // 갯수별로 조합을 구하려면 이게 포인트
    // #include <algorithm>
    // next_epermutation(벡터시작,벡터끝)❗️
    for(int i=1;i<=len;i++){
        vector<bool> position(len-i,false);
        position.insert(position.end(),i,true);

        do{
            string temp = "";
            for(int j=0;j<len;j++){
                if(position[j]){
                    temp+=str[j];
                };
            };
            op.emplace_back(temp);

        }while(next_permutation(position.begin(),position.end()));
    }

    return op;
}

int sum(string str){
    int answer = 0;
    for(int i=0;i<str.length();i++){
        answer+=str[i]-'0';
    };
    return answer;
}


int main(){
    int n;
    vector<int> ans;
    cin >> n;
    for(int i=0;i<n;i++){
        int bulb,button,connet;
        cin >> bulb >> button >> connet;
        string line;// 전구
        vector<int> bbox[17]; // 버튼통
        vector<string> caselist(connet); // 버튼경우의조합
        //getline(cin,line,'\n');
        for(int ch = 0;ch<bulb;ch++){
            char tmp;
            cin >> tmp;
            line+=tmp;
        }
        //cout << line << endl;
        // 공백 지우기
        line.erase(remove(line.begin(),line.end(),' '),line.end());


        string button_count="";
        // 연결된 버튼끼리 넣기
        for(int b=0;b<button;b++){
            button_count+=b+'0';
            for(int c=0;c<connet;c++){
                int bt;
                cin >> bt;
                bbox[b].emplace_back(--bt);
                //cout << bbox[b][c] << endl;
            }
        };
        //sort(button_count.begin(), button_count.end());
        vector<string> case_v;
        case_v = make_list(button_count);

        int min_count = bulb + 1;
        for(int j=0;j<case_v.size();j++){
            bool check = true;
            string copy_line = line;
            for(int h=0;h<case_v[j].length();h++){
                int idx = case_v[j][h] - '0';
                if (!check)
                {
                    break;
                }
                for(int b= 0;b<bbox[idx].size();b++){
                    copy_line[bbox[idx][b]] = copy_line[bbox[idx][b]] == '0' ? '1' : '0';
                };
                if (sum(copy_line) == bulb)
                {
                    min_count = min_count < h+1 ? min_count : h+1;
                    check = false;
                }
            };
        };
        if(min_count == bulb+1){
            ans.emplace_back(-1);
        }else{
            ans.emplace_back(min_count);
        }
    };

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }

}