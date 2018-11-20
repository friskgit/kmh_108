declare name	"KMH108_channel_map";
declare version " 0.1 ";
declare author " Henrik Frisk " ;
declare license " BSD ";
declare copyright "(c) dinergy/kmh 2018 ";

//---------------`Channel mapping plugin` --------------------------
//
// Channel mapping plugin that takes 8 channels of input (center speaker excluded)
// and maps it to the channel/speaker configuration of the studio 108 according to:
//
// * Audio interface ch -> signal output (clock wise starting at left)
// * 1 -> 1 (L)    
// * 2 -> 2 (R)    
// * 3 -> 8 (LSR)  
// * 4 -> 3 (RSR)  
// * 5 -> 7 (LSF)  
// * 6 -> 4 (RSF)  
// * 7 -> 6 (RL)   
// * 8 -> 5 (RR)  
//
//---------------------------------------------------

import("stdfaust.lib");

vmeter(x)	= attach(x, envelop(x) : vbargraph("[unit:dB]", -70, +5));
hmeter(x)	= attach(x, envelop(x) : hbargraph("[2][unit:dB]", -70, +5));
envelop         = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;

process(s0, s1, s2, s3, s4, s5, s6, s7) = s0, s1, s7, s2, s6, s3, s5, s4;
//process(L, R, RSF, RSR, RR, LR, LSR, LSF) = (L, R, RSF, RSR, RR, LR, LSR, LSF) <:
					    // ba.selector(0, 8), // 1 L
					    // ba.selector(1, 8), // 2 R
					    // ba.selector(7, 8), // 3 LSF
					    // ba.selector(2, 8), // 4 RSF
					    // ba.selector(6, 8), // 5 LSR
					    // ba.selector(3, 8), // 6 RSR
					    // ba.selector(5, 8), // 7 RL
					    // ba.selector(4, 8); // 8 RR
//hgroup("lower ring", par(i, 8, vgroup("%i", vmeter)));  
