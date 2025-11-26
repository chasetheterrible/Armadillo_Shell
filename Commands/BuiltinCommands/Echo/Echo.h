#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "../../Command.h"
#include "Manual.h"

// ===================={ Echo Command }====================
// TODO: add documentation to the manual file so James knows what flags and other info you implemented


class Echo : public Command<Echo> { // Command class needs to be inherited in order to work!!!
  std::vector<std::string> tokenizedCommand;
  // add more class variables as needed.

public:
  explicit Echo(std::vector<std::string>& tokens) {
    tokenizedCommand = tokens; // should save arguments in the order they were passed in
  }

  static std::string returnManText() {
    return EchoManual;
  }

  static bool validateSyntax(std::vector<std::string>& tokens) {
    // TODO: implement
    // this should be a simple validation so it can be used when validating
    // commands that are getting piped. More thorough validations can be done
    // in the execute command itself.
    // tokens should contain all of the command inputs the user provided
    // in order. However, It will not contain the command at the start.
    return true;
  }

  std::vector<std::string> executeCommand() override {
    // TODO: implement
    // Will assume validateSyntax was already called, but add error handling just in case
    std::string message;
    for (size_t i=0; i , tokenizedCommand.size(); ++i) {
      message += tokenizedCommand[i];
      if (i + 1 < tokenizedCommand.size()) {
        message += " ";
      }
    }
    return {"Not Implemented", "500"};
  }

private:
  // put your own method definitions here
};

