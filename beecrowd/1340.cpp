#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main () {
  int len;
  while (cin >> len) {
    vector<int> nums;
    bool is_queue = true;
    bool is_stack = true;
    bool is_priority = true;

    for (int i = 0; i < len; i++) {
      int action, num;
      cin >> action;
      cin >> num;

      if (action == 1) {
        nums.push_back(num);
      } else {
        if (nums.empty()) {
          is_queue = false;
          is_stack = false;
          is_priority = false;
          continue;
        }

        auto it = find(nums.begin(), nums.end(), num);
        if (it == nums.end()) {
          is_queue = false;
          is_stack = false;
          is_priority = false;
          continue;
        }
        
        if (is_queue && num != nums.front())
          is_queue = false;
        
        if (is_priority) {
            auto max_it = max_element(nums.begin(), nums.end());
            if (num != *max_it)
                is_priority = false;
        }

        if (is_stack && num != nums.back())
          is_stack = false;
        
        nums.erase(it);
      }
    }

    int true_count = is_stack + is_queue + is_priority;

    if (true_count > 1)
      cout << "not sure" << endl;
    else if (true_count == 0)
      cout << "impossible" << endl;
    else if (is_stack)
      cout << "stack" << endl;
    else if (is_queue)
      cout << "queue" << endl;
    else 
      cout << "priority queue" << endl;
  }

  return 0;
}