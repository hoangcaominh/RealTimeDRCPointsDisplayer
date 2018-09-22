#pragma once

struct drc_score
{
    unsigned base;
    float exp;
};

struct drc_diff_score
{
    drc_score easy;
    drc_score normal;
    drc_score hard;
    drc_score lunatic;
    drc_score extra;
};
