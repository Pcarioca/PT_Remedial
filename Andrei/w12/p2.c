#include <stdio.h>

int x[6], n, a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void show() {

  for (int j = 0; j < 6; j++)
    printf("%d ", x[j]);
  putchar('\n');
}

int ok(int k) {
  int sum = 0;
  for (int i = 0; i <= k; i++) {
    if (i != k && x[i] == x[k])
      return 0;
    sum += x[i];
    if (sum > 22) {
      return 0;
    }
  }

  return 1;
}

int done(int k) { return (k == 5); }

void back(int k) {
  for (int i = 0; i < n; i++) {
    x[k] = a[i];
    if (ok(k)) {
      if (done(k))
        show();
      else
        back(k + 1);
    }
  }
}
int main() {
  // 6 numbers from the alphabet a that sum to 22
  n = 9;
  back(0);
  return 0;
}