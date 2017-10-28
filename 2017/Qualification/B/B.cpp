/**
 * Google Code Jam 2017 - Qualification - B
 * @author Lukas Botsch <lukas.botsch@gmail.com>
 *
 * Notes:
 *
 * Complexity: O(log10(N))
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
#define tos(v) to_string(v)
#define dtoi(d) (d - '0')
#define itod(i) ((char)((int)i + '0'))

#define DEBUG false
#define debug if(DEBUG) cerr

/**
 * Process one test case and output result.
 * @return Result
 */
static string process() {
  // Parse test case input
  string number, output;
  cin >> number;
  size_t s = number.length();
  int min = 0;

  debug << number;

  FOR(i, s) {
    int d = dtoi(number[i]);
    if (d < min) {
      // decrement backwards while keeping everything tidy
      int j = output.length() - 1;
      while (j > 0 && output[j] == output[j-1]) {
        j--;
      }
      output.erase(j+1, string::npos);
      output[j]--;
      break;
    }
    min = d;

    output.append(tos(d));
    debug << " => " << output;
  }

  // Fill with 9's
  debug << " => " << output;
  size_t fill = s-output.length();
  FOR(i, fill) {
    output.append("9");
  }
  debug << " => " << output;

  // Remove leading 0
  if (output[0] == '0') output.erase(0, 1);
  debug << " => " << output << endl;

  if (DEBUG) {
    // Test response:
    min = 0;
    FOR(i, output.length()) {
      int d = dtoi(output[i]);
      if (d < min)
        debug << "Error: " << output << "is not tidy!" << endl;
      min = d;
    }
  }

  return output;
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
