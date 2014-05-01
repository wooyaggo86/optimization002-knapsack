#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <vector>
#include <set>
#include <algorithm>

#include "Object.h"
#include "KnapsackSolver.h"
#include "KnapsackSolverDP.h"
#include "KnapsackResult.h"

using namespace std;

int main(int argc, char* argv[]) {
  freopen(argv[1], "r", stdin);
  
  int N, K;
  scanf("%d %d", &N, &K);
  
  vector<Object> objects;
  for (int i = 0; i < N; i++) {
    int value, weight;
    scanf("%d %d", &value, &weight);

    Object object(value, weight);
    objects.push_back(object);
  }

  KnapsackSolver* knapsack_solver = new KnapsackSolverDP();
  
  KnapsackResult knapsack_result = knapsack_solver->find_optimal_knapsack(objects, K);
  
  knapsack_result.print();

  delete knapsack_solver;

  return 0;
}
