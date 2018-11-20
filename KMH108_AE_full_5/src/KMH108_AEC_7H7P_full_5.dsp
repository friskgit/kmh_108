// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:06:50

//------- decoder information -------
// decoder file = ../decoders/KMH108_AEC_7H7P_Slepian41_2_band.dsp
// description = KMH108_AEC_7H7P_Slepian41_2_band
// speaker array name = KMH108_AEC
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L C R FSR SR RR RL SL FSR 
//-------


// start decoder configuration
declare name "KMH108_AEC_7H7P_full_5";

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
ns = 9;

// radius for each speaker in meters
rs = (           2.5,           2.5,           2.5,           2.5,           2.5,           2.5,           2.5,           2.5,           2.5);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1,             1,             1,             1);
gamma(1) = (             1,  0.9602898565,  0.8832349127,  0.7734093083,  0.6372937645,  0.4828486811,  0.3189921291,  0.1550188129);

// gain matrix
s(00,0) = (  0.0217645521,  0.0312182585, -0.0014697679,  0.0450591294,  0.0684792599, -0.0015024758, -0.0524969647,  -0.004016163,  0.0279124158,  0.0974992582,  -0.007412836,  -0.042374927,   0.004220267, -0.0623473759, -0.0010342825,  0.0019145127,  0.0941377556, -0.0034256935, -0.0747239522,  0.0027465732,  0.0651806878,   0.007600917, -0.0296033491, -0.0002915814, -0.0428017771,  0.0846525957, -0.0103422686, -0.0925932147,  0.0097808952,  0.0482607899, -0.0044265413,  0.0733687059,  0.0007750439, -0.0021555458,  0.0021870017, -0.0917405486,  0.0328635107,  0.0002619648, -0.0825166877,  0.0014286909,  0.0788268141, -0.0015568058, -0.0686720824, -0.0062738165,  0.0299993668,  0.0002804264,  0.0359163881,  0.0041945015, -0.0855200574, -0.0108251673,  0.0247465508, -0.0722132896, -0.0007848272,  0.0954172002,  0.0058250383, -0.0516652291, -0.0100767194, -0.0824682065,  0.0056598382,  0.0028233641,  0.0029894637,  0.0838501606, -0.0611990377, -0.1449607827);
s(01,0) = (  0.0107179474,  -4.13466e-05, -0.0022094972,  0.0508059847,    3.5443e-06,    -3.535e-07, -0.0265413016, -0.0007964063,   0.082008878,   5.14171e-05,   1.12418e-05,   5.46999e-05,  0.0065827423, -0.0678761934, -0.0098934374,  0.0996442947,   2.89003e-05,  -2.48198e-05,    1.8325e-06,      9.85e-07,  0.0348765582,   0.001225613, -0.0897020566, -0.0057623389,  0.1192518184, -0.0001489971,   3.87372e-05,  -6.52995e-05,  -1.76421e-05,  -5.94751e-05, -0.0087230454,  0.0751357139,  0.0134764281, -0.0957820959, -0.0060129866,  0.1305119317,  0.0001445876,  -4.17559e-05,    -3.684e-07,   2.89927e-05,   -1.0277e-05,   -3.0889e-06, -0.0396792218,  0.0010549307,   0.094898445,  0.0042895677, -0.0999062459, -0.0091956884,  0.1049718749,   3.89533e-05,  0.0001011862,   7.45071e-05,  -4.27413e-05,   9.35259e-05,   1.55694e-05,   5.90544e-05,  -2.98508e-05, -0.0768092601,  0.0045467562,  0.1003671176,  -0.008527297, -0.1223069345,  0.0714657434,  0.1483174569);
s(02,0) = (  0.0217879197, -0.0311336957, -0.0014768956,  0.0450645056, -0.0684906252,   0.001502279, -0.0525559354, -0.0040041064,  0.0278030121, -0.0976180712,  0.0073954459,   0.042262531,  0.0042416311, -0.0623473996, -0.0010442289,   0.001997204, -0.0941517861,  0.0034625414,  0.0747272985, -0.0027467699,  0.0652611816,   0.007577083, -0.0294948672, -0.0002791876, -0.0427752026, -0.0844310673,  0.0102964996,  0.0927292645, -0.0097533807,  -0.048137523, -0.0044557763,  0.0733543339,  0.0007933173, -0.0022230011,  0.0021713643,  -0.091880036, -0.0330785227, -0.0002240181,  0.0825008066,  -0.001470545, -0.0788171014,  0.0015610867,  -0.068767998, -0.0062469562,  0.0299009142,  0.0002628754,  0.0358857266,  0.0041963405, -0.0854508365,  0.0107072497, -0.0248971041,  0.0720725873,  0.0008329184, -0.0955943208, -0.0058508912,  0.0515410537, -0.0100689255, -0.0824294483,  0.0056226263,  0.0028751853,  0.0030019547,   0.083971114, -0.0611478933,  -0.144874895);
s(03,0) = (  0.0271241126, -0.0478612259, -0.0010670987,  0.0230569484, -0.0617946891,  0.0023453625, -0.0650629422,   -0.00451352, -0.0613640351,  0.0014164318,   0.007533706,  0.0650866609,  0.0029399069, -0.0332950403,  0.0078605778, -0.0938522573,  0.0961782902, -0.0036320873,  0.0678663065, -0.0042831858,  0.0797738865,  0.0087481912,  0.0676782574,  0.0050940209, -0.0398468136,  0.0649649212, -0.0022771248, -0.0040868719,  -0.010127394, -0.0743823247, -0.0021407231,  0.0418728636, -0.0105337271,  0.0904049169,  -2.52386e-05,   0.065070873, -0.0394341514, -0.0046382844, -0.0793679498,   0.004394171, -0.0722353561,  0.0024343399, -0.0825058863, -0.0086540608, -0.0724694749,  -0.003581438,  0.0322274866,   0.004346893,  0.0771266128, -0.1444336355,  -0.029239604, -0.0616459108, -0.0092074813,  0.0086443728, -0.0042523231,  0.0801379578, -0.0151355291, -0.0512298756, -0.0044353324, -0.0951900323,  0.0048562027, -0.0504983125,  0.0565301127,  0.0153316937);
s(04,0) = (   0.023122752, -0.0534288484, -0.0013166961, -0.0105969084,    0.04980029,  0.0024548872, -0.0556523836, -0.0009030537, -0.0697745383,  0.0545637059, -0.0003568903,  0.0724987608,  0.0037399648,  0.0136164599,  0.0072805318,  0.0494086542,  -0.108147617, -0.0084039677, -0.0519503825, -0.0044649271,  0.0687616398,  0.0018639978,  0.0759868905, -0.0034583666,   0.020212579, -0.0113074594,  0.0142598843,  -0.056427498, -0.0008118549, -0.0825285048, -0.0036158989, -0.0139997534,  -0.009514088, -0.0482862469, -0.0031390596, -0.1165455282,  0.1037473018, -0.0036854664,  0.0962137436,  0.0087625482,  0.0513156233,  0.0023831158, -0.0719293618, -0.0026158271, -0.0799396077,  0.0028203841,  -0.018154461,  0.0064067962,  0.0265302955, -0.0871649843,  0.0738854548,  0.0042893062, -0.0015101963,  0.0654785926,  0.0112573739,  0.0883305544, -0.0115586301,  0.0126081047, -0.0064546437,  0.0519830014,  0.0006633999,  0.1069417605,  0.0209689737,   0.115808145);
s(05,0) = (  0.0170029446, -0.0295325115,  0.0135604969, -0.0414149229,  0.0499044902, -0.0162766132, -0.0340785687, -0.0306580762,  0.0264407165, -0.0843983778,  0.0491462358,  0.0296853192, -0.0413211146,  0.0371121637,  0.0331231976, -0.0183841421,  0.0805294954, -0.0692215385,  -0.027240888,  0.0323381489,  0.0229647378,  0.0608199423, -0.0108585395, -0.0080152325, -0.0365430571,  -0.076903603,  0.0912892216,    0.02735345, -0.0777077168, -0.0132272505,  0.0614575716, -0.0044807571, -0.0521084667,  0.0111677052, -0.0314354577,  0.0760374744,  0.0382678831, -0.0625392909, -0.0109440147,  0.0872144271, -0.0111779611, -0.0375370501,   0.005356282, -0.0699426638,  -0.014945739,  0.0103453657,   0.010946103,  0.0658917978, -0.1221368687,  0.0142093449,  0.0256985467, -0.0122273939, -0.1022129708,  0.0563491812,  0.0739229622, -0.0191907272, -0.0573341822, -0.0563497503,  0.0477156228, -0.0014543428,  0.0362314233,  0.0167319722, -0.0850477394,  0.1080378108);
s(06,0) = (  0.0169501497,   0.029102979,  0.0135577159, -0.0413929138, -0.0494831397,  0.0162378476, -0.0339542631, -0.0306758731,  0.0267434779,  0.0846840191, -0.0490262506, -0.0291375517, -0.0413120915,    0.03707242,  0.0332730258, -0.0190467257, -0.0812991387,  0.0691179353,  0.0268625326, -0.0322586384,  0.0228188788,  0.0608549204, -0.0110985451, -0.0083700981, -0.0359486147,  0.0777287814, -0.0914297572, -0.0276926981,  0.0775091237,  0.0126732402,   0.061440245, -0.0044159575, -0.0523499295,  0.0115197639, -0.0307625472,  0.0754881515, -0.0390107873,  0.0630927611,  0.0114845765, -0.0870955209,  0.0114578886,  0.0374275978,  0.0054969925, -0.0699806601, -0.0148249623,  0.0107989873,   0.010863131,  0.0652905589, -0.1219875198, -0.0135815276, -0.0262178922,  0.0122123333,  0.1024476369, -0.0558908092, -0.0736679525,  0.0196703172, -0.0572881413, -0.0564508343,  0.0479790635, -0.0013729782,  0.0354792157,  0.0164515676, -0.0849411074,  0.1080179398);
s(07,0) = (  0.0230166861,  0.0535402938, -0.0014083155, -0.0101235472, -0.0491150594, -0.0025088723, -0.0554430045, -0.0007139086, -0.0702496634, -0.0556701492,  0.0004287568, -0.0726767788,  0.0040190254,  0.0130988229,  0.0071003319,  0.0488325249,  0.1072764465,  0.0083024779,   0.051276552,  0.0045708878,  0.0686313052,  0.0014873335,  0.0763844657, -0.0033849592,  0.0218516101,  0.0128699741, -0.0139826829,  0.0573700026,  0.0006834021,  0.0827838788,   -0.00403016, -0.0136574035, -0.0092260808, -0.0477014239, -0.0029888068, -0.1172214628, -0.1041253121,  0.0035217017, -0.0953420148, -0.0086074314, -0.0507133324, -0.0024966067, -0.0719900241, -0.0021724801, -0.0801808413,  0.0027466653, -0.0193901839,  0.0059376343,  0.0251224536,  0.0847253119, -0.0741409746, -0.0058249038,  0.0013334206, -0.0662744855, -0.0110175061, -0.0886874502,  -0.011177953,  0.0126425246, -0.0067639201,  0.0513205093,   0.000311158,  0.1069269259,  0.0199762137,  0.1168516003);
s(08,0) = (  0.0271906494,  0.0478551451, -0.0010834919,  0.0230566413,  0.0619807524, -0.0023566544, -0.0652290296, -0.0044917742, -0.0616085345, -0.0016005041, -0.0075199107, -0.0650848299,  0.0029889043, -0.0332816565,  0.0078645859,  -0.093687443, -0.0964499646,   0.003614661, -0.0680521608,  0.0043055565,  0.0799957226,  0.0087052884,  0.0679338506,   0.005071134, -0.0397798432, -0.0645872192,  0.0023087914,  0.0042431245,  0.0101013615,  0.0743928866, -0.0022067608,  0.0418319291, -0.0105336321,  0.0902353926,   2.73338e-05,  0.0645132826,  0.0392188592,  0.0046591588,  0.0796071706, -0.0043677166,  0.0724061833, -0.0024597338, -0.0827634614, -0.0086062409, -0.0727226808, -0.0035581359,  0.0322045566,  0.0042865225,  0.0773843981,  0.1439125218,  0.0290912985,  0.0613495914,   0.009207901, -0.0087752835,  0.0043104451, -0.0801693833, -0.0151263838, -0.0511442194, -0.0044853561, -0.0949943155,  0.0047947804, -0.0500995031,  0.0567187956,  0.0157384555);


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
route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_)
                               : m.bus(n_outputs);

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
