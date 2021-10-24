// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 17:23:33

//------- decoder information -------
// decoder file = ../decoders/KMH108_AE_7h7v_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMH108_AE_7h7v_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMH108_AE_7h7v_normal_4";

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
s(00,0) = (  0.0884923393,  0.0573417204, -0.0015537064,  0.1041719286,  0.0969350916,   8.61134e-05, -0.0448903543,  0.0022939594,  0.0699551126,  0.1148069913, -0.0001630799, -0.0350724119,   0.002033797, -0.0626711331, -0.0015936029,  0.0218063469,  0.1041724231,  0.0002023063, -0.0626624199,  -9.68948e-05,  0.0346515408,  -0.002581165, -0.0460459288,  0.0003759699, -0.0253857491,  0.0735940668, -0.0001908602, -0.0758118691,  0.0001662873,  0.0276779736, -0.0019459503,  0.0482351825,  0.0016249455, -0.0141897205,  0.0010063556, -0.0645333414,  0.0276625685,  0.0001311139, -0.0700107465, -0.0001891823,  0.0508517391,   8.26068e-05, -0.0298623893,  0.0022005487,  0.0381748524, -0.0003515801,  0.0177134723, -0.0021857035,  -0.083260211, -0.0218237383,  -3.85723e-05, -0.0497272494,  0.0001639973,  0.0621783222, -0.0001267308, -0.0235917255,  0.0014359587, -0.0400473177, -0.0012384023,  0.0114582946, -0.0008647147,  0.0420861103,  0.0028638041, -0.0817933908);
s(01,0) = (  0.0885472811, -0.0573358503, -0.0015667481,  0.1041794965, -0.0969963566,  -7.64558e-05, -0.0449232324,  0.0023133613,  0.0698452503, -0.1147361132,  0.0001468088,  0.0350735361,  0.0020508685, -0.0626662872, -0.0016075386,  0.0218713322, -0.1041472744, -0.0001870509,  0.0626928782,   8.60281e-05,  0.0346844571,  -0.002602996, -0.0459827966,  0.0003801794, -0.0253300298, -0.0736778985,  0.0001853466,  0.0757744753, -0.0001496962, -0.0276843804, -0.0019622844,  0.0482202658,  0.0016391552, -0.0142300863,  0.0010134455, -0.0646274011, -0.0276023312, -0.0001415683,  0.0699901277,  0.0001749166, -0.0508674956,  -7.33425e-05, -0.0298980968,  0.0022191606,  0.0381313471, -0.0003555166,  0.0176809149, -0.0022028205, -0.0832396107,  0.0218716513,   6.60194e-05,  0.0497763357, -0.0001592597, -0.0621557051,  0.0001140863,  0.0236020013,   0.001448012, -0.0400249272, -0.0012492318,  0.0114892219, -0.0008708067,  0.0421372341,  0.0028872772, -0.0817310762);
s(02,0) = (  0.0934344506, -0.1055729779, -0.0022779079,  0.0517380921, -0.0907102822,   -4.1218e-05, -0.0476616723,  0.0033633521, -0.0721238788,  0.0212936323,   8.01276e-05,  0.0646298415,  0.0029817744, -0.0300395655,  -0.002336974,  -0.105029055,  0.1070507871, -0.0001044567,  0.0585979902,   4.63785e-05,  0.0371885787, -0.0037844465,  0.0452504602,  0.0005522946, -0.0205794246,  0.0644295996,  0.0001076526, -0.0141493773,  -8.17036e-05, -0.0510708253, -0.0028529813,  0.0218266449,   0.002382937,  0.0698136716,   0.001474038,  0.0780674325, -0.0399114955,  -8.85598e-05,  -0.071738661,   9.76804e-05, -0.0475137121,  -3.95395e-05, -0.0324362233,  0.0032263954, -0.0353762651, -0.0005164664,  0.0148072565, -0.0032032254,  0.0909384605, -0.0826237262,   5.10484e-05, -0.0436840019,  -9.25009e-05,  0.0116803969,   6.22679e-05,  0.0435895123,  0.0021052764, -0.0169646821, -0.0018160822, -0.0576512149, -0.0012665725, -0.0552014013,  0.0041980781,  0.0056578755);
s(03,0) = (  0.0911734838, -0.1168274082,  -0.004547024, -0.0339271001,  0.0733985573,   0.000904021, -0.0474719906,  0.0067128372, -0.0940464979,   0.067653394, -0.0017200768,  0.0719836112,  0.0059520405,   0.024056077, -0.0046615511,  0.0858807812, -0.1028802914,  0.0021534978,  -0.048339304, -0.0010172051,  0.0384830752, -0.0075532898,  0.0581030709,  0.0010960931,  0.0377170653, -0.0056361556, -0.0020671087, -0.0434092163,  0.0017539068, -0.0574245714, -0.0056949513, -0.0228535094,  0.0047532332, -0.0561231181,  0.0029505856,  -0.095186238,  0.0902409497,  0.0014768939,   0.067608826,  -0.002013797,  0.0401020137,   0.000867209, -0.0349551315,  0.0064394885, -0.0445140667, -0.0010249878, -0.0232953529, -0.0064015143,  0.0297764749, -0.0418193734, -0.0005317991,  0.0048989665,  0.0017761707,  0.0345201704, -0.0013366862,  0.0494853394,  0.0042024274,   0.022854728, -0.0036225306,  0.0455274991, -0.0025353013,  0.0597460093,  0.0083833685,  0.0635067208);
s(04,0) = (  0.0874789438, -0.0598121905,  0.0325908247, -0.1041711239,  0.0910535682, -0.0303575184, -0.0302269391,  -0.048092859,  0.0671420499, -0.1015033977,  0.0578433922,  0.0217939121, -0.0426612901,  0.0402921799,  0.0333299379, -0.0151390889,  0.0873449613, -0.0726186412, -0.0264667327,  0.0341583042,  0.0020343628,  0.0541141236, -0.0247237624, -0.0077021709, -0.0270021869, -0.0552500517,  0.0700624395,  0.0219753944, -0.0589810392,  0.0001157605,  0.0408186014,  -0.004374971, -0.0339854614,  0.0052234524, -0.0213468282,  0.0602693844,  0.0164036258, -0.0506204911, -0.0109592155,  0.0679077547, -0.0102610292, -0.0291213515,  0.0189894205, -0.0461345038,  0.0017617979,  0.0072025189,  0.0036004841,  0.0460626911, -0.0647555841,  0.0169338845,  0.0191533149,  0.0002753777, -0.0602014052,  0.0205272061,  0.0449505865, -0.0152025862, -0.0301209267, -0.0201917351,   0.025900975, -0.0001993883,  0.0183423395, -0.0070165341, -0.0601705283,  0.0506307226);
s(05,0) = (  0.0874855063,  0.0594627604,  0.0325935288, -0.1042605492, -0.0908733945,   0.030273152, -0.0302290992,  -0.048151309,  0.0675339065,  0.1016669033, -0.0577272304, -0.0216211543, -0.0426648297,  0.0403183814,  0.0335403192, -0.0156967858, -0.0875104874,  0.0725810548,  0.0264153126,  -0.034063375,  0.0020342708,  0.0541798916, -0.0248591975, -0.0080940747, -0.0264581295,  0.0555520733, -0.0702188314, -0.0221069188,  0.0588625927, -0.0002041332,  0.0408219882, -0.0043622886, -0.0341999804,  0.0053486025, -0.0208445835,  0.0598044438, -0.0169043125,  0.0510356726,  0.0109639272, -0.0678726066,  0.0102390208,  0.0290404204,  0.0189912134, -0.0461905737,  0.0017562117,  0.0075689992,  0.0035769819,   0.045609962, -0.0645077349, -0.0160997217, -0.0198020815, -0.0001753203,  0.0603357855, -0.0203991783, -0.0448603161,   0.015236074, -0.0301234259, -0.0202316453,  0.0260644641,  -9.39935e-05,  0.0179107839, -0.0070338353, -0.0599655757,  0.0507489163);
s(06,0) = (  0.0910162807,   0.117038392, -0.0045864445, -0.0333973723, -0.0728131272, -0.0009022094, -0.0474097332,  0.0067726636, -0.0945737349, -0.0685791119,  0.0017228803, -0.0721119267,  0.0060036418,   0.023760919, -0.0047081761,  0.0852988693,  0.1023666504, -0.0021722026,  0.0479629763,  0.0010151667,  0.0384613424, -0.0076206066,  0.0584173588,  0.0011173019,    0.03900545,  0.0069012023,  0.0021121812,  0.0440098884, -0.0017567654,  0.0575249787, -0.0057443237, -0.0226543495,  0.0048007752, -0.0557250294,  0.0029610862, -0.0951942309, -0.0905780288, -0.0015518507, -0.0672336215,  0.0020312883, -0.0397986899, -0.0008654711, -0.0349620402,  0.0064968788, -0.0447431158, -0.0010448207, -0.0241524886, -0.0064433529,  0.0280629308,  0.0402403292,  0.0006291338, -0.0058103864, -0.0018148994, -0.0350037351,  0.0013388648, -0.0495701771,  0.0042388604,  0.0227144282, -0.0036587633,  0.0451891679, -0.0025443241,  0.0597207328,   0.008449767,   0.064544582);
s(07,0) = (   0.093497459,  0.1055432744,     -0.002291,    0.05171209,  0.0906712418,   5.13744e-05, -0.0476986046,  0.0033825994, -0.0721803975, -0.0211683239,  -9.63574e-05, -0.0646066893,   0.002998912, -0.0300142379, -0.0023500878, -0.1049042158, -0.1070298614,  0.0001172524, -0.0585818548,  -5.78065e-05,  0.0372245676, -0.0038061035,  0.0452796183,  0.0005548699, -0.0206721676, -0.0645963105, -0.0001065078,  0.0140744515,   9.82526e-05,  0.0510467188, -0.0028693786,  0.0217956243,  0.0023963086,  0.0697326998,  0.0014832816,   0.077926527,  0.0399592179,   6.65729e-05,  0.0717254019, -0.0001096461,  0.0475095358,   4.92824e-05, -0.0324745234,  0.0032448589, -0.0353926987, -0.0005188746,  0.0148757548, -0.0032223347,  0.0911459638,  0.0826719089,   -8.3012e-06,  0.0437807388,   9.15172e-05, -0.0116256374,  -7.48802e-05, -0.0435638743,  0.0021173764, -0.0169286172,  -0.001826273,  -0.057586058, -0.0012745151, -0.0551200241,  0.0042225277,  0.0056858327);


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
