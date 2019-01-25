#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "Powerup.h"
#include "Button.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

class Game{
private:
	sf::RenderWindow window;
	sf::Texture texturePlayer;
	sf::Texture textureMonster;
	sf::Texture textureMap;
	sf::Texture textureTerrain;
	sf::Texture textureMenu;
	sf::Sprite spriteMenu;
	sf::Clock m_clock;
	sf::Clock n_clock;
	sf::Clock o_clock;
	sf::Clock s_clock;
	sf::Clock h_clock;
	sf::Text healthText;
	sf::String healthString;
	sf::Font healthFont;
	sf::Text lifeText;
	sf::String lifeString;
	sf::Font lifeFont;
	std::ostringstream convert;
	std::ostringstream ubah;
	sf::Text typerText;
	sf::String typerString;
	sf::Font typerFont;
	sf::Text inputText;
	sf::String inputString;
	sf::Font inputFont;
	sf::Text scoreText;
	sf::String scoreString;
	sf::Font scoreFont;
	sf::Text nilaiText;
	sf::String nilaiString;
	sf::Font nilaiFont;
	sf::Time m_time;
	sf::Time n_time;
	sf::Time o_time;
	sf::Time s_time;
	sf::Time h_time;
	player hero;
	Map m_map;
	powerup skill;
	monster *zombie[100];
	int jumlah_zombie, jumlah_kata, kill, count, jumlah_input, score, jumlah_score;
	bool timekeeper;
	char kata[100][20], temp[20], input[20];
	std::string highscore[10];
	std::fstream pf;
public:
	//Constructor
	Game():window(sf::VideoMode(640,640), "SFML works!"){
		srand(time(NULL));

		scoreFont.loadFromFile("font/Demonized.ttf");
		scoreString="SCORE: ";
		scoreText.setString(scoreString);
		scoreText.setFont(scoreFont);
		scoreText.setColor(sf::Color::White);
		scoreText.setCharacterSize(16);
		scoreText.setPosition(32,32);

		score = 0;
		nilaiFont.loadFromFile("font/Demonized.ttf");
		ubah<<score;
		nilaiString = ubah.str();
		ubah.str("");
		nilaiText.setString(nilaiString);
		nilaiText.setFont(nilaiFont);
		nilaiText.setColor(sf::Color::White);
		nilaiText.setCharacterSize(16);
		nilaiText.setPosition(120,32);

		healthFont.loadFromFile("font/Demonized.ttf");
		healthString="HEALTH: ";
		healthText.setString(healthString);
		healthText.setFont(healthFont);
		healthText.setColor(sf::Color::White);
		healthText.setCharacterSize(16);
		healthText.setPosition(450,32);

		lifeFont.loadFromFile("font/Demonized.ttf");
		convert<<hero.gethealth();
		lifeString = convert.str();
		convert.str(""); 
		lifeText.setString(lifeString);
		lifeText.setFont(lifeFont);
		lifeText.setColor(sf::Color::White);
		lifeText.setCharacterSize(16);
		lifeText.setPosition(550,32);

		texturePlayer.loadFromFile("images/hero.png");
		textureMap.loadFromFile("images/tile.png");
		textureTerrain.loadFromFile("images/rumput.png");
		hero.setTexture(texturePlayer);
		hero.setPosition(320,320);
		m_map.setTexture(textureMap);
		m_map.setTerrainTexture(textureTerrain);
		m_time = sf::seconds(1);
		n_time = sf::seconds(0.5);
		o_time = sf::seconds(1.5);
		s_time = sf::seconds(2);
		h_time = sf::seconds(1);
		m_map.loadFile("map1.txt");
		m_map.display();
		jumlah_zombie = 0;
		zombie[jumlah_zombie] = new monsterA;
		zombie[jumlah_zombie]->setTexture(textureMonster);
		textureMonster.loadFromFile("images/monster.png");
		zombie[jumlah_zombie]->setPosition(64,64);
		jumlah_zombie++;
		kill = 0;
		count = 0;
		timekeeper = false;
		jumlah_input = 0;

		jumlah_kata = 0;
		pf.open("words.txt", std::ios::in);
		if (pf.is_open() == true){
			while (!pf.eof()){
				pf.getline(kata[jumlah_kata], '\n');
				jumlah_kata++;
			}
		} else {
			std::cout<<"File tidak bisa dibuka!!!";
		}
		pf.close();

		typerFont.loadFromFile("font/Demonized.ttf");
		strcpy(temp, kata[0]);
		typerString = temp;
		typerText.setString(typerString);
		typerText.setFont(typerFont);
		typerText.setColor(sf::Color::White);
		typerText.setCharacterSize(40);
		typerText.setPosition(225, 560);

		for (int i = 0; i < 20; i++){
			input[i] = '\0';
		}

		textureMenu.loadFromFile("images/menu.jpg");
		spriteMenu.setTexture(textureMenu);
	}

	//Screen menu utama
	void Menu(){
		sf::Text titleText;
		sf::String titleString;
		sf::Font titleFont;
		sf::SoundBuffer bufferHorn1;
		sf::Sound soundHorn1;
		sf::SoundBuffer suarawal;
		sf::Sound suarawal1;
		bufferHorn1.loadFromFile("sounds/Killer_Movie_Scene-SoundBible (1).wav");
		soundHorn1.setPlayingOffset(sf::seconds(4));
		soundHorn1.setLoop(true);
		soundHorn1.setBuffer(bufferHorn1);
		suarawal.loadFromFile("sounds/Halloween_Vocals-Mike_Koenig-517765553.wav");
		suarawal1.setPlayingOffset(sf::seconds(4));
		suarawal1.setLoop(true);
		suarawal1.setBuffer(suarawal);
		CButton buttonStart("START");
		CButton buttonHighscore("HIGHSCORE");
		CButton buttonExit("EXIT");
		buttonStart.setPosition(150, 100);
		buttonHighscore.setPosition(20, 350);
		buttonExit.setPosition(320, 350);

		titleFont.loadFromFile("font/Demonized.ttf");
		titleString="Typing of the Dead";
		titleText.setString(titleString);
		titleText.setFont(titleFont);
		titleText.setColor(sf::Color::Red);
		titleText.setCharacterSize(40);
		titleText.setPosition(96,32);
		suarawal1.play();
		while (window.isOpen()){
			window.clear();
			window.draw(spriteMenu);
			sf::Event event;
			while (window.pollEvent(event)){
				if (event.type == sf::Event::Closed)
					window.close();

				//Mengecek apakah mouse diklik
				if (event.type == sf::Event::MouseButtonPressed){
					if (event.mouseButton.button == sf::Mouse::Left){
						if(buttonStart.isClicked(event.mouseButton.x, event.mouseButton.y)){
							play();
						}

						if(buttonHighscore.isClicked(event.mouseButton.x, event.mouseButton.y)){
							Highscore();
						}

						if(buttonExit.isClicked(event.mouseButton.x, event.mouseButton.y)){
							window.close();
						}
					}
				}

			}

			
			spriteMenu.setPosition(0, 0);
			
			window.draw(titleText);
			buttonStart.draw(window);
			buttonHighscore.draw(window);
			buttonExit.draw(window);
			window.display();
		}
	}

	//Screen highscore
	void Highscore(){
		CButton buttonBack("BACK");
		buttonBack.setPosition(175, 400);

		sf::Font hFont;
		sf::Text hText;
		hText.setFont(hFont);
		hText.setColor(sf::Color::White);
		hText.setCharacterSize(35);
		
		std::ifstream ff("Score.txt");
		for(int i=0; i<10; i++){
			std::getline(ff,highscore[i]);
			std::cout<<highscore[i]<<std::endl;
		}
		ff.close();
		int y = 64;
		hFont.loadFromFile("font/Demonized.ttf");
		while (window.isOpen()){
			sf::Event event;
			while (window.pollEvent(event)){
				if (event.type == sf::Event::Closed)
					window.close();

				//Mengeccek apakah button diklik
				if (event.type == sf::Event::MouseButtonPressed){
					if (event.mouseButton.button == sf::Mouse::Left){
						if(buttonBack.isClicked(event.mouseButton.x, event.mouseButton.y)){
							Menu();
						}
					}
				}

			}

			window.clear();
			buttonBack.draw(window);
			for (int i = 0; i < 10; i++){
				hText.setPosition(64, y+i*32);
				hText.setString(highscore[i]);
				window.draw(hText);
			}
			window.display();
		}
	}

	//Screen game over
	void gameOver(){
		bool back = false;
		sf::Text endText;
		sf::String endString;
		sf::Font endFont;
		sf::SoundBuffer bufferHorn1;
		sf::Sound soundHorn1;
		bufferHorn1.loadFromFile("sounds/Killer_Movie_Scene-SoundBible (1).wav");
		soundHorn1.setPlayingOffset(sf::seconds(4));
		soundHorn1.setLoop(true);
		soundHorn1.setBuffer(bufferHorn1);
		//button
		CButton buttonBack("BACK");
		buttonBack.setPosition(224, 400);

		endFont.loadFromFile("font/Demonized.ttf");
		endString="GAME OVER";
		endText.setString(endString);
		endText.setFont(endFont);
		endText.setColor(sf::Color::Red);
		endText.setCharacterSize(60);
		endText.setPosition(128,64);

		while (window.isOpen()){
			sf::Event event;
			soundHorn1.play();
			while (window.pollEvent(event)){
				if (event.type == sf::Event::Closed)
					window.close();

				//Mengecek apakah mouse diklik
				if (event.type == sf::Event::MouseButtonPressed){
					if (event.mouseButton.button == sf::Mouse::Left){
						if(buttonBack.isClicked(event.mouseButton.x, event.mouseButton.y)){
							Menu();
						}
					}
				}

			}

			window.clear();
			spriteMenu.setPosition(0, 0);
			window.draw(spriteMenu);
			window.draw(endText);
			window.draw(scoreText);
			window.draw(nilaiText);
			buttonBack.draw(window);
			window.display();
		}
	}

	//Merandom monster mana yang akan dimunculkan
	int randomMonster(){
		int temp;
		temp = rand() % 3;
		return temp;
	}

	//Merandom posisi X monster
	int randomPositionX(){
		int x = 1;
		while (x % 32 != 0 || x == 320){
			x = rand() % 608 + 32;
		}
		return x;
	}

	//Merandom posisi Y monster
	int randomPositionY(){
		int y = 1;
		while (y % 32 != 0 || y == 320){
			y = rand() % 608 + 32;
		}
		return y;
	}

	//Merandom powerup
	int randomPowerup(){
		int temp;
		temp = rand() % 3;
		return temp;
	};
	
	//Merandom kata
	int randomKata(){
		int temp;
		temp = rand() % jumlah_kata;
		return temp;
	}

	//Memulai game
	void play(){
		sf::SoundBuffer bufferHorn1;
		sf::Sound soundHorn1;
		sf::SoundBuffer bufferHorn2;
		sf::Sound soundHorn2;
		bufferHorn1.loadFromFile("sounds/Zombie Come Here-SoundBible.com-1731145186.wav");
		soundHorn1.setPlayingOffset(sf::seconds(4));
		soundHorn1.setLoop(true);
		soundHorn1.setBuffer(bufferHorn1);		
		bufferHorn2.loadFromFile("sounds/Zombie Gets Attacked-SoundBible.com-20348330.wav");
		soundHorn2.setPlayingOffset(sf::seconds(0));
		soundHorn2.setLoop(true);
		soundHorn2.setBuffer(bufferHorn2);
		while (window.isOpen()){
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed){
					window.close();
				}

				//Untuk menginput kata
				if (event.type == sf::Event::TextEntered){
					if (event.text.unicode < 128){
						char c = static_cast<char>(event.text.unicode);
						if (c == temp[jumlah_input]){
							input[jumlah_input] = c;
							puts(input);

							inputFont.loadFromFile("font/Demonized.ttf");
							inputString = inputString + input[jumlah_input];
							inputText.setString(inputString);
							inputText.setFont(inputFont);
							inputText.setColor(sf::Color::Red);
							inputText.setCharacterSize(40);
							inputText.setPosition(225, 560);
							jumlah_input++;
						}
					}
				}

				//Untuk menghapus kata
				if (event.type == sf::Event::KeyReleased){
					if (event.key.code == sf::Keyboard::BackSpace){
						input[jumlah_input - 1] = '\0';
						puts(input);
						jumlah_input--;
						if (jumlah_input < 0){
							jumlah_input = 0;
						}

						inputString.clear();
						inputText.setString(inputString);
						for (int i = 0; i < jumlah_input; i++){
							inputString = inputString + input[i];
						}
						inputText.setString(inputString);
					}
				}
			}

			//Untuk menghitung waktu animasi player
			if (h_clock.getElapsedTime() >= h_time){
				hero.updateSprite();
				h_clock.restart();
			}

			//Untuk menghitung waktu animasi monster
			if (m_clock.getElapsedTime() >= m_time){
				for (int i = 0; i < jumlah_zombie; i++){
					count++;
					if (zombie[i]->getPosition().x < 320 && zombie[i]->getPosition().y < 320){
						zombie[i]->walk(2);
						zombie[i]->updateSprite();
					} else if (zombie[i]->getPosition().x > 320 && zombie[i]->getPosition().y < 320){
						zombie[i]->walk(1);
						zombie[i]->updateSprite();
					} else if (zombie[i]->getPosition().x && zombie[i]->getPosition().y < 320){
						zombie[i]->walk(0);
						zombie[i]->updateSprite();
					} else if (zombie[i]->getPosition().x < 320 && zombie[i]->getPosition().y == 320){
						zombie[i]->walk(2);
						zombie[i]->updateSprite();
					} else if (zombie[i]->getPosition().x > 320 && zombie[i]->getPosition().y == 320){
						zombie[i]->walk(1);
						zombie[i]->updateSprite();
					} else if (zombie[i]->getPosition().x == 320 && zombie[i]->getPosition().y == 320){
						zombie[i]->updateSprite();
						hero.damagetaken(zombie[i]->getdamage());
						convert<<hero.gethealth();
						lifeString = convert.str();
						convert.str(""); 
						lifeText.setString(lifeString);
					} else if (zombie[i]->getPosition().x < 320 && zombie[i]->getPosition().y > 320){
						zombie[i]->walk(3);
						zombie[i]->updateSprite();
					} else if (zombie[i]->getPosition().x > 320 && zombie[i]->getPosition().y > 320){
						zombie[i]->walk(1);
						zombie[i]->updateSprite();
					} else if (zombie[i]->getPosition().x == 320 && zombie[i]->getPosition().y > 320){
						zombie[i]->walk(3);
						zombie[i]->updateSprite();
					}
					m_clock.restart();
				}
			}

			//Zombie baru muncul
			if (s_clock.getElapsedTime() >= s_time){
				int temp;
				temp = randomMonster();
				if (temp == 0){
					zombie[jumlah_zombie] = new monsterA;
				} else if (temp == 1){
					zombie[jumlah_zombie] = new monsterB;
				} else if (temp == 2){
					zombie[jumlah_zombie] = new monsterC;
				}
				zombie[jumlah_zombie]->setTexture(textureMonster);
				textureMonster.loadFromFile("images/monster.png");
				zombie[jumlah_zombie]->setPosition(randomPositionX(), randomPositionY());
				jumlah_zombie++;
				s_clock.restart();
				soundHorn1.play();
			}

			//Untuk mengeck apakah kata yang diinputkan benar
			if (strcmp(temp, input) == 0){
				for (int i = 0; i < 20; i++){
					input[i] = '\0';
				}
				int index = randomKata();
				strcpy(temp, kata[index]);
				typerString = temp;
				typerText.setString(typerString);
				jumlah_input = 0;
				inputString.clear();
				inputText.setString(inputString);

				//Untuk mengecek zombie mana yang posisinya terdekat dengan pemain
				int min = 1000, bil = 0, no = 0;		
				for (int i = 0; i < jumlah_zombie; i++){
					bil = sqrt((float)pow((float)(zombie[i]->getPosition().x - hero.getPosition().x), 2) + (float)pow((float)(zombie[i]->getPosition().y - hero.getPosition().y), 2));
					if (bil < min){
						min = bil;
						no = i;
					}
				}

				//Untuk menambah score
				if (zombie[no]->getType() == 0){
					score = score + 100;
				} else if (zombie[no]->getType() == 1){
					score = score + 150;
				} else if (zombie[no]->getType() == 2){
					score = score + 200;
				}

				ubah<<score;
				nilaiString = ubah.str();
				ubah.str("");
				nilaiText.setString(nilaiString);

				//Untuk menghilangkan zombie terdekat
				for (int i = no; i < jumlah_zombie - 1; i++){
					if (zombie[i + 1]->getType() == 0){
						zombie[i] = new monsterA;
						zombie[i] = zombie[i + 1];
					} else if (zombie[i + 1]->getType() == 1){
						zombie[i] = new monsterB;
						zombie[i] = zombie[i + 1];
					} else if (zombie[i + 1]->getType() == 2){
						zombie[i] = new monsterC;
						zombie[i] = zombie[i + 1];
					}
				}
				jumlah_zombie--;
				kill++;
			}

			//Untuk memunculkan powerup
			if (kill == 10 && kill != 0){
				int temp = randomPowerup();
				if (temp == 0){//Paramedic
					skill.setparamedic(hero);
					std::cout<<"Paramedic"<<std::endl;
				} else if (temp == 1){//Poison
					for (int i = 0; i < jumlah_zombie; i++){
						skill.setpoison(zombie[i]);
					}
					std::cout<<"Poison"<<std::endl;
				} else if (temp == 2){//Timekeeper
					count = 0;
					m_time = sf::seconds(3);
					n_time = sf::seconds(2.5);
					o_time = sf::seconds(3.5);
					s_time = sf::seconds(4);
					timekeeper = true;
					std::cout<<"Timekeeper"<<std::endl;
				}
				kill = 0;
			}

			//Untuk mengecek timekeeper
			if (timekeeper == true){
				if (count == 5){
					m_time = sf::seconds(1);
					n_time = sf::seconds(0.5);
					o_time = sf::seconds(1.5);
					s_time = sf::seconds(2);
					count = 0;
					timekeeper = false;
				}
			}

			//Untuk mengecek apakah health player sudah habis atau belum
			if (hero.gethealth() <= 0){
				std::ofstream InputFile("Score.txt");
				if(InputFile.is_open()){
					for (int i = 0; i < 10; i++){
						if (score >= std::stoi(highscore[i])){
							for (int j = 9; j >= i; j--){
								if (j == i){
									std::ostringstream skor;
									skor<<score;
									highscore[j] = skor.str();
								} else {
									highscore[j] = highscore[j - 1];
								}
							}
						}
					}

					for(int i=0; i<10; i++){
					InputFile<<highscore[i]<<std::endl;
					}
				}
				InputFile.close();
				break;
			}

			window.clear();
			m_map.draw(window);
			hero.draw(window);
			for (int i = 0; i < jumlah_zombie; i++){
				zombie[i]->draw(window);
			}
			window.draw(healthText);
			window.draw(lifeText);
			window.draw(typerText);
			window.draw(inputText);
			window.draw(scoreText);
			window.draw(nilaiText);
			window.display();
		}
	}
};