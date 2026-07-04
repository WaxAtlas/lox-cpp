/* I am stopping here for now. I need to start a new repo and commit something
 * before I go too much further. */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void run(std::string source) {
  std::cout << "source == " << source << std::endl;
}

void runFile(std::string arg1) {
  std::ifstream f(arg1);
  std::string str{};
  if (f) {
    std::ostringstream ss;
    ss << f.rdbuf();
    str = ss.str();
  } else {
    std::cerr << "Error: Could not open the file.\n";
  }
  run(str);
}

void runPrompt() {}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cerr << "Usage: cpplox [script]\n";
    return 1;
  } else if (argc == 2) {
    runFile(std::string{argv[1]});
  } else {
    runPrompt();
  }
}
