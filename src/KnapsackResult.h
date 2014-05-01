#ifndef KNAPSACK_RESULT_
#define KNAPSACK_RESULT_

#include <vector>

using namespace std;

class KnapsackResult {

private:
  bool is_optimal;
  int cost;
  vector<bool> arrange;

public:  
  KnapsackResult(bool is_optimal, int cost, const vector<bool>& arrange);

  void print(void) const;
};

#endif // KNAPSACK_RESULT_
