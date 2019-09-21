#pragma once

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <sstream>

void DebugOut(wchar_t *fmt, ...);
using namespace std;

//Show and save game logs
#define GAMELOG(s,...) printLog(s , ##__VA_ARGS__)

void printLog(const LPCSTR s, ...);