// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:06:46

//------- decoder information -------
// decoder file = ../decoders/KMH108_AEC_7h7v_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMH108_AEC_7h7v_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMH108_AEC_7h7v_full_4";

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
s(00,0) = (  0.0825289694,  0.0577413706, -0.0010855664,  0.0882861386,  0.0975896214,   8.70419e-05, -0.0417145731,  0.0016027531,  0.0500152605,  0.1155572313, -0.0001651705,  -0.035316693,  0.0014210031, -0.0532808535, -0.0011133499,  0.0002721803,  0.1048437552,   0.000205711, -0.0630860847,  -9.79396e-05,  0.0319732882,  -0.001803419,  -0.032906567,  0.0002625147, -0.0483888549,  0.0740913317, -0.0001955336, -0.0763059888,   0.000168419,  0.0278705642, -0.0013596251,  0.0412064489,  0.0011352469,  -1.67679e-05,  0.0007033587, -0.0877836196,  0.0278368367,  0.0001366683, -0.0704642671, -0.0001923662,  0.0511960926,   8.34975e-05, -0.0273333934,  0.0015374885,  0.0272675463,  -0.000245485,  0.0329384253, -0.0015273418, -0.1065709725, -0.0219663114,  -4.42175e-05, -0.0500598253,  0.0001680129,   0.062582474, -0.0001283554, -0.0237557191,  0.0010032967, -0.0343892888, -0.0008651935, -0.0001256962, -0.0006043635,  0.0583095178,  0.0020010177,  -0.104375413);
s(01,0) = (  0.0523914214,  -1.33695e-05, -0.0022999772,  0.1000100367,  -1.84018e-05,   -2.4323e-06, -0.0271493078,  0.0033959025,  0.1147987383,   2.22478e-05,    6.2119e-06,    6.9986e-06,  0.0030106632, -0.0595840689, -0.0023594815,  0.1189362615,   4.82518e-05,  -1.16277e-05,   1.53479e-05,    2.7369e-06,  0.0218182793, -0.0038210723, -0.0754201417,  0.0005573927,  0.1231788653,   -8.3651e-05,   1.80333e-05,   -2.1947e-05,   -6.3341e-06,   -4.1431e-06, -0.0028806222,  0.0451650273,  0.0024058871, -0.0783222903,  0.0014886449,  0.1221800572,   4.97012e-05,  -2.37185e-05,   -2.0108e-05,   1.08734e-05,  -1.58377e-05,   -2.3333e-06, -0.0196416474,  0.0032576204,  0.0623904304, -0.0005212337, -0.0816188053, -0.0032345547,  0.1212320282,   4.55566e-05,   2.63666e-05,   3.92349e-05,  -1.54952e-05,    2.4209e-05,    4.8273e-06,    2.3277e-06,  0.0021256733, -0.0368774253, -0.0018335729,  0.0640521884, -0.0012791235, -0.0850887688,  0.0042388866,  0.1171141969);
s(02,0) = (  0.0825829434, -0.0577298002, -0.0010985631,  0.0882904218, -0.0976437051,   -7.6213e-05, -0.0417469487,  0.0016220893,  0.0499007792, -0.1154950123,  0.0001460252,  0.0353148989,  0.0014380158, -0.0532740282, -0.0011272418,  0.0003330231,  -0.104839222, -0.0001852882,  0.0631103022,   8.57549e-05,  0.0320057992, -0.0018251762, -0.0328404289,  0.0002667178, -0.0483375622, -0.0741406325,  0.0001822595,  0.0762775361, -0.0001488972, -0.0278753332, -0.0013759029,   0.041190005,  0.0011494121,  -5.43977e-05,  0.0007104138, -0.0878827671, -0.0277969229, -0.0001371632,  0.0704522014,  0.0001732682, -0.0512052183,  -7.31096e-05, -0.0273687346,  0.0015560373,  0.0272215819, -0.0002494154,  0.0329088137, -0.0015443904, -0.1065549657,  0.0219952733,   6.08144e-05,  0.0500928391, -0.0001566071, -0.0625699483,  0.0001134774,  0.0237651791,  0.0010153085, -0.0343656268, -0.0008759891,  -9.70133e-05, -0.0006104256,  0.0583641361,  0.0020244056, -0.1043173431);
s(03,0) = (   0.091436386, -0.1063197628, -0.0021023052,  0.0454877287, -0.0913260999,  -4.11178e-05,  -0.046589833,  0.0031040759, -0.0806893734,  0.0214354786,   7.98165e-05,  0.0650872009,  0.0027519111,  -0.026338704, -0.0021568285, -0.1142996517,  0.1077458963, -0.0001037739,  0.0589953251,   4.62658e-05,  0.0362735113, -0.0034927087,  0.0508800824,  0.0005097384, -0.0297325247,  0.0648660876,  0.0001064738, -0.0142427752,  -8.13863e-05, -0.0514324569, -0.0026330465,  0.0190489994,  0.0021992484,  0.0759191285,  0.0013603797,  0.0695871702, -0.0401749904,  -8.68924e-05, -0.0722057559,   9.70419e-05, -0.0478354196,  -3.94435e-05, -0.0315622157,   0.002977677, -0.0400355105, -0.0004766709,  0.0208700694, -0.0029562674,  0.0825727577, -0.0831958325,   4.90904e-05, -0.0439782827,   -9.1488e-05,  0.0117567683,   6.20261e-05,  0.0438983638,  0.0019429818, -0.0147218131, -0.0016760896, -0.0626447497, -0.0011689112,  -0.049279098,  0.0038744399, -0.0029844655);
s(04,0) = (  0.0903752495, -0.1176425689, -0.0044682924, -0.0377682937,  0.0738822204,  0.0009081402, -0.0470402304,  0.0065965869, -0.0990594085,  0.0681025307, -0.0017279826,  0.0724848059,  0.0058489811,  0.0263515154, -0.0045807688,  0.0818310767, -0.1035572076,  0.0021635613, -0.0486559229, -0.0010218401,  0.0381094039, -0.0074224849,  0.0613840112,  0.0010769867,  0.0331008282, -0.0056654218, -0.0020770641, -0.0437000337,  0.0017619681, -0.0578231543, -0.0055963434, -0.0246017909,  0.0046708621, -0.0534563729,  0.0028996606, -0.1006830976,  0.0908420677,  0.0014844727,  0.0680561468, -0.0020232076,  0.0403628371,  0.0008711605, -0.0345937694,  0.0063279719, -0.0472162055, -0.0010071209, -0.0202333094, -0.0062908212,  0.0251289909, -0.0421172871, -0.0005352948,  0.0049243387,  0.0017847248,  0.0347537546, -0.0013428298,  0.0498277437,  0.0041296625,  0.0242897696,  -0.003559754,  0.0433466955, -0.0024915439,  0.0635485919,  0.0082382792,  0.0592735078);
s(05,0) = (  0.0870319147, -0.0602163965,  0.0328937357,  -0.107556542,  0.0916643005, -0.0305589162, -0.0298778342, -0.0485399241,  0.0643681794, -0.1021728154,  0.0582270772,   0.021943029, -0.0430577996,  0.0421468697,   0.033639995,  -0.018632304,  0.0879165338, -0.0731001887, -0.0266466537,  0.0343849171,  0.0015807371,  0.0546171616, -0.0227600561, -0.0077742788, -0.0307546343, -0.0556140013,  0.0705267798,  0.0221186898, -0.0593722703,  0.0001129459,  0.0411979844, -0.0055857927, -0.0343016166,  0.0074891519, -0.0215445621,  0.0571135003,   0.016517101,  -0.050955577, -0.0110269456,  0.0683580635, -0.0103255582, -0.0293145482,  0.0195596933, -0.0465633642,    1.0847e-06,   0.007269949,  0.0059832684,  0.0464902065, -0.0687458357,  0.0170419665,  0.0192794467,  0.0002759942, -0.0606003913,  0.0206653201,  0.0452487513, -0.0153003839, -0.0304008816,  -0.019380227,   0.026141923, -0.0020225399,  0.0185122431, -0.0045664168, -0.0607294955,   0.047572514);
s(06,0) = (  0.0870323606,   0.059865767,  0.0328969204, -0.1076626347, -0.0914816769,   0.030474115, -0.0298767367,  -0.048599445,  0.0647426413,   0.102335526, -0.0581105022,  -0.021769749, -0.0430619683,  0.0421827546,  0.0338522471, -0.0192148198,  -0.088086432,   0.073063091,   0.026593883, -0.0342894987,  0.0015778975,  0.0546841346, -0.0228832181, -0.0081688955, -0.0302291673,  0.0559238404, -0.0706854363, -0.0222493845,  0.0592534025, -0.0002014829,   0.041201973, -0.0055801537, -0.0345180432,  0.0076290309, -0.0210392838,  0.0566230387, -0.0170248487,  0.0513752071,  0.0110330505, -0.0683233724,  0.0103044175,  0.0292332002,  0.0195640808, -0.0466204615,  -1.54691e-05,  0.0076389663,  0.0059742995,  0.0460351236, -0.0685187297, -0.0162051339, -0.0199344727, -0.0001779662,  0.0607367174, -0.0205382337, -0.0451581598,  0.0153337958, -0.0304038249, -0.0194146556,  0.0263068658, -0.0019278048,  0.0180780809, -0.0045681666, -0.0605240354,   0.047670036);
s(07,0) = (  0.0902169734,  0.1178559973, -0.0045079015, -0.0372353727, -0.0732911353, -0.0009060852, -0.0469775148,   0.006656699, -0.0995900673,  -0.069036201,  0.0017302145, -0.0726144995,  0.0059008293,  0.0260545415, -0.0046276147,  0.0812450978,   0.103035904, -0.0021812864,  0.0482756257,  0.0010195279,  0.0380874468,  -0.007490123,  0.0617003845,  0.0010982927,   0.034397917,  0.0069470414,  0.0021207252,   0.044306575, -0.0017642438,  0.0579245119, -0.0056459521, -0.0244013585,  0.0047186293, -0.0530555337,  0.0029102169,  -0.100690879, -0.0911860272, -0.0015576785, -0.0676767617,  0.0020397829, -0.0400559844, -0.0008691892, -0.0346006109,  0.0063856362,  -0.047446823, -0.0010270448, -0.0210962462, -0.0063328649,   0.023403884,   0.040523222,  0.0006307771, -0.0058456942, -0.0018222408, -0.0352426618,  0.0013445642, -0.0499132719,  0.0041662698,  0.0241485255, -0.0035961583,  0.0430060527, -0.0025006144,  0.0635230218,  0.0083049976,  0.0603186179);
s(08,0) = (  0.0914982313,  0.1062921235, -0.0021153428,  0.0454578003,  0.0912898425,   5.17571e-05, -0.0466261612,  0.0031232424,  -0.080750879, -0.0213130553,  -9.72072e-05, -0.0650650768,  0.0027689772, -0.0263110114, -0.0021698854, -0.1141793581, -0.1077329411,  0.0001186121, -0.0589816345,  -5.82371e-05,  0.0363090126, -0.0035142748,  0.0509124913,  0.0005122986, -0.0298311613,  -0.065019985, -0.0001083407,  0.0141710279,   9.91191e-05,  0.0514088873, -0.0026493755,  0.0190161554,   0.002212562,   0.075841154,  0.0013695903,    0.06944017,    0.04021475,   6.87145e-05,   0.072195796, -0.0001109176,  0.0478338601,   4.96495e-05, -0.0316000748,   0.002996063, -0.0400546088,  -0.000479065,  0.0209424989, -0.0029753021,  0.0827758725,  0.0832367295,  -1.04414e-05,  0.0440691386,   9.30921e-05, -0.0117057054,  -7.55406e-05, -0.0438729441,  0.0019550314, -0.0146842313, -0.0016862362, -0.0625820473, -0.0011768254, -0.0491935399,    0.00389879, -0.0029614475);


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
