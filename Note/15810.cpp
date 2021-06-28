//https://www.acmicpc.net/problem/15810

#include <iostream>
#include <vector>

using namespace std;

int N, M, minTime = 1000001;
vector<int> staff;

long long binarySearch(long long s, long long e) {
	if (s > e) return -1;

	long long mid = (s + e) / 2;
	long long sum = 0;
	
	for (int i = 0; i < N; i++)
		sum += mid / staff[i];

	if (sum >= M) {
		long long candidate = binarySearch(s, mid - 1);
		if (candidate != -1 && candidate < mid) return candidate;
		else return mid;
	}

	return binarySearch(mid + 1, e);
}

int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		int time;
		scanf("%d", &time);

		if (minTime > time) minTime = time;
		staff.push_back(time);
	}

	long long upper_bound = (long long)minTime * (long long)M;
	
	cout << binarySearch(0, upper_bound);

	return 0;
}