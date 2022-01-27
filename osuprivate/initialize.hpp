#pragma once
#include "memory.hpp"
#include "process.hpp"
#include <random>
#include <string>
#include <stdlib.h>

namespace init {
	std::string random_string(const int length) {
		const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

