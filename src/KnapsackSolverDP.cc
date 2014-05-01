#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <vector>
#include <set>
#include <algorithm>

#include "KnapsackResult.h"
#include "KnapsackSolverDP.h"

using namespace std;

const int kMaxN = 400;
const int kMaxK = 1000000;

static void check_input_size(int N, int K) {
  if (N > kMaxN) {
    fprintf(stderr, "N = %d, K = %d\n", N, K);
    assert(N <= kMaxN);
  }

  if (K > kMaxK) {
    fprintf(stderr, "N = %d, K = %d\n", N, K);
    assert(K <= kMaxK);
  }
}

static vector<bool> get_arrange(int D[kMaxN][kMaxK + 1], const vector<Object>& objects, int obj_i, int obj_w) {
  set<int> s;
  {
    int i = obj_i;
    int w = obj_w;
    
    for (;w != 0 && i >= 0; i--) {
      if (i == 0 || D[i][w] != D[i-1][w]) {
        w -= objects[i].weight;
        s.insert(i);
      }
    }
  }

  int N = objects.size();
  
  vector<bool> res;
  for (int i = 0; i < N; i++) {
    res.push_back(s.count(i) ? 1 : 0);
  }

  return res;
}

KnapsackResult KnapsackSolverDP::find_optimal_knapsack(vector<Object> objects, int K) {
  static int D[kMaxN][kMaxK + 1];

  int N = objects.size();

  check_input_size(N, K);

  int obj_v = objects[0].value;
  int obj_i = 0;
  int obj_w = objects[0].weight;
  int max_w = objects[0].weight;
  
  D[0][0] = 0;
  D[0][objects[0].weight] = objects[0].value;

  for (int i = 1; i < N; i++) {
    int v = objects[i].value;
    int w = objects[i].weight;

    max_w = min(max_w + w, K);

    for (int j = max_w; j >= 0; j--) {
      D[i][j] = D[i-1][j]; 

      if (j < w || D[i-1][j - w] == -1) continue;

      if (D[i][j] == -1 || D[i][j] < D[i-1][j - w] + v) {
        D[i][j] = D[i-1][j - w] + objects[i].value;

        if (obj_v < D[i][j]) {
          obj_v = D[i][j];
          obj_w = j;
          obj_i = i;
        }
      }
    }
  }

  vector<bool> arrange = get_arrange(D, objects, obj_i, obj_w);
  
  KnapsackResult result(true, obj_v, arrange);

  return result;
}

