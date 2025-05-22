#include <stdio.h>

int x[6], n;

void show() {
  for (int j = 0; j < 6; j++)
    printf("%d ", x[j]);
  putchar('\n');
}

int ok(int k) {
  int odds = 0;
  int evens = 0;
  for (int i = 0; i <= k; i++) {
    if (x[i] % 2 == 0)
      evens++;
    else
      odds++;
    if (odds > 3 || evens > 3) {

      return 0;
    }
  }

  return 1;
}

int done(int k) { return (k == 5); }

void back(int k) {
  for (int i = 0; i < n; i++) {
    x[k] = i;
    if (ok(k)) {
      if (done(k))
        show();
      else
        back(k + 1);
    }
  }
}
int main() {
  // generate all numbers with 6 digits of which exactly 3 are odd and 3 are
  // even
  n = 10;
  back(0);
  return 0;
}