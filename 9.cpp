#include<stdio.h>

int N,K;
int h[12000];
int maxleft[12000], maxright[12000];//从左开始和从右开始，n块土地的最大面积

void getMaxLeft(int n)
{

}

void getMaxRight(int n)
{

}

int main()
{
	scanf_s("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf_s("%d", &h[i]);
	maxleft[0] = h[0]; maxright[0] = h[N - 1];
}