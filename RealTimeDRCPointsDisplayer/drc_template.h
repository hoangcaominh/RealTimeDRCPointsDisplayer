#pragma once

// unsigned long long for convenience
typedef unsigned long long ull;
// unsigned long for convenience (PC-98 only)
typedef unsigned long ul;

template <typename T, typename Ex = T>
struct difficulty
{
	T easy;
	T normal;
	T hard;
	T lunatic;
	// Default is T, unless it's HSiFS
	Ex extra;
};

template <typename T>
// For games without Extra difficulty
struct difficulty_noextra
{
	T easy;
	T normal;
	T hard;
	T lunatic;
};

template <typename T>
// For PCB
struct difficulty_withphantasm
{
	T easy;
	T normal;
	T hard;
	T lunatic;
	T extra;
	T phantasm;
};
