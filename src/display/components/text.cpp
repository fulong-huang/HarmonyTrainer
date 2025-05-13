#include "text.h"
// Setup and load font
sf::Font FONT = [] {
  sf::Font font;
  std::string srcDir = std::__fs::filesystem::path(__FILE__).parent_path();
  srcDir += "/../../../resources/";
  if (!font.loadFromFile(srcDir + "roboto/Roboto-Black.ttf")) {
    std::cerr << "Failed to load font" << std::endl;
    return font;
  };
  return font;
}();

Text::Text(sf::Color color, sf::Vector2i pos, std::string str, int fontSize,
           bool centered, bool verticalCentered, bool transparent,
           sf::Uint32 style, int maxWidth)
    : color(color), pos(pos), str(str), fontSize(fontSize), style(style),
      transparent(transparent), centered(centered),
      verticalCentered(verticalCentered), maxWidth(maxWidth) {
  this->setup();
};

Text::~Text() {

};

Text::Text(const Text &t) {
  this->color = t.color;
  this->pos = t.pos;
  this->style = t.style;
  this->str = t.str;
  this->fontSize = t.fontSize;
  this->transparent = t.transparent;
  this->centered = t.centered;

  this->setup();
};

Text Text::operator=(const Text &t) {
  this->color = t.color;
  this->pos = t.pos;
  this->style = t.style;
  this->str = t.str;
  this->transparent = t.transparent;
  this->fontSize = t.fontSize;

  this->setup();
  return *this;
};

void Text::setup() {
  this->setString(this->str);
  this->text.setFont(FONT);
  this->text.setCharacterSize(this->fontSize);
  if (this->transparent) {
    this->text.setFillColor(sf::Color::Transparent);
  } else {
    this->text.setFillColor(this->color);
  };
  this->text.setStyle(this->style);
  this->text.setOrigin(
      {this->text.getLocalBounds().left, this->text.getLocalBounds().top});
	this->scrollPosition = 0;
  this->recenter();
};

void Text::setMaxWidth(int maxWidth){
	this->maxWidth = maxWidth;
	this->setString(this->str);
}

void Text::setString(std::string str) {
  std::string currWord = "";
  int pos;
  // find first word
  for (pos = 0; pos < str.size(); pos++) {
    if (str[pos] == ' ') {
      pos++;
      break;
    }
    currWord += str[pos];
  }
  // if string only contain one word,
  // 	set text to that word no matter its in or out of bound
  if (pos >= str.size()) {
    this->text.setString(this->str);
    return;
  }

  // assign first word to current line;
  std::string currLine = currWord;
  std::string prevLine = currWord;
  currWord = "";

  sf::Text tempText;
  tempText.setFont(FONT);
  tempText.setCharacterSize(this->fontSize);
  tempText.setStyle(this->style);
  std::string finalString = "";
  // traverse through string from the second word
  for (char c : str.substr(pos)) {
    if (c == ' ') {
      // Add word to current line
      currLine += ' ' + currWord;

      // If current string is out of bond,
      // 	do not add current word to the line
      tempText.setString(currLine);
      if (tempText.getLocalBounds().width > maxWidth) {
        finalString += prevLine + '\n';
        currLine = currWord;
        prevLine = currWord;
      } else {
        prevLine = currLine;
      }

      currWord = "";
    } else {
      currWord += c;
    }
  }

  // Add final word to the string
  {
    // Add word to current line
    currLine += ' ' + currWord;

    // If current string is out of bond,
    // 	do not add current word to the line
    tempText.setString(currLine);
    if (tempText.getLocalBounds().width > maxWidth) {
      finalString += prevLine + '\n' + currWord;
    } else {
      finalString += currLine;
    }
  }

  this->text.setString(finalString);
}

void Text::draw(sf::RenderWindow *window) { window->draw(this->text); };

sf::Text *Text::getTextObject() { return &this->text; };

void Text::setColor(sf::Color color) {
  this->color = color;
  this->text.setFillColor(this->color);
};

void Text::setPosition(sf::Vector2i pos) {
  this->scrollPosition = 0;
  this->pos = pos;
  this->recenter();
};

void Text::setTransparency(bool transparent) {
  this->transparent = transparent;
  if (this->transparent) {
    this->text.setFillColor(sf::Color::Transparent);
  } else {
    this->text.setFillColor(this->color);
  }
};

void Text::setSize(int width, int height) {
  // TODO
};

sf::Color Text::getColor() { return this->color; };

sf::Vector2i Text::getPosition() { return this->pos; };

sf::Vector2i Text::getSize() {
	float width = this->text.getLocalBounds().width;
	float height = this->text.getLocalBounds().height;
  return {(int)width, (int)height};
};

bool Text::boundCheck(sf::Vector2i pos) {
  // TODO
  return true;
};

void Text::setText(std::string str) {
  this->str = str;
  this->text.setString(this->str);
}

void Text::recenter() {
  if (this->centered) {
    float width = this->text.getLocalBounds().width;
    float height = this->text.getLocalBounds().height;
    if (this->verticalCentered) {
      this->text.setPosition(this->pos.x - width / 2, this->pos.y - height / 2 + this->scrollPosition);
    } else {
      this->text.setPosition(this->pos.x - width / 2, this->pos.y + this->scrollPosition);
    }
  } else {
    this->text.setPosition(this->pos.x, this->pos.y + this->scrollPosition);
  };
};

void Text::scroll(int amount) {
  this->scrollPosition += amount;
  if (this->scrollPosition > 0) {
    this->scrollPosition = 0;
  }
	this->recenter();
}

void Text::resetScroll(){
	this->scrollPosition = 0;
	this->recenter();
}

std::string Text::getText() { return this->str; };

void Text::setXPosition(int newX) {
	this->pos = {newX, this->pos.y};
  this->recenter();
};

