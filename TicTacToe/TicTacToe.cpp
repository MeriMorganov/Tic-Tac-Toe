#include "TicTacToe.h"
namespace TicTacToe
{
    void TicTacToe::TicTacToe::Launch()
    {
        std::unique_ptr<Grid> grid = std::make_unique<Grid>();
        grid->InitializeGrid();
        while (Commons::AppWindow::Instance().IsOpen())
        {
            sf::Event event;
            while (Commons::AppWindow::Instance().PollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    Commons::AppWindow::Instance().Close();
            }

            Commons::AppWindow::Instance().Clear();
            grid->Draw();
            TurnManager::Instance().Draw();
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
    }
}
