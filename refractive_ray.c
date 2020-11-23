#include <stdio.h>
#include <math.h>
#include <malloc.h>

double dependence(double x) {
  double y = 3 - 2*pow(x, 2);
  return y;
}

double angle (int angle_degree) {
  double angle = (double)angle_degree * (double)0.017;
  return angle;
}

double sinAngle (double angle_radian) {
  double sin_angle = sin(angle_radian);
  return sin_angle;
}

double dotA (double sin_angle) {
  double A_x = sqrt((3-sin_angle)/2);
  return A_x;
}

int countDots (double delta_x, double A_x) {
  int count_dots = (A_x/delta_x) + 2;
  return count_dots;
}

double tgAngle (double sin_angle, double n) {
  double k = -tan(asin(sin_angle/n));
  return k;
}

double dots (double k, double dot_x, double delta_x, double pre_dot_y) {
  double dot_y = k * (delta_x) + pre_dot_y;
  return dot_y;
}

double ray_length (double a_x, double a_y, double b_x, double b_y) {
  double length = sqrt(pow((b_x-a_x), 2) + pow((b_y-a_y), 2));
  return length;
}

int main () {
  double** coordinates;
  double delta_x;
  double angle_radian;
  int angle_degree;
  double sin_angle;
  double A_x;
  int count_dots;
  double k, n;
  printf ("angle = ");
  scanf ("%d", &angle_degree);
  angle_radian = angle(angle_degree);
  printf ("step = ");
  scanf ("%lf", &delta_x);
  sin_angle = sinAngle(angle_radian);
  A_x = dotA(sin_angle);
  count_dots = countDots(delta_x, A_x);
  coordinates = (double**)malloc(2*sizeof(double*));
  for (int i = 0; i < count_dots; i++) {
		coordinates[i] = (double*)malloc(count_dots*sizeof(double));
  }
  coordinates[0][0] = (double)0;
  coordinates[1][0] = (double)0;
  for (int i = 1; i < count_dots-1; i++) {
    coordinates[0][i] = coordinates[0][i-1] + delta_x;
    n = dependence(coordinates[0][i]);
    k = tgAngle(sin_angle, n);
    coordinates[1][i] = dots(k, coordinates[0][i], delta_x, coordinates[1][i-1]);
  }
  coordinates[0][count_dots-1] = A_x;
  coordinates[1][count_dots-1] = dots(k, coordinates[0][count_dots-2], delta_x, coordinates[1][count_dots-2]);
  for (int i = 0; i < count_dots; i++) {
    printf("%lf\n", coordinates[0][i]);
  }
  for (int i = 0; i < count_dots; i++) {
    printf("%lf\n", coordinates[1][i]);
  }
  double length = 0;
  for (int i = 1; i < count_dots; i++) {
    length += ray_length(coordinates[0][i-1], coordinates[1][i-1], coordinates[0][i], coordinates[1][i]);
  }
  printf ("Ray's length = %lf", length);
  return 0;
}
