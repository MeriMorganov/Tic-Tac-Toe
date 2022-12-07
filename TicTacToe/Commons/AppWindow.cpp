#include "AppWindow.h"
namespace Commons
{

	const char* AppWindow::WINDOW_NAME = "Tic-Tac-Toe";

	AppWindow::AppWindow()
	{

	}
	AppWindow::~AppWindow()
	{
		renderWindow.clear();
	}

	AppWindow& AppWindow::Instance()
	{
		static AppWindow INSTANCE;
		return INSTANCE;
	}

	sf::Vector2f AppWindow::GetMousePos()
	{
		return renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));
	}

	bool AppWindow::IsOpen()
	{
		return renderWindow.isOpen();
	}
	bool AppWindow::PollEvent(sf::Event& event)
	{
		return renderWindow.pollEvent(event);
	}

	void AppWindow::Draw(const sf::Drawable& drawable, const sf::RenderStates& states)
	{
		renderWindow.draw(drawable, states);
	}
	void AppWindow::Close()
	{
		renderWindow.close();
	}
	void AppWindow::Clear()
	{
		renderWindow.clear();
	}
	void AppWindow::Display()
	{
		renderWindow.display();
	}
}