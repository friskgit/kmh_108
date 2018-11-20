// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Sep-2018 17:51:55

//------- decoder information -------
// decoder file = ../decoders/KMH108_AE_7H7P_Slepian41_2_band.dsp
// description = KMH108_AE_7H7P_Slepian41_2_band
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
declare name	"KMH108_AE_7H7P_Slepian41_2_band";

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
s(00,0) = (  0.0222352958,  0.0312164425, -0.0015668113,  0.0472905825,  0.0684794155, -0.0015024914,  -0.053662687,  -0.004051142,  0.0315143333,  0.0975015165, -0.0074123422, -0.0423725245,  0.0045093881, -0.0653285708, -0.0014688129,  0.0062909966,  0.0941390249, -0.0034267837, -0.0747238717,  0.0027466164,  0.0667125035,  0.0076547472, -0.0335431593, -0.0005446695, -0.0375641099,  0.0846460515, -0.0103405672, -0.0925960827,  0.0097801204,  0.0482581777, -0.0048096668,  0.0766687468,   0.001366943, -0.0063623978,  0.0019229049, -0.0860083252,  0.0328698612,  0.0002601308, -0.0825167039,  0.0014299643,  0.0788263627, -0.0015569415, -0.0704148362, -0.0062274828,  0.0341674079,  0.0004688288,   0.031528399,   0.003790617, -0.0809095806, -0.0108234564,   0.024750995, -0.0722100172, -0.0007867044,  0.0954213079,  0.0058257222, -0.0516626353, -0.0100780305, -0.0858417512,  0.0058595366,  0.0072315951,  0.0026149357,  0.0784783094, -0.0580601859, -0.1384465215);
s(01,0) = (  0.0222590631, -0.0311355132, -0.0015740215,  0.0472978537, -0.0684904694,  0.0015022634, -0.0537226477, -0.0040391151,  0.0314079884,  -0.097615811,  0.0073959401,  0.0422649355,  0.0045309977, -0.0653311262, -0.0014791282,  0.0063774045, -0.0941505156,  0.0034614504,   0.074727379, -0.0027467266,  0.0667942981,   0.007630959, -0.0334380231, -0.0005324906, -0.0375330874, -0.0844376169,  0.0102982024,   0.092726394, -0.0097541562, -0.0481401374, -0.0048392271,  0.0766571772,  0.0013857191, -0.0064334256,  0.0019070432, -0.0861429446, -0.0330721668, -0.0002258536,  0.0825007904, -0.0014692705, -0.0788175531,   0.001560951, -0.0705122318, -0.0062005832,  0.0340724949,  0.0004514378,  0.0314940112,  0.0037921131, -0.0808364443,  0.0107089621, -0.0248926561,  0.0720758625,  0.0008310396, -0.0955902096, -0.0058502068,  0.0515436496, -0.0100702377, -0.0858058579,  0.0058224943,  0.0072871599,  0.0026271086,  0.0785947009, -0.0580063759, -0.1383551019);
s(02,0) = (  0.0278351421, -0.0478639688, -0.0012136769,  0.0264274215, -0.0617944539,  0.0023453391, -0.0668236942, -0.0045663536, -0.0559235595,  0.0014198428,  0.0075344518,  0.0650902897,  0.0033766066, -0.0377979524,  0.0072042463, -0.0872418468,  0.0961802074, -0.0036337339,  0.0678664281, -0.0042831204,  0.0820876002,  0.0088294984,  0.0617274158,  0.0047117469, -0.0319356385,  0.0649550367, -0.0022745549, -0.0040912039, -0.0101285644, -0.0743862703, -0.0027194107,  0.0468573729, -0.0096396998,  0.0840507249, -0.0004241406,   0.073729045, -0.0394245595, -0.0046410545, -0.0793679743,  0.0043960944, -0.0722360379,   0.002434135,  -0.085138209, -0.0085840766, -0.0661739045, -0.0032968678,  0.0255996982,  0.0037368503,  0.0840904554, -0.1444310513, -0.0292328913,  -0.061640968, -0.0092103168,  0.0086505774, -0.0042512902,  0.0801418755, -0.0151375094, -0.0563254081, -0.0041337002, -0.0885316697,  0.0042905011, -0.0586121643,  0.0612711559,  0.0251710857);
s(03,0) = (  0.0236819961, -0.0534310058, -0.0014319839, -0.0079459391,  0.0498004749,  0.0024548688, -0.0570372633, -0.0009446088, -0.0654954554,  0.0545663887, -0.0003563038,  0.0725016149,   0.004083441,  0.0100747963,  0.0067643092,  0.0546079229,  -0.108146109, -0.0084052627, -0.0519502869, -0.0044648757,  0.0705814389,  0.0019279482,  0.0713063907, -0.0037590356,  0.0264349348, -0.0113152338,  0.0142619056, -0.0564309052, -0.0008127754, -0.0825316081, -0.0040710524, -0.0100793004, -0.0088109111, -0.0532839927,  -0.003452807,  -0.109735639,  0.1037548461, -0.0036876452,  0.0962137244,  0.0087640609,  0.0513150871,  0.0023829547, -0.0739997556, -0.0025607826, -0.0749879693,  0.0030442064, -0.0233673979,  0.0059269809,  0.0320075483, -0.0871629517,  0.0738907345,  0.0042931938, -0.0015124265,  0.0654834727,  0.0112581863,  0.0883336358, -0.0115601876,   0.008600329, -0.0062174017,  0.0572199858,  0.0002184601,  0.1005599941,  0.0246979338,   0.123547096);
s(04,0) = (  0.0174296102, -0.0295341574,    0.01347254, -0.0393924119,  0.0499046313, -0.0162766273, -0.0351351386, -0.0306897799,  0.0297053685, -0.0843963309,  0.0491466833,  0.0296874967, -0.0410590654,   0.034410113,  0.0327293545, -0.0144174503,  0.0805306459, -0.0692225265, -0.0272408151,  0.0323381881,   0.024353122,  0.0608687322, -0.0144294456, -0.0082446227, -0.0317958188, -0.0769095343,  0.0912907637,  0.0273508505, -0.0777084191, -0.0132296181,  0.0611103201, -0.0014897155, -0.0515719901,  0.0073547618, -0.0316748258,  0.0812329612,  0.0382736389, -0.0625409531, -0.0109440294,  0.0872155813, -0.0111783702,  -0.037537173,  0.0037767109, -0.0699006686, -0.0111679725,   0.010516127,  0.0069689833,  0.0655257311, -0.1179580938,  0.0142108955,  0.0257025748, -0.0122244279, -0.1022146723,  0.0563529043,   0.073923582, -0.0191883763, -0.0573353705, -0.0594074132,  0.0478966224,  0.0025411235,  0.0358919642,  0.0118631143, -0.0822027939,  0.1139421091);
s(05,0) = (  0.0173801976,    0.02910132,  0.0134690618, -0.0393543697, -0.0494829975,  0.0162378334, -0.0350192088, -0.0307078282,  0.0300340098,  0.0846860821, -0.0490257995, -0.0291353569, -0.0410479649,  0.0343489492,  0.0328760606, -0.0150485886, -0.0812979791,  0.0691169395,  0.0268626061, -0.0322585989,  0.0242182691,   0.060904097, -0.0146977588, -0.0086013067, -0.0311637435,   0.077722803, -0.0914282029, -0.0276953182,  0.0775084158,  0.0126708539,  0.0610902407,  -0.001401205,    -0.0518092,   0.007676594, -0.0310038128,  0.0807248245, -0.0390049858,  0.0630910857,  0.0114845617, -0.0870943576,  0.0114574762,  0.0374274739,  0.0039048997, -0.0699383319, -0.0110172481,  0.0109711023,  0.0068544834,  0.0649215903, -0.1177756184, -0.0135799646, -0.0262138322,  0.0122153229,  0.1024459219, -0.0558870566, -0.0736673278,  0.0196726867,  -0.057289339, -0.0595327363,   0.048161498,  0.0026541615,  0.0351370656,  0.0115441127, -0.0820736091,  0.1139690434);
s(06,0) = (   0.023581698,  0.0535381141, -0.0015247923, -0.0074452371, -0.0491148726, -0.0025088909, -0.0568421671, -0.0007558923, -0.0659264482, -0.0556674387,  0.0004293495, -0.0726738953,  0.0043660441,  0.0095206323,  0.0065787853,  0.0540854163,    0.10727797,  0.0083011695,  0.0512766486,  0.0045709397,  0.0704698728,  0.0015519435,  0.0716556936, -0.0036887291,  0.0281381402,  0.0128621195, -0.0139806408,  0.0573665603,  0.0006824721,  0.0827807435, -0.0044900078, -0.0096965169, -0.0085156516,  -0.052750714,   -0.00330579, -0.1103413398,   -0.10411769,  0.0035195005, -0.0953420342,  -0.008605903, -0.0507138742, -0.0024967696,  -0.074081771,  -0.002116868, -0.0751781341,  0.0029727959, -0.0246568845,  0.0054528704,   0.030656196,  0.0847273654, -0.0741356404, -0.0058209761,  0.0013311674, -0.0662695551, -0.0110166854, -0.0886843371, -0.0111795266,  0.0085934147, -0.0065242314,  0.0566115053, -0.0001383706,   0.100479341,  0.0237436326,   0.124670367);
s(07,0) = (   0.027903593,  0.0478523948, -0.0012304647,  0.0264361877,  0.0619809882,  -0.002356678, -0.0669945216, -0.0045447501, -0.0561534131, -0.0015970839, -0.0075191629, -0.0650811913,  0.0034267795, -0.0377966904,  0.0072064877, -0.0870592373, -0.0964480422,    0.00361301, -0.0680520389,  0.0043056221,  0.0823156648,  0.0087868145,  0.0619669893,  0.0046878309, -0.0318473711, -0.0645971303,  0.0023113682,  0.0042387808,  0.0101001879,  0.0743889304, -0.0027870062,  0.0468298567, -0.0096371981,  0.0838640951,  -0.000372642,  0.0731947624,   0.039228477,  0.0046563812,  0.0796071461, -0.0043657881,  0.0724054997, -0.0024599393, -0.0854028703, -0.0085360684, -0.0664101627, -0.0032727995,  0.0255589262,  0.0036748376,  0.0843669874,  0.1439151129,  0.0290980293,  0.0613545475,   0.009205058, -0.0087690622,  0.0043114808,  -0.080165455, -0.0151283695,  -0.056253469,  -0.004182912, -0.0883180285,   0.004227556, -0.0582351975,  0.0614726017,  0.0256043352);


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
