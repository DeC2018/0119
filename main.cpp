#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1, 1);

    for (int i = 2; i < rowIndex + 1; ++i)
      for (int j = 1; j < i; ++j)
        ans[i - j] += ans[i - j - 1];

    return ans;
  }
};

// Helper function to print a row of Pascal's triangle
void printRow(const vector<int>& row) {
    cout << "[";
    for (size_t i = 0; i < row.size(); ++i) {
        cout << row[i];
        if (i + 1 < row.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    int rowIndex1 = 3;
    cout << "Input: rowIndex = " << rowIndex1 << endl;
    cout << "Output: ";
    printRow(solution.getRow(rowIndex1));

    int rowIndex2 = 0;
    cout << "Input: rowIndex = " << rowIndex2 << endl;
    cout << "Output: ";
    printRow(solution.getRow(rowIndex2));

    int rowIndex3 = 1;
    cout << "Input: rowIndex = " << rowIndex3 << endl;
    cout << "Output: ";
    printRow(solution.getRow(rowIndex3));

    return 0;
}
