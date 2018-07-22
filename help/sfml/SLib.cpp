//
// SLib.cpp for Project-Master in /home/zibaire/cpp_arcade/games
//
// Made by Antoine Maciazek
// Login   <maciaz_a@epitech.eu>
//
// Started on  Wed Mar 16 12:33:45 2016 Antoine Maciazek
// Last update Tue Apr  5 12:56:00 2016 Antoine Maciazek
//

#include  "tools.h"
#include  "SLib.hh"

SLib::SLib() : m_window(sf::VideoMode(H, W), "ARCADE")
{
}

SLib::~SLib(){
}

sf::Sprite	*SLib::createSprite(const std::string path, int r, int g, int b)
{
  sf::Sprite	*nw = new sf::Sprite();
  sf::Texture	*tex;

  tex = new sf::Texture();
  if (tex->loadFromFile(path))
    nw->setTexture(*tex);
  else
    nw->setColor(sf::Color(0, r, g, b));
  return nw;
}

int SLib::initLib(GameType type)
{
  this->_type = type;
  this->back = createSprite("ressources/back.jpg", 145, 145, 145);
  this->snakehead = createSprite("ressources/snakeheadRT.png", 51, 153, 0);
  this->snake = createSprite("ressources/snakebodyRT.png", 102, 255, 0);
  this->foodPicture = createSprite("ressources/apple2.png", 255, 0, 102);
  this->Wall = createSprite("ressources/wall.png", 255, 0, 102);
  this->Grass = createSprite("ressources/grass.png", 0, 255, 0);
  this->Orange = createSprite("ressources/orange.png", 255, 255, 255);
  this->Rouge = createSprite("ressources/rouge.png", 255, 255, 255);
  this->Bleu = createSprite("ressources/bleu.png", 255, 255, 255);
  this->Rose = createSprite("ressources/rose.png", 255, 255, 255);
  this->Pac = createSprite("ressources/pacTOP.png", 223, 28, 252);
  this->foo = createSprite("ressources/foo.png", 223, 28, 252);
  this->Life = createSprite("ressources/Pacman.png", 255, 255, 0);
  if (!this->font.loadFromFile("ressources/font.ttf"))
    std::cout << "Load font fail" << std::endl;
  this->text.setFont(font);
  return 0;
}

HS SLib::getEvent()
{
  sf::Event event;

  if(this->m_window.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
	{
	  if (event.key.code == sf::Keyboard::Escape)
	    {
	      this->m_window.close();
	      return EXIT;
	    }
	  else if (event.key.code == sf::Keyboard::Left)
	    {
	      this->Pac =  createSprite("ressources/pacLEFT.png", 223, 28, 252);
	      return BOT;
	    }
	  else if (event.key.code == sf::Keyboard::Right)
	    {
	      this->Pac =  createSprite("ressources/pacRIGHT.png", 223, 28, 252);
	      return TOP;
	    }
	  else if (event.key.code == sf::Keyboard::Up)
	    {
	      this->Pac = createSprite("ressources/pacTOP.png", 223, 28, 252);
	      return RIGHT;
	    }
	  else if (event.key.code == sf::Keyboard::Down)
	    {
	      this->Pac = createSprite("ressources/pacBOT.png", 223, 28, 252);
	      return LEFT;
	    }
	  else if (event.key.code == sf::Keyboard::Space)
	    {
	      this->snake = createSprite("ressources/snakeheadRT2.png", 102, 255, 0);
	    }
	  else if (event.key.code == sf::Keyboard::Num2)
	    {
	      return PREVLIB;
	    }
	  else if (event.key.code == sf::Keyboard::Num3)
	    {
	      return NEXTLIB;
	    }
	  else if (event.key.code == sf::Keyboard::Num4)
	    {
	      return PREVGAME;
	    }
	  else if (event.key.code == sf::Keyboard::Num5)
	    {
	      return NEXTGAME;
	    }
	  else if (event.key.code == sf::Keyboard::Num8)
	    {
	      return RESTART;
	    }
	  else if (event.key.code == sf::Keyboard::Num9)
	    {
	      return MENU;
	    }
	}
      return NONE;
    }
  return NONE;
}

void SLib::setScore(int value)
{
  this->score = value;
}

void SLib::setHP(int value)
{
  this->_HP = value;
}

void SLib::setType(GameType type)
{
  this->_type = type;
}

void SLib::drawSprite(sf::Sprite *display, int x, int y)
{
  display->setPosition(x * 24, y * 24);
  this->m_window.draw(*display);
}


void SLib::AffScore()
{
  if(this->_type == PACMAN)
    {
      std::string newscore = std::to_string(score);
      this->text.setString(newscore);
      this->text.setCharacterSize(30);
      this->text.setColor(sf::Color::Yellow);
      this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
      this->text.setPosition(540, 15);
    }
  else
    {
      std::string newscore = std::to_string(score);
      this->text.setString(newscore);
      this->text.setCharacterSize(50);
      this->text.setColor(sf::Color::Black);
      this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
      this->text.setPosition(40,40);
    }
  this->m_window.draw(this->text);
  this->m_window.display();
}

void SLib::AffLife()
{
  if(this->_HP == 3){
    drawSprite(this->Life, 23, 3);
    drawSprite(this->Life, 23, 5);
    drawSprite(this->Life, 23, 7);}
  else if (this->_HP == 2){
    drawSprite(this->Life, 23, 3);
    drawSprite(this->Life, 23, 5);}
  else if (this->_HP == 1)
    drawSprite(this->Life, 23, 3);
  this->m_window.display();
}

void SLib::drawMap(std::map<int, std::map<int, int> > _map)
{
  unsigned int i = 0;
  unsigned int j;

  this->m_window.clear();

  while (i < _map.size())
    {
      j = 0;
      while (j < _map[0].size())
	{
	  switch (_map[i][j])
	    {
	    case 0: //WALL
	      drawSprite(this->Wall, i, j);
	      break;
	    case 2:
	      if (this->_type == NIBBLER)
		drawSprite(this->snake, i, j); //BODY
	      else
		drawSprite(this->Pac, i, j);
	      break;
	    case 3:
	      drawSprite(this->foodPicture, i, j);
	      break;
	    case 7:
	      drawSprite(this->Rouge, i, j); //ROUGE
	      break;
	    case 4:
	      drawSprite(this->Rose, i, j); //ROSE
	      break;
	    case 5:
	      drawSprite(this->Orange, i, j); // ORANGE
	      break;
	    case 6:
	      drawSprite(this->Bleu, i, j);//BLEU
	      break;
	    case 1:
	      drawSprite(this->Grass, i, j); //FLOOR
	      break;
	    case 8:
	      drawSprite(this->foo, i, j);
	      break;
	    }
	  j++;
	}
      i++;
    }
  AffScore();
  AffLife();
  this->m_window.display();
}

extern "C"
ILib*  createEnv()
{
  return new SLib();
}

extern "C"
{
  void		deleteEnv(ILib* lib)
  {
    delete lib;
  }
}
