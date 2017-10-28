/**
 * Google Code Jam 2017 - Qualification - A
 * @author Lukas Botsch <lukas.botsch@gmail.com>
 *
 * Notes:
 * - Flipping a pancake 2*N times is equivalent to not flipping it
 * - Flipping a pancake 2*N+1 times is equivalent to flipping it once
 * - The order in which pancakes are flipped is irrelevant
 *
 * Complexity: O(N)
 */

#include <string>
#include <iostream>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define FOR(i,stop) for(size_t i=0;i<stop;++i)
#define v vector
#define l list

const string IMP = "IMPOSSIBLE";
const char P = '+';

/**
 * Process one test case.
 * @param input Start face of each pancake +/-
 * @param k Size of the flipper
 * @return Number of flips or 'IMPOSSIBLE'
 */
static string process() {
  // Parse test case input
  string pcs;
  size_t k;
  cin >> pcs >> k;

  size_t s = pcs.size();

  // O(n)
  bool f = false;
  l<size_t> dec;
  size_t fc = 0;
  FOR(i, s-k+1) {
    if (dec.size() > 0 && i >= dec.front()) {
      dec.pop_front();
      f = !f;
    }
    // Taking into account all flips, is the pancake on the right side?
    if ((pcs[i] == P) ^ f) {
      continue;
    }
    // So we had to flip the pancake.
    fc++;
    // Flip the next k pancakes.
    dec.push_back(i+k);
    f = !f;
  }
  // Check remaining pancakes
  FOR(i, k-1) {
    if (dec.size() > 0 && s-k+1+i >= dec.front()) {
      dec.pop_front();
      f = !f;
    }
    // Taking into account all flips, is the pancake on the right side?
    if (!((pcs[s-k+1+i] == P) ^ f)) {
      return IMP;
    }
  }
  // All remaining pancakes were on the right side.
  return to_string(fc);
}

/**
 * Main loop. Takes input from stdin and outputs result to stdout
 * Run: ./a < cases.in > cases.out
 */
int main() {
  size_t num_cases;
  cin >> num_cases;
  auto ts = high_resolution_clock::now();

  FOR (i, num_cases) {
    // Output result
    cout << "Case #" << (i+1) << ": " << process() << endl;
  }

  auto d = duration_cast<microseconds>(high_resolution_clock::now()-ts).count();
  cerr << "Done. " << num_cases << " cases processed in " << d << "us (" << (d/num_cases) << "us/case)." << endl;
  return 0;
}
