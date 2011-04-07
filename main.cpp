#include <string.h>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())

#define for0n(i,n) for(i=0;i<n;i++)
#define for1n(i,n) for(i=1;i<=n;i++)
#define forn(i,j,n) for(i=j;i<n;i++)
#define ZERO(arr) for(int CNT=0;CNT<sizeof(arr);CNT++){arr[CNT]=0;}

const int MAX = 1000000;
const int inf = 2100000000;

ofstream debug("debug.txt", fstream::trunc);

//
// Add variables here.
//
int c, i, j, k, l;

class BeautifulCrossword {
public:
  class node {
    public:
      int value;
      vector<int>& wt;
      vector<string>& wds;
      string wordUsed;
      char soln[100][100];

      node(int N, vector<int>& weights);
      node(const node& copy);
  };


  vector< set < string> > wordSets;

  BeautifulCrossword();

  vector<string> generateCrossword(int N, vector<string> words, vector<int> weights);
};

BeautifulCrossword::BeautifulCrossword() :
  wordSets(30)
{
}

vector<string>
BeautifulCrossword::generateCrossword(int N, vector<string> words, vector<int> weights)
{
  vector<string> solution(N);
  int i, j, k;
  for0n(i, N) {
    solution[i] = string(N, '.');
  }
  int maxLength = 3;
  int deleted = 0;
  for0n(i, words.size()) {
    debug << words[i] << endl;
    if ((words[i].length() > maxLength) &&
        (words[i].length() <= N)) {
      maxLength = words[i].length();
    }
    if (words[i].length() > N) {
      deleted++;
    } else {
      wordSets[words[i].length()].insert(words[i]);
    }
  }

  for0n(i, maxLength) {
    debug << "Length " << i << ": " << wordSets[i].size() << endl;
  }
  debug << "Max length: " << maxLength << endl;
  debug << "Deleted: " << deleted << endl;

  return solution;
}

int main (int argc, char **argv)
{
  int i;
  int N;
  int W;
  cin >> N >> W;
  vector<string> words(W);
  vector<int> weights(4);

  for0n(i, W) {
    cin >> words[i];
  }
  for0n(i, 4) {
    cin >> weights[i];
  }

  BeautifulCrossword solver;
  vector<string> ret = solver.generateCrossword(N, words, weights);

  for0n(i, N) {
    debug << ret[i] << endl;
    cerr << ret[i] << endl;
    cout << ret[i] << endl;
  }

  return 0;
}
