#include<stdio.h>

typedef struct
{
	int height;//这块地的高度
	bool blocked=0;//这块地是否能继续往右/左扩展
	int length=1;//以这块地为短板能扩展的长度
} Rect;

int N,K;
Rect r[12000];
int maxleft[12000], maxright[12000];//以第n块地为左右边界的最大面积

int max(int a, int b, int c)
{
	if (a > b && a > c) return a;
	if (b > c) return b;
	return c;
}

int max(int a, int b)
{
	if (a > b) return a;
    return b;
}

void getMaxRight(int n)
{
	int tempmax = 0, s;
	for (int i = 0; i < n; i++)
	{
		if (r[i].blocked == 1) continue;
		if (r[i].height > r[n].height) r[i].blocked = 1;
		else
		{
			r[i].length++;
			s = r[i].height*r[i].length;
			if (s > tempmax) tempmax = s;
		}
	}//得到tempmax
	for (int i = n - 1; i >= 0; i--)
	{
		if (r[i].height < r[n].height) break;
		r[n].length++;
	}
	maxright[n] = max(maxright[n - 1], tempmax, r[n].height*r[n].length);
}

void getMaxLeft(int n)
{
	int tempmax = 0, s;
	for (int i = N - 1; i > n; i--)
	{
		if (r[i].blocked == 1) continue;
		if (r[i].height > r[n].height) r[i].blocked = 1;
		else
		{
			r[i].length++;
			s = r[i].height*r[i].length;
			if (s > tempmax) tempmax = s;
		}
	}//得到tempmax
	for (int i = n + 1; i < N; i++)
	{
		if (r[i].height < r[n].height) break;
		r[n].length++;
	}
	maxleft[n] = max(maxleft[n - 1], tempmax, r[n].height*r[n].length);
}

int main()
{
	scanf_s("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf_s("%d", &r[i].height);
	maxright[0] = r[0].height; maxleft[0] = r[N - 1].height;
	for (int i = 1; i < N; i++) getMaxRight(i);
	for (int i = N - 1; i >= 0; i--)
	{
		r[i].blocked = 0; r[i].length = 1;
		getMaxLeft(i);
	}
	int ans = 0, temp;
	for (int i = 0; i < N - K - 1; i++)
	{
		temp = maxright[i] + maxleft[i + K + 1];
		if (temp > ans) ans = temp;
	}
	printf("%d", ans);
}