#include <iostream>
#include <deque>

using namespace std;

#define MAX_DEQUE_SIZE 100001

int N;
vector<int> answer;

class Deque {
private:
    int front;  // 첫번째 요소 앞의 index
    int rear;   // 마지막 요소 index
    int data[MAX_DEQUE_SIZE];

public:
    Deque(){ // 생성자
        front = 0;
        rear = 0;
    }
    ~Deque(){} // 소멸자

    void addFront(int n){
        if(isFull()){
            cout << "Deque Full Error" << endl;
            exit(1);
        }
        data[front] = n;
        front = (front-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;    // front가 0 이하로 떨어지는 경우 max index로 순회
    }

    void addRear(int n){    // push
        if(isFull()){
            cout << "Deque Full Error" << endl;
            exit(1);
        }
        rear = (rear+1)%MAX_DEQUE_SIZE;   // rear가 max를 넘어가는 경우 다시 0번째 index로 순회
        data[rear] = n;
    }

    int deleteFront(){  // pop
        if(isEmpty()){
            //cout << "Deque Empty Error" << endl;
            //exit(1);
            return -1;
        }
        front = (front+1)%MAX_DEQUE_SIZE;   // front가 max를 넘어가는 경우 다시 0번째 index로 순회
        return data[front];
    }

    int deleteRear(){
        if(isEmpty()){
            //cout << "Deque Empty Error" << endl;
            //exit(1);
            return -1;
        }
        int tmp = data[rear];
        rear = (rear-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;   // rear가 0 이하로 떨어지는 경우 max index로 순회
        return tmp;
    }

    int getFront(){
        if(isEmpty()){
            //cout << "Deque Empty Error" << endl;
            return -1;
        }
        return data[(front+1)%MAX_DEQUE_SIZE];
    }

    int getRear(){
        if(isEmpty()){
            //cout << "Deque Empty Error" << endl;
            return -1;
        }
        return data[rear];
    }

    int size(){
        return front<=rear ? rear-front : (rear+MAX_DEQUE_SIZE)-front;
    }

    void display(){
        for(int i=front+1; i<=front+size(); i++){
            cout << "[" << data[i%MAX_DEQUE_SIZE] << "]";
        }
        cout << endl;
    }

    // circular array의 front와 rear 정보를 보기위한 메소드
    void displayDetail(){
        cout << "DEQUE :";
        for(int i=front+1; i<=front+size(); i++){
            cout << "[" << data[i%MAX_DEQUE_SIZE] << "]";
        }
        cout << endl;
        cout << "index :";
        for(int i=front+1; i<=front+size(); i++){
            cout << " " << i%MAX_DEQUE_SIZE << " ";
        }
        cout << endl;
        cout << "front : " << front << ", rear : " << rear << endl;
        cout << endl;
    }

    bool isEmpty(){
        return front == rear;
    }
    bool isFull() {
        return front == (rear+1)%MAX_DEQUE_SIZE;
    }
};


void input(){
  Deque dq;
  
  for(int i=0;i<N;i++){
    string str;
    int num;
    cin >> str;
    if(str=="push_back" || str=="push_front"){
      cin >> num;
    }

    if(str=="push_back"){
      dq.addRear(num);
    }
    if(str=="push_front"){
      dq.addFront(num);
    }

    if(str=="front"){
      answer.push_back(dq.getFront());
    }

    if(str=="back"){
      answer.push_back(dq.getRear());
    }

    if(str=="size"){
      answer.push_back(dq.size());
    }

    if(str=="empty"){
      answer.push_back(dq.isEmpty());

    }
    if(str=="pop_back"){
      answer.push_back(dq.deleteRear());
    }
    if(str=="pop_front"){
      answer.push_back(dq.deleteFront());
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  cin >> N;
  input();
  for(auto it : answer){
    cout << it << endl;
  }


}