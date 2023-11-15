#include <planet.hpp>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>


int main()
{
	srand(time(NULL));
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Fractal");
	
	int x0, y0;
	sf::VertexArray apex(sf::Points, 5);
	for (int i = 0; i < 5; i++)
	{
		apex[i].color = sf::Color(255, 100, 100);
		//apex[i].position = sf::Vector2f(rand() % 800, rand() % 800);

		x0 = 400 + 400 * sin(2 * M_PI * i / 5);
		y0 = 400 + 400 * cos(2 * M_PI * i / 5);
		apex[i].position = sf::Vector2f(x0, y0);
	}

	/*apex[0].position = sf::Vector2f(0, 0);
	apex[1].position = sf::Vector2f(0, 800);
	apex[2].position = sf::Vector2f(800, 0);
	apex[3].position = sf::Vector2f(800, 800);
	apex[4].position = sf::Vector2f(400, 400);
	apex[4].position = sf::Vector2f(0, 400);
	apex[5].position = sf::Vector2f(400, 0);
	apex[6].position = sf::Vector2f(800, 400);
	apex[7].position = sf::Vector2f(400, 800);*/


	int x = rand() % 800;
	int y = rand() % 800;
	int n = 0;
	int m = 0;
	
	sf::VertexArray p(sf::Points, 100000);
	for (int i = 0; i < 100000; i++)
	{
		p[i].color = sf::Color(255, 255, 255);
		while (n == m)
		{
			m = rand() % 5;
		}
		n = m;
		x = (x + apex[n].position.x)/2;
		y = (y + apex[n].position.y)/2;
		p[i].position = sf::Vector2f(x, y);

		if (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}


			window.clear();
			window.draw(apex);
			window.draw(p);
			window.display();
		}
	}

	

}