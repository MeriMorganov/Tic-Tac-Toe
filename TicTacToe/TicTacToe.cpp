#include "TicTacToe.h"
namespace TicTacToe
{
    TicTacToe::TicTacToe()
    {
        grid->InitializeGrid();
    }
    TicTacToe::~TicTacToe()
    {
    }
    TicTacToe& TicTacToe::Instance()
    {
            static TicTacToe INSTANCE;
            return INSTANCE;
    }
    void TicTacToe::TicTacToe::Update()
    {
        while (Commons::AppWindow::Instance().IsOpen())
        {
            sf::Event event;
            while (Commons::AppWindow::Instance().PollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    Commons::AppWindow::Instance().Close();
            }

            Commons::AppWindow::Instance().Clear();
            Draw();
            Commons::AppWindow::Instance().Display();
            if (grid->IsGameDone())
            {
                
            }
            else
            {
                grid->CheckForPiecesMouseClick(event);
            }
        }
    }
    void TicTacToe::Draw()
    {
        grid->Draw();
        TurnManager::Instance().Draw();
    }
}
