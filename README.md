# 3gpp_vad
3gpp协议26073里面的vad的移植

1. 在语音识别时，为了能够很好的取到一段语音数据，切除两端的静音，使得更纯粹的语音进入解码器，就需要vad的功能

2. 移植并验证3gpp的vad，达到良好的效果后，移植到实时解码器程序中，GitHub仓库：https://github.com/xiangxyq/kaldi_nnet3_real_time_audio_decode
