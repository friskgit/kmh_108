KMH108ChannelMap : MultiOutUGen
{
  *ar { | in1, in2, in3, in4, in5, in6, in7, in8 |
      ^this.multiNew('audio', in1, in2, in3, in4, in5, in6, in7, in8)
  }

  *kr { | in1, in2, in3, in4, in5, in6, in7, in8 |
      ^this.multiNew('control', in1, in2, in3, in4, in5, in6, in7, in8)
  } 

  checkInputs {
    if (rate == 'audio', {
      8.do({|i|
        if (inputs.at(i).rate != 'audio', {
          ^(" input at index " + i + "(" + inputs.at(i) + 
            ") is not audio rate");
        });
      });
    });
    ^this.checkValidInputs
  }

  init { | ... theInputs |
      inputs = theInputs
      ^this.initOutputs(8, rate)
  }

  name { ^"KMH108ChannelMap" }


  info { ^"Generated with Faust" }
}

