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

		std::string str(length, 0);
		for (auto& it : str) {
			it = alpha_numeric[distribution(generator)];
		}

		return str;
	}

	void Initialize() {
		std::string title{ random_string(15) };
		//std::cout<<"Initializing...\n";

		SetConsoleTitle((LPCWSTR)title.c_str());
	}

	void DrawMenu() {
		system("CLS");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 13);
		std::cout << "private osu! cheat\n";
		std::cout << "Features:\n";
		std::cout << "-------------------------------------\n";
		std::cout << "Disable score submission []\n";
	}
