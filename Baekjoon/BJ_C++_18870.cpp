#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, temp = 0;
    cin >> n;
    vector<int> v;
    vector<int> vc;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        vc.push_back(temp);
    }
    sort(vc.begin(), vc.end());
    vc.erase(unique(vc.begin(), vc.end()), vc.end()); // 중복제거
    for (int i = 0; i < v.size(); i++) {
        cout << lower_bound(vc.begin(), vc.end(), v[i]) - vc.begin() << " ";
    }
    cout << "\n";
    return 0;
}
