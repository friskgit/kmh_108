// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 17:49:25

//------- decoder information -------
// decoder file = ../decoders/KMH108_AEC_7h7v_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMH108_AEC_7h7v_pinv_even_energy_rV_max_rE_2_band
// speaker array name = KMH108_AEC
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HV
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L C R FSR SR RR RL SL FSR 
//-------


// start decoder configuration
declare name "KMH108_AEC_7h7v_full_2";

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
gamma(1) = (  0.6749284505,  0.6481269449,  0.5961203711,  0.5219959461,   0.430127693,  0.3258883121,  0.2152968634,  0.1046266072);

// gain matrix
s(00,0) = (  0.0950715753,  0.0586363492, -0.0008990919,  0.0968172423,  0.0961666751,   5.43534e-05, -0.0479085616,  0.0013274541,  0.0553419205,  0.1115216286, -0.0001029893, -0.0358807256,  0.0011769086,  -0.058639584, -0.0009221636,  0.0053758576,  0.1007254677,  0.0001278983, -0.0621328459,  -6.11585e-05,  0.0365007077, -0.0014936525, -0.0362381252,  0.0002175354, -0.0422661864,  0.0709054964,  -0.000120908, -0.0736850816,  0.0001050149,  0.0283351484, -0.0011260738,  0.0456001948,  0.0009403004, -0.0034205066,   0.000582391, -0.0802463285,  0.0272690923,   8.34536e-05, -0.0676508999, -0.0001196014,   0.050389802,   5.21401e-05, -0.0309878915,  0.0012733998,  0.0298616357, -0.0002034235,  0.0287489717, -0.0012648472, -0.0987602698, -0.0196552259,   -2.5226e-05, -0.0479420365,  0.0001038906,  0.0604705204,  -8.00339e-05, -0.0241686968,  0.0008309542, -0.0382781327, -0.0007166211,  0.0026946577, -0.0005004215,  0.0533992819,  0.0016572291, -0.0974165439);
s(01,0) = (  0.0744943629,   -9.1066e-06, -0.0017527302,   0.109177097,   -1.5117e-05,    -9.964e-07, -0.0379738837,  0.0025878949,  0.1135664973,    1.8521e-05,    3.0998e-06,    5.0898e-06,  0.0022943185, -0.0655925362, -0.0017980734,  0.1128969186,   3.13766e-05,   -6.8081e-06,   1.14894e-05,    1.1211e-06,  0.0295902056, -0.0029119014, -0.0743111623,  0.0004247634,  0.1135414077,  -6.14193e-05,   1.17591e-05,  -1.64846e-05,   -3.1608e-06,   -3.4545e-06,  -0.002195219,  0.0503768087,  0.0018334374, -0.0744101249,  0.0011344501,  0.1109338022,   3.74894e-05,  -1.66378e-05,  -1.30534e-05,    6.3665e-06,  -1.10063e-05,    -9.558e-07, -0.0257709263,   0.002482515,  0.0611843702, -0.0003972084, -0.0753946097, -0.0024649447,  0.1090969913,     3.245e-05,   1.95423e-05,   2.93776e-05,  -1.01041e-05,   1.71606e-05,    2.4089e-06,    2.4542e-06,  0.0016198994, -0.0417298379, -0.0013972979,  0.0609084817, -0.0009747803, -0.0769105251,  0.0032303066,  0.1047510419);
s(02,0) = (  0.0951092914, -0.0586301938, -0.0009070475,  0.0968198257, -0.0962056959,  -4.69882e-05, -0.0479307181,  0.0013392915,  0.0552685852, -0.1114764241,   9.01875e-05,   0.035880555,  0.0011873224, -0.0586353819, -0.0009306719,  0.0054144287, -0.1007194705, -0.0001148169,  0.0621508834,   5.28712e-05,  0.0365223624, -0.0015069719, -0.0361955398,  0.0002201173, -0.0422323929, -0.0709494375,  0.0001136091,  0.0736633172,  -9.19613e-05, -0.0283392217, -0.0011360378,  0.0455901093,  0.0009489761, -0.0034444132,  0.0005866978, -0.0803091844, -0.0272352429,  -8.65282e-05,  0.0676419146,  0.0001073685, -0.0503973979,  -4.50748e-05, -0.0310109863,  0.0012847552,  0.0298318006, -0.0002058379,  0.0287292304, -0.0012752725,  -0.098751343,  0.0196794201,    3.9972e-05,  0.0479695296,   -9.7619e-05, -0.0604595892,   7.00855e-05,  0.0241758395,  0.0008383068, -0.0382636311,  -0.000723233,  0.0027129272, -0.0005041222,  0.0534341889,  0.0016715404, -0.0973773163);
s(03,0) = (  0.1021859411, -0.1105121934, -0.0015528741,  0.0489645247, -0.0912129175,  -1.72035e-05, -0.0517368101,  0.0022928233, -0.0775926314,  0.0212208085,   3.38561e-05,   0.067666215,  0.0020327075, -0.0288641958, -0.0015931029, -0.1107513579,  0.1033085317,  -4.51172e-05,  0.0588965952,   1.93574e-05,  0.0397858556, -0.0025798866,  0.0491960098,  0.0003764349, -0.0281293647,   0.063489372,   4.81797e-05, -0.0140643046,   -3.4522e-05, -0.0534850104, -0.0019449078,  0.0215091011,  0.0016244355,  0.0734892489,   0.001004958,  0.0698559111, -0.0383397182,  -4.21048e-05, -0.0692687138,   4.21904e-05, -0.0477302503,   -1.6503e-05, -0.0341404568,  0.0021994588, -0.0389802101, -0.0003520149,  0.0195529954,  -0.002183755,  0.0825495268, -0.0839845742,   2.78001e-05,  -0.043013391,  -4.13986e-05,  0.0115789758,   2.63098e-05,  0.0456629631,  0.0014351894, -0.0172261462, -0.0012380136, -0.0605775766, -0.0008635138, -0.0488944146,  0.0028619124,   -0.00063258);
s(04,0) = (  0.1017068694, -0.1205399773, -0.0031539175, -0.0390635413,  0.0713518804,  0.0005916737, -0.0521610854,  0.0046562058, -0.0976324625,  0.0665073846, -0.0011256531,  0.0741044657,  0.0041284684,  0.0261965718, -0.0032334773,  0.0821554215, -0.0997056339,  0.0014089963, -0.0466861678, -0.0006657517,  0.0411178099, -0.0052391666,  0.0612154435,   0.000760503,  0.0330366474, -0.0048661843, -0.0013519446, -0.0431142208,  0.0011477922, -0.0589227885, -0.0039501456, -0.0233706226,  0.0032970724, -0.0538677335,  0.0020462981, -0.0982115932,  0.0891445008,  0.0009650945,  0.0659654218, -0.0013175925,  0.0384370417,  0.0005675806, -0.0362665679,  0.0044666038, -0.0478180439,  -0.000711168, -0.0207704339, -0.0044399672,  0.0248231525, -0.0437245451, -0.0003461389,  0.0040022993,  0.0011616633,  0.0346733559, -0.0008747545,   0.050609284,  0.0029148977,  0.0222730643, -0.0025127624,  0.0438528086, -0.0017582891,  0.0632329387,  0.0058147695,  0.0630579216);
s(05,0) = (  0.0993807386, -0.0597912646,  0.0339726477, -0.1098403624,   0.090159616,  -0.029771792, -0.0356049167, -0.0501336371,  0.0629258678, -0.0988137176,  0.0567259683,   0.022067298, -0.0444700922,  0.0427666913,  0.0347495116, -0.0166919248,  0.0846900823, -0.0712124441, -0.0265138197,  0.0334992443,  0.0051929041,  0.0564104089, -0.0212093339, -0.0080408219, -0.0302003242, -0.0541737078,  0.0686997903,  0.0210708766, -0.0578416381, -0.0004350362,  0.0425492751, -0.0051652056, -0.0354329549,  0.0060399439, -0.0222363472,  0.0568225602,  0.0170011688, -0.0496266355, -0.0101046971,  0.0665927799, -0.0096104713,  -0.028559476,  0.0172343173, -0.0480921808, -0.0018632233,   0.007519201,  0.0051410997,  0.0480016076, -0.0684444499,  0.0161867127,   0.018762082,   0.000275662, -0.0590305439,  0.0205232395,  0.0440822269, -0.0144408383, -0.0313980282, -0.0205322896,  0.0270041377, -0.0006902813,  0.0191066619, -0.0032608679, -0.0627152222,   0.052311298);
s(06,0) = (  0.0993795145,  0.0594862408,  0.0339743947, -0.1099451967, -0.0899688192,  0.0296830261, -0.0356035804, -0.0501896178,  0.0632792563,  0.0989027047,  -0.056603313,  -0.021923883, -0.0444723789,  0.0428035354,  0.0349548848, -0.0172440416,  -0.084871465,  0.0711712919,  0.0264591693, -0.0333993648,  0.0051907957,  0.0564733983, -0.0213227352, -0.0084249059, -0.0296591684,  0.0545370393, -0.0688609045, -0.0211553293,  0.0577165705,  0.0003723748,  0.0425514631, -0.0051623478, -0.0356423672,  0.0061662663, -0.0217432573,  0.0563419837, -0.0175760674,  0.0500580324,  0.0101168351, -0.0665542973,   0.009587521,  0.0284743246,   0.017237183, -0.0481458819, -0.0018839141,  0.0078783689,    0.00511332,  0.0475563863, -0.0682263858, -0.0153588843, -0.0194378159, -0.0002052179,  0.0591689819, -0.0204319906, -0.0439869105,   0.014450182, -0.0313996427, -0.0205625819,  0.0271637349, -0.0005900043,  0.0186829727, -0.0032620767, -0.0625125771,  0.0524373258);
s(07,0) = (  0.1015929215,  0.1207259743, -0.0031809707, -0.0385678863, -0.0707496224, -0.0005897236,  -0.052115328,  0.0046972107, -0.0981334575, -0.0674012316,  0.0011262755, -0.0742174123,  0.0041638809,  0.0259130823, -0.0032652755,  0.0815499082,  0.0992113561, -0.0014203087,  0.0462977596,  0.0006635575,  0.0411006213, -0.0052853053,  0.0615210736,  0.0007746826,  0.0343115524,  0.0062317964,  0.0013816017,  0.0436984096, -0.0011484267,  0.0590109663, -0.0039840285, -0.0231699334,   0.003329496, -0.0534584056,  0.0020539879, -0.0981949184, -0.0895208156, -0.0010159209, -0.0656136871,   0.001328171, -0.0381227361, -0.0005657099, -0.0362694141,  0.0045059389, -0.0480482054, -0.0007244277, -0.0216204381, -0.0044691178,  0.0230982444,  0.0420983944,  0.0004132037, -0.0049641031, -0.0011871462, -0.0351473058,  0.0008752381, -0.0506836099,  0.0029399006,  0.0221220944,  -0.002537473,  0.0435089779, -0.0017648965,  0.0632002685,  0.0058605382,  0.0641117502);
s(08,0) = (  0.1022275007,  0.1104902929, -0.0015615443,  0.0489495981,  0.0911910043,   2.45327e-05, -0.0517611847,  0.0023055872,  -0.077626607, -0.0211252367,  -4.56932e-05, -0.0676492225,  0.0020440567, -0.0288488184, -0.0016018544, -0.1106732996, -0.1032947177,   5.48119e-05, -0.0588890618,  -2.76042e-05,  0.0398096263, -0.0025942486,  0.0492130528,  0.0003782667,  -0.028208371, -0.0636132926,  -4.83388e-05,  0.0140071191,   4.65918e-05,   0.053467389, -0.0019557668,  0.0214896512,  0.0016333592,  0.0734387575,  0.0010109168,   0.069748043,  0.0383547447,   2.77981e-05,   0.069259339,  -5.12561e-05,  0.0477306349,   2.35338e-05, -0.0341657685,   0.002211703, -0.0389892202, -0.0003537279,  0.0196100456, -0.0021962626,  0.0826921587,  0.0840139552,    1.0779e-06,   0.043086792,   4.15353e-05, -0.0115371438,  -3.55085e-05, -0.0456442695,  0.0014432025, -0.0172031873, -0.0012448145, -0.0605370668, -0.0008686339, -0.0488305616,  0.0028780362, -0.0005959304);


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
