#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long int lli;

lli traverse(vector<string> &m, int dx, int dy){
  lli cnt = 0;
  for(int x = 0, y = 0; y < m.size(); x += dx, y += dy){
    int n = m[y].size();
    if(m[y][x % n] == '#')
      ++cnt;
  }
  return cnt;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("./input.txt", "r", stdin);
  vector<string> m;
  for(string line; getline(cin, line); ){
    m.push_back(line);
  }
  int slopes[5][2] = {
    {1, 1},
    {3, 1},
    {5, 1},
    {7, 1},
    {1, 2},
  };
  lli ans = 1;
  for(int j = 0; j < 5; ++j){
    ans *= traverse(m, slopes[j][0], slopes[j][1]);
  }
  cout << ans << "\n";
  return 0;
}