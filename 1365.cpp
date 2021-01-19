#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> ascending_arr, int num) {
    int low = 0, high = ascending_arr.size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;
        if (ascending_arr[mid] >= num)
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}

int main(void)
{
    int n, num;
    cin >> n;
    vector<int> ascending_arr;
    ascending_arr.push_back(-1);
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > ascending_arr[ascending_arr.size() - 1])
            ascending_arr.push_back(num);
        else
            ascending_arr[search(ascending_arr, num)] = num;
    }
    cout << n - ascending_arr.size() + 1;

    return 0;
}
