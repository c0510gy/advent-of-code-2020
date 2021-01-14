#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("./input.txt", "r", stdin);
  int ans = 0, x = 0, y = 0;
  for(string line; getline(cin, line); ++y, x += 3){
    int n = line.size();
    if(line[x % n] == '#')
      ++ans;
  }
  cout << ans << "\n";
  return 0;
}