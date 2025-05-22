#include <stdio.h>

int x[3][3], n, a[2] = {0, 1};

void show() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d ", x[i][j]);
    putchar('\n');
  }
  puts("--------------------------\n");
}

int ok(int k, int l) {
  if (x[k][l] == 0)
    return 1;

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;
      int ni = k + i;
      int nj = l + j;
      if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
        if (x[ni][nj] == 1)
          return 0;
      }
    }
  }

  return 1;
}

int done(int k, int l) { return (k == 2 && l == 2); }

void back(int k, int l) {
  if (l >= 3)
    return;

  for (int i = 0; i < n; i++) {
    x[k][l] = a[i];
    if (ok(k, l)) {
      if (done(k, l))
        show();
      else {
        if (k == 2)
          back(0, l + 1);
        else
          back(k + 1, l);
      }
    }
    x[k][l] = 0;
  }
}

int main() {
  // 3 by 3 grids respecting king's constraint
  n = 2;
  back(0, 0);
  return 0;
}