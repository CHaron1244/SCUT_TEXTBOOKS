#include<bits/stdc++.h>
using namespace std;
const int MAXM = 18;
const int MAXN = (1<<MAXM)+1;
int RMQ_MinIndex(int A[], int l, int r) {
    return A[r] < A[l] ? r : l;
}
void RMQ_Init(int A[], int ALen, int(*f)[MAXN]) {
    for (int i = 0; i < MAXM; i++) {
        for (int j = 1; j + (1 << i) - 1 <= ALen; j++) {
            if (i == 0) {
                f[i][j] = j;
            }
            else {
                f[i][j] = RMQ_MinIndex(A, f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
}
int RMQ_Query(int A[], int(*f)[MAXN], int a, int b) {
    if (a == b) {
        return a;
    }
    else if (a > b) { 
        a = a^b, b = a^b, a = a^b;   // 交换 a 和 b 的值
    }
    int k = lg2K[b - a + 1];
    return RMQ_MinIndex(A, f[k][a], f[k][b - (1 << k) + 1]);
}
int main(){
	return 0;
}
