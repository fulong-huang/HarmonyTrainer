#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <map>

enum NoteName{
	A, B, C, D, E, F, G, As, Cs, Ds, Fs, Gs,
};
const std::map<NoteName, float> pitches{
		{C, 16.351599},
		{Cs, 17.323914},
		{D, 18.354048},
		{Ds, 19.445436}, 
		{E, 20.601723}, 
		{F, 21.826765},
		{Fs, 23.124651},
		{G, 24.499714},
		{Gs, 25.956543},
		{A, 27.500000},
		{As, 29.135235},
		{B, 30.867706},
};

class Notes{
public:
    Notes();
    explicit Notes(const std::string& note);
	~Notes(){};

	void setNote(std::string noteName);

    bool isPlaying;
    void start();
    void stop();

private:

	static const unsigned SAMPLES = 44100;
	static const unsigned SAMPLE_RATE = 44100;
	static const unsigned AMPLITUDE = 30000 / 10.f;
	constexpr static const double TWO_PI = 6.28318;

	Notes(const Notes& n);
	Notes operator=(const Notes& n);

    sf::Sound noteSound;

    sf::SoundBuffer noteBuffer;

	int parseNote(std::string strName);
};


