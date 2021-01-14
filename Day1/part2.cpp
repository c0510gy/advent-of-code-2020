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
    for(int i = j + 1; i < arr.size() && num1 + arr[i] <= 2020; ++i){
      int num2 = arr[i];
      int diff = 2020 - num1 - num2;
      if(binary_search(arr.begin(), arr.end(), diff))
        cout << num1 << " " << num2 << " " << diff << " " << num1 * num2 * diff << "\n";
    }
  }
  return 0;
}