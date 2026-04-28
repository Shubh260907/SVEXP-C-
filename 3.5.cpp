#include <iostream>
using namespace std;

int main() {
    long long n, k;
    long long sum = 0;

    cout << "Enter the number n and k: " << endl;
    cin >> n >> k;


    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    sum = sum * k;

    while (sum >= 10) {
        long long current_sum = 0;
        while (sum > 0) {
            current_sum += sum % 10;
            sum /= 10;
        }
        sum = current_sum;
    }

    cout << sum << endl;

    return 0;
}
