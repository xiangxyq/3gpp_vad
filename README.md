# 3gpp_vad
3gpp协议26073里面的vad的移植

1. 在语音识别时，为了能够很好的取到一段语音数据，切除两端的静音，使得更纯粹的语音进入解码器，就需要vad的功能

2. 移植并验证3gpp的vad，达到良好的效果后，移植到实时解码器程序中，GitHub仓库：https://github.com/xiangxyq/kaldi_nnet3_real_time_audio_decode

3. 编译方法: 

	a. 进入c-code目录，执行make VAD=VAD1

	b. 将.o链接生成静态链接库libvad.a,执行命令ar rc libvad.a *.o

	c. 测试代码为wav_vad_test.c，执行gcc wav_vad_test.c -L. libtest.a -o wav_vad_test

4. 执行./wav_vad_test, 会将原始音频文件vad.pcm进行vad检测，输出后的文件为processed.pcm，处理的结果见result.jpg

注：

a. vad依赖文件未从3gpp代码中剥离，没有裁剪掉不相关的代码，而是整体编译生成一个库文件，如果需要请自行裁剪

b. vad相关参数并不是最优(针对您的场景)，在本代码中，修改了vad的判断阈值参数为(cnst_vad.h)：

/* Constants for VAD threshold */

//#define VAD_THR_HIGH 1260 /* Highest threshold                 */

//#define VAD_THR_LOW  720  /* Lowest threshold                  */

#define VAD_THR_HIGH 2500 /* Highest threshold                 */

#define VAD_THR_LOW  1500  /* Lowest threshold

/* Limits for background noise estimate */

//#define NOISE_MIN 40          /* minimum */

#define NOISE_MIN 350          /* minimum */

//#define NOISE_INIT 150        /* initial */

#define NOISE_INIT 450        /* initial */

c. 相关的pcm文件，可以用Audacity软件打开，文件->导入->原始数据->signed 16-bit PCM  小尾端 1声道 偏移0 总计要导入100% 采样率 16000Hz
