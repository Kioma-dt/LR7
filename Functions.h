#pragma once
#include "Functions.cpp"

int CharToInt(char);
char IntToChar(int);
unsigned long long CheckUnsigned();
std::string CheckSystem(int);

std::string MirrorNumber(std::string);
std::string AddZeroes(std::string, size_t);
std::string DeleteZeroes(std::string);
std::string AddMinus(std::string);
bool Greater(std::string, std::string);

std::string SumNumbers(std::string, std::string, int);
std::string SubstractNumber(std::string, std::string, int);
std::string DivideByTwo(std::string);

std::string DirectToReverse(std::string);
std::string DirectToAdditional(std::string);
std::string DecToDirect(std::string, bool);

long long Multiplying(long long, long long);
bool checkDivisible(long long, int, int, int, int);

void OutputBarrels(int, int);
char EnterSlavesDay(int);
int FindBarrel(std::string);

void repeat();