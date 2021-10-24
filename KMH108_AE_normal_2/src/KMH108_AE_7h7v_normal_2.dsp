// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Sep-2018 13:20:19

//------- decoder information -------
// decoder file = ../decoders/KMH108_AE_7h7v_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMH108_AE_7h7v_pinv_even_energy_rV_max_rE_2_band
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
declare name "KMH108_AE_7h7v_normal_2";

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
s(00,0) = (  0.1000095461,  0.0578411174,  -0.001178403,  0.1076276986,  0.0948626196,   5.33889e-05, -0.0504933525,  0.0017398559,  0.0684486169,  0.1100151553, -0.0001009596, -0.0353942188,  0.0015425259, -0.0650580999, -0.0012087032,  0.0196072988,   0.099367776,  0.0001248839, -0.0612899481,  -6.00732e-05,   0.038616155, -0.0019576872, -0.0448585064,  0.0002852299, -0.0269060356,   0.069935398, -0.0001171699, -0.0726905178,  0.0001029452,  0.0279510821, -0.0014758989,  0.0504388434,  0.0012324756, -0.0127916197,  0.0007631676,  -0.064532582,  0.0269062702,   7.94514e-05, -0.0667375912, -0.0001167825,  0.0497058643,   5.12149e-05, -0.0329280372,  0.0016690084,  0.0370019829, -0.0002667266,  0.0185679745, -0.0016576491,  -0.082911886, -0.0193836157,  -2.15942e-05, -0.0472882123,  0.0001006787,  0.0596550044,  -7.84565e-05, -0.0238412176,  0.0010890976, -0.0422047338, -0.0009392934,  0.0103578471, -0.0006557545,  0.0424729132,  0.0021720005, -0.0821281255);
s(01,0) = (  0.1000476601, -0.0578382245, -0.0011863039,  0.1076322393, -0.0949059938,  -4.65811e-05, -0.0505156853,  0.0017516112,  0.0683786288, -0.1099646206,   8.96027e-05,  0.0353957738,  0.0015528681, -0.0650551365, -0.0012171507,    0.01964781, -0.0993506061, -0.0001145463,  0.0613116027,    5.2413e-05,  0.0386379073, -0.0019709143, -0.0448180476,  0.0002877897, -0.0268701318, -0.0699995328,  0.0001141733,  0.0726635214,   -9.1365e-05, -0.0279562012, -0.0014857944,   0.050429784,  0.0012410893, -0.0128168233,  0.0007674505, -0.0645920362, -0.0268603483,  -8.82302e-05,   0.066724036,  0.0001071155, -0.0497171823,  -4.46843e-05, -0.0329511786,  0.0016802851,  0.0369738373, -0.0002691203,  0.0185468013, -0.0016680077,  -0.082900543,  0.0194186373,    4.2722e-05,  0.0473251927,  -9.81039e-05, -0.0596383169,    6.9631e-05,   0.023848976,  0.0010963997, -0.0421911492, -0.0009458581,   0.010377194, -0.0006594346,  0.0425055661,  0.0021862158,  -0.082086982);
s(02,0) = (   0.103493812, -0.1090170588, -0.0016513736,  0.0534024696, -0.0899793573,  -1.70604e-05, -0.0524315846,   0.002438257, -0.0707599888,  0.0209348104,   3.36508e-05,  0.0667507057,   0.002161643, -0.0315108085, -0.0016941499, -0.1033023926,   0.101912533,   -4.5023e-05,  0.0581002208,   1.91964e-05,  0.0403693043, -0.0027435287,  0.0447291188,  0.0004003043, -0.0216112969,  0.0626257937,   4.83799e-05, -0.0138750761,  -3.43126e-05, -0.0527613185, -0.0020682742,  0.0235183357,  0.0017274699,  0.0685770664,  0.0010687132,  0.0749741638, -0.0378182236,   -4.2706e-05, -0.0683321133,   4.21023e-05, -0.0470850008,  -1.63657e-05, -0.0346891797,  0.0023389704, -0.0353062352, -0.0003743359,   0.015223888, -0.0023222809,   0.087443919, -0.0828455682,   2.87704e-05, -0.0424291867,  -4.15706e-05,  0.0114234587,   2.61503e-05,  0.0450450647,  0.0015262241, -0.0188694995, -0.0013165381, -0.0565544885, -0.0009182957, -0.0524610939,  0.0030434491,  0.0051603206);
s(03,0) = (  0.1018776918,  -0.118908826, -0.0031773649, -0.0356570356,   0.070385575,  0.0005836173, -0.0522562181,  0.0046908329, -0.0930680952,  0.0656078887, -0.0011102805,  0.0731016571,   0.004159161,  0.0241274412, -0.0032575588,  0.0843723627,  -0.098354867,  0.0013896435, -0.0460538341, -0.0006566867,  0.0412040058,  -0.005278129,  0.0582557065,  0.0007662372,  0.0360175996, -0.0048026682,  -0.001333178,  -0.042531296,  0.0011321171, -0.0581253954, -0.0039795124, -0.0217546161,  0.0033216275, -0.0553305361,  0.0020614075, -0.0934981076,  0.0879393506,  0.0009513866,  0.0650720587, -0.0012994951,  0.0379163677,  0.0005598522, -0.0363532794,  0.0044998209, -0.0454071849, -0.0007165302, -0.0227598449, -0.0044728817,  0.0278406757, -0.0431314789, -0.0003407098,  0.0039492441,  0.0011455381,  0.0342047163, -0.0008628083,  0.0499243718,  0.0029365681,  0.0209103641, -0.0025314763,   0.045051577, -0.0017712719,  0.0600177518,  0.0058579554,  0.0654299872);
s(04,0) = (   0.099253084, -0.0589822577,  0.0334628704, -0.1061339071,  0.0889388831, -0.0293688661,  -0.035752449, -0.0493813163,  0.0645595678, -0.0974757583,  0.0559582838,  0.0217687639, -0.0438027952,  0.0408645625,   0.034227927, -0.0139212619,  0.0835447403, -0.0702487943, -0.0261546258,  0.0330458718,  0.0056263338,  0.0555638969, -0.0225552108, -0.0079198824, -0.0271756855, -0.0534422368,  0.0677702898,  0.0207852102,  -0.057058855, -0.0004292438,   0.041910801,  -0.004091294, -0.0349011119,   0.004282537, -0.0219030434,  0.0586334954,  0.0167721299, -0.0489554248, -0.0099683207,  0.0656916435,  -0.009480716, -0.0281729573,  0.0165495807, -0.0473704947, -0.0004870798,  0.0074061071,  0.0033387147,  0.0472816483, -0.0649627808,    0.01596857,  0.0185086986,   0.000272773, -0.0582318672,  0.0202459571,  0.0434856529, -0.0142453172, -0.0309268843,  -0.021075015,  0.0265988099,  0.0006893213,  0.0188202694, -0.0050149521, -0.0617742992,  0.0540600915);
s(05,0) = (  0.0992569304,  0.0586808265,  0.0334643295, -0.1062268896, -0.0887515178,  0.0292812314, -0.0357537672, -0.0494361492,  0.0649203063,   0.097564577, -0.0558370863, -0.0216269961, -0.0438047051,  0.0408947097,  0.0344302494, -0.0144532958,  -0.083721788,  0.0702077782,  0.0261013762, -0.0329472652,  0.0056263986,  0.0556255949, -0.0226750604, -0.0082987039, -0.0266287582,   0.053797102, -0.0679285205, -0.0208694669,  0.0569352738,  0.0003672384,  0.0419126285, -0.0040837976, -0.0351074135,  0.0043988487, -0.0214164564,  0.0581724078,  -0.017337098,  0.0493800095,  0.0099795111, -0.0656532882,  0.0094574298,  0.0280888912,  0.0165504527, -0.0474230948, -0.0005008748,  0.0077603538,  0.0033026421,  0.0468420815, -0.0647347698, -0.0151500526,  -0.019174161, -0.0002015937,  0.0583678276, -0.0201549417, -0.0433914692,  0.0142546637, -0.0309282329, -0.0211086972,  0.0267560363,   0.000795027,  0.0184021679, -0.0050252075,   -0.06157391,  0.0541968434);
s(06,0) = (  0.1017661716,  0.1190915935, -0.0032040673, -0.0351669216, -0.0697925856, -0.0005817898, -0.0522115292,  0.0047313056, -0.0935611664, -0.0664882756,  0.0011111683, -0.0732126859,  0.0041941144,  0.0238470849, -0.0032889425,  0.0837761469,  0.0978697839, -0.0014013669,  0.0456715569,  0.0006546303,  0.0411873966, -0.0053236689,  0.0585564534,  0.0007802286,  0.0372763328,   0.006145101,  0.0013633698,  0.0431063262, -0.0011330225,  0.0582121272, -0.0040129561, -0.0215560998,  0.0033536284, -0.0549274749,  0.0020690032, -0.0934806138, -0.0883077323,  -0.001002816, -0.0647261285,   0.001310458, -0.0376071744, -0.0005580991, -0.0363563858,  0.0045386455, -0.0456336177,  -0.000729614, -0.0235990647, -0.0045016595,  0.0261401348,  0.0415298483,  0.0004083553, -0.0048957978, -0.0011714804, -0.0346709233,  0.0008634983, -0.0499975239,  0.0029612469,  0.0207609848, -0.0025558648,  0.0447129949, -0.0017777985,  0.0599848005,  0.0059031332,  0.0664705235);
s(07,0) = (  0.1035359539,  0.1089941608,  -0.001659989,  0.0533901659,  0.0899557288,   2.41109e-05, -0.0524562275,  0.0024509405, -0.0707906707, -0.0208380809,  -4.48216e-05, -0.0667332386,  0.0021729205, -0.0314970766, -0.0017028471, -0.1032224383, -0.1018943424,   5.35532e-05, -0.0580912081,  -2.71296e-05,  0.0403932416, -0.0027578002,   0.044744066,  0.0004021265, -0.0216861623, -0.0627565399,  -4.68317e-05,  0.0138164006,   4.57031e-05,  0.0527434812, -0.0020790645,  0.0235002327,  0.0017363382,  0.0685253148,  0.0010746318,  0.0748708035,  0.0378381819,   2.62501e-05,  0.0683209632,  -5.00791e-05,  0.0470838219,   2.31291e-05, -0.0347145954,  0.0023511375, -0.0353135773, -0.0003760399,  0.0152781331, -0.0023347071,  0.0875876495,   0.082879104,    2.4106e-06,  0.0425056323,   4.02403e-05, -0.0113797839,  -3.48312e-05, -0.0450263254,  0.0015341866, -0.0188477307, -0.0013232968, -0.0565129383, -0.0009233813,  -0.052400233,  0.0030594699,  0.0051993943);


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
