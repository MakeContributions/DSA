#include<iostream>
using namespace std;

class Triplet {
public:
    int x, y, gcd;
};

Triplet extendedEuclid(int a, int b) {
    if (b == 0) {
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;

    }
    Triplet smallAns = extendedEuclid(b, a % b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}

int main() {

    int a, b;
    cin >> a >> b;
    Triplet ans = extendedEuclid(a, b);
    cout << ans.x << "\n";
    cout << ans.y << "\n";
    cout << ans.gcd << "\n";
    return 0;
}

//find value of x and y such that, ax + by = gcd(a,b).
//Have lots of application in number theory like calculating inverse mod.