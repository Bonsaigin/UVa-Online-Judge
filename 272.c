/* TEX Quotes */
#include <stdio.h>

int main(void)
{
  int c;
  int in_quote = 0;

  while ((c = getchar()) != EOF) {
    if(c == '\"') {
      if(in_quote) {
        putchar('\'');
        putchar('\'');
        in_quote = 0;
      }
      else {
        putchar('\`');
        putchar('\`');
        in_quote = 1;
      }
    }
    else {
      putchar(c);
    }
  }
  return 0;
}
