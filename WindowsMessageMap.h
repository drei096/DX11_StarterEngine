#pragma once
#include <unordered_map>
#include "CustomWindowsH.h"
class WindowsMessageMap
{
public:
	WindowsMessageMap() noexcept;

public:
	std::string operator()(DWORD msg, LPARAM lp, WPARAM wp) const noexcept;

private:
	std::unordered_map<DWORD, std::string> map;
};

