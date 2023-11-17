#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 17
#define V 1000001
int N, M, NN;
int fr[MAX];
vector<pair<int,pair<int,int>>> m;
int visited[MAX];
int arr[MAX];
vector<int> Result;

void bt(int cnt){
	if(cnt==N){
		int sum = 0;
		for(int j=0;j<cnt;j++){
			sum+=arr[j];
		}

		for(int k=0;k<m.size();k++){
			int Cnt = 0;
			for(int l=0;l<cnt;l++){
				if(m[k].second.second == arr[l] || m[k].second.first == arr[l]){
					Cnt++;
				}
			}
      if(Cnt==2){
			  sum+=m[k].first;
			}
		}
		
		Result.emplace_back(sum);
		return;
	}
	for(int i=0;i<NN;i++){
		if(!visited[i]){
      visited[i] = true;
      arr[cnt]=fr[i];
      bt(cnt+1);
      visited[i] = false;
    }
	}
	
}



int main() {
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> fr[i];
	}
	
	for(int i=0;i<M;i++){
		int a, b, score;
		cin >> a >> b >> score;
		
		
		m.emplace_back(score,make_pair(fr[a-1],fr[b-1]));
		
	}
	
	NN = N;
	for(int i=NN;i>=0;--i){
		bt(0);
    N=i;
	}
	sort(Result.begin(),Result.end(),greater<>());

	cout << Result.front() << endl;
	
}