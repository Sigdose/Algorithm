#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    int L, U;
    ull sum = 0, multi = 1;
    cin >> L >> U;
    if (L == 1) // 1에서 시작
    {
        ++sum;
        ++L;
    }
    if (U != 1 && L == 2) // 1에서 끝이 안 나고 2에서 시작
    {
        ++sum;
        ++L;
    }
    cout << (sum & 1 ? "H" : "A") << "\n"; // 이후 더해지는 값은 모두 짝수이기에 지금 홀수여야 호영이의 승리
    for (int i = 3; i <= U; ++i)
    {
        if (i & 1) // 2칸마다 26을 곱해준다.
        {
            multi = (multi * 26) % 1000000007;
        }
        if (i >= L) // 범위 안에 있을 경우
        {
            sum = (sum + multi) % 1000000007;
        }
    }
    cout << sum;
}
