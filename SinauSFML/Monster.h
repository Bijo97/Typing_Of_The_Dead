#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class monster{
protected:
	sf::Sprite spriteMonster;
	int m_facing;
	int m_col;
	bool m_status;
	int health, damage;
public:
	monster(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
	}

	virtual void updateSprite() = 0;

	virtual void walk(int facing) = 0;

	virtual void setTexture(sf::Texture &texture) = 0;

	virtual void setPosition(int x, int y) = 0;

	virtual sf::Vector2f getPosition() = 0;

	virtual void draw(sf::RenderWindow &window) = 0;

	virtual void sethealth(int h) = 0;

	virtual int gethealth() = 0;

	virtual void setdamage(int d) = 0;

	virtual void doubledamage() = 0;

	virtual int getdamage() = 0;

	virtual void damagetaken(int d) = 0;

	virtual int getType() = 0;
};

class monsterA: public monster{
public:
	monsterA(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
		damage = 5;
	}
	void updateSprite(){
		spriteMonster.setTextureRect(sf::IntRect(m_col * 32, m_facing * 32, 32, 32));
		if (m_status){
			m_col++;
		} else{
			m_col--;
		}
		if(m_col == 2){
			m_status = false;
		} else if(m_col == 0){
			m_status = true;
		}
	}
	void walk(int facing){
		m_facing = facing;
		updateSprite();
		if(facing == 0){
			if(spriteMonster.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spriteMonster.getPosition().x > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x -= 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spriteMonster.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spriteMonster.getPosition().y > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y -= 32;
				spriteMonster.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spriteMonster.setTexture(texture);
		spriteMonster.setTextureRect(sf::IntRect(0, 0, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spriteMonster.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health=h;
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

	int getType(){
		return 0;
	}
};

class monsterB: public monster{
public:
	monsterB(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
		damage = 8;
	}
	void updateSprite(){
		spriteMonster.setTextureRect(sf::IntRect(m_col * 32, m_facing * 32 + 128, 32, 32));
		if (m_status){
			m_col++;
		} else {
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
			if(spriteMonster.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spriteMonster.getPosition().x > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x -= 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spriteMonster.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spriteMonster.getPosition().y > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y -= 32;
				spriteMonster.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spriteMonster.setTexture(texture);
		spriteMonster.setTextureRect(sf::IntRect(0, 160, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spriteMonster.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health=h;
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

	int getType(){
		return 1;
	}
};

class monsterC: public monster{
public:
	monsterC(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
		damage = 10;
	}
	void updateSprite(){
		spriteMonster.setTextureRect(sf::IntRect(m_col * 32 + 96, m_facing * 32, 32, 32));
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
			if(spriteMonster.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spriteMonster.getPosition().x > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x -= 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spriteMonster.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spriteMonster.getPosition().y > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y -= 32;
				spriteMonster.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spriteMonster.setTexture(texture);
		spriteMonster.setTextureRect(sf::IntRect(128,0, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spriteMonster.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health=h;
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

	int getType(){
		return 2;
	}
};

class bossA: public monster{
public:
	bossA(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
	}
	void updateSprite(){
		spriteMonster.setTextureRect(sf::IntRect(m_col * 32, m_facing * 32, 32, 32));
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
			if(spriteMonster.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spriteMonster.getPosition().x > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x -= 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spriteMonster.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spriteMonster.getPosition().y > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y -= 32;
				spriteMonster.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spriteMonster.setTexture(texture);
		spriteMonster.setTextureRect(sf::IntRect(0,32, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spriteMonster.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health=h;
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

	int getType(){
		return 3;
	}
};

class bossB: public monster{
public:
	bossB(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
	}
	void updateSprite(){
		spriteMonster.setTextureRect(sf::IntRect(m_col * 32, m_facing * 32, 32, 32));
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
			if(spriteMonster.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spriteMonster.getPosition().x > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x -= 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spriteMonster.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spriteMonster.getPosition().y > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y -= 32;
				spriteMonster.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spriteMonster.setTexture(texture);
		spriteMonster.setTextureRect(sf::IntRect(0,32, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spriteMonster.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health=h;
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

	int getType(){
		return 4;
	}
};

class bossC: public monster{
public:
	bossC(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
	}
	void updateSprite(){
		spriteMonster.setTextureRect(sf::IntRect(m_col * 32, m_facing * 32, 32, 32));
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
			if(spriteMonster.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spriteMonster.getPosition().x > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x -= 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spriteMonster.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spriteMonster.getPosition().y > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y -= 32;
				spriteMonster.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spriteMonster.setTexture(texture);
		spriteMonster.setTextureRect(sf::IntRect(0,32, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spriteMonster.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health=h;
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

	int getType(){
		return 5;
	}
};

class bossD: public monster{
public:
	bossD(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
	}
	void updateSprite(){
		spriteMonster.setTextureRect(sf::IntRect(m_col * 32, m_facing * 32, 32, 32));
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
			if(spriteMonster.getPosition().y < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 1){
			if(spriteMonster.getPosition().x > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x -= 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 2){
			if(spriteMonster.getPosition().x < 640 - 32){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.x += 32;
				spriteMonster.setPosition(tmp);
			}
		} else if(facing == 3){
			if(spriteMonster.getPosition().y > 0){
				sf::Vector2f tmp = spriteMonster.getPosition();
				tmp.y -= 32;
				spriteMonster.setPosition(tmp);
			}
		}
	}
	void setTexture(sf::Texture &texture){
		spriteMonster.setTexture(texture);
		spriteMonster.setTextureRect(sf::IntRect(0,32, 32, 32));
	}
	
	bool clicked(int x, int y){
		return spriteMonster.getGlobalBounds().contains(x,y);
	}
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health=h;
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

	int getType(){
		return 6;
	}
};

class monsterDefeated: public monster{
public:
	monsterDefeated(){
		m_facing = 0;
		m_col = 0;
		m_status = true;
	}
	void updateSprite(){
		
	}
	void walk(int facing){
		
	}
	void setTexture(sf::Texture &texture){
		
	}
	
	void setPosition(int x, int y){
		spriteMonster.setPosition(x,y);
	}
	sf::Vector2f getPosition(){
		return spriteMonster.getPosition();
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteMonster);
	}
	void sethealth(int h)
	{
		health = 0;
	}
	int gethealth()
	{
		return 0;
	}
	void setdamage(int d)
	{
		damage = 0;
	}
	void doubledamage()
	{
		damage = 0;
	}
	int getdamage()
	{
		return 0;
	}
	void damagetaken(int d){
		health = 0;
	}

	int getType(){
		return 7;
	}
};