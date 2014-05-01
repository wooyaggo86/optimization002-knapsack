#ifndef KNAPSACK_SOLVER_
#define KNAPSACK_SOLVER_

#include <vector>

#include "Object.h"
#include "KnapsackResult.h"

using namespace std;

class KnapsackSolver {

public:
  virtual KnapsackResult find_optimal_knapsack(vector<Object> objects, int K) = 0;
};

#endif // KNAPSACK_SOLVER_
