#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class player{
private:
	sf::Sprite spritePlayer;
	int m_facing;
	int m_col;
	bool m_status;
	int health, damage;
public:
	player(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
		health = 100;
	}
	void updateSprite(){
		spritePlayer.setTextureRect(sf::IntRect(m_col * 32, m_facing * 32, 32, 32));
		if(m_status){
			m_col++;
		}else{
			m_col--;
		}
		if(m_col == 2){
			m_status = false;
		}else if(m_col == 0){
			m_status = true;
		}
	}
	void walk(int facing){
		m_facing = facing;
		updateSprite();
		if(facing == 0){
			if(spritePlayer.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spritePlayer.getPosition();
				tmp.y += 32;
				spritePlayer.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spritePlayer.getPosition().x > 0){
				sf::Vector2f tmp = spritePlayer.getPosition();
				tmp.x -= 32;
				spritePlayer.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spritePlayer.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spritePlayer.getPosition();
				tmp.x += 32;
				spritePlayer.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spritePlayer.getPosition().y > 0){
				sf::Vector2f tmp = spritePlayer.getPosition();
				tmp.y -= 32;
				spritePlayer.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spritePlayer.setTexture(texture);
		spritePlayer.setTextureRect(sf::IntRect(0,32, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spritePlayer.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spritePlayer.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spritePlayer.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spritePlayer);
	}
	void sethealth(int h)
	{
		health=h;
	}
	void addhealth(int h=0)
	{
		health = health + h;
	}
	int gethealth()
	{
		return health;
	}
	void setdamage(int d)
	{
		damage=d;
	}
	void doubledamage()
	{
		damage = 2*damage;
	}
	int getdamage()
	{
		return damage;
	}
	void damagetaken(int d){
		health = health - d;
	}
};