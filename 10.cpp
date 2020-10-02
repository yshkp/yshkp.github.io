/*

Coded and Decoded by : Yash Kapoor

*/

// Solution for problem - https://www.codechef.com/LRNDSA08/problems/ACM14KG3


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// s.find_by_order(index);
// s.order_of_key(value);

#define ll long long
#define vl vector<ll>
#define all(a) a.begin(), a.end()
#define sz(x) (ll) x.size()
#define dl '\n'
#define why (ll)1000000007
//#define why (ll)998244353
#define lp(i, a, b) for (ll i = a; i < b; ++i)
#define lpr(i, a, b) for (ll i = a; i >= b; i--)
#define lpd(i, x) for (auto i : x)
#define ios                                                                                                            \
  ios_base::sync_with_stdio(false);                                                                                    \
  cin.tie(0);                                                                                                          \
  cout.tie(0);

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

ll inf = 1e18;
double pi = 3.141592653589;
ll mod = why;
ll fast_power(ll base, ll power)
{
  ll result = 1;
  while (power) {
    if (power % 2)
      result = (result * base) % mod;
    base = (base * base) % mod;
    power /= 2;
  }
  return result;
}

ll inverse(ll base, ll mod) { return fast_power(base, mod - 2); }
int test = 1;
vector<char> a[26];
vl vis(26);

const pair<ll, ll> dir[] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

bool dfs(char node, char target)
{
  vis[node - 'a'] = 1;
  if (node == target) {
    return true;
  }
  for (auto i : a[node - 'a']) {
    if (!vis[i - 'a']) {
      if (dfs(i, target))
        return true;
    }
  }
  return false;
}

void solve()
{
  for (size_t i = 0; i < 26; i++) {
    a[i].clear();
    vis[i] = 0;
  }
  string s, t;
  cin >> s >> t;
  ll m;
  cin >> m;
  while (m--) {
    string mp;
    cin >> mp;
    a[mp[0] - 'a'].push_back(mp[3]);
  }
  if (s == t) {
    cout << "YES" << dl;
    return;
  }
  if (sz(s) != sz(t)) {
    cout << "NO" << dl;
    return;
  }
  for (size_t i = 0; i < sz(s); i++) {
    if (s[i] != t[i]) {
      for (size_t j = 0; j < 26; j++) {
        vis[j] = 0;
      }

      if (!dfs(s[i], t[i])) {
        cout << "NO" << dl;
        return;
      }
    }
  }
  cout << "YES" << dl;
}

int main()
{
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
  ios;
  ll t = 1;
  cin >> t;
  while (t--) {
    // cout << "Case #" << test++ << ": ";
    solve();
  }
}
