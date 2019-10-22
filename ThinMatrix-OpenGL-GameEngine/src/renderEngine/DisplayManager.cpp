#include "DisplayManager.h"

#include <SFML/Graphics.hpp>
#include <GL/glew.h>

#include <memory>

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;
constexpr int FPS_LIMIT = 60;

namespace DisplayManager
{

namespace
{
std::unique_ptr<sf::RenderWindow> m_window;
}

void Create()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT),
												   "C++ Game Engine",
												   sf::Style::Default, settings);
	m_window->setFramerateLimit(FPS_LIMIT);

	glewInit();
	glewExperimental = GL_TRUE;

	glViewport(0, 0, WIDTH, HEIGHT);
}

void Update()
{
	m_window->display();
}

void Close()
{
	m_window->close();
}

void Refresh(float R, float G, float B, float A)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(R, G, B, A);
}

void CheckForClose()
{
	sf::Event e;

	while(m_window->pollEvent(e))
	{
		switch(e.type)
		{
			case sf::Event::Closed:
				Close();
			default:
				break;
		}
	}
}

bool isOpen()
{
	return m_window->isOpen();
}

}