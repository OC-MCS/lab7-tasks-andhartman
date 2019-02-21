#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0f;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{

		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		ship.move(DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		ship.move(0, -DISTANCE);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		ship.move(0, DISTANCE);
	}
}



int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");

	window.setFramerateLimit(60);

	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}

	Sprite background;
	background.setTexture(starsTexture);
	background.setScale(1.5, 1.5);

	Sprite ship;
	ship.setTexture(shipTexture);

	Sprite missile;
	missile.setTexture(missileTexture);

	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 2.0f;
	ship.setPosition(shipX, shipY);

	bool isMissileInFlight = false;

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space && !isMissileInFlight)
				{
					isMissileInFlight = true;

					Vector2f pos = ship.getPosition();
					missile.setPosition(pos.x, pos.y);
					window.draw(missile);
				}
			}
		}

		window.draw(background);
		moveShip(ship);
		window.draw(ship);

		if (isMissileInFlight)
		{
			missile.move(0, -5);
			window.draw(missile);
			float pos = missile.getPosition().y;
			if (pos < -5)
				isMissileInFlight = false;
		}

		window.display();

	}

	return 0;
}

