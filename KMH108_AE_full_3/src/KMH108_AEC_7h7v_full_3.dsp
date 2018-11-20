// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:05:36

//------- decoder information -------
// decoder file = ../decoders/KMH108_AEC_7h7v_pinv_match_rV_max_rE_2_band.dsp
// description = KMH108_AEC_7h7v_pinv_match_rV_max_rE_2_band
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
declare name "KMH108_AEC_7h7v_full_3";

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
s(00,0) = (  0.0699863635,  0.0568463919, -0.0012720409,  0.0797550349,  0.0990125676,  0.0001197304, -0.0355205846,   0.001878052,  0.0446886006,  0.1195928339, -0.0002273516, -0.0347526603,  0.0016650977, -0.0479221229, -0.0013045362, -0.0048314971,  0.1089620427,  0.0002835237, -0.0640393235, -0.0001347207,  0.0274458687, -0.0021131856, -0.0295750088,   0.000307494, -0.0545115234,   0.077277167, -0.0002701592,  -0.078926896,  0.0002318231,    0.02740598, -0.0015931763,   0.036812703,  0.0013301934,  0.0033869708,  0.0008243264, -0.0953209107,  0.0284045811,  0.0001898829, -0.0732776343,  -0.000265131,  0.0520023831,  0.0001148549, -0.0236788953,  0.0018015772,  0.0246734568, -0.0002875464,  0.0371278789, -0.0017898363, -0.1143816751, -0.0242773969,  -6.32089e-05, -0.0521776141,  0.0002321352,  0.0646944276, -0.0001766768, -0.0233427414,  0.0011756392, -0.0305004448,  -0.001013766, -0.0029460502, -0.0007083055,  0.0632197537,  0.0023448064, -0.1113342822);
s(01,0) = (  0.0302884798,  -1.76324e-05, -0.0028472242,  0.0908429765,  -2.16866e-05,   -3.8683e-06,  -0.016324732,  0.0042039102,  0.1160309794,   2.59747e-05,     9.324e-06,    8.9074e-06,  0.0037270078, -0.0535756016, -0.0029208896,  0.1249756043,    6.5127e-05,  -1.64473e-05,   1.92065e-05,    4.3526e-06,  0.0140463529, -0.0047302431, -0.0765291212,  0.0006900219,  0.1328163228, -0.0001058826,   2.43074e-05,  -2.74095e-05,   -9.5073e-06,   -4.8317e-06, -0.0035660255,  0.0399532459,  0.0029783368, -0.0822344557,  0.0018428397,  0.1334263121,   6.19129e-05,  -3.07993e-05,  -2.71626e-05,   1.53803e-05,  -2.06691e-05,   -3.7108e-06, -0.0135123685,  0.0040327257,  0.0635964907, -0.0006452591, -0.0878430008, -0.0040041648,  0.1333670651,   5.86631e-05,   3.31909e-05,   4.90922e-05,  -2.08863e-05,   3.12575e-05,    7.2457e-06,    2.2013e-06,  0.0026314471, -0.0320250126, -0.0022698479,  0.0671958952, -0.0015834667, -0.0932670124,  0.0052474666,   0.129477352);
s(02,0) = (  0.0700565954, -0.0568294067, -0.0012900788,  0.0797610179, -0.0990817143, -0.0001054377, -0.0355631793,   0.001904887,  0.0445329733, -0.1195136005,   0.000201863,  0.0347492428,  0.0016887092, -0.0479126745, -0.0013238116, -0.0047483824, -0.1089589735, -0.0002557595,   0.064069721,  0.0001186386,  0.0274892359, -0.0021433804,  -0.029485318,  0.0003133184, -0.0544427316, -0.0773318274,  0.0002509099,   0.078891755, -0.0002058332, -0.0274114446,  -0.001615768,  0.0367899007,   0.001349848,  0.0033356179,  0.0008341298, -0.0954563498,  -0.028358603, -0.0001877982,  0.0732624883,   0.000239168, -0.0520130386, -0.0001011443, -0.0237264829,  0.0018273195,  0.0246113631, -0.0002929929,   0.037088397, -0.0018135084, -0.1143585884,  0.0243111265,   8.16567e-05,  0.0522161486, -0.0002155952, -0.0646803073,  0.0001568694,  0.0233545186,  0.0011923101, -0.0304676224, -0.0010287452, -0.0029069538,  -0.000716729,  0.0632940833,  0.0023772709, -0.1112573699);
s(03,0) = (  0.0806868308, -0.1021273322, -0.0026517363,  0.0420109328, -0.0914392824,  -6.50321e-05, -0.0414428559,  0.0039153285, -0.0837861154,  0.0216501488,   0.000125777,  0.0625081868,  0.0034711147, -0.0238132121, -0.0027205542, -0.1178479455,  0.1121832608, -0.0001624306,  0.0590940549,   7.31742e-05,   0.032761167, -0.0044055308,   0.052564155,   0.000643042, -0.0313356847,  0.0662428032,  0.0001647679, -0.0144212458, -0.0001282507, -0.0493799033, -0.0033211852,  0.0165888978,  0.0027740613,   0.078349008,  0.0017158013,  0.0693184293, -0.0420102626, -0.0001316801, -0.0751427979,  0.0001518935, -0.0479405889,   -6.2384e-05, -0.0289839747,  0.0037558952, -0.0410908109, -0.0006013268,  0.0221871434, -0.0037287797,  0.0825959886, -0.0824070909,   7.03806e-05, -0.0449431744, -0.0001415774,  0.0119345608,   9.77423e-05,  0.0421337645,  0.0024507743, -0.0122174799, -0.0021141656, -0.0647119228, -0.0014743085, -0.0496637814,  0.0048869674,  -0.005336351);
s(04,0) = (  0.0790436296, -0.1147451605, -0.0057826672, -0.0364730462,  0.0764125603,  0.0012246067, -0.0419193755,  0.0085369679, -0.1004863545,  0.0696976767, -0.0023303121,  0.0708651461,  0.0075694937,   0.026506459, -0.0059280604,  0.0815067319, -0.1074087812,  0.0029181262, -0.0506256779, -0.0013779284,  0.0351009978, -0.0096058032,   0.061552579,  0.0013934704,  0.0331650089, -0.0064646592, -0.0028021835, -0.0442858466,   0.002376144, -0.0567235201, -0.0072425411, -0.0258329591,  0.0060446517, -0.0530450123,  0.0037530231, -0.1031546019,  0.0925396346,  0.0020038509,  0.0701468717, -0.0027288227,  0.0422886326,  0.0011747403, -0.0329209709,  0.0081893401, -0.0466143671, -0.0013030738,  -0.019696185, -0.0081416752,  0.0254348292, -0.0405100292, -0.0007244506,  0.0058463782,  0.0024077863,  0.0348341533, -0.0018109051,  0.0490462034,  0.0053444274,   0.026306475, -0.0046067456,  0.0428405825, -0.0032247988,  0.0638642451,  0.0106617889,   0.055489094);
s(05,0) = (  0.0746830907, -0.0606415284,  0.0318148237, -0.1052727216,  0.0931689849, -0.0313460403, -0.0241507516,  -0.046946211,  0.0658104911, -0.1055319132,  0.0597281861,  0.0218187599, -0.0416455071,  0.0415270481,  0.0325304784, -0.0205726833,  0.0911429854, -0.0749879333, -0.0267794876,  0.0352705898, -0.0020314299,  0.0528239144, -0.0243107784, -0.0075077357, -0.0313089445, -0.0570542948,  0.0723537694,  0.0231665031, -0.0609029026,  0.0006609279,  0.0398466936, -0.0060063798, -0.0331702784,  0.0089383599,  -0.020852777,  0.0574044405,  0.0160330333, -0.0522845184, -0.0119491941,  0.0701233471, -0.0110406451, -0.0300696204,  0.0218850693, -0.0450345476,  0.0018653928,   0.007020697,   0.006825437,  0.0449788053, -0.0690472216,  0.0178972202,  0.0197968115,  0.0002763265, -0.0621702387,  0.0208074007,  0.0464152756, -0.0161599295,  -0.029403735, -0.0182281643,  0.0252797083, -0.0033547984,  0.0179178243, -0.0058719657, -0.0587437687,  0.0428337301);
s(06,0) = (  0.0746852066,  0.0602452932,  0.0318194461, -0.1053800727, -0.0929945346,  0.0312652039,  -0.024149893, -0.0470092722,  0.0662060262,  0.1057683472, -0.0596176913,  -0.021615615, -0.0416515577,  0.0415619738,  0.0327496094,  -0.021185598, -0.0913013991,  0.0749548901,  0.0267285967, -0.0351796326, -0.0020350006,   0.052894871, -0.0244437009,  -0.007912885, -0.0307991662,  0.0573106415,  -0.072509968, -0.0233434396,  0.0607902346, -0.0007753406,   0.039852483, -0.0059979597, -0.0333937192,  0.0090917955, -0.0203353103,  0.0569040937, -0.0164736301,  0.0526923818,   0.011949266, -0.0700924474,  0.0110213139,  0.0299920757,  0.0218909786,  -0.045095041,  0.0018529758,  0.0073995636,  0.0068352789,  0.0445138609, -0.0688110736, -0.0170513836, -0.0204311296, -0.0001507145,  0.0623044529, -0.0206444768, -0.0463294092,  0.0162174095,  -0.029408007, -0.0182667292,  0.0254499968, -0.0032656054,  0.0174731891, -0.0058742565, -0.0585354938,  0.0429027461);
s(07,0) = (  0.0788410253,  0.1149860203, -0.0058348323,  -0.035902859, -0.0758326482, -0.0012224469, -0.0418397016,  0.0086161872, -0.1010466771, -0.0706711705,  0.0023341534, -0.0710115867,  0.0076377777,  0.0261960006, -0.0059899539,  0.0809402873,   0.106860452, -0.0029422642,  0.0502534918,  0.0013754982,  0.0350742723, -0.0096949408,  0.0618796954,  0.0014219029,  0.0344842816,  0.0076622864,  0.0028598488,  0.0449147404, -0.0023800609,  0.0568380575, -0.0073078756, -0.0256327837,  0.0061077625, -0.0526526617,  0.0037664459, -0.1031868395, -0.0928512389,  -0.002099436, -0.0697398363,  0.0027513949, -0.0419892327, -0.0011726685, -0.0329318077,  0.0082653335, -0.0468454405, -0.0013296618, -0.0205720543, -0.0081966119,  0.0237095235,  0.0389480495,  0.0008483504, -0.0067272853, -0.0024573354, -0.0353380179,  0.0018138903, -0.0491429338,  0.0053926391,  0.0261749565, -0.0046548435,  0.0425031276, -0.0032363323,  0.0638457751,   0.010749457,  0.0565254857);
s(08,0) = (  0.0807689619,   0.102093954, -0.0026691413,  0.0419660025,  0.0913886808,   7.89814e-05, -0.0414911378,  0.0039408975,  -0.083875151, -0.0215008739, -0.0001487213,  -0.062480931,  0.0034938978, -0.0237732044, -0.0027379163, -0.1176854166, -0.1121711644,  0.0001824124, -0.0590742072,    -8.887e-05,  0.0328083988, -0.0044343011,  0.0526119298,  0.0006463306, -0.0314539516, -0.0664266774, -0.0001683426,  0.0143349367,  0.0001516463,  0.0493503855, -0.0033429842,  0.0165426595,  0.0027917649,  0.0782435505,  0.0017282639,  0.0691322969,  0.0420747553,   0.000109631,   0.075132253,  -0.000170579,  0.0479370853,   7.57653e-05, -0.0290343811,   0.003780423, -0.0411199974, -0.0006044021,  0.0222749522, -0.0037543416,  0.0828595863,  0.0824595038,  -2.19608e-05,  0.0450514853,   0.000144649, -0.0118742669, -0.0001155726, -0.0421016187,  0.0024668602, -0.0121652752, -0.0021276578, -0.0646270278,  -0.001485017, -0.0495565183,  0.0049195438, -0.0053269646);


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
