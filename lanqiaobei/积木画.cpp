#include <iostream>
using namespace std;

const int MOD = 1000000007; // 取模防止溢出

int main() {
  int N; // 输入画布大小
  cin >> N;
  int dp[N+1]; // 定义状态数组
  dp[0] = 1; // 初始状态
  dp[1] = 1;
  for (int i = 2; i <= N; i++) { // 状态转移
    dp[i] = (dp[i-1] + 3 * dp[i-2]) % MOD;
  }
  cout << dp[N] << endl; // 输出结果
  return 0;
}
