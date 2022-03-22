#include "Audio.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

Audio::Audio(char* file_name)
{
	ifstream file = ifstream(file_name, ios::binary | ios::ate);
	streamsize n_bufferbytes = file.tellg();
	file.seekg(0, ios::beg);

	buffer = new char[n_bufferbytes];

	if (file.read(buffer, n_bufferbytes))
	{
		auto* b_buffer = reinterpret_cast<int*>(buffer);
		numchannels = bytes_read(22, 2);
		samplerate = bytes_read(24, 4);
		n_databytes = bytes_read(40, 4);
		getdata();
	}
	else
	{
		cout << "\n Unable to read audio file " << file_name << "\n";
	}
}

Audio::~Audio()
{
	delete buffer;
}

void Audio::getdata()
{
	data = new char[n_databytes];
	int index = 0;

	for (int i = 44; i < 44 + n_databytes; i++)
	{
		data[index] = buffer[i];
	}
}

int Audio::bytes_read(int index, int n_bytes)
{
	int value = 0;

	for (int i = index + n_bytes - 1; i >= index; i--)
	{
		value = (value << 8) + buffer[i];
	}

	return value;
}

void Audio::play()
{
	PlaySoundA(buffer, NULL, SND_MEMORY | SND_ASYNC);
}