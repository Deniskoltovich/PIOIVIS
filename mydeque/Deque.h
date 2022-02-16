#pragma once
//
#include <iostream>
using namespace std;

struct Node {                //��������� ����� ������ 
    int value;          //������������ ��������
    Node* next, * prev;      //��������� �� ��������� � ���������� ��������
};

struct deque {
    Node* head = nullptr;     //������������� ������ � ����� ������, ������� ���� 
    Node* tail = nullptr;
    int count = 0;
    void push_back(int num) {
        Node* element = new Node; //��������� ������ ��� ����� ������� ���������
        element->value = num;  //��������� �������� � ���������
        count++;
        if (!head) {          //���� ������ ����
            head = element;       //�.� ������� ������������, 
            tail = head;      //�� �������� � ������� � �������
        }
        else {
            element->prev = tail; //���������� ������� ������ ������������ ������������, ����� ���������(�������)
            tail->next = element; //��������� ������� �� ������� ��� ����������� ������� ������
            tail = element;       //������������ �������� ������� ������
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
            element->next = head;      //��������� ������� �� ����������� ��������� �������� �����
            head->prev = element;      //����� ������� ��������� ����������� �������
            head = element;           //������������ �������� ������� ������
        }
        cout << "ok" << endl;
    }
    void pop_back() {
        if (count != 0) {               //���� ��� �� ������
            cout << tail->value << endl;
            if (count > 1) {         //���� � ���� ��������� ������ ������ ��������
                Node* element = tail;     //��������� �� ��, ��� ����� �������������� �����
                tail = tail->prev; //����������� ������ ������ ����������� ��������
                tail->next = nullptr;     //��������� �� ��, ��� �� ��������� �����
                delete element;     //������� ������ �����
                count--;        //��������� ������ ����
            }
            else {               //���� � ���� ��������� ����� ���� �������
                head = tail = 0;        //����������� ��� �������� ����
                count--;        //��������� ������ ����
            }
        }
        else cout << "error" << endl;
    }
    void pop_front() {
        if (count != 0) {
            cout << head->value << endl;
            if (head->next) {          //���� � ���� ������ ������ �������� 
                Node* element = head; //��������� �� ��, ��� ����� ������������ ������
                head = head->next; //����������� ������ ������ ���������� �� ������ ������� �������� 
                head->prev = nullptr;  //��������� �� ��, ��� ����� ������� �����
                delete element;     //������� ������ ������
                count--;        //��������� ������ ����
            }
            else if (head == tail) {    //���� ������� ���� � ����
                head->next = nullptr;  //���������, ��� �� ������� �����
                head = nullptr;       //��������� �� ��, ��� ������ ���� �����
                delete head;        //������� ������������ �������
                count = 0;        //����������� ���� ������� ����
            }
        }
        else cout << "error" << endl;
    }
    void back() {
        if (count != 0) cout << tail->value << endl; //������� �������� ������
        else cout << "error" << endl;
    }
    void front() {
        if (count != 0)cout << head->value << endl; //������� �������� ������
        else cout << "error" << endl;
    }
    void size() {
        cout << count << endl;          //������� ������ ����
    }
    void clear() {
        count = 0;               //����������� ������� ���� ����
        cout << "ok" << endl;
        while (head)             //����: ���� �� ������ ������ ���-�� �����
        {
            tail = head->next;        //����������� ������ ������ ���������� ��������, ��� ����� �� ������� 
            //delete head;           //������� ������ ������� ����
            head = tail;             //��������� �� ��, ��� ����� ��������� ������ ������
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
//        void Creation(Deque* D) //�������� ����
//        {
//            D->last = 0;
//        }
//
//        void push_front(Deque* D, int n) //���������� �������� � ������
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
//                D->data[i - 1] = D->data[i];//������������� ������, �������� �� ���. ����������� ������������������ ���, ���� ������� ���� �������.
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


 