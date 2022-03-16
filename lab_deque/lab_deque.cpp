#include <iostream>
#include"Deque.h"

using namespace std;

int main() {
    deque deq;
    string str;
    while (cin >> str) {
        if (str == "push_front") {
            int num;
            cin >> num;
            deq.push_front(num);
           
        }
        if (str == "push_back") {
            int num;
            cin >> num;
            deq.push_back(num);
           
        }
        if (str == "pop_front") { deq.pop_front();}
        if (str == "pop_back") { deq.pop_back();  }
        if (str == "clear"){deq.clear();}
        if (str == "size") { deq.size(); }
        if (str == "front") { deq.front(); }
        if (str == "back") { deq.back(); }
        if (str == "exit") {
            deq.exit();
            break;
        }
    }
    return 0;
}
