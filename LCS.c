#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LENGTH 100

int max(int a, int b){if(a>b){return a;}else{return b;}}

int lcsOf3(char X[], char Y[], char Z[], int m, int n, int o){
	
	//write your code here...

	int lenX = m;
int lenY = n;
int lenZ = o;

if (lenX > 0 && (X[lenX - 1] == '\n' || X[lenX - 1] == '\r'))
    lenX--;

if (lenY > 0 && (Y[lenY - 1] == '\n' || Y[lenY - 1] == '\r'))
    lenY--;

if (lenZ > 0 && (Z[lenZ - 1] == '\n' || Z[lenZ - 1] == '\r'))
    lenZ--;

int dp[lenX + 1][lenY + 1][lenZ + 1];

for (int i = 0; i <= lenX; i++) {
    for (int j = 0; j <= lenY; j++) {
        for (int k = 0; k <= lenZ; k++) {

            if (i == 0 || j == 0 || k == 0) {
                dp[i][j][k] = 0;
            }
            else if (X[i - 1] == Y[j - 1] &&
                     X[i - 1] == Z[k - 1]) {

                dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
            }
            else {
                dp[i][j][k] = max(
                    dp[i - 1][j][k],
                    max(dp[i][j - 1][k],
                        dp[i][j][k - 1])
                );
            }
        }
    }
}

return dp[lenX][lenY][lenZ];
	
	
	
}

int main()
{	char x[MAX_LENGTH], y[MAX_LENGTH],z[MAX_LENGTH];
    fgets(x, MAX_LENGTH, stdin);
    fgets(y, MAX_LENGTH, stdin);
    fgets(z, MAX_LENGTH, stdin);
	printf("%d", lcsOf3(x, y, z, strlen(x), strlen(y), strlen(z)));
	
	return 0;
}
