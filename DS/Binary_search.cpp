#include <iostream>
using namespace std; 
int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;

    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            found = true;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Element found in the array.\n";
    } else {
        cout << "Element not found in the array.\n";
    }
    return 0;
}