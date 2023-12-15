#include <bits/stdc++.h>
#define MAXN ((int) 1e6 + 100)
using namespace std;
int n, A[MAXN + 10];
vector<int> B[MAXN + 10];
int LIM[MAXN + 10];
long long f[MAXN + 10];
int head, tail, q[MAXN + 10];
void solve() {
    scanf("%d", &n);
	int m; scanf("%d", &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    // Ϊ�˷���õ����մ𰸣������� A[n + 1] = 0��Ȼ��Ҫ�� [n + 1, n + 1] �ｨ��һ����վ��
    // �����𰸾��� f[n + 1] ��
    A[++n] = 0;
//    cout<<"n="<<n<<endl;
//    for(int i=1;i<=n;i++)
//    	cout<<"A["<<i<<"]="<<A[i]<<endl;
    // B[i] ��һ�� vector��
    // ����ĸ��� -j ��ʾ��һ������������ [i, j]��
    // ���������� j ��ʾ��һ������������ [j, i]��
    // �������ǵ�����˫ָ���� p_i
    for (int i = 1; i <= n; i++) B[i].clear();
    for (int i = 1; i <= m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        B[l].push_back(-r);
        B[r].push_back(l);
    }
    B[n].push_back(-n);//�����n�������n��1�� 
    B[n].push_back(n);
    int now = 0;// now ��¼��˫ָ������ [j, i] ���м�����������������
    for (int i = 1, j = 1; i <= n; i++) {
        // ˫ָ���Ҷ˵��ƶ�һ���������Ҷ˵�Ϊ i ��λ�� [j, i] �����������
        for (int x : B[i]) //��i������������һ���˵� 
			if (x > 0 && x >= j) //x����˵�,i���Ҷ˵�   j   x   i 
				now++;//������[x,i]������� 
        // ��� j = p_i + 1
        while (now > 0 && j <= i) {
            // ˫ָ����˵��ƶ�һ����������˵�Ϊ j ��λ�� [j, i] �����������
            for (int x : B[j]) //��j������������һ���˵� 
				if (x < 0 && -x <= i) //x���Ҷ˵�,i����˵�  j 	 x	 i		
					now--;
            j++;
        }
        assert(now == 0);
        LIM[i] = j;// LIM[i] = p_i
    }
//    for(int i=1;i<=n;i++)
//    	cout<<"LIM["<<i<<"]="<<LIM[i]<<endl;
    // dp ��ֵ
    f[0] = 0;
    f[1] = A[1];
    // �� dp ��ֵ��ʼ����������
    head = tail = 1;
    q[tail++] = 0;//����q�ǵ������� 
    q[tail++] = 1;
    for (int i = 2; i <= n; i++) {
        int lim = LIM[i - 1] - 1;// Ҫ����һ����վ��λ�� >= p_{i - 1} - 1
        while (q[head] < lim) head++;
        f[i] = f[q[head]] + A[i];
        while (head < tail && f[q[tail - 1]] >= f[i]) tail--;//������
        q[tail++] = i;
//        cout<<"�˵�"<<i<<"��Ӧ��limֵ��:"<<lim<<endl;
    }
    printf("%lld\n", f[n]);
}
int main() {
	solve();
    return 0;
}
