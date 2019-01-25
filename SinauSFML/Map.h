#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

class Map{
private:
	int **m_grid;
	sf::Sprite m_sprite;
	sf::Sprite m_terrain;
	std::vector <sf::Vector2i> m_pos;
public:
	Map(){
		m_grid = new int*[20];
		for(int q = 0; q < 20; q++){
			m_grid[q] = new int[20];
			for(int w = 0; w < 20;w++){
				m_grid[q][w] = 0;
			}
		}
		//Set Dulu posisi gambar
		m_pos.push_back(sf::Vector2i(0,0));
		m_pos.push_back(sf::Vector2i(3,3));
		m_pos.push_back(sf::Vector2i(0,2));

		//Terrain
		m_terrain.setTextureRect(sf::IntRect(0,0,32,32));
	}
	void setTexture(sf::Texture &texture){
		m_sprite.setTexture(texture);
	}
	void setTerrainTexture(sf::Texture &texture){
		m_terrain.setTexture(texture);
	}
	void loadFile(char * fileName){
		FILE *pf = fopen(fileName,"r");
		for(int q = 0; q < 20; q++){
			for(int w = 0; w < 20;w++){
				fscanf(pf,"%d",&m_grid[q][w]);
			}
		}
		fclose(pf);
	}
	void display(){
		for(int q = 0; q < 20;q++){
			for(int w = 0; w < 20;w++){
				std::cout << m_grid[q][w] << " ";
			}
			std::cout << std::endl;
		}
	}
	bool canMoveTo(int facing, sf::Vector2f pos){
		int x = pos.x, y = pos.y;
		//std::cout << "x : " << x << " " << "y : " << y << std::endl;
		if(facing == 0){
			if(y < 19){
				return m_grid[y + 1][x] == 0;
			}
		}else if(facing  == 1){
			if (x > 0) {
				return m_grid[y][x - 1] == 0;
			}
		}else if(facing == 2){
			if(x < 19){
				return m_grid[y][x + 1] == 0;
			}
		}else if(facing == 3){
			if(y > 0){
				return m_grid[y - 1][x] == 0;
			}
		}
	}
	void draw(sf::RenderWindow &window){
		for(int q = 0; q < 20;q++){
			for(int w = 0; w < 20;w++){
				m_sprite.setPosition(w * 32, q * 32);
				m_terrain.setPosition(w * 32, q * 32);
				sf::Vector2i tmp = m_pos[m_grid[q][w]];
				m_sprite.setTextureRect(sf::IntRect(tmp.x * 30, tmp.y *31,29,31));
				window.draw(m_terrain);
				window.draw(m_sprite);
			}
		}
	}
};