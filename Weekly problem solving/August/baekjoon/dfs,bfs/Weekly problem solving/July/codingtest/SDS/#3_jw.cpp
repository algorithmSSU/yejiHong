#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define COIN_MAX 3

void dfs(vector<int>& coins, vector<int>& costs, int depth, int cost, int& min, int& max) {
	if (depth >= COIN_MAX) {
		if (binary_search(costs.begin(), costs.end(), cost)) {
			if (cost < min)	min = cost;
			if (cost > max) max = cost;
		}
		return;
	}

	int lower_bound = cost + coins[0] * (COIN_MAX - depth);
	int upper_bound = cost + coins[coins.size() - 1] * (COIN_MAX - depth);

	if (min < lower_bound && max > upper_bound) return;
	
	for (const auto coin : coins)
		dfs(coins, costs, depth + 1, cost + coin, min, max);
};

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		int n, m;
		cin >> n >> m;

		vector<int> coins(n);
		for (int i = 0; i < n; ++i)
			cin >> coins[i];

		vector<int> costs(m);
		for (int i = 0; i < m; ++i)
			cin >> costs[i];

		sort(coins.begin(), coins.end());
		sort(costs.begin(), costs.end());

		int min = INT_MAX, max = INT_MIN;

		dfs(coins, costs, 0, 0, min, max);

		cout << "#" << test_case << " ";
		if (min == INT_MAX || max == INT_MIN)
			cout << "-1\n";
		else
			cout << min << " " << max << "\n";
	}

	return 0;
}
