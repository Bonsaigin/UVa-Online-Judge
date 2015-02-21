/* Bit Maps
 * http://uva.onlinejudge.org/external/1/183.pdf
 */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int printCount = 0;

struct bitmap
{
  bool bitmap[200][200];
  int rowDim, colDim;
};

void readBitmap(bitmap *a)
{
  char ch;
  for (int i = 0; i < a->rowDim; i++) {
    for (int j = 0; j < a->colDim; j++) {
      scanf(" %c", &ch);
      a->bitmap[i][j] = ch - '0';
    }
  }
}

void printBitmap(bitmap *a)
{
  int count = 0;
  for (int i = 0; i < a->rowDim; i++) {
    for (int j = 0; j < a->colDim; j++) {
      if (printCount % 50 == 0 && printCount != 0) printf("\n");
      printCount++;
      putchar(a->bitmap[i][j]?'1':'0');
    }
  }  
}

void decomp(const bitmap *a, int x, int y, int row, int col)
{
  if ( row < 1 || col < 1) return;
  bool orig = a->bitmap[x][y];

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (orig != a->bitmap[x+i][y+j]) {
      if (printCount % 50 == 0 && printCount != 0) printf("\n");
        printCount++;
        putchar('D');
        decomp(a, x, y, (row+1) / 2, (col+1) / 2);
        decomp(a, x, y+(col+1)/2,(row+1)/2, col-(col+1)/2);
        decomp(a, x+(row+1)/2,y,row-(row+1)/2,(col+1)/2);
        decomp(a, x+(row+1)/2,y+(col+1)/2,row-(row+1)/2,col-(col+1)/2);
        return;
      }
    }
  }
  if (printCount % 50 == 0 && printCount != 0) printf("\n");
  printCount++;
  putchar(orig?'1':'0');
}

void decode(bitmap *a, int x, int y, int row, int col)
{
  if ( row < 1 || col < 1 ) return;
  char ch;
  scanf(" %c", &ch);
  
  if (ch == '1' || ch == '0') {
    for (int i = 0; i < a->rowDim; i++) {
      for (int j = 0; j < a->colDim; j++) {
        a->bitmap[x+i][y+j] = ch - '0'; 
      }
    }  
  }
  else { //ch == 'D'
    decode(a, x, y, (row+1)/2,(col+1)/2);
    decode(a, x, y+(col+1)/2,(row+1)/2,col-(col+1)/2);
    decode(a, x+(row+1)/2,y,row-(row+1)/2,(col+1)/2);
    decode(a, x+(row+1)/2,y+(col+1)/2,row-(row+1)/2,col-(col+1)/2);
  }
}

int main(void)
{
  char mapType;
  int numRows, numColumns;
  bitmap bmp;
  
  //Read input
  while (scanf(" %c %d %d", &mapType, &bmp.rowDim, &bmp.colDim) == 3) {
    printf("%c%4d%4d\n", mapType=='B'?'D':'B', bmp.rowDim, bmp.colDim);
    printCount = 0;
    if (mapType == 'B') {
      readBitmap(&bmp);
      decomp(&bmp, 0, 0, bmp.rowDim, bmp.colDim);
      printf("\n");
    }
    else { //mapType == 'D'
      decode(&bmp, 0, 0, bmp.rowDim, bmp.colDim);
      printBitmap(&bmp);
      printf("\n");
    }
  }
  return 0;
}
