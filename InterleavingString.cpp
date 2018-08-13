#include <iostream>
#include <vector>

using namespace std;

/**
给出三个字符串:s1、s2、s3，判断s3是否由s1和s2交叉构成。
比如 s1 = "aabcc" s2 = "dbbca"

    - 当 s3 = "aadbbcbcac"，返回  true.

    - 当 s3 = "aadbbbaccc"， 返回 false.

*/


bool interleaving(const string& s1, const string& s2, const string s3) {
    int size1 = s1.size();
    int size2 = s2.size();
    int size3 = s3.size();

    if(size1 + size2 != size3) {
        return false;
    }

    if(size1 == 0) {
        return s2 == s3;
    }

    if(size2 == 0) {
        return s1 == s3;
    }

    vector<vector<bool> > dp(size1 + 1, vector<bool>(size2 + 1, false));
    dp[0][0] = true;
    for(int i = 1; i < size1 + 1; ++i) {
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }

    for(int j = 1; j < size2 + 1; ++j) {
        dp[0][j] = dp[0][j-1] && s2[j - 1] == s3[j - 1];
    }

    for(int i = 1; i < size1 + 1; ++i) {
        for(int j = 1; j < size2 + 1; ++j) {
            dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i+j-1]) || (dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
        }
    }

    return dp[size1][size2];
}


int main() {
    bool ret = interleaving("aabcc", "dbbca", "aadbbcbcac");
    cout << "result: " << ret << endl;
    ret = interleaving("aabcc", "dbbca", "aadbbbaccc");
    cout << "result: " << ret << endl;
   ret = interleaving("aabcc", "", "aabcc");
    cout << "result: " << ret << endl;
   ret = interleaving("", "dbbca", "dbbca");
    cout << "result: " << ret << endl;
}
