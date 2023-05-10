#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

constexpr auto maxPosition = int{ 100'000 };
constexpr auto inf = int{ 987'654'321 };

int n, k;

int fastest;
int countOfFastest;

void findFastest() {
	fastest = inf;

	auto dist = vi(maxPosition + 1, inf);
	dist[n] = 0;

	auto q = priority_queue<pii, vector<pii>, greater<pii>>{};
	q.push({ 0, n });

	while (!q.empty()) {
		auto f = q.top();
		q.pop();

		const auto& x = f.second;

		if (k == x) {
			break;
		}

		const auto& y1 = 2 * x;
		if (y1 <= maxPosition) {
			const auto& newDist = dist[x] + 1;
			if (newDist < dist[y1]) {
				dist[y1] = newDist;
				q.push({ dist[y1], y1 });
			}
		}

		const auto& y2 = x - 1;
		if (0 <= y2) {
			const auto& newDist = dist[x] + 1;
			if (newDist < dist[y2]) {
				dist[y2] = newDist;
				q.push({ dist[y2], y2 });
			}
		}

		const auto& y3 = x + 1;
		if (y3 <= maxPosition) {
			const auto& newDist = dist[x] + 1;
			if (newDist < dist[y3]) {
				dist[y3] = newDist;
				q.push({ dist[y3], y3 });
			}
		}
	}

	fastest = dist[k];
}

void countFastest() {
	countOfFastest = int{ 0 };

	auto dist = vi(maxPosition + 1, inf);
	dist[n] = 0;

	auto q = priority_queue<pii, vector<pii>, greater<pii>>{};
	q.push({ 0, n });

	while (!q.empty()) {
		auto f = q.top();
		q.pop();

		const auto& x = f.second;

		if (fastest < dist[x]) {
			continue;
		}

		if (k == x) {
			if (dist[k] == fastest) {
				++countOfFastest;
			}

			continue;
		}

		const auto& y1 = 2 * x;
		if (y1 <= maxPosition) {
			const auto& newDist = dist[x] + 1;
			if (newDist <= dist[y1]) {
				dist[y1] = newDist;
				q.push({ dist[y1], y1 });
			}
		}

		const auto& y2 = x - 1;
		if (0 <= y2) {
			const auto& newDist = dist[x] + 1;
			if (newDist <= dist[y2]) {
				dist[y2] = newDist;
				q.push({ dist[y2], y2 });
			}
		}

		const auto& y3 = x + 1;
		if (y3 <= maxPosition) {
			const auto& newDist = dist[x] + 1;
			if (newDist <= dist[y3]) {
				dist[y3] = newDist;
				q.push({ dist[y3], y3 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> k;

	findFastest();
	countFastest();

	cout << fastest << '\n'
		<< countOfFastest;

	return 0;
}