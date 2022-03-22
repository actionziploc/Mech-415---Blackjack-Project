#ifndef Audio_h
#define Audio_h

#include <iostream>
#include <cstdlib>
#include <cstring>

class Audio
{

public:
	char* buffer = nullptr;
	char* data = nullptr;

	int n_bufferbytes;
	int n_databytes;
	int samplerate;
	short int numchannels;

	Audio(char* file_name);
	~Audio();

	void play();

private:

	int bytes_read(int index, int n_bytes);
	void getdata();
};

#endif // !Audio

