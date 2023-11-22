#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;


long long cal(string s){
	long long result = 0;
	int len = s.length();
	vector<long long> numbers;
	stack<char> op;
	
	
	bool flag = false;
	string temp="";
	for(int i=0;i<=len;i++){
		if(i!=len && isdigit(s[i])){
			temp+=s[i];
		}else if(i==len-1){
			int toNum = stoi(temp);
			temp.clear();
			numbers.emplace_back((long long)toNum);
		}else{
			int toNum = stoi(temp);
			temp.clear();
			numbers.emplace_back((long long)toNum);
			
			if(numbers.size()>=2 && (op.top()=='*' || op.top()=='/')){
				long long a,b,ab;
				b = numbers.back();
				numbers.pop_back();
				a = numbers.back();
				numbers.pop_back();
				if(op.top()=='*'){
					ab = a*b;
				}else if(op.top()=='/'){
					ab = a/b;
				}
				//cout << "ab: "<< ab << endl; 
				numbers.emplace_back(ab);
				op.pop();
			}
			op.push(s[i]);
		}
	}

	long long a,b,ab=0;
	if(op.top()=='*' || op.top()=='/'){
		b = numbers.back();
		numbers.pop_back();
		a = numbers.back();
		numbers.pop_back();
		if(op.top()=='*'){
			ab  = a * b;
		}else if(op.top()=='/'){
			ab = a /b;
		}
		op.pop();
		numbers.emplace_back(ab);
	}

	
	stack<char> ops;
	while(!op.empty()){
		ops.push(op.top());
		op.pop();
	}

	if(ops.top()=='-'){
		result= numbers[0]-numbers[1];
		ops.pop();
	}else if(ops.top()=='+'){
		result= numbers[0]+numbers[1];
		ops.pop();
	}
	
	if(numbers.size()>2){
		for(int i=2;i<numbers.size();i++){
			if(ops.top()=='-'){
				result-=numbers[i];
			}else if(ops.top()=='+'){
				result+=numbers[i];
			}
		}
	}
	
	
	return result;
}


int main() {
	string s1,s2;
	cin >> s1 >> s2;
	
	long long num1,num2, answer;
	num1 = cal(s1);
	num2 = cal(s2);

	//cout << num1  << " , "<< num2 << endl;
	
	answer = max(num1,num2);
	cout << answer << endl;
	
}