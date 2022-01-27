#pragma once
#include "memory.hpp"
#include "process.hpp"
#include <random>
#include <string>
#include <stdlib.h>

namespace init {
	std::string random_string(const int length) {
		const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

		std::default_random_engine generator{ std::random_device{}() };
		const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

