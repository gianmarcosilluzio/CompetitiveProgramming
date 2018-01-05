#include <iostream>
#include <string.h>

using namespace std;

int main() {
  char s[100011], *p = s+100010;
  *p = 0;
  cin >> s;
  for (int i = strlen(s)-1, m = i; i+1; i--){
    if (s[i] >= s[m]){
      *--p=s[i];
      m=i;
    }
  }
  cout << p;
  return 0;
}
