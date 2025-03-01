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
