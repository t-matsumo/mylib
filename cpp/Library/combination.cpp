#include <bits/stdc++.h>

using ll = long long;
using namespace std;

constexpr static ll MOD = 1000000007ll;
constexpr static int INF = 1 << 28; // for x <= 10^9
constexpr static ll INFL = 1ll << 60; // for x <= 10^19
constexpr static double EPS = 1e-10;

class combination {
    vector<ll> factrial;
    vector<ll> factrialInverse;
    vector<ll> inverse;

public:
    combination(ll n, ll mod)
        : factrial(n + 1)
        , factrialInverse(n + 1)
        , inverse(n + 1) {
        factrial[0] = factrial[1] = 1;
        factrialInverse[0] = factrialInverse[1] = 1;
        inverse[1] = 1;
        for (int i = 2; i <= n; i++) {
            factrial[i] = (factrial[i - 1] * i) % mod;
            inverse[i] = mod - (inverse[mod % i] * (mod / i)) % mod;
            factrialInverse[i] = (factrialInverse[i - 1] * inverse[i]) % mod;
        }
    }

    ll value(ll i, ll j) {
        return (factrial[i] * ((factrialInverse[j] * factrialInverse[i - j]) % MOD)) % MOD;
    }
};

int main() {
    combinationTable c = combination(1000);
    cout << c.value(100, 50) << endl;
    c = combination(1000, 2);
    cout << c.value(100, 50) << endl;
}
