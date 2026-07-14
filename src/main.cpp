#include <SFML/Graphics.hpp>
#include <iostream>

void test()
{
	sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
	sf::CircleShape shape(100.f);
	sf::Vector2f test = shape.getGeometricCenter();
	test.x = test.x - 100;
	shape.setPosition(test);
	shape.setFillColor(sf::Color::Green);

	/*while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/
	sf::VertexArray point(sf::PrimitiveType::Points, 100*100);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) 
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		// Задаем координаты и цвет пикселя
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				point[i*100+j].position = sf::Vector2f(static_cast<float>(i)+ 50, static_cast<float>(j) + 50);
				point[i*100+j].color = sf::Color::Red;
			}
		}

		window.clear();
		window.draw(point); // Отрисовка на экране
		window.display();
	}
}


int main()
{
	//int a;
	//std::cin >> a;
	//while (a != 0)
	{
		test();
		//std::cin >> a;
	}
}
