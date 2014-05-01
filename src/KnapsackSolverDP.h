#ifndef KNAPSACK_SOLVER_DP_
#define KNAPSACK_SOLVER_DP_

#include <vector>

#include "Object.h"
#include "KnapsackResult.h"
#include "KnapsackSolver.h"

using namespace std;

class KnapsackSolverDP : public KnapsackSolver {
  virtual KnapsackResult find_optimal_knapsack(vector<Object> objects, int K);
};

#endif // KNAPSACK_SOLVER_DP_
