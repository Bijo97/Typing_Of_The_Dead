#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include <stdlib.h>
#include <time.h>

class powerup{
public:
	void setparamedic(player h)
	{
		h.addhealth(20);
	}
	void setpoison(monster *z)
	{
		z->sethealth(0);
	}
};