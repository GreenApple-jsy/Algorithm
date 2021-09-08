using namespace std;

long long cal(int n) {
    if (n <= 1)
        return 1;
    return n + cal(n - 1);
}


long long solution(int price, int money, int count)
{
    if ((cal(count) * price) < money)
        return 0;

    return (cal(count) * price) - money;
}
