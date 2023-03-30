#include <iostream>
using namespace std;

const int MOD = 1000000007; // ȡģ��ֹ���

int main() {
  int N; // ���뻭����С
  cin >> N;
  int dp[N+1]; // ����״̬����
  dp[0] = 1; // ��ʼ״̬
  dp[1] = 1;
  for (int i = 2; i <= N; i++) { // ״̬ת��
    dp[i] = (dp[i-1] + 3 * dp[i-2]) % MOD;
  }
  cout << dp[N] << endl; // ������
  return 0;
}
