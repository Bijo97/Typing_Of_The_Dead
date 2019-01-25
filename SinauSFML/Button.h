#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class CButton{
private:
	sf::Texture textureButton;
	sf::Sprite spriteButton;
	sf::Font fontButton;
	sf::Text textButton;
public:
	CButton(){
		textureButton.loadFromFile("images/blood8.png");
		spriteButton.setTexture(textureButton);
		spriteButton.setScale(0.6, 0.6);
		fontButton.loadFromFile("font/Demonized.ttf");
		textButton.setFont(fontButton);
		textButton.setColor(sf::Color::White);
		textButton.setCharacterSize(30);
		textButton.setString("Click here");
		textButton.setOrigin(textButton.getGlobalBounds().width / 2, textButton.getGlobalBounds().height / 2);
		textButton.setPosition(spriteButton.getGlobalBounds().width / 2, spriteButton.getGlobalBounds().height / 2);
	}
	CButton(char *nama){
		textureButton.loadFromFile("images/blood8.png");
		spriteButton.setTexture(textureButton);
		spriteButton.setScale(0.4, 0.4);
		fontButton.loadFromFile("font/Demonized.ttf");
		textButton.setString(nama);
		textButton.setFont(fontButton);
		textButton.setColor(sf::Color::White);
		textButton.setCharacterSize(30);
		textButton.setOrigin(textButton.getGlobalBounds().width / 2, textButton.getGlobalBounds().height / 2);
		textButton.setPosition(spriteButton.getGlobalBounds().left + spriteButton.getGlobalBounds().width / 2, spriteButton.getGlobalBounds().top + spriteButton.getGlobalBounds().height / 2);
	}
	void draw(sf::RenderWindow &window){
		window.draw(spriteButton);
		window.draw(textButton);
	}
	void settext(char *nama){
		textButton.setString(nama);
	}
	void setPosition(float x, float y){
		spriteButton.setPosition(x, y);
		textButton.setPosition(spriteButton.getGlobalBounds().left + spriteButton.getGlobalBounds().width / 2, spriteButton.getGlobalBounds().top + spriteButton.getGlobalBounds().height / 2);
	}
	bool isClicked(float x, float y){
		if(spriteButton.getGlobalBounds().contains(x, y)){
			return true;
		}
		return false;
	}
	float getX(){
		return spriteButton.getPosition().x;
	}
	float getY(){
		return spriteButton.getPosition().y;
	}
};