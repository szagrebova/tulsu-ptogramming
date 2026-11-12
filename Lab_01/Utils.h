#pragma once
#include <string>

void clearInput();
int readInt(const std::string& prompt);
int readPositiveInt(const std::string& prompt);
std::string readNonEmptyLine(const std::string& prompt);
int readIntInRange(const std::string& prompt, int min, int max);