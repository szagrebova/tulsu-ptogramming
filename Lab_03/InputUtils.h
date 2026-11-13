#pragma once
#include <string>

void clearInput();
int readInt(const std::string& prompt);
int readIntInRange(const std::string& prompt, int lo, int hi);
std::string readLine(const std::string& prompt);