#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedian(const vector<int>& X, const vector<int>& Y) {
    int n = X.size();
    /*for (int i = 0; i < n; i++) {
        cout<< X[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << Y[i];
    }
    cout << endl;*/
    if (n == 1) {
        return (X[0] + Y[0]) / 2.0;
    }
    if (n == 2) {
        return (max(X[0], Y[0]) + min(X[1], Y[1])) / 2.0;
    }
    int mid = n / 2;
    int m = (n % 2 == 0) ? mid : mid + 1;
    int x1 = X[mid - 1];
    int x2 = X[mid];
    int y1 = Y[m - 1];
    int y2 = Y[m];
    if (x2 <= y1) {
        return findMedian(vector<int>(X.begin() + mid, X.end()), vector<int>(Y.begin(), Y.begin() + m));
    }
    else if (y2 <= x1) {
        return findMedian(vector<int>(X.begin(), X.begin() + mid), vector<int>(Y.begin() + m, Y.end()));
    }
    else {
        if (n % 2 == 0) {
            return (max(x1, y1) + min(x2, y2)) / 2.0;
        }
        else {
            return (X[mid]+Y[mid]) / 2.0;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> Y[i];
    }


    double median = findMedian(X, Y);

    cout.precision(1);
    cout << fixed << median << endl;

    return 0;
}
