#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int n;
double z, r;
struct NODE
{
    int id;
    int ziN = 0;
    vector<int>ziId;
    double v=0;
    double nbN=1;
} node[100001];
double  DFS()
{
    double sum = 0;
    int s = 0;
    queue<NODE>q;
    if (node[0].nbN != 1)
    {
        node[0].v *=  node[0].nbN;
        sum = node[0].v;
    }
    q.push(node[0]);
    while (!q.empty())
    {
        NODE t;
        t = q.front();
        q.pop();
        for (int i = 0; i < t.ziId.size(); i++)
        {
            if (t.ziId[i] != -1)
            {

                node[t.ziId[i]].v = t.v * (1 - 0.01 * r);
                if (node[t.ziId[i]].nbN != 1)
                {
                    node[t.ziId[i]].v *= node[t.ziId[i]].nbN;
                    sum += node[t.ziId[i]].v;
                }
                q.push(node[t.ziId[i]]);
            }
        }
    }
    return sum;
}
int main()
{
    scanf("%d%lf%lf", &n, &z, &r);
    node[0].id = 0;
    node[0].v = z;
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        if (m == 0)
        {
            int t;
            scanf("%d", &t);
            node[i].id = i;
            node[i].nbN = t;
            continue;
        }
        for (int j = 0; j < m; j++)
        {
            int t;
            scanf("%d", &t);
            node[i].ziId.push_back(t);
            node[t].id = t;
        }
    }
    printf("%d\n", (int)DFS());
    return 0;
}
