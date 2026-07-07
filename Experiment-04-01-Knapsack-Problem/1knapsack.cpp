#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n, vector<int>& selected) {
    vector<vector<int>> C(n + 1, vector<int>(W + 1, 0));

    // Step 1 & 2: Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                C[i][w] = max(val[i - 1] + C[i - 1][w - wt[i - 1]], C[i - 1][w]);
            } else {
                C[i][w] = C[i - 1][w];
            }
        }
    }

    // Step 3: Trace back to find items chosen
    int res = C[n][W];
    int w = W;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res == C[i - 1][w]) {
            // Item not included
            continue;
        } else {
            // Item included
            selected.push_back(i - 1);
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }

    return C[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n), selected;

    cout << "Enter value and weight of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }

    cout << "Enter size of Knapsack: ";
    cin >> W;

    int maxValue = knapSack(W, wt, val, n, selected);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    cout << "Items chosen:\n";
    for (int i = selected.size() - 1; i >= 0; i--) {
        int idx = selected[i];
        cout << "Item " << (idx + 1)
             << " -> Value = " << val[idx]
             << ", Weight = " << wt[idx] << endl;
    }

    return 0;
}
