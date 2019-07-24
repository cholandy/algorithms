#include <stdio.h>
#include <math.h>
#define MAXN 5000
int N;
double Dx, Dy;
typedef struct Point {
	double x, y;
	double scope;
} dot;
dot dots[MAXN];
int convexhull[MAXN];
int convexhull_size;

int ccw(dot a, dot b, dot c) {
	dot ab;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	dot bc;
	bc.x = c.x - b.x;
	bc.y = c.y - b.y;
	double ret = ab.x*bc.y - ab.y*bc.x;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}
double getDistance(const dot A, const dot B) {
	return sqrt(pow(A.y - B.y, 2.0) + pow(A.x - B.x, 2.0));
}
void setSlope(const dot P0) {
	for (int i = 1; i < N; i++) {
		dots[i].scope = (dots[i].x - P0.x) / getDistance(P0, dots[i]);
	}
}
void ConvexHull() {
	for (int i = 2; i < N; i++) {
		while (convexhull_size >= 2 && ccw(dots[convexhull_size - 2], dots[convexhull_size - 1], dots[i]) < 0) {
			convexhull_size--;
		}
		convexhull[convexhull_size++] = i;
	}
}
void dotSortByXY(int s, int d) {
	for (int i = s; i < d; i++) {
		dot temp = dots[i];

		int j = i - 1;

		for (; j >= 0; j--) {

			if (dots[j].y < temp.y)
				break;
			else if (dots[j].x == temp.y && dots[j].x < temp.x)
				break;

			dots[j + 1] = dots[j];
		}
		dots[j + 1] = temp;
	}
}
void dotSortByScope(int s, int d) {
	for (int i = s; i < d; i++) {
		dot temp = dots[i];

		int j = i - 1;

		for (; j >= s; j--) {

			if (dots[j].scope < temp.scope)
				break;
			dots[j + 1] = dots[j];
		}
		dots[j + 1] = temp;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &Dx, &Dy);
		dots[i].y = Dy;
		dots[i].x = Dx;
	}
	dotSortByXY(0, N);
	setSlope(dots[0]);
	dotSortByScope(1, N);
	convexhull[convexhull_size++] = 0;
	convexhull[convexhull_size++] = 1;
	ConvexHull();

	printf("%d\n", convexhull_size);

}