//
// SLib.hh for Project-Master in /home/zibaire/cpp_arcade/games/include
//
// Made by Antoine Maciazek
// Login   <maciaz_a@epitech.eu>
//
// Started on  Wed Mar 16 12:38:43 2016 Antoine Maciazek
// Last update Wed Mar 30 16:51:26 2016 Antoine Maciazek
//

#ifndef		SLIB_H_
# define	SLIB_H_

#include  <SFML/Graphics.hpp>
#include  <SFML/Audio.hpp>
#include  <iostream>
#include  <vector>
#include  <string>
#include  <unistd.h>
#include  "ILib.hh"
#include  "tools.h"

# define	H 600
# define	W 960

class SLib : public ILib {
public:
  SLib();
  ~SLib();

  sf::Sprite* createSprite(const std::string, int, int ,int);
  void drawSprite(sf::Sprite *, int, int);
  int initLib(GameType);
  HS getEvent();
  void drawMap(std::map<int, std::map<int, int> >);
  void setScore(int);
  void setHP(int);
  void setType(GameType);
  void AffScore();
  void AffLife();

private:

  sf::RenderWindow	m_window;
  sf::SoundBuffer	buffer;
  sf::Sound		sound;

  sf::Sprite		*back;
  sf::Sprite		*snakehead;
  sf::Sprite		*snake;
  sf::Sprite		*foodPicture;
  sf::Sprite		*Wall;
  sf::Sprite		*Grass;
  sf::Sprite		*Rose;
  sf::Sprite		*Rouge;
  sf::Sprite		*Bleu;
  sf::Sprite		*Orange;
  sf::Sprite		*foo;
  sf::Sprite		*Life;
  sf::Sprite		*Pac;


  sf::Font		font;
  sf::Text		text;

  GameType		_type;
  int			score = 0;
  int			_HP;
};

#endif		//SLIB_H_
