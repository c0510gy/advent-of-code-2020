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

bool checkValid(string key, string value){
  if(key == "byr"){
    int v = stoi(value);
    return v >= 1920 && v <= 2002;
  }else if(key == "iyr"){
    int v = stoi(value);
    return v >= 2010 && v <= 2020;
  }else if(key == "eyr"){
    int v = stoi(value);
    return v >= 2020 && v <= 2030;
  }else if(key == "hgt"){
    int v = 0;
    for(int j = 0; j < value.size() - 2; ++j)
      v = v * 10 + value[j] - '0';
    if(value.back() == 'm')
      return v >= 150 && v <= 193;
    else
      return v >= 59 && v <= 76;
  }else if(key == "hcl"){
    if(value.size() != 7 || value[0] != '#')
      return false;
    for(int j = 1; j < value.size(); ++j){
      if((value[j] >= '0' && value[j] <= '9') || (value[j] >= 'a' && value[j] <= 'z')){}
      else return false;
    }
    return true;
  }else if(key == "ecl"){
    return (value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth");
  }else if(key == "pid"){
    if(value.size() != 9) return false;
    for(int j = 0; j < value.size(); ++j){
      if(value[j] < '0' || value[j] > '9')
        return false;
    }
    return true;
  }else if(key == "cid"){
    return true;
  }
  return false;
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
      if(!checkValid(k, pass[k])){
        sat = false;
        break;
      }
    }
    ans += sat;
  }
  cout << ans << "\n";
  return 0;
}