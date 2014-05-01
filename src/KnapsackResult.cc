#include <stdio.h>
#include <vector>

#include "KnapsackResult.h"

using namespace std;

KnapsackResult::KnapsackResult(bool is_optimal, int cost, const vector<bool>& arrange) {
  this->is_optimal = is_optimal;
  this->cost = cost;
  this->arrange = arrange;
}

void KnapsackResult::print(void) const {
  printf("%d %d\n", cost, is_optimal);
  for (int i = 0; i < (int)arrange.size(); i++) {
    printf("%d ", arrange[i]);
  }
  printf("\n");
}


