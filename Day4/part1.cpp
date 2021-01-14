#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void parse(map<string, string> &pass, string str){
  string key = "", value = "";
  bool isKey = true;
  for(int j = 0; j < str.size(); ++j){
    if(str[j] == ' '){
      isKey = true;
      pass[key] = value;
      key = "";
      value = "";
      continue;
    }else if(str[j] == ':'){
      isKey = false;
      continue;
    }
    if(isKey)
      key += str[j];
    else
      value += str[j];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("./input.txt", "r", stdin);
  vector<string> infostr(1, "");
  for(string line; getline(cin, line);){
    if(line == ""){
      infostr.push_back("");
      continue;
    }
    line += " ";
    infostr[infostr.size() - 1] += line;
  }
  vector<string> keys({
    "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid",
  });
  int ans = 0;
  for(int j = 0; j < infostr.size(); ++j){
    map<string, string> pass;
    parse(pass, infostr[j]);
    bool sat = true;
    for(string &k: keys){
      if(pass.find(k) == pass.end()){
        sat = false;
        break;
      }
    }
    ans += sat;
  }
  cout << ans << "\n";
  return 0;
}