#include <iostream>
#include <vector>
using namespace std;

bool isMinHeap(vector<int>& arr, int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Left child check
        if (arr[i] > arr[2 * i + 1])
            return false;

        // Right child check (if exists)
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isMinHeap(arr, n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}