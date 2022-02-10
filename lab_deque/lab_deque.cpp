#include <iostream>
#include"Deque.h"

using namespace std;


int main()
{
    Deque d;
    string s;
    int n;
    d.Creation(&d);
    while (cin >> s)
    {
        if (s == "push_front")
        {
            cin >> n;
            d.push_front(&d, n);
            cout << "ok\n";
        }

        else if (s == "push_back")
        {
            cin >> n;
            d.push_back(&d, n);
            cout << "ok\n";
        }
        else if (s == "pop_front")
        {
            d.pop_front(&d);
            cout << "ok" << endl;
        }
        else if (s == "pop_back")
        {
            d.pop_back(&d);
            cout << "ok" << endl;
        }
        else if (s == "output") {
            d.Output(&d);
        }
    }

	return 0;
}
