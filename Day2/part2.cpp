#include <iostream>
#include <string>
using namespace std;

struct password{
  int least, most;
  char c;
  string str;

  password(string &str){
    int idx = 0;
    least = 0; most = 0;
    for(; str[idx] != '-'; ++idx)
      least = least * 10 + str[idx] - '0';
    for(++idx; str[idx] != ' '; ++idx)
      most = most * 10 + str[idx] - '0';
    c = str[++idx];
    this->str = "";
    for(int j = idx + 2; j < str.size(); ++j)
      this->str += str[j];
  }

  bool check(){
    int cnt = 0;
    for(int j = 0; j < str.size(); ++j)
      if(str[j] == c) ++cnt;
    if(cnt >= least && cnt <= most)
      return true;
    return false;
  }

  bool check2(){
    int cnt = 0;
    cnt += least < str.size() ? (str[least] == c) : 0;
    cnt += most < str.size() ? (str[most] == c) : 0;
    return cnt == 1;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("./input.txt", "r", stdin);
  string line;
  int ans = 0;
  while(getline(cin, line)){
    password pw(line);
    ans += pw.check2();
  }
  cout << ans << "\n";
  return 0;
}