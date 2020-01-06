#include <stdio.h>
#include <stdlib.h>

int num=0;

int valid(int i, int j, int n, int a[n][n])
{
    if (i < 0 || i > n - 1 || j < 0 || j > n - 1) return 0;
    if (a[i][j]!=0)return 0;
    return 1;
}
void print(int n, int a[n][n]) {
    num ++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int k(int n, int a[n][n], int x, int y, int step)
{
    int lin,col;
    int mx[8]={1, 2, 2, 1, -1, -2, -2, -1};
    int my[8]={2, 1, -1, -2, -2, -1, 1, 2};
    if(step==n*n+1)
    {
        print(n,a);
    }
    else for(int i=0;i<8;i++)
    {
        int lin=x+mx[i];
        int col=y+my[i];
        if(valid(lin, col, n, a))
        {
            a[lin][col] = step;
             k(n, a, lin, col, step + 1);
             a[lin][col] = 0;

        }

    }

}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        a[i][j]=0;
    a[0][0]=1;
    k(n, a, 0, 0, 2);
    printf("%d",num);
    }
