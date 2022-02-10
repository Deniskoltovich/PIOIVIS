#pragma once
#include <iostream>
#define N 10000
using namespace std;

	struct Deque
	{
		int data[N];
		int last;
        void Creation(Deque* D) //�������� ����
        {
            D->last = 0;
        }

        void push_front(Deque* D, int n) //���������� �������� � ������
        {
            if (D->last == N)
            {
                cout << "deque is full" << endl;
            }

            for (int i = D->last; i > 0; i--)
                D->data[i] = D->data[i - 1];
            D->data[0] = n;
            D->last++;

        }
        void push_back(Deque* D, int n) //���������� �������� � �����
        {
            if (D->last == N)
            {
                cout << "deque is full" << endl;
            }

            D->data[D->last++] = n;

        }
        void pop_front(Deque* D) //�������� ������� ��������
        {
            for (int i = 0; i < D->last; i++) //�������� ���������
                D->data[i] = D->data[i + 1];
            D->last--;
        }
        void pop_back(Deque* D) //�������� ���������� ��������
        {
            D->last--;
        }
        void Output(Deque* D) {
            cout << "[";
            for (int i = 0; i < D->last; i++) {
                cout << D->data[i] << " ";

            }
            cout << "]" << endl;
        }

	};

