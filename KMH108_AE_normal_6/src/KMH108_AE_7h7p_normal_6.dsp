// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Sep-2018 17:31:05

//------- decoder information -------
// decoder file = ../decoders/KMH108_AE_7h7p_allrad_5200_rE_max_2_band.dsp
// description = KMH108_AE_7h7p_allrad_5200_rE_max_2_band
// speaker array name = KMH108_AE
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L R FSR SR RR RL SL FSR 
//-------


// start decoder configuration
declare name "KMH108_AE_7h7p_normal_6";

// bands
nbands = 2;

// decoder type
decoder_type = 2;

// crossover frequency in Hz
xover_freq = hslider("xover [unit:Hz]",400,200,800,20): dezipper;

// lfhf_balance
lfhf_ratio = hslider("lf/hf [unit:dB]", 0, -3, +3, 0.1): mu.db2linear : dezipper;


// decoder order
decoder_order = 7;

// ambisonic order of each input component
co = ( 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7);

// use full or reduced input set
input_full_set = 1;

// delay compensation
delay_comp = 1;

// level compensation
level_comp = 1;

// nfc on input or output
nfc_output = 0;
nfc_input  = 1;

// enable output gain and muting controls
output_gain_muting = 1;

// number of speakers
ns = 8;

// radius for each speaker in meters
rs = (           2.5,           2.5,           2.5,           2.5,           2.5,           2.5,           2.5,           2.5);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1,             1,             1,             1);
gamma(1) = (             1,  0.9602898565,  0.8832349127,  0.7734093083,  0.6372937645,  0.4828486811,  0.3189921291,  0.1550188129);

// gain matrix
s(00,0) = (   0.317270681,  0.1591965169,  0.3869098215,  0.2698084622,  0.1675597563,  0.0613271213,  0.1281750224,  -0.035653194,  0.1633572797,   0.136132053, -0.0767709252, -0.0161948601, -0.0594124646, -0.0932789698, -0.0959706701,  0.0594990209,  0.0898990306, -0.1321915699, -0.0408032115, -0.0628262746, -0.1361910658,  -0.051955682, -0.0199751134, -0.0647026501,  0.0001374161,  0.0288571208,  -0.098572701, -0.0029427143, -0.0167053695, -0.0255165309, -0.0079977493,  0.0353109064,  0.0093012705,  0.0088112575, -0.0030743347, -0.0177207483,  -0.009344245, -0.0473054302,  0.0278822681,  0.0206102711,  0.0471113219,   0.038022088,  0.0689363283,  0.0699245415,  0.0397469117,   0.015120098,  0.0038114849,  0.0291275518, -0.0108802226, -0.0223500656,  0.0039992964,   0.020434134,  0.0163877975,  0.0553178986,  0.0213749651,  0.0368753034,  0.0385861643,  0.0083166237,   -0.01246219,  0.0180143647,    7.8227e-05, -0.0070879281,  0.0156311285,  0.0126982689);
s(01,0) = (  0.1239185073, -0.1635808515,  -0.002752845,  0.2165854376, -0.1950225345, -0.0630655458, -0.1113339468, -0.0815764869,  0.1003268831, -0.1519691636,  0.0403303656,  0.0235190501, -0.0263870061, -0.0594964233, -0.1636861065,  0.0434268642, -0.1079463487,  0.1194137984,   0.023222475,  0.0720989146,  0.0012185886,  0.0178968273, -0.0243836459, -0.0713663857, -0.0049716186, -0.0382084682,  0.0801283338,  0.0089263775,  0.0226225884,   0.024636242,  0.0382780688,  0.0381922988,  0.0536076754,  0.0235995425, -0.0016196148, -0.0219674832,  0.0033663923,  0.0411794432, -0.0310419599, -0.0057157744, -0.0384016108, -0.0470475342,   0.010351164,  0.0039142327,  0.0586746766,  0.0277723466,  0.0138896771,  0.0245470331, -0.0047121397,  0.0205376635, -0.0081480233, -0.0159621957, -0.0096765516, -0.0534507265, -0.0237050136, -0.0405972781,  -0.019829757, -0.0258944251, -0.0407241357,  0.0045652216,  0.0057183457, -0.0097038861,  0.0252314037,  0.0123704768);
s(02,0) = (  0.0668405624, -0.1580224645, -0.0593573484,  0.0532937816, -0.1105365897,  0.1103436785, -0.0715208382, -0.0560708291, -0.1435981588,  0.0814435415,  0.1145587639,  0.0591341851,  0.0628070102, -0.0069739632,  0.0844733161, -0.1318585919,  0.1084260885, -0.0285300015, -0.0064837081, -0.0439495564,  0.0355357658,  0.0364429354,  0.0325313058,  0.1371857354,  0.0147829427,  0.0227013912, -0.1139549228, -0.0236273795, -0.0452370527, -0.0536284866, -0.0166427687,  0.0074600011,  -0.003348699, -0.0199165187,   0.021864456,  0.0594860593, -0.0145635158,  -0.041431804,  0.0218483466, -0.0175724397, -0.0228413546,  0.0098574162, -0.0401648735, -0.0295675634, -0.0498988807, -0.0346003156, -0.0241324582, -0.0639008981,  0.0233380607, -0.0029795344,  0.0174800079,  0.0231376725,  0.0181872309,  0.0347460961,  0.0513132188,  0.0452973485,  0.0027325409, -0.0114302878, -0.0040158106, -0.0360134419, -0.0184712442,  0.0134407285,  -0.028856798,  0.0070351221);
s(03,0) = (     0.0657387, -0.1551984774, -0.0670039787, -0.0532627648,  0.1132247168,  0.1321335672, -0.0631875842,  0.0393008965, -0.1434846292,  0.0858326047, -0.0795119704,   0.041472204,  0.0774860183,  0.0193772098,  0.1241239476,  0.1380254868, -0.1154432755, -0.0866499443, -0.0185241352, -0.0699362722,  0.0252706476, -0.0175535722,  0.0050681861, -0.0962778244,  0.0226764055,  0.0135438131,  0.0837831262,  0.0152319905,   0.014246322, -0.0397373409, -0.0357668834, -0.0192864659, -0.0364494824, -0.0075925294, -0.0442603766, -0.0633187388,  0.0127363497,  0.0156516033, -0.0035236066,  0.0189133823,  0.0377262378,  0.0434348947, -0.0350904197,  0.0073982335, -0.0341862048,  0.0029637502,  0.0204742768,  0.0531094042,  0.0149243806,  0.0033683685, -0.0215111054,  -0.016529921,  0.0040972827,  0.0184540221, -0.0126967249,  0.0393140563,  0.0262394647,   0.017818624,  0.0396392232,   0.045965489,  0.0142490648, -0.0090334062,  0.0056257242, -0.0140445785);
s(04,0) = (  0.3480401896, -0.2056117627,   0.422196811,  -0.175724713,  0.1917242587, -0.0790779667,  0.0973773267,  0.0960821408,  0.1587466271, -0.1570838031, -0.0535759357,  0.0527173129, -0.1118260237,  0.0247359205, -0.0497999497, -0.0437165792,  0.1042012447,  0.0927275341, -0.0204324362,  0.1051187591, -0.1182518169, -0.0562678048, -0.0152199133,  0.0144360573,  -0.004389682, -0.0255128232,  -0.047377041,  0.0053976745, -0.0293158848,  0.0071331521,  0.0461362487,  -0.024868615, -0.0158931052, -0.0080934145,  0.0277845872,   0.012835388, -0.0094861916,  0.0039904119, -0.0049613691,  0.0100778059,  0.0145330565, -0.0851793587,   0.070439868,  0.0484578012,  0.0191059657,  0.0022936866, -0.0095895127, -0.0319346105,  0.0051471268,  0.0124784197,  0.0184330071,  0.0015395074, -0.0223005047, -0.0356374669,  0.0070999476, -0.0397232979, -0.0085342541,  0.0298561677, -0.0033401322, -0.0004607368, -0.0118275796,  0.0035290415,  0.0016199526, -0.0294026196);
s(05,0) = (  0.1495484856,  0.2083917655,  0.0236365913, -0.2449339399, -0.2175610254,  0.0852816324, -0.1447728887,  0.0329606712,  0.0920374227,  0.1576292861,  0.0146632736, -0.0453891045, -0.0780855403,  0.0601612766, -0.1203285128, -0.0521062531, -0.1174312307, -0.0863734053,  -0.005401259, -0.1030790021,  0.0150016403,  0.0305006292, -0.0178762723,  0.0208788361, -0.0058142981,  0.0257388255,  0.0277291662,   0.005813896,  0.0308524164, -0.0129384008,  0.0875012241, -0.0123738193,  0.0303919353,  0.0173147992,  0.0305228476,  0.0186559495,  0.0061583799,  0.0001670854, -0.0068225297, -0.0033058519,  0.0008900437,   0.078286402,  0.0155944739, -0.0244278881,  0.0355202975,  0.0152203468,    -0.0041012,  -0.023839016,  0.0154733861, -0.0121523373, -0.0228208352,  0.0043122717,   0.022916858,   0.030477531, -0.0002873832,  0.0404635871, -0.0581775399, -0.0143502519, -0.0350407435, -0.0215521665, -0.0126742307,  0.0048041783,  0.0112201405, -0.0232039204);
s(06,0) = (  0.0658424437,  0.1554407886, -0.0670572089, -0.0533155185, -0.1132727083, -0.1322338879, -0.0633364916,  0.0392719343,   -0.14369428, -0.0860062973,  0.0793897605, -0.0416249988,  0.0775152897,  0.0194225672,  0.1242499347,  0.1379470009,  0.1152047596,  0.0868592559,  0.0186102509,  0.0699356778,  0.0253831911, -0.0174423693,   0.005142057,  -0.096042957,  0.0229372541, -0.0130888023, -0.0834976421, -0.0152478873,  -0.014057068,  0.0398798492, -0.0356997364, -0.0193737778, -0.0364964129, -0.0077028959, -0.0446013876, -0.0630571132, -0.0126665083, -0.0160993788,  0.0034122798, -0.0190262795,  -0.037840283, -0.0433623613, -0.0352117085,  0.0072913593, -0.0342618091,  0.0028093034,  0.0205748985,  0.0528725006,  0.0143387717, -0.0038498746,   0.021381395,  0.0166946141, -0.0041420608, -0.0184877062,  0.0125251643, -0.0394245752,  0.0261473435,  0.0178430534,  0.0396569278,  0.0460211265,  0.0143412054, -0.0089439729,  0.0060904012, -0.0138275793);
s(07,0) = (  0.0667016674,  0.1576841183, -0.0591879506,  0.0533473415,  0.1106855288, -0.1099681072, -0.0713827716, -0.0560820234, -0.1432382729, -0.0810939194, -0.1145955126, -0.0590489105,  0.0625655396, -0.0070182964,  0.0840097797, -0.1321266122, -0.1088010394,   0.028026695,  0.0063883813,  0.0436597356,  0.0354661871,  0.0364171881,  0.0325693393,  0.1372690017,  0.0143953101, -0.0231545475,  0.1140747134,  0.0237680014,  0.0451887622,  0.0535169917, -0.0164941739,    0.00752582, -0.0030992963, -0.0197750482,  0.0223514599,  0.0599109827,  0.0149513664,  0.0418626826, -0.0216849529,  0.0177687436,  0.0229755993, -0.0096600644, -0.0400049958, -0.0295427669, -0.0498187397, -0.0345342411, -0.0243179811, -0.0640093289,  0.0237663145,  0.0032030255, -0.0175414786, -0.0233048248,  -0.018102393, -0.0347159431, -0.0512538837,  -0.045066361,  0.0026261562, -0.0114331624, -0.0042536852, -0.0362343897, -0.0185648386,  0.0133165819, -0.0292485959,  0.0067654302);


// ----- do not change anything below here ----

// mask for full ambisonic set to channels in use
input_mask(0) = bus(nc);
input_mask(1) = (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_);


// Start of decoder implementation.  No user serviceable parts below here!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//declare name		"Fill in name in configuration section below";
declare version 	"1.2";
declare author 		"AmbisonicDecoderToolkit";
declare license 	"BSD 3-Clause License";
declare copyright	"(c) Aaron J. Heller 2013";

/*
Copyright (c) 2013, Aaron J. Heller
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
  Author: Aaron J. Heller <heller@ai.sri.com>
  $Id: 21810b615fa65b96af41a7c8783d7435b41084b8 $
*/

// v 1.2, 28-Oct-2017 ajh
//  . add 6th-order NFC filters
//  . fixed error in speaker_chain and speaker_chain2, where speaker 
//    distance was being indexed by order, not speaker number

// v 1.1 remove dependancies on Faust Libraries, 23-Nov-2016 ajh
//   m = library("math.lib");
//   mu = library("music.lib");

m = environment {
  // from the old math.lib
  take (1, (xs, xxs)) = xs;
  take (1, xs) = xs;
  take (nn, (xs, xxs)) = take (nn-1, xxs);

  bus(2) = _,_; // avoids a lot of "bus(1)" labels in block diagrams
  bus(n) = par(i, n, _);

  SR = min(192000, max(1, fconstant(int fSamplingFreq, <math.h>)));
  //PI = 3.1415926535897932385;
  // quad precision value
  PI = 3.14159265358979323846264338327950288;
};

mu = environment {
   // from the old music.lib
   db2linear(x)	= pow(10, x/20.0);
};



// m.SR from math.lib is an integer, we need a float
SR = float(m.SR);

// descriptive statistics
total(c) = c:>_;

average(c) = total(c)/count(c);

count(c) = R(c) :>_ with {
 R((c,cl)) = R(c),(R(cl));
 R(c)      = 1;
};

rms(c) = R(c) :> /(count(c)) : sqrt with {
 R((c,cl)) = R(c),R(cl);
 R(c)      = (c*c);
};

sup(c) = R(c) with {
 R((c,cl)) = max(R(c),R(cl));
 R(c)      = c;
};

inf(c) = R(c) with {
 R((c,cl)) = min(R(c),R(cl));
 R(c)      = c;
};

// bus
bus(n)   = par(i,n,_);

// bus with gains
gain(c) = R(c) with {
  R((c,cl)) = R(c),R(cl);
  R(1)      = _;
  R(0)      = !:0;  // need to preserve number of outputs, faust will optimize away
  R(float(0)) = R(0);
  R(float(1)) = R(1);
  R(c)      = *(c);
};

// fir filter  (new improved, better behaved)
fir(c) = R(c) :>_ with {
  R((c,lc)) = _<: R(c), (mem:R(lc));
  R(c)      = gain(c);
};

// --- phase-matched bandsplitter from BLaH3
xover(freq,n) = par(i,n,xover1) with {

	sub(x,y) = y-x;

	k = tan(m.PI*float(freq)/m.SR);
	k2 = k^2;
	d =  (k2 + 2*k + 1);
	//d = (k2,2*k,1):>_;
	// hf numerator
	b_hf = (1/d,-2/d,1/d);
	// lf numerator
	b_lf = (k2/d, 2*k2/d, k2/d);
	// denominator
	a = (2 * (k2-1) / d, (k2 - 2*k + 1) / d);
	// 
	xover1 = _:sub ~ fir(a) <: fir(b_lf),fir(b_hf):_,*(-1);
};

shelf(freq,g_lf,g_hf) = xover(freq,1) : gain(g_lf),gain(g_hf):>_;

// from http://old.nabble.com/Re%3A--Faudiostream-devel---ANN--Faust-0.9.24-p28597267.html
//   (not used currently, do we need to worry about denormals?)
anti_denormal = pow(10,-20);
anti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1); 

// UI "dezipper"
smooth(c) = *(1-c) : +~*(c);
dezipper = smooth(0.999);

// physical constants     

temp_celcius = 20;                        
c = 331.3 * sqrt(1.0 + (temp_celcius/273.15)); // speed of sound m/s


// ---- NFC filters ----
//  see BesselPoly.m for coefficient calculations
//
// [1] J. Daniel, “Spatial Sound Encoding Including Near Field Effect:
//     Introducing Distance Coding Filters and a Viable, New Ambisonic 
//     Format ,” Preprints 23rd AES International Conference, Copenhagen,
//     2003.
// [2] Weisstein, Eric W. "Bessel Polynomial." From MathWorld--A Wolfram 
//     Web Resource. http://mathworld.wolfram.com/BesselPolynomial.html
// [3] F. Adriaensen, “Near Field filters for Higher Order
//     Ambisonics,” Jul. 2006.
// [4] J. O. Smith, “Digital State-Variable Filters,” CCRMA, May 2013.
//
// [5] "A Filter Primer", https://www.maximintegrated.com/en/app-notes/index.mvp/id/733

// first and second order state variable filters see [4]
//   FIXME FIXME this code needs to be refactored, so that the roots are 
//               passed in rather then hardwired in the code, or another 
//               API layer, or ...
svf1(g,d1)    = _ : *(g) :       (+      <: +~_, _ ) ~ *(d1)                   : !,_ ;
svf2(g,d1,d2) = _ : *(g) : (((_,_,_):> _ <: +~_, _ ) ~ *(d1) : +~_, _) ~ *(d2) : !,_ ;

//  these are Bessel filters, see [1,2]
nfc1(r,gain) = svf1(g,d1)  // r in meters
 with {
   omega = c/(float(r)*SR);
   //  1  1
   b1 = omega/2.0;
   g1 = 1.0 + b1;
   d1 = 0.0 - (2.0 * b1) / g1;
   g = gain/g1;
};

nfc2(r,gain) = svf2(g,d1,d2)
 with {
   omega = c/(float(r)*SR);
   r1 = omega/2.0;
   r2 = r1 * r1;

   // 1.000000000000000   3.00000000000000   3.00000000000000
   b1 = 3.0 * r1;
   b2 = 3.0 * r2;
   g2 = 1.0 + b1 + b2;

   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;
   g = gain/g2;
};

nfc3(r,gain) = svf2(g,d1,d2):svf1(1.0,d3)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;

   // 1.000000000000000   3.677814645373914   6.459432693483369
   b1 = 3.677814645373914 * r1;
   b2 = 6.459432693483369 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   2.322185354626086
   b3 = 2.322185354626086 * r1;
   g3 = 1.0 + b3;
   d3 = 0.0 - (2.0 * b3) / g3;

   g = gain/(g3*g2);
};

nfc4(r,gain) = svf2(g,d1,d2):svf2(1.0,d3,d4)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;
   
   // 1.000000000000000   4.207578794359250  11.487800476871168
   b1 =  4.207578794359250 * r1;
   b2 = 11.487800476871168 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   5.792421205640748   9.140130890277934
   b3 = 5.792421205640748 * r1;
   b4 = 9.140130890277934 * r2;         
   g3 = 1.0 + b3 + b4;
   d3 = 0.0 - (2.0 * b3 + 4.0 * b4) / g3;  // fixed
   d4 = 0.0 - (4.0 * b4) / g3;
   
   g = gain/(g3*g2);
};

nfc5(r,gain) = svf2(g,d1,d2):svf2(1.0,d3,d4):svf1(1.0,d5)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;
   
   // 1.000000000000000   4.649348606363304  18.156315313452325
   b1 =  4.649348606363304 * r1;
   b2 = 18.156315313452325 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   6.703912798306966  14.272480513279568
   b3 =  6.703912798306966 * r1;
   b4 = 14.272480513279568 * r2;         
   g3 = 1.0 + b3 + b4;
   d3 = 0.0 - (2.0 * b3 + 4 * b4) / g3;  // fixed
   d4 = 0.0 - (4.0 * b4) / g3;

   // 1.000000000000000   3.646738595329718
   b5 = 3.646738595329718 * r1;
   g4 = 1.0 + b5;
   d5 = 0.0 - (2.0 * b5) / g4;

   g = gain/(g4*g3*g2);
 };

nfc6(r,gain) = svf2(g,d11,d12):svf2(1.0,d21,d22):svf2(1.0,d31,d32)
with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;

   // reverse Bessel Poly 6:
   //   1          21         210        1260        4725       10395       10395
   // factors:
   //   1.000000000000000   5.031864495621642  26.514025344067996
   //   1.000000000000000   7.471416712651683  20.852823177396761
   //   1.000000000000000   8.496718791726696  18.801130589570320


   // 1.000000000000000   5.031864495621642  26.514025344067996
   b11 =  5.031864495621642 * r1;
   b12 = 26.514025344067996 * r2;         
   g1 = 1.0 + b11 + b12;
   d11 = 0.0 - (2.0 * b11 + 4.0 * b12) / g1;
   d12 = 0.0 - (4.0 * b12) / g1;

   // 1.000000000000000   7.471416712651683  20.852823177396761
   b21 =  7.471416712651683 * r1;
   b22 = 20.852823177396761 * r2;         
   g2 = 1.0 + b21 + b22;
   d21 = 0.0 - (2.0 * b21 + 4.0 * b22) / g2;
   d22 = 0.0 - (4.0 * b22) / g2;

   // 1.000000000000000   8.496718791726696  18.801130589570320
   b31 =  8.496718791726696 * r1;
   b32 = 18.801130589570320 * r2;         
   g3 = 1.0 + b31 + b32;
   d31 = 0.0 - (2.0 * b31 + 4.0 * b32) / g3;
   d32 = 0.0 - (4.0 * b32) / g3;

   g = gain/(g3*g2*g1);
};


// ---- End NFC filters ----

nfc(0,r,g) = gain(g);
nfc(1,r,g) = nfc1(r,g);
nfc(2,r,g) = nfc2(r,g);
nfc(3,r,g) = nfc3(r,g);
nfc(4,r,g) = nfc4(r,g);
nfc(5,r,g) = nfc5(r,g);
nfc(6,r,g) = nfc6(r,g);

// null NFC filters to allow very high order decoders. FIXME!
nfc(o,r,g) = gain(g);

//declare name "nfctest";
//process = bus(6):(nfc(0,2,1),nfc(1,2,1),nfc(2,2,1),nfc(3,2,1),nfc(4,2,1),nfc(5,2,1)):bus(6);


// top level api to NFC filters
nfc_out(1,order,r,g) = nfc(order,r,g);
nfc_out(0,order,r,g) = _;

nfc_inp(1,order,r,g) = nfc(order,r,g);
nfc_inp(0,order,r,g) = _;



// ---- delay and level
delay(dc,r)  = R(dc,r) with {
 R(0,r) = _;  // delay_comp off
 R(1,0) = _;  // delay_comp on, but no delay
 R(1,float(0)) = R(1,0);
 R(1,r) = @(meters2samples(r));
 meters2samples(r) = int(m.SR * (float(r)/float(c)) + 0.5);
};

level(lc,r,rmax) = R(lc,r,rmax) with{
 R(0,r,rmax) = _;  // level_comp off
 R(1,r,rmax) = gain(float(r)/float(rmax));
};


delay_level(r) = R(r) with {  // delay_comp and level_comp are free variables (fix?)
 R((r,rl)) =   R(r), R(rl);
 R(r)      =   delay(delay_comp,(r_max-r)) : level(level_comp,r,r_max);
};

// ---- gates
gate(0) = !;
gate(1) = _;
dirac(i,j) = i==j;
gate_bus(order,(o,oss)) = (gate(order==o),gate_bus(order,oss));
gate_bus(order,o)       =  gate(order==o);


// route (not used)
//route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
//                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_)


//process = route(4,4,(3,1,1,2)); // test


// deinterleave 
deinterleave(n,span) = par(i,n,_) <: par(i,span, par(j,n,gate(%(j,span)==i)));


// 1 band speaker chain
speaker_chain(ispkr) = gain(s(ispkr,0))  // decoder matrix gains
		     // iterate over orders, select each order from matrix
		     <: par(jord,no,gate_bus(jord,co)
		            // sum and apply NFC filter for that order
			    // at the speaker distance
		            :> nfc_out(nfc_output,jord,m.take(ispkr+1,rs),1.0))
		     // sum the orders
	             :>_;

// 1 band speaker chain -- bad definition
// speaker_chain(i) = gain(s(i,0)) <: par(i,no,gate_bus(i,co):>nfc_out(nfc_output,i,m.take(i+1,rs),1.0)):>_;

// near field correction at input, nfc_input = 1
nfc_input_bus(nc) = par(i,nc, nfc_inp(nfc_input, m.take(i+1,co), r_bar, 1.0));

// per order gains
gamma_bus(n) = par(i,nc, gain( m.take(m.take(i+1,co)+1, gamma(n))));

// output gain and muting
output_gain = hslider("gain [unit:dB]", -10, -30, +10, 1): mu.db2linear :*(checkbox("mute")<0.5): dezipper;

gain_muting_bus(0,n) = bus(n);
gain_muting_bus(1,n) = par(i,n,*(output_gain));


// one band decoder
decoder(1,nc,ns) = nfc_input_bus(nc) 
                :  gamma_bus(0) 
                <: par(is,ns, speaker_chain(is)) 
                : delay_level(rs); 


// two band decoder
//   there are two variants of the two-band decoder
//     1. classic, with shelf-filters and one matrix
//     2. vienna,  bandsplitting filters and separate LF and HF matricies.

// classic shelf filter decoder
decoder(2,nc,ns) = nfc_input_bus(nc) 
                :  par(i,nc, shelf(xover_freq,m.take(m.take(i+1,co)+1, gamma(0))/lfhf_ratio,
                                              m.take(m.take(i+1,co)+1, gamma(1))*lfhf_ratio))
                <: par(is,ns, speaker_chain(is)) 
                :  delay_level(rs);

// vienna decoder
//   FIXME FIXME  need to incorporate lfhf_ratio
decoder(3,nc,ns) = bus(nc)
                   : nfc_input_bus(nc) 
                   : xover(xover_freq,nc) : deinterleave(2*nc,2) 
                   : (gamma_bus(0),gamma_bus(1)) : bus(2*nc)
                   <: par(j, ns, speaker_chain2(j,nc))
                   : delay_level(rs)
; 
// 2 band speaker chain for vienna decoder
// i is speaker, j is order
speaker_chain2(i,nc) = gain(s(i,0)), gain(s(i,1))
                       :> bus(nc)
                       <: par(j,no,gate_bus(j,co):>nfc_out(nfc_output,j,m.take(i+1,rs),1.0))
                       :>_ ;

//process = speaker_chain2(1,16); // test



// --------------------------------------
//  things calculated from decoder config 

// maximum and average speaker distance
r_max = sup(rs);
r_bar = (rs :> float) / float(count(rs));

// number of ambisonic orders, including 0
no = decoder_order+1;

// number of input component signals
nc = count(co);



// the top-level process
process = input_mask(input_full_set):decoder(decoder_type,nc,ns):gain_muting_bus(output_gain_muting,ns);


// End of decoder implementation.  No user serviceable parts above here!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//EOF!
