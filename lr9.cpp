using System;
using System.Collections.Generic;

class Program
{
struct edge
{
public int x, y;
}
static int[,] a = new int[55, 55];
static int[] du = new int[55];
static List<edge> my = new List<edge>();

static void jie(int u)
{
edge t;
for (int v = 1; v <= 50; v++)
{
if (a[u, v] != 0)
{
a[u, v]--;
a[v, u]--;
t.x = u;
t.y = v;
my.Add(t);
jie(v);
}
}
}

static void Main()
{
int t, i, n, k = 1, v;
t = int.Parse(Console.ReadLine());
int u = 0;
while (t— > 0)
{
n = int.Parse(Console.ReadLine());
Array.Clear(a, 0, a.Length);
Array.Clear(du, 0, du.Length);

for (i = 1; i <= n; i++)
{
string[] line = Console.ReadLine().Split();
u = int.Parse(line[0]);
v = int.Parse(line[1]);
a[u, v]++;
a[v, u]++;
du[u]++;
du[v]++;
}

int flag = 1;


for (i = 1; i <= 50; i++)
{
if (du[i] % 2 != 0)
{
flag = 0;
break;
}
}

if (flag != 0)
{
my.Clear();
jie(u);
if (my.Count != n || my[0].x != my[n - 1].y)
{
flag = 0;
}
}

if (k != 1)
{
Console.WriteLine();
}

Console.WriteLine($"Case #{k}");
k++;

if (flag == 0)
{
Console.WriteLine("IMPOSSIBLEEE");
}
else
{
for (i = 0; i < my.Count; i++)
{
Console.WriteLine($"{my[i].x} {my[i].y}");
}
}
}
}
}
