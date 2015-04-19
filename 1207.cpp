//UVa 1207 AGTC
//http://uva.onlinejudge.org/external/12/1207.pdf

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Calculate edit distance between 2 strings
int edit(string s, int m, string t, int n)
{
  int E[m+1][n+1];
  int delta;
  for (int i = 0; i <= m; i++) {
    E[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    E[0][j] = j;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      delta = (s[i-1] != t[j-1]) ? 1 : 0;
      E[i][j] = min(E[i-1][j]+1, 
                min(E[i][j-1]+1, 
                    E[i-1][j-1] + delta));
    }
  }
  return E[m][n];
}


int main(void)
{
  int sLen, tLen;
  string s, t;
  while (cin >> sLen >> s >> tLen >> t) {
    cout << edit(s, sLen, t, tLen) << endl;
  }
  return 0;
}
