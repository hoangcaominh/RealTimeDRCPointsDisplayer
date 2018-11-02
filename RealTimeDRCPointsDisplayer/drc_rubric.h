#pragma once

#include "drc_template.h"

// survival

struct drc_survival
{
	unsigned base;
	float exp;
	unsigned miss;
	unsigned firstBomb;
	unsigned bomb;
};

// survival struct exclusive for PoDD & PoFV
struct drc_survival_phantasmagoria
{
	unsigned base;
	unsigned min;
	unsigned lives;
	unsigned noBombBonus;
};

// survival struct exclusive for HSiFS
struct drc_survival_hsifs
{
	unsigned base;
	float exp;
	unsigned miss;
	unsigned firstBomb;
	unsigned bomb;
	unsigned firstRelease;
	float release;
};

// number of last spells in IN
struct last_spell_final
{
	unsigned finalA;
	unsigned finalB;
};

// scoring

struct drc_scoring
{
	unsigned base;
	float exp;
};
