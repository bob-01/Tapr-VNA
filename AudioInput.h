 
#ifndef AUDIOINPUT_H
#define AUDIOINPUT_H
#define WAVEHDRBUFFER 4

#define MAXNUMPTS	2*192*10 // 192kHz
// For debugging
//#define NUMPTS 2*SAMP // stereo  * 10 * SAMP

extern short int waveIn[WAVEHDRBUFFER][MAXNUMPTS];   // 'short int' is a 16-bit type; I request 16-bit samples below

extern float decoded[1024][2];
extern  int audio_delay;
//extern volatile float gamma[4];

extern int sampleRate;
extern int IFREQ;
extern double audio_volume_reflection;
extern double audio_phase_reflection;
extern double audio_volume_transmission;
extern double audio_phase_transmission;
extern bool audio_simulation;

extern int OpenAudio (void);
extern void ArmAudio(int pM);
extern bool RetreiveData(int i, int duration, float& m, float& p, float& tm, float& tp, float& r);
extern void StartAudioSimulation(int mode, int numPoints, int duration, long startF, long stepF,int cable_before, int cable_after, int direction, int r, int c, int l);
extern void SetAudioPower(int power);

typedef struct measurementType {
	float magnitude;
	float phase;
	float reference;
} measurementType;

extern measurementType measured[1040*300];
extern int measurementIndex[1100];
extern int lastMeasurement;
extern volatile measurementType actualMeasurement;
extern volatile int nextDecoded;

#endif