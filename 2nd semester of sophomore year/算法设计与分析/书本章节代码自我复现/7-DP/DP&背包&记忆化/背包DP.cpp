#include <iostream>
using namespace std;
const int maxn = 13010;
int n, W, w[maxn], v[maxn], f[maxn];
int main() {// 0/1���� 
  cin >> n >> W;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];  // ��������
  for (int i = 1; i <= n; i++)
    for (int l = W; l >= w[i]; l--)
      if (f[l - w[i]] + v[i] > f[l]) f[l] = f[l - w[i]] + v[i];  // ״̬����
  cout << f[W];
  return 0;
}


#include <iostream>
using namespace std;
const int maxn = 1e4 + 5;
const int maxW = 1e7 + 5;
int n, W, w[maxn], v[maxn];
long long f[maxW];
int main() {//��ȫ���� 
  cin >> W >> n;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
    for (int l = w[i]; l <= W; l++)
      if (f[l - w[i]] + v[i] > f[l]) f[l] = f[l - w[i]] + v[i];  // ����״̬����
  cout << f[W];
  return 0;
}

index = 0;//�����Ʒ��飨���ڶ��ر�����ÿ����Ʒ��Ki��������һ����
for (int i = 1; i <= m; i++) {
  int c = 1, p, h, k;
  cin >> p >> h >> k;
  while (k - c > 0) {
    k -= c;
    list[++index].w = c * p;
    list[index].v = c * h;
    c *= 2;
  }
  list[++index].w = p * k;
  list[index].v = h * k;
}

