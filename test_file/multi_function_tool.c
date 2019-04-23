#include <stdio.h>
#include <math.h>

//计算最大公因数 (gcd(m,n) = gcd(n, m mod n)) 
int gcd(int x, int y){
	int g = y;
	while(x > 0){
		g = x;
		x = y % x;
		y = g;
	}
	return g;
}

//两个数字相除
int divide(int a, int b, int *remainer){
	int quot = a / b;
	*remainder = a % b;
	return quot;
}

//一个阵列中的平均值
double avg(double *a, int n){
	int i;
	double total = 0.0;
	for (i = 0; i < n; i++)
		total += a[i];
	return total / n;
} 


