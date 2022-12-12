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
            if (restartButton->IsClicked(event))
            {
                Reset();
            }
            if (grid->IsGameDone())
            {
                
            }
            else
            {
                grid->CheckForPiecesMouseClick(event);
            }
            restartButton->UpdateState(event);
            Commons::AppWindow::Instance().Display();
        }
    }
    void TicTacToe::Draw()
    {
        grid->Draw();
        restartButton->Draw();
        ScoreBoard::Instance().Draw();
        grid->IsGameDone() ? WinnerBoard::Instance().Draw() : TurnManager::Instance().Draw();

        if (grid->IsGameDone() && !grid->CheckIfTie())
        {
            WinnerBoard::Instance().DrawWinnerMedal();
        }
    }
    void TicTacToe::Reset()
    {
        grid->Reset();
        TurnManager::Instance().Reset();
    }
}
