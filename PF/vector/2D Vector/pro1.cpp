#include <iostream>
#include <vector>
using namespace std;

bool searchInRow(vector<vector<int>>& matrix, int row, int target) {
    int start = 0;
    int end = matrix[0].size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

// Search in Matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int startRow = 0;
    int endRow = rows - 1;

    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;

        // Check if target can be in this row
        if (target >= matrix[midRow][0] && target <= matrix[midRow][cols - 1]) {
            return searchInRow(matrix, midRow, target);
        }
        else if (target < matrix[midRow][0]) {
            endRow = midRow - 1;
        }
        else {
            startRow = midRow + 1;
        }
    }

    return false;
}

int main() {
    int m, n;

    cout << "Enter rows: ";
    cin >> m;

    cout << "Enter columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (searchMatrix(matrix, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}