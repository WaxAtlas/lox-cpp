/* I am stopping here for now. I need to start a new repo and commit something
 * before I go too much further. */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool hadError = false;

void report(int line, std::string where, std::string message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message
            << std::endl;
  hadError = true;
}

void error(int line, std::string message) { report(line, "", message); }

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

void runPrompt() {
  while (true) {
    std::cout << "> ";
    std::string line{};
    if (!std::getline(std::cin, line)) {
      break;
    }
    run(line);
    hadError = false;
  }
}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cerr << "Usage: lox-cpp [script]\n";
    std::exit(64);
  } else if (argc == 2) {
    runFile(std::string{argv[1]});
  } else {
    std::cout << "Running prompt" << std::endl;
    runPrompt();
  }
}
