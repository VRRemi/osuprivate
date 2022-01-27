#include <iostream>
#include <Windows.h>
#include <vector>
#include <limits>
#include <TlHelp32.h>
#include <cstdint>
#include "memory.hpp"
#include "process.hpp"
#include "initialize.hpp"
#include "sigs.hpp"
#include "writereadFunc.hpp"
#include "hacks.hpp"
#include <stdlib.h>
int main()
{
	bool isScore{ false }, isTaikoMania{ false };
	init::Initialize();
