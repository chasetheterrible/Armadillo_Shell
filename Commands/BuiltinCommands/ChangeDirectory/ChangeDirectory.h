#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "../../Command.h"
#include "Manual.h"



// ===================={ Change Directory Command }====================
// TODO: add documentation to the manual file so James knows what flags and other info you implemented


class ChangeDirectory : public Command<ChangeDirectory> { // Command class needs to be inherited in order to work!!!
  std::vector<std::string> tokenizedCommand;
  // add more class variables as needed.

public:
  explicit ChangeDirectory(std::vector<std::string>& tokens) {
    tokenizedCommand = tokens; // should save arguments in the order they were passed in
  }

  static std::string returnManText() {
    return ChangeDirectoryManual;
  }

  static bool validateSyntax(std::vector<std::string>& tokens) {
    // TODO: implement
    // this should be a simple validation so it can be used when validating
    // commands that are getting piped. More thorough validations can be done
    // in the execute command itself.
    // tokens should contain all of the command inputs the user provided
    // in order. However, It will not contain the command at the start.
    return toekns.size() <= 1;
  }

  std::vector<std::string> executeCommand() override {
    // TODO: implement
    // Will assume validateSyntax was already called, but add error handling just in case
    if (!validateSyntax(tokenizedCommand)) {
      return { "cd: too many areguments", "400"};
    }

    const char* targetPath = nullptr;

    if (tokenizedCommand.empty()) {
      targetPath = std::getenv("HOME");
      if (!targetPath) {
        return { "cd: HOME not set", "500" }
      }
    }
    else {
      targetPath = tokenizedCommand[0].c_str();
    }


    if (chdir(targetPath) != 0) {
      if (!tokenizedCommand.empty()) {
        return { "cd: not such file or directory:", + tokenizedCommand[0], "404"};
      } else {
        return { "cd: failed to change directory", "500"}; 
      }
    }

  

private:
  // put your own method definitions here
};

