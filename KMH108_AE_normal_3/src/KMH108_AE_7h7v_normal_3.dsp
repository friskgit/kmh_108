// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 17:28:09

//------- decoder information -------
// decoder file = ../decoders/KMH108_AE_7h7v_pinv_match_rV_max_rE_2_band.dsp
// description = KMH108_AE_7h7v_pinv_match_rV_max_rE_2_band
// speaker array name = KMH108_AE
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HV
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L R FSR SR RR RL SL FSR 
//-------


// start decoder configuration
declare name "KMH108_AE_7h7v_normal_3";

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
gamma(1) = (  0.6363286456,  0.6110599437,  0.5620276757,  0.4921424976,   0.405528278,  0.3072504472,  0.2029838295, 0.09864291124);

// gain matrix
s(00,0) = (  0.0769751325,  0.0568423234, -0.0019290099,  0.1007161587,  0.0990075637,  0.0001188378,  -0.039287356,  0.0028480629,  0.0714616084,  0.1195988273, -0.0002252002,  -0.034750605,  0.0025250681, -0.0602841663, -0.0019785027,   0.024005395,  0.1089770701,  0.0002797286, -0.0640348918, -0.0001337164,  0.0306869265, -0.0032046427, -0.0472333511,  0.0004667098, -0.0238654626,  0.0772527356, -0.0002645505, -0.0789332204,  0.0002296294,  0.0274048652, -0.0024160017,  0.0460315217,  0.0020174153, -0.0155878214,  0.0012495436, -0.0645341009,  0.0284188669,  0.0001827763, -0.0732839018, -0.0002615822,  0.0519976139,  0.0001139987, -0.0267967415,   0.002732089,  0.0393477219, -0.0004364336,  0.0168589701,  -0.002713758,  -0.083608536, -0.0242638609,  -5.55504e-05, -0.0521662866,  0.0002273159,    0.06470164,  -0.000175005, -0.0233422335,  0.0017828197, -0.0378899017, -0.0015375111,  0.0125587421, -0.0010736748,  0.0416993074,  0.0035556078, -0.0814586561);
s(01,0) = (  0.0770469021, -0.0568334761, -0.0019471923,  0.1007267537, -0.0990867194, -0.0001063305, -0.0393307795,  0.0028751114,  0.0713118718, -0.1195076058,  0.0002040149,  0.0347512985,  0.0025488688, -0.0602774379, -0.0019979265,  0.0240948545, -0.1089439427, -0.0002595554,  0.0640741536,  0.0001196432,  0.0307310069, -0.0032350777, -0.0471475456,  0.0004725691, -0.0237899279, -0.0773562642,  0.0002565198,  0.0788854292, -0.0002080274, -0.0274125597, -0.0024387744,  0.0460107477,  0.0020372211, -0.0156433493,  0.0012594405, -0.0646627661,  -0.028344314, -0.0001949064,  0.0732562194,  0.0002427176, -0.0520178089, -0.0001020007, -0.0268450151,   0.002758036,  0.0392888568, -0.0004419128,  0.0168150285, -0.0027376334, -0.0835786784,  0.0243246654,   8.93169e-05,  0.0522274786, -0.0002204156, -0.0646730934,  0.0001585417,  0.0233550267,  0.0017996242, -0.0378587051, -0.0015526055,  0.0126012498, -0.0010821788,  0.0417689021,  0.0035883386, -0.0813751704);
s(02,0) = (  0.0833750893, -0.1021288971, -0.0029044421,  0.0500737145, -0.0914412072,  -6.53755e-05, -0.0428917599,  0.0042884472, -0.0734877687,  0.0216524542,  0.0001266045,  0.0625089774,  0.0038019058, -0.0285683225, -0.0029797982, -0.1067557173,  0.1121890412, -0.0001638904,  0.0590957596,   7.35605e-05,  0.0340078531, -0.0048253643,  0.0457718016,   0.000704285, -0.0195475524,  0.0662334056,  0.0001669253, -0.0144236785, -0.0001290945, -0.0493803322, -0.0036376884,   0.020134954,   0.003038404,  0.0710502768,  0.0018793628,  0.0811607013, -0.0420047675, -0.0001344137, -0.0751452087,  0.0001532586, -0.0479424234,  -6.27134e-05, -0.0301832669,  0.0041138204,  -0.035446295, -0.0006585969,   0.014390625,   -0.00408417,  0.0944330021, -0.0824018842,   7.33265e-05, -0.0449388172, -0.0001434312,  0.0119373351,   9.83854e-05,  0.0421339599,  0.0026843287, -0.0150598646, -0.0023156262, -0.0587479412, -0.0016148493, -0.0579417088,  0.0053527071,  0.0061554304);
s(03,0) = (  0.0804692759, -0.1147459904,  -0.005916683, -0.0321971645,  0.0764115395,  0.0012244246, -0.0426877631,  0.0087348415, -0.0950249005,  0.0696988993, -0.0023298732,  0.0708655654,    0.00774492,  0.0239847128, -0.0060655435,  0.0873891998, -0.1074057157,  0.0029173521, -0.0506247739, -0.0013777236,  0.0357621446, -0.0098284507,  0.0579504352,   0.001425949,   0.039416531,  -0.006469643, -0.0028010394, -0.0442871367,  0.0023756965, -0.0567237475, -0.0074103901, -0.0239524026,  0.0061848388,    -0.0569157,  0.0038397636, -0.0968743683,  0.0925425488,  0.0020024012,  0.0701455932, -0.0027280988,  0.0422876597,  0.0011745657, -0.0335569836,  0.0083791562, -0.0436209484, -0.0013334454, -0.0238308609, -0.0083301469,  0.0317122742,  -0.040507268, -0.0007228884,  0.0058486889,  0.0024068032,  0.0348356246,  -0.001810564,   0.049046307,  0.0054682868,  0.0247990919, -0.0047135849,  0.0460034213, -0.0032993308,  0.0594742667,  0.0109087816,  0.0615834543);
s(04,0) = (  0.0757048036, -0.0606421232,  0.0317187791, -0.1022083406,  0.0931682534, -0.0313461708, -0.0247014292, -0.0468044016,   0.069724532,  -0.105531037,  0.0597285006,  0.0218190604, -0.0415197849,  0.0397197972,  0.0324319489, -0.0163569159,  0.0911451823, -0.0749884882, -0.0267788397,  0.0352707366, -0.0015576082,  0.0526643504,  -0.026892314, -0.0074844594, -0.0268286883, -0.0570578665,  0.0723545893,  0.0231655785, -0.0609032233,  0.0006607649,  0.0397264019, -0.0046586481,  -0.033069811,  0.0061643678,  -0.020790613,  0.0619052733,  0.0160351217, -0.0522855573, -0.0119501103,   0.070123866, -0.0110413423, -0.0300697456,  0.0214292603, -0.0448985128,  0.0040106756,  0.0069989307,  0.0038622534,   0.044843734, -0.0645483874,  0.0178991991,  0.0197979311,  0.0002779825, -0.0621709433,  0.0208084551,    0.04641552, -0.0161598553, -0.0293149691, -0.0193084552,  0.0252031402, -0.0010880979,  0.0178644096,  -0.009018116, -0.0585667574,  0.0472013537);
s(05,0) = (  0.0757140823,  0.0602446942,  0.0317227281, -0.1022942088, -0.0929952713,  0.0312650725, -0.0247044312, -0.0468664687,  0.0701475067,  0.1057692296, -0.0596173745, -0.0216153124, -0.0415249542,   0.039742053,  0.0326503891, -0.0169402758, -0.0912991868,  0.0749543314,  0.0267292491, -0.0351794848, -0.0015578571,  0.0527341884, -0.0270433345, -0.0078894455, -0.0262875009,  0.0573070447, -0.0725091423, -0.0233443707,  0.0607899117, -0.0007755047,  0.0397313479, -0.0046407796, -0.0332925474,  0.0062983562, -0.0202727105,  0.0614364798,  -0.016471527,  0.0526913356,  0.0119483433,  -0.070091925,  0.0110206118,  0.0299919497,  0.0214319741, -0.0449580525,  0.0040132982,  0.0073776447,  0.0038513218,  0.0443778426, -0.0642807001, -0.0170493908, -0.0204300021, -0.0001490469,  0.0623037434,  -0.020643415,  -0.046329163,  0.0162174843, -0.0293186189, -0.0193545935,  0.0253728919, -0.0009830141,     0.0174194,  -0.009042463, -0.0583572415,  0.0473009892);
s(06,0) = (  0.0802663897,  0.1149851905, -0.0059688216, -0.0316278231, -0.0758336687,  -0.001222629, -0.0426079373,  0.0088140216, -0.0955863034, -0.0706699482,  0.0023345922, -0.0710111676,  0.0078131692,  0.0236747532, -0.0061274098,  0.0868215917,  0.1068635168, -0.0029430382,  0.0502543957,  0.0013757031,  0.0357352883, -0.0099175442,  0.0582782641,  0.0014543751,  0.0407345673,  0.0076573036,  0.0028609927,  0.0449134505, -0.0023805083,  0.0568378301, -0.0074756914, -0.0237525991,  0.0062479219, -0.0565225839,  0.0038531692,  -0.096907848, -0.0928483253, -0.0021008854, -0.0697411145,  0.0027521187, -0.0419902053, -0.0011728431, -0.0335676946,  0.0084551121, -0.0438526139, -0.0013600275, -0.0247059125, -0.0083850464,  0.0299857268,  0.0389508102,  0.0008499124, -0.0067249751, -0.0024583183,  -0.035336547,  0.0018142312, -0.0491428302,   0.005516474,  0.0246678716, -0.0047616617,  0.0456653408, -0.0033108496,   0.059456665,  0.0109964008,  0.0626186406);
s(07,0) = (  0.0834589642,   0.102092388,  -0.002922011,  0.0500340142,  0.0913867547,   7.86379e-05, -0.0429409816,  0.0043142582, -0.0735701242,  -0.021498567, -0.0001478932, -0.0624801399,  0.0038249035, -0.0285313993, -0.0029973285, -0.1065859933, -0.1121653803,  0.0001809517, -0.0590725014,  -8.84834e-05,  0.0340558936, -0.0048544068,  0.0458151705,  0.0007076133, -0.0196581728, -0.0664360811, -0.0001661838,  0.0143325024,   0.000150802,  0.0493499564, -0.0036596927,  0.0200910159,   0.003056279,  0.0709400849,  0.0018919315,  0.0809822505,   0.042080254,  0.0001068957,  0.0751298406,  -0.000169213,  0.0479352496,   7.54357e-05, -0.0302344513,  0.0041385804, -0.0354718202, -0.0006617093,  0.0144733765, -0.0041099624,   0.094704278,  0.0824647138,   -1.9013e-05,  0.0450558453,   0.000142794, -0.0118714908, -0.0001149291, -0.0421014232,  0.0027005662, -0.0150095036, -0.0023292492, -0.0586591777,  -0.001625649, -0.0578398153,  0.0053855855,  0.0061722711);


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
