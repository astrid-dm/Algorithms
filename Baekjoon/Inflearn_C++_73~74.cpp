//73
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>>pq;

	int temp = 0;
	while (temp != -1) {
		cin >> temp;
		if (temp == 0) {
			cout << "출력값 : " <<  pq.top() << "\n";
			while (!pq.empty()) pq.pop();
		}
		else pq.push(temp);
	}

	return 0;
}

//*-----------------------------------------------------------------------------------------------*

//74
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>>pq;

	int temp = 0;
	while (temp != -1) {
		cin >> temp;
		if (temp == 0) {
			cout << pq.top() << "\n";
			while (!pq.empty()) pq.pop();
		}
		else pq.push(temp);
	}

	return 0;
}
