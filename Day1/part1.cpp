#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("./input.txt", "r", stdin);
  vector<int> arr;
  for(int t; cin >> t;){
    arr.push_back(t);
  }
  sort(arr.begin(), arr.end());
  for(int j = 0; j < arr.size(); ++j){
    int num1 = arr[j];
    int diff = 2020 - num1;
    if(binary_search(arr.begin(), arr.end(), diff))
      cout << num1 << " " << diff << " " << num1 * diff << "\n";
  }
  return 0;
}