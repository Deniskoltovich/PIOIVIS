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

//int main() {
//    deque* d = new deque();
//
//    string str;
//    int n;
//    while (str != "exit") {
//        cin >> str;
//        if (str == "push_back") {
//            cin >> n;
//            d->push_back(n);
//            d->print();
//        }
//
//        else if (str == "push_front") {
//            cin >> n;
//            d->push_front(n);
//            d->print();
//        }
//        else if (str == "pop_back") {
//            if (!d->empty()) {
//                d->pop_back();
//                d->print();
//            }
//        }
//
//        else if (str == "pop_front") {
//            if (!d->empty()) {
//                d->pop_front();
//                d->print();
//            }
//
//        }
//        else if (str == "print") {
//            d->print();
//        }
//        else if (str == "clear") {
//            d->clear();
//        }
//
//        else if (str == "back") {
//            if (!d->empty())
//                cout << d->back() << endl;
//
//        }
//
//        else if (str == "size")
//            cout << d->size() << endl;
//
//        else if (str == "front") {
//            if (!d->empty())
//                cout << d->front() << endl;
//        }
//
//    }
//    if (str == "exit")
//        cout << "bye";
//    delete[] d;
//    return 0;
//}


//int main()
//{
//    Deque d;
//    string s;
//    int n;
//    d.Creation(&d);
//    while (cin >> s)
//    {
//        if (s == "push_front")
//        {
//            cin >> n;
//            d.push_front(&d, n);
//            cout << "deque:";
//            d.Output(&d);
//            cout << endl;
//        }
//
//        else if (s == "push_back")
//        {
//            cin >> n;
//            d.push_back(&d, n);
//            cout << "deque:";
//            d.Output(&d);
//            cout << endl;
//        }
//        else if (s == "pop_front")
//        {
//            d.pop_front(&d);
//            cout << "deque:";
//            d.Output(&d);
//            cout << endl;
//        }
//        else if (s == "pop_back")
//        {
//            d.pop_back(&d);
//            cout << "deque:";
//            d.Output(&d);
//            cout << endl;
//        }
//        else if (s == "output") {
//           cout << "deque:";
//            d.Output(&d);
//            cout << endl;
//        }
//        else if (s == "exit") {
//            break;
//        }
//    }
//
//	return 0;
//}
