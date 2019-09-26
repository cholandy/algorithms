#include <bits/stdc++.h>

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
const string DS[] = {"down", "right", "up", "left"};
const int DO[] = {2, 3, 0, 1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x * x; }
ll sqr(int x) { return (ll)x * x; }
double sqr(double x) { return x * x; }
ld sqr(ld x) { return x * x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y)
{
    static uniform_int_distribution<ll> d;
    return d(mmtw) % (y - x + 1) + x;
}

// ========================================================================= //

const int N = 1002;
const int K = 12;

enum Type
{
    FREE = 0,
    WALL = 1,
    DOOR = 2
};

int sx, sy;
int cx0, cy0;
bool key[N][N];
bool finish[N][N];
Type e[N][N][4];

void readLab()
{
    scanf("%*d%*lld%d%d%d%d", &sx, &sy, &cx0, &cy0);

    for (int x = 0; x < sx; ++x)
        e[x][0][3] = e[x][sy - 1][1] = WALL;
    for (int y = 0; y < sy; ++y)
        e[0][y][2] = e[sx - 1][y][0] = WALL;
    int c, d, k, en;
    scanf("%d%d%d%d", &c, &d, &k, &en);
    for (int i = 0; i < c; ++i)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 + y1 > x2 + y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x1 == x2)
        {
            e[x1][y1][1] = WALL;
            e[x2][y2][3] = WALL;
        }
        else
        {
            e[x1][y1][0] = WALL;
            e[x2][y2][2] = WALL;
        }
    }
    for (int i = 0; i < d; ++i)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 + y1 > x2 + y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x1 == x2)
        {
            e[x1][y1][1] = DOOR;
            e[x2][y2][3] = DOOR;
        }
        else
        {
            e[x1][y1][0] = DOOR;
            e[x2][y2][2] = DOOR;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        key[x][y] = true;
    }
    for (int i = 0; i < en; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        finish[x][y] = true;
    }
}

int main()
{
    readLab();

    static int pd[N][N];
    memset(pd, -1, sizeof(pd));
    vector<ipair> q;
    q.push_back({cx0, cy0});
    pd[cx0][cy0] = 4;
    int fx = -1, fy = -1;
    for (int i = 0; i < sz(q); ++i)
    {
        int x = q[i].X, y = q[i].Y;
        if (finish[x][y])
        {
            fx = x;
            fy = y;
            break;
        }
        for (int d : DO)
            if (e[x][y][d] == FREE)
            {
                int nx = x + DX[d];
                int ny = y + DY[d];
                if (pd[nx][ny] == -1)
                {
                    pd[nx][ny] = d;
                    q.push_back({nx, ny});
                }
            }
    }
    if (fx == -1)
    {
        cout << "terminate\n";
        return 0;
    }

    vector<int> ans;
    while (fx != cx0 || fy != cy0)
    {
        int d = pd[fx][fy];
        ans.push_back(d);
        fx -= DX[d];
        fy -= DY[d];
    }
    reverse(ALL(ans));
    int i = 0;
    while (i < sz(ans))
    {
        int j = i;
        int d = ans[i];
        while (j < sz(ans) && ans[j] == d)
            ++j;
        int cnt = j - i;
        i = j;
        int len1 = cnt * (5 + sz(DS[d]));
        int len2 = (5 + sz(DS[d])) + 7 + sz(to_string(cnt));
        if (len1 < len2)
        {
            while (cnt--)
                cout << "move-" << DS[d] << "\n";
        }
        else
        {
            cout << "for-" << cnt << " move-" << DS[d] << " end\n";
        }
    }

    return 0;
}