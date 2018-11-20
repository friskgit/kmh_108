declare name	"KMH108_channel_map_C";
declare version " 0.1 ";
declare author " Henrik Frisk " ;
declare license " BSD ";
declare copyright "(c) dinergy 2018 ";

//---------------`Channel mapping plugin` --------------------------
//
// Channel mapping plugin that takes 8 channels of input (center speaker included)
// and maps it to the channel/speaker configuration of the studio 108 according to:
//
// * Audio interface ch -> signal output (clock wise starting at left)
// * 1 -> 1 (L)    
// * 2 -> 3 (R)    
// * 3 -> 9 (LSR)  
// * 4 -> 4 (RSR)  
// * 5 -> 8 (LSF)  
// * 6 -> 5 (RSF)  
// * 7 -> 7 (RL)   
// * 8 -> 6 (RR)
// * 9 -> 2 (C)
//
//---------------------------------------------------

import("stdfaust.lib");

vmeter(x)	= attach(x, envelop(x) : vbargraph("[unit:dB]", -70, +5));
hmeter(x)	= attach(x, envelop(x) : hbargraph("[2][unit:dB]", -70, +5));
envelop         = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;

process(s0, s1, s2, s3, s4, s5, s6, s7, s8) = s0, s1, s7, s2, s6, s3, s5, s4, s8 : hgroup("lower ring", par(i, 9, vgroup("%i", vmeter))); 

// process(L, C, R, RSF, RSR, RR, RL, LSR, LSF) = (L, C, R, RSF, RSR, RR, RL, LSR, LSF) <:
// 				     ba.selector(0, 9), // 1 L
// 				     ba.selector(2, 9), // 2 R
// 				     ba.selector(8, 9), // 3 LSF
// 				     ba.selector(3, 9), // 4 RSF
// 				     ba.selector(7, 9), // 5 LSR
// 				     ba.selector(4, 9), // 6 RSR
// 				     ba.selector(6, 9), // 7 LR
// 				     ba.selector(5, 9), // 8 RR
// 				     ba.selector(1, 9) : // 9 C


