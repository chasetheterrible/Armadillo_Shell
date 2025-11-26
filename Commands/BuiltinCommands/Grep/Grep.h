#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../../Command.h"
#include "Manual.h"

// ===================={ Grep Command }====================

class Grep : public Command<Grep> {
  std::vector<std::string> tokenizedCommand;

public:
  explicit Grep(std::vector<std::string>& tokens) {
    tokenizedCommand = tokens;
  }

  static std::string returnManText() {
    return GrepManual;
  }

  static bool validateSyntax(std::vector<std::string>& tokens) {
    // grep <pattern> <filename>
    return tokens.size() == 2;
  }

  std::vector<std::string> executeCommand() override {
    if (!validateSyntax(tokenizedCommand)) {
      return { "grep: usage: grep <pattern> <filename>", "400" };
    }

    std::string pattern = tokenizedCommand[0];
    std::string file = tokenizedCommand[1];

    std::ifstream in(file);
    if (!in.is_open()) {
      return { "grep: could not open file: " + file, "404" };
    }

    std::string line;
    std::string output;

    while (std::getline(in, line)) {
      if (line.find(pattern) != std::string::npos) {
        output += line + "\n";
      }
    }

    // If no matches, still return 200 but empty output
    if (output.empty()) {
      return { "", "200" };
    }

    return { output, "200" };
  }

private:
  // put your own method definitions here
};