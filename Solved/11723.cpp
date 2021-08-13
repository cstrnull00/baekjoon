#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string order;
    int a, b = 0;
    while (n--)
    {
        cin >> order;
        if (order == "add")
        {
            cin >> a;
            b |= (1 << a);
        }
        else if (order == "remove")
        {
            cin >> a;
            b &= ~(1 << a);
        }
        else if (order == "check")
        {
            cin >> a;
            if (b & (1 << a))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "toggle")
        {
            cin >> a;
            b ^= (1 << a);
        }
        else if (order == "all")
        {
            b = (1 << 21) - 1;
        }
        else if (order == "empty")
        {
            b = 0;
        }
    }

    return 0;
}