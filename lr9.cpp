using System;

class MainClass
{
static void Main()
{
int scenario = 1;
while (true)
{
string[] line = Console.ReadLine().Split();
int n = int.Parse(line[0]);
int r = int.Parse(line[1]);
if (n == 0 && r == 0)
{
break;
}

// Считываем граф и его свойства
int[,] graph = new int[n, n];
for (int i = 0; i < r; i++)
{
line = Console.ReadLine().Split();
int c1 = int.Parse(line[0]) - 1;
int c2 = int.Parse(line[1]) - 1;
int p = int.Parse(line[2]);
graph[c1, c2] = p;
graph[c2, c1] = p;
}
line = Console.ReadLine().Split();
int start = int.Parse(line[0]) - 1;
int end = int.Parse(line[1]) - 1;
int tourists = int.Parse(line[2]);

// Используем алгоритм Флойда-Уоршелла для поиска кратчайших путей
for (int k = 0; k < n; k++)
{
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
graph[i, j] = Math.Max(graph[i, j], Math.Min(graph[i, k], graph[k, j]));
}
}
}

// Вычисляем минимальное число поездок
int trips = (int)Math.Ceiling((double)tourists / (double)(graph[start, end] - 1));

// Выводим результат
Console.WriteLine("Scenario #{0}", scenario++);
Console.WriteLine("Minimum Number of Trips = {0}\n", trips);
}
}
}
