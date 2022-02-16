#pragma once
//
#include <iostream>
using namespace std;

struct Node {                //структура звена списка 
    int value;          //передаваемое значение
    Node* next, * prev;      //указатели на следующий и предыдущий элементы
};

struct deque {
    Node* head = nullptr;     //инициализация начала и конца списка, размера дека 
    Node* tail = nullptr;
    int count = 0;
    void push_back(int num) {
        Node* element = new Node; //выделение памяти под новый элемент структуры
        element->value = num;  //добавляем значение в структуру
        count++;
        if (!head) {          //если список пуск
            head = element;       //т.к элемент единственный, 
            tail = head;      //он является и хвостом и головой
        }
        else {
            element->prev = tail; //предыдущий элемент списка относительно добавленного, будет последним(хвостом)
            tail->next = element; //следующий элемент за хвостом это добавляемый элемент списка
            tail = element;       //присваивание элементу статуса хвоста
        }
        cout << "ok" << endl;
    }
    void push_front(int num) {
        Node* element = new Node;
        element->value = num;
        count++;
        if (!head) {
            head = element;
            tail = head;
        }
        else {
            element->next = head;      //следующий элемент за добавляемым элементом является хвост
            head->prev = element;      //перед головой находится добавляемый элемент
            head = element;           //присваивание элементу статуса головы
        }
        cout << "ok" << endl;
    }
    void pop_back() {
        if (count != 0) {               //если дек не пустой
            cout << tail->value << endl;
            if (count > 1) {         //если в деке находится больше одного элемента
                Node* element = tail;     //указываем на то, что будет использоваться хвост
                tail = tail->prev; //присваиваем статус хвоста предыдущему элементу
                tail->next = nullptr;     //указываем на то, что за элементом пусто
                delete element;     //удаляем бывший хвост
                count--;        //уменьшаем размер дека
            }
            else {               //если в деке находится всего один элемент
                head = tail = 0;        //присваиваем ему значение ноль
                count--;        //уменьшаем размер дека
            }
        }
        else cout << "error" << endl;
    }
    void pop_front() {
        if (count != 0) {
            cout << head->value << endl;
            if (head->next) {          //если в деке больше одного элемента 
                Node* element = head; //указываем на то, что будем использовать голову
                head = head->next; //присваиваем статус головы следующему за бывшей головой элементу 
                head->prev = nullptr;  //указываем на то, что перед головой пусто
                delete element;     //удаляем бывшую голову
                count--;        //уменьшаем размер дека
            }
            else if (head == tail) {    //если элемент один в деке
                head->next = nullptr;  //указываем, что за головой пусто
                head = nullptr;       //указываем на то, что голова тоже пуста
                delete head;        //удаляем единственный элемент
                count = 0;        //присваиваем ноль размеру дека
            }
        }
        else cout << "error" << endl;
    }
    void back() {
        if (count != 0) cout << tail->value << endl; //выводим значение хвоста
        else cout << "error" << endl;
    }
    void front() {
        if (count != 0)cout << head->value << endl; //выводим значение головы
        else cout << "error" << endl;
    }
    void size() {
        cout << count << endl;          //выводим размер дека
    }
    void clear() {
        count = 0;               //присваиваем размеру дека ноль
        cout << "ok" << endl;
        while (head)             //цикл: пока по адресу головы что-то лежит
        {
            tail = head->next;        //присваиваем статус хвоста следующему элементу, что лежит за головой 
            //delete head;           //удаляем первый элемент дека
            head = tail;             //указываем на то, что хвост принимает статус головы
        }
    }
    void exit() {
        cout << "bye";
    }
    void print() {
        cout << "deque: " << "[";
        Node* t = head;
        while (t != nullptr) {
            cout << t->value;
            t = t->next;
            cout << ", ";
        }
        cout << "]" << endl;
    }
};






//class Node {
//public:
//    int data;
//    Node* next;
//    Node* prev;
//    Node(int data) {
//        this->data = data;
//        next = NULL;
//        prev = NULL;
//    }
//};
//
//class Deque {
//public:
//    Node* head;
//    Node* tail;
//    int sz;
//
//    Deque() {
//        head = NULL;
//        tail = NULL;
//        sz = 0;
//    }
//    void push_back(int data) {
//        sz++;
//        if (head != NULL) {
//            Node* t = new Node(data);
//            tail->next = t;
//            t->prev = tail;
//            tail = t;
//        }
//        else {
//            head = new Node(data);
//            tail = head;
//        }
//        cout << "ok" << endl;
//    }
//
//    void push_front(int data) {
//        sz++;
//        Node* t = new Node(data);
//        if (head != NULL) {
//            t->next = head;
//            head->prev = t;
//            head = t;
//        }
//        else {
//            head = new Node(data);
//            tail = head;
//        }
//        cout << "ok" << endl;
//    }
//    void pop_front() {
//        sz--;
//        head = head->next;
//        head->prev = NULL;
//    }
//
//
//    void pop_back() {
//        sz--;
//        tail = tail->prev;
//        tail->next = NULL;
//    }
//
//
//    void print() {
//        cout << "deque: " << "[";
//        Node* t = head;
//        while (t != NULL) {
//            cout << t->data;
//            t = t->next;
//            cout << ", ";
//        }
//        cout << "]" << endl;
//    }
//
//
//    int front() {
//        return head->data;
//    }
//
//    int back() {
//        return tail->data;
//    }
//
//    int size() {
//        return sz;
//    }
//
//    void clear() {
//        while (!empty())
//            pop_back();
//        cout << "ok" << endl;
//    }
//
//    bool empty() {
//        return sz == 0;
//    }
//
//};






//using namespace std;
//
//	struct Deque
//	{
//		int data[N];
//		int last;
//        void Creation(Deque* D) //создание дека
//        {
//            D->last = 0;
//        }
//
//        void push_front(Deque* D, int n) //добавление элемента в начало
//        {
//            if (D->last == N)
//            {
//                cout << "deque is full" << endl;
//            }
//
//            for (int i = D->last; i > 0; i--)
//                D->data[i] = D->data[i - 1];
//            D->data[0] = n;
//            D->last++;
//
//        }
//        void push_back(Deque* D, int n) 
//        {
//            if (D->last == N)
//            {
//                cout << "deque is full" << endl;
//            }
//
//            D->data[D->last++] = n;
//
//        }
//        void pop_front(Deque* D)
//        {
//            if (D->last > 0) {
//                for (int i = 0; i < D->last; i++)
//                    D->data[i] = D->data[i + 1];
//                D->last--;
//            }
//            else {
//                cout << "deque is empty" << endl;
//
//            }
//            
//        }
//        void pop_back(Deque* D)
//        {
//            for (int i = D->last; i > 0 ; i++)
//                D->data[i - 1] = D->data[i];//присваивается первый, которого не сущ. Попробовать Реинициализировать дек, если убираем ласт элемент.
//            D->last--;
//        }
//        void Output(Deque* D) {
//            cout << "[" << D->data[0];
//            for (int i = 1; i < D->last; i++) {
//                cout <<", "<< D->data[i];
//
//            }
//            cout << "]" << endl;
//        }
//
//	};


 