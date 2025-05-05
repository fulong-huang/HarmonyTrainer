#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
#include <string>

const std::map<std::string, int> NoteIndex{
	{"C", 0}, {"Cs", 1}, {"D", 2}, {"Ds", 3}, {"E", 4}, {"F", 5}, {"Fs", 6}, {"G", 7}, {"Gs", 8}, {"A", 9}, {"As", 10}, {"B", 11}
};
const double NotePitches[] = {
    16.351599,  17.323914, 18.354048,  19.445436,
    20.601723,  21.826765,  23.124651, 24.499714,
    25.956543, 27.500000,  29.135235, 30.867706,
};
enum NoteSteps{
	m2 = 1, M2 = 2,
	m3 = 3, M3 = 4,
	P4 = 5, A4 = 6, P5 = 7,
	m6 = 8, M6 = 9,
	m7 = 10, M7 = 11
};

const std::string NoteStepNames[] = {
	"m2", "M2", 
	"m3", "M3", 
	"P4", "A4", 
	"P5", "A5", 
	"m6", "M6", 
	"m7", "M7", 
	"P8",
};

const int MajorSteps[] = {
	2, 2, 1, 2, 2, 2, 1
};

const int MinorSteps[] = {
	2, 1, 2, 2, 1, 2, 2
};

class Notes {
public:
  Notes();
  explicit Notes(const std::string &note);
  explicit Notes(int noteNumber);
  ~Notes() {};

  /**
   * This function set the pitch of the note using noteName
   *
   * @param Note name starts with name of the note, followed by octave of the
   * note. C4 for middle C, Fs4 for the F sharp after middle C.
   */
  void setNote(std::string noteName);
  /**
   * This function set the pitch of the note using note number
   *
   * @param Note number is the number of half steps from C1
   */
  void setNote(int noteNumber);
	void incrementNote(int halfSteps);

  bool isPlaying;
  void start();
  void stop();

private:
  static const unsigned SAMPLES = 44100;
  static const unsigned SAMPLE_RATE = 44100;
  static const unsigned AMPLITUDE = 30000 / 10.f;
  constexpr static const double TWO_PI = 6.28318;

  Notes(const Notes &n);
  Notes operator=(const Notes &n);

  sf::Sound noteSound;
  sf::SoundBuffer noteBuffer;

	int currentNote;

  double parseNote(std::string strName);
  double parseNote(int noteNumber);
};
