#pragma once
#include "Graph.h"
#include "UI_Panel.h"

class MouseEvents {
public:
	 MouseEvents(unsigned int height,unsigned int width, sf::RenderWindow& win) {
		 gr = Graph(width, height, win);
		 UI.DrawPanel(win,0,gr.currentAlgo);
		 gr.Draw(win);

	}
	void ProcessClick(sf::RenderWindow& win) {
		sf::Vector2i mouse= sf::Mouse::getPosition(win);
		if (CheckUIElemets(mouse, win)) {
		
		}
		else if (!isSelected) {
			startPoint = mouse;
			win.clear();
			for (int i = 0; i < gr.winWidth; i++) {
				for (int j = 0; j < gr.winHeight; j++) {
					if (gr.graph[i][j].picture.getGlobalBounds().contains(startPoint.x, startPoint.y) && !gr.graph[i][j].isWall) {
						isSelected = true;
						startPoint.x = i;
						startPoint.y = j;
						gr.graph[i][j].picture.setFillColor(sf::Color::Magenta);
					}
					else if(gr.graph[i][j].isWall) gr.graph[i][j].picture.setFillColor(gr.GetWallColor());
					else  gr.graph[i][j].picture.setFillColor(gr.GetBaseColor());
					win.draw(gr.graph[i][j].picture);
				}
			}
			
		
		}
		else {
			isSelected = false;
			sf::Vector2i endPos = sf::Mouse::getPosition(win);
			gr.SearchByCoords(endPos, win, startPoint);
			
		};
		UI.DrawPanel(win,gr.GetExecutionTime(),gr.currentAlgo);
		win.display();
	}
	bool CheckUIElemets(sf::Vector2i& Mouse,sf::RenderWindow& win) {
		sf::Vector2i mouse= Mouse;
		if (UI.GetRebuildSp().getGlobalBounds().contains(Mouse.x, Mouse.y)) {
			gr.RandomizeWalls(win);
			return true;
		}
		else if (UI.GetChangeMethodSp().getGlobalBounds().contains(Mouse.x, Mouse.y)) {
			gr.ChangeAlgo();
			gr.Draw(win);
			return true;
		}
		return false;
	}
private:
	Graph gr;
	sf::Vector2i startPoint;
	bool isSelected=false;
};