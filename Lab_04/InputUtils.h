#pragma once
#include <string>

void clearInput();
int readInt(const std::string& prompt);
int readIntInRange(const std::string& prompt, int lo, int hi);
int readNonZeroInt(const std::string& prompt);