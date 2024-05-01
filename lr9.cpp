#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct edge
{
int x, y;
};

int a[55][55], du[55];

vector<edge> my;

void jie(int u)
{
edge t;
for (int v = 1; v <= 50; v++)
{
if (a[u][v])
{
a[u][v]--; a[v][u]--;
t.x = u; t.y = v;
my.push_back(t);
jie(v);
}
}
}

int main()
{
int t, i, j, n, k = 1, u, v;
cin » t;

while (t--)
{
cin » n;
memset(a, 0, sizeof(a));
memset(du, 0, sizeof(du));

for (i = 1; i <= n; i++)
{
cin » u » v;
a[u][v]++;
a[v][u]++;
du[u]++;
du[v]++;
}

int flag = 1;

for (i = 1; i <= 50; i++)
{
if (du[i] % 2)
{
flag = 0;
}
break;
}

if (flag)
{
my.clear();
jie(u);
if (my.size() != n || my[0].x != my[n - 1].y)
{
flag = 0;
}
}

if (k != 1)
{
cout « endl;
}

cout « "Case #" « k « endl;
k++;

if (!flag)
{
cout « "IMPOSSIBLEEE" « endl;
}
else
{
for (i = 0; i < my.size(); i++)
{
cout « my[i].x « " " « my[i].y « endl;
}
}
}
return 0;
}
