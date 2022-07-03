#include "stdio.h"

#include "stdlib.h"

#include "math.h"

#define EPSILON 0.02

double

function (double x) {

  return 0.85 * x * x - 2.14 * x;
}

double derivativefunc(double x) {

  return 1.7 * x - 2.14;
}

void bisection(double a, double b) {

  int max = 10, i, k;
  double values[max][5];
  double _a, c, _c;
  for (i = 1; i <= max; i++) {
    c = (a + b) / 2;
    _a = function (a);
    _c = function (c);
    values[i - 1][0] = a;
    values[i - 1][1] = b;
    values[i - 1][2] = c;
    values[i - 1][3] = _c;
    if (_a * _c < 0)
      b = c;
    else
      a = c;
    values[i - 1][4] = b - a;
  }
  printf("\tİKİYE BÖLME METODU\n");
  printf("\n#\t   Kök\t\t  Error\n");
  printf("__\t________\t________\n");
  for (k = 0; k < i - 1; k++) {
    printf("%d\t%f\t%lf\n", k + 1, values[k][2], values[k][4]);
  }
  if (values[i - 1][4] < EPSILON)
    printf("\nİkiye Bölme Metodu İle 0.02'den Daha Küçük Bir Hata Değerine %d. Adımda Ulaşılmıştır.\n\n", k - 1);
  printf("---------------------------------------------------------------------------------------\n");
}

void linear(double a, double b) {

  int max = 10, i, j;
  double values[max][5];
  double _a, k, _k;
  for (i = 1; i <= max; i++) {
    k = ((a * function (b)) - (b * function (a))) / (function (b) - function (a));
    _a = function (a);
    _k = function (k);
    values[i - 1][0] = a;
    values[i - 1][1] = b;
    values[i - 1][2] = k;
    values[i - 1][3] = _k;
    if (_a * _k < 0)
      b = k;
    else
      a = k;
    values[i - 1][4] = (b - a);
  }
  printf("\nDOĞRUSAL İNTERPOLASYON\n\t\tMETODU\n");
  printf("\n#\t   Kök\t\t  Error\n");
  printf("__\t________\t________\n");
  for (j = 0; j < i - 1; j++) {
    printf("%d\t%f\t%lf\n", j + 1, values[j][2], values[j][4]);
  }
  if (values[i - 1][4] < EPSILON)
    printf("\nDoğrusal İnterpolasyon Metodu İle 0.02'den Daha Küçük Bir Hata Değerine %d. Adımda Ulaşılmıştır.\n\n", j - 1);
  printf("---------------------------------------------------------------------------------------");
}

void newton(double x0) {

  int max = 10, i, l;
  double values[max][5];
  double x1, f0, g0;
  for (i = 1; i <= max; i++) {
    g0 = derivativefunc(x0);
    f0 = function (x0);
    x1 = x0 - (f0 / g0);
    values[i - 1][0] = x0;
    values[i - 1][2] = x1;
    values[i - 1][4] = (x1 - x0);
    x0 = x1;
  }
  printf("\n\n\tNEWTON RAPSHON\n\t\tMETODU");
  printf("\n\n#\t   Kök\t\t  Error\n");
  printf("__\t________\t________\n");
  for (l = 0; l < i - 1; l++) {
    printf("%d\t%f\t%lf\n", l + 1, values[l][2], values[l][4]);
  }
  if (values[i - 1][4] < EPSILON)
    printf("\nNewton Raphson Metodu İle 0.02'den Daha Küçük Bir Hata Değerine %d. Adımda Ulaşılmıştır.\n\n", l - 8);
  printf("---------------------------------------------------------------------------------------\n");
}
int main() {
  double a = 2, b = 12, x0 = 2;
  bisection(a, b);
  linear(a, b);
  newton(x0);
  return 0;
}
