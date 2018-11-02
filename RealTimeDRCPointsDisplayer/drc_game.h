#pragma once
#include "drc_rubric.h"
#include "drc_wr.h"

// Global drc points for both categories
float drcpoints_survival, drcpoints_score;

// Game template
template <typename T_survival, typename T_scoring, typename T_wrs>
struct game
{
	T_survival survival;
	T_scoring scoring;
	T_wrs wrs;
};

game < difficulty_noextra<drc_survival>, difficulty_noextra<drc_scoring>, difficulty_noextra<HRtP_route> > HRtP;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<SoEW_shottype> > SoEW;
game < difficulty_noextra<drc_survival_phantasmagoria>, difficulty_noextra<drc_scoring>, difficulty_noextra<PoDD_shottype> > PoDD;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<LLS_shottype> > LLS;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<MS_shottype> > MS;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<EoSD_shottype> > EoSD;
game < difficulty_withphantasm<drc_survival>, difficulty_withphantasm<drc_scoring>, difficulty_withphantasm<PCB_shottype> > PCB;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<IN_shottype> > INight;
game < difficulty<drc_survival_phantasmagoria>, difficulty<drc_scoring>, difficulty<PoFV_shottype> > PoFV;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<MoF_shottype> > MoF;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<SA_shottype> > SA;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<UFO_shottype> > UFO;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<GFW_shottype> > GFW;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<TD_shottype> > TD;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<DDC_shottype> > DDC;
game < difficulty<drc_survival>, difficulty<drc_scoring>, difficulty<LoLK_shottype> > LoLK;
game < difficulty<drc_survival_hsifs>, difficulty<drc_scoring>, difficulty<HSiFS_shottype<HSiFS_season>, HSiFS_shottype<ull>> > HSiFS;
