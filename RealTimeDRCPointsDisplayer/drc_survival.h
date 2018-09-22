#pragma once

struct drc_survival
{
    unsigned base;
    float exp;
    unsigned miss;
    unsigned firstBomb;
    unsigned bomb;
};

struct drc_diff_survival
{
    drc_survival easy;
    drc_survival normal;
    drc_survival hard;
    drc_survival lunatic;
    drc_survival extra;
};

// survival struct exclusive for PoDD & PoFV
struct drc_phantasmagoria
{
    unsigned base;
    unsigned min;
    unsigned lives;
    unsigned noBombBonus;
};

struct drc_diff_phantasmagoria
{
    drc_phantasmagoria easy;
    drc_phantasmagoria normal;
    drc_phantasmagoria hard;
    drc_phantasmagoria lunatic;
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

struct drc_diff_survival_hsifs
{
    drc_survival_hsifs easy;
    drc_survival_hsifs normal;
    drc_survival_hsifs hard;
    drc_survival_hsifs lunatic;
    drc_survival_hsifs extra;
};

// number of last spells in IN
struct last_spell_final
{
    unsigned finalA;
    unsigned finalB;
};

struct last_spell_diff
{
    last_spell_final easy;
    last_spell_final normal;
    last_spell_final hard;
    last_spell_final lunatic;
};
//max_last_spells{ 1, 5, 6, 10, 6, 10, 6, 10 };
