#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/**
在一个排序矩阵中找从小到大的第 k 个整数。
排序矩阵的定义为：每一行递增，每一列也递增。
给出 k = 4 和一个排序矩阵：

[
  [1 ,5 ,7],
  [3 ,7 ,8],
  [4 ,8 ,9],
]
返回 5。
*/

typedef vector<vector<int> > Matrix;
int find(const Matrix& matrix, int k) {
    int lineNum = matrix.size();
    int columnNum = matrix[0].size();
    vector<int> row(lineNum, 0);

    for(int i = 0;  i < k; ++i) {
        int temp = matrix[lineNum - 1][columnNum - 1] + 1;
        int minIdx = 0;
        for(int j = 0; j < lineNum; ++j) {
            if(matrix[j][row[j]] < temp) {
                minIdx = j;
                temp = matrix[j][row[j]];
            }
        }
        row[minIdx]++;
        if(i == k - 1) {
            return temp;
        }
    }

    return -1;
}

void adjustMatrix(Matrix& matrix) {
    int i = 0;
    int j = 0;
    int maxNum = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;
    while(i < matrix.size() - 1 && j < matrix[0].size() - 1) {
        if(matrix[i+1][j] < matrix[i][j+1]) {
            matrix[i][j] = matrix[i+1][j];
            i++;
        }else {
            matrix[i][j] = matrix[i][j+1];
            j++;
        }
    }

    while(i < matrix.size() - 1) {
        if(matrix[i+1][j] < maxNum) {
            matrix[i][j] = matrix[i+1][j];
            i++;
        }
    }

    while(j < matrix[0].size() - 1) {
        if(matrix[i][j+1] < maxNum) {
            matrix[i][j] = matrix[i][j+1];
            j++;
        }
    }
    matrix[i][j] = maxNum;
}

int find2(Matrix& matrix, int k) {
    for(int i = 0; i < k; ++i) {
        if(i == k - 1) {
            return matrix[0][0];
        }
        cout << matrix[0][0] << endl;
        adjustMatrix(matrix);
    }

    return -1;
}

int main() {
    
    int a[][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Matrix matrix(4, vector<int>());
    matrix[0].insert(matrix[0].end(), a[0], a[0] + 4);
    matrix[1].insert(matrix[1].end(), a[1], a[1] + 4);
    matrix[2].insert(matrix[2].end(), a[2], a[2] + 4);
    matrix[3].insert(matrix[3].end(), a[3], a[3] + 4);

    for(auto line: matrix) {
        for(auto n: line) {
            cout << n << "," ;
        }
        cout << endl;
    }

    int ret;
    //ret = find(matrix, 7);
    //cout << "result: " << ret << endl; 

    //ret = find(matrix, 9);
    //cout << "result: " << ret << endl; 

    ret = find2(matrix, 9);
    cout << "result: " << ret << endl; 

    return 0;
}

