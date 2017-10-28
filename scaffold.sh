#!/bin/bash

E_BADARGS=85

if [ $# -lt 3 ]; then
    echo "Usage: `basename $0` year round name"
    exit $E_BADARGS
fi

name=`echo $3 | awk '{print toupper($0)}'`
path=$1/$2/$name

if [ ! -d "$path" ]; then
    mkdir -p "$path"
fi

cat <<EOF > "$path/$name.cpp"
/**
 * Google Code Jam $1 - $2 - $name
 * @author Lukas Botsch <lukas.botsch@gmail.com>
 *
 * Notes:
 *
 * Complexity:
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

/**
 * Process one test case and output result.
 * @return Result
 */
static string process() {
  // Parse test case input
  string pcs;
  size_t k;
  cin >> pcs >> k;

  // TODO: Implement solution here!

  return tos(0);
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
EOF

cat <<EOF > "$path/Makefile"
CC=g++
CFLAGS=--std=c++11
TARGET=$name

SOURCE = $name.cpp

all: small large
	@true

clean:
	@-rm -f \$(TARGET) *.out

\$(TARGET):
	@\$(CC) \$(CFLAGS) -o \$@ \$(SOURCE)

small: \$(TARGET)
	@./\$(TARGET) < \$(TARGET)-small-practice.in > \$(TARGET)-small-practice.out

large: \$(TARGET)
	@./\$(TARGET) < \$(TARGET)-large-practice.in > \$(TARGET)-large-practice.out
EOF
