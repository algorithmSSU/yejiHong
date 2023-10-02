#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 다시..
void draw_star(){
    std::cout << "*"<<'\n';
};

void draw_line(){
    std::cout<<'\n';
}

int main(){
    int n;
    std::cin >> n;

    int end = n*2-1;
    int temp = end;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            std::cout << " ";
        };
        for(int k=0;k<temp;k++){
            std::cout << "*";
        };
        std::cout << '\n';
        temp-=2;
    };

    temp+=end/2-1;
    int start = temp;
    for(int i=0;i<n-1;i++){
        for(int s = 0;s<n-i-2;s++){
            std::cout << " ";
        };
        for(int c=0;c<2*(i+2)-1;c++){
            std::cout << "*";
        }
        start--;
        temp+=2;
        std::cout << '\n';
    }
    
}