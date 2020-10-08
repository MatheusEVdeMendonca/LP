#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  int a, b, j, k, sum = 285, cnt = 0;
  int matriz[9][9];
  string s = "";

  cin >> a;
  while(a--) {
    for(b= 0; b < 9; b++ )
      for(j = 0; j < 9; j++)
        cin >> matriz[b][j];

        int sl[9], sc[9], sm[3][3];

        for (b= 0; b < 9; b++ )
          sl[b]= sc[b]=sm[b/3][b%3]=0;

        for (b= 0; b< 9; b++) {
          for (j = 0; j < 9; j++) {
            k = matriz[b][j];
            k *= k;
            sl[b] += k;
            sc[j] += k;
            sm[b/3][j/3] += k;

            if (b== 8 && sc[j] != sum)
              break;
          }

          if (sl[b]  != sum)
            break;
        }

        if(s == "")
          for (b= 0; b< 3; b++)
            for (j = 0; j < 3; j++)
              if (sm[b][j] != sum)
                s = "NAO";

        if(s == "")
          s  = "SIM";

        cnt++;
        cout << "Instancia " << cnt << endl << s << endl << endl;
        s = "";
  } 
  return 0;
    }
