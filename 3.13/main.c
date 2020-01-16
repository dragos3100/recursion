#include <stdio.h>
#include <stdlib.h>

void print(int m, int n,int a[n][m])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int valid(int x, int y, int m, int n, int a[n][m])
{
    if (x < 0 || y > m - 1 || y < 0 || x > n - 1) return 0;
    if (a[x][y]==0) return 0;
    if(a[x][y]>=2) return 0;
    return 1;

}
int t(int n, int m, int a[n][m],int x,int y,int step)
{
    int lin,col;
    int mx[4]={-1, 0, 1, 0};
    int my[4]={0, 1, 0, -1};
    for(int i=0;i<4;i++)
    {
        lin=x+mx[i];
        col=y+my[i];
        if (valid(lin, col, m, n, a))
            {
            a[lin][col] = step;
            if (lin == 0 || lin == m - 1 || col == 0 || col == n - 1)
            {
                print(m, n,a);
                a[lin][col]=1;
                return 0;
            }
            else
             t(n, m, a, lin, col, step+1);
            a[lin][col] = 1;
            }
    }
}
int main()
{
   int n,m,x,y;
   scanf("%d""%d",&n,&m);
   int a[n][m];
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
    }
    do
    {
         printf("choose a start point:\n");
         scanf("%d""%d",&x,&y);
    }while((x<0)||(y<0)||(x>n-1)||(y>m-1));
    a[x][y]=2;
    if (a[x][y]!=0 && (x == 0 || x == m - 1 || y == 0 || y == n - 1))
    print(m,n,a);
    t(n,m,a,x,y,3);

}
