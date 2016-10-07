/***********************************************************************************
**
** SoundManager.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
//----------------------------------------------------------------------------------
#include "../IndexObject.h"
//----------------------------------------------------------------------------------
#pragma pack (push,1)
struct WaveHeader
{
	char chunkId[4];
	unsigned long chunkSize;
	char format[4];
	char subChunkId[4];
	unsigned long subChunkSize;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned long sampleRate;
	unsigned long bytesPerSecond;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char dataChunkId[4];
	unsigned long dataSize;
	//data;
};
#pragma pack (pop)
//----------------------------------------------------------------------------------
class CSoundManager
{
private:
	static const int MIDI_MUSIC_COUNT = 57;
	static const char *m_MusicName[MIDI_MUSIC_COUNT];
	HSTREAM m_Music = 0;
	HSTREAM m_WarMusic = 0;

	void TraceMusicError(DWORD error);
	//std::map<HSTREAM, BYTE*> streams;
public:
	CSoundManager();
	~CSoundManager();
	
	bool Init();
	void Free();
	void ResumeSound();
	void PauseSound();

	//Mix_Chunk *LoadSoundEffect(TIndexSound &is);

	bool FreeStream(HSTREAM hSteam);

	//����� ������� �����. ��� ������� �����������: ���� �������, ��������� ��� ��������.
	float GetVolumeValue(int distance = -1, bool music = false);

	HSTREAM LoadSoundEffect(CIndexSound &is);

	UCHAR_LIST CreateWaveFile(CIndexSound &is);

	//void PlaySoundEffect(Mix_Chunk *mix, int volume);
	void PlaySoundEffect(HSTREAM stream, float volume);

	void PlayMidi(int index, bool loop, bool warmode);

	void PlayMP3(std::string fileName, bool loop, bool warmode = false);

	void StopMusic();

	void StopWarMusic();

	void SetMusicVolume(float volume);
};
//----------------------------------------------------------------------------------
extern CSoundManager g_SoundManager;
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
