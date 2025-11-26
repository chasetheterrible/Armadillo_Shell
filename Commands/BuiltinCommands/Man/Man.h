#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "../../Command.h"
#include "Manual.h"

// ===================={ Man Command }====================

class Man : public Command<Man> {
  std::vector<std::string> tokenizedCommand;

public:
  explicit Man(std::vector<std::string>& tokens) {
    tokenizedCommand = tokens; // arguments after "man"
  }

  static std::string returnManText() {
    return ManManual;   // description of the man command itself
  }

  static bool validateSyntax(std::vector<std::string>& tokens) {
    // Require exactly one argument: man <command>
    return tokens.size() == 1;
  }

  std::vector<std::string> executeCommand() override {
    if (!validateSyntax(tokenizedCommand)) {
      return { "man: usage: man <command>", "400" };
    }

    std::string topic = tokenizedCommand[0];
    std::string manualText;

 
    if (topic == "man") {
      manualText = ManManual;
    } else if (topic == "cd" || topic == "changedirectory") {
      manualText = ChangeDirectoryManual;
    } else if (topic == "ls" || topic == "list") {
      manualText = ListManual;
    } else if (topic == "cp" || topic == "copy") {
      manualText = CopyManual;
    } else if (topic == "mkdir" || topic == "makedirectory") {
      manualText = MakeDirectoryManual;
    } else if (topic == "echo") {
      manualText = EchoManual;
    } else if (topic == "date") {
      manualText = DateManual;
    } else if (topic == "grep") {
      manualText = GrepManual;
    }
    // TODO: add more commands here as you implement them
    else {
      return { "man: no manual entry for " + topic, "404" };
    }

    return { manualText, "200" };
  }

private:
  // helper methods if needed
};