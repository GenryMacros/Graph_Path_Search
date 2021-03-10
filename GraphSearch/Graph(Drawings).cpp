#include "Graph.h"

void Graph::Draw(sf::RenderWindow& win) {

	for (int i = 0; i < winHeight; i++) {
		for (int j = 0; j < winWidth; j++) {
			win.draw(graph[i][j].picture);
		}
	}

	//win.display();
}
void Graph::PaintToNormal() {
	for (int i = 0; i < winHeight; i++) {
		for (int j = 0; j < winWidth; j++) {
			if (!graph[i][j].isWall) graph[i][j].picture.setFillColor(baseColor);
			else  graph[i][j].picture.setFillColor(baseWallColor);
			//win.draw(graph[i][j].picture);
			//if (graph[i][j].isWall) graph[i][j].picture.setFillColor(baseWallColor);
		}
	}
}
void Graph::DestroyWalls() {
	for (int i = 0; i < winHeight; i++) {
		for (int j = 0; j < winWidth; j++) {
			graph[i][j].isWall = false;
		}
	}
}
void Graph::RandomizeWalls(sf::RenderWindow& win) {
	win.clear();
	DestroyWalls();
	int wallsC = 0;
	int rowWallsC = 0;
	for (int x = 0; x < winWidth; x++) {
		for (int y = 0; y < winHeight; y++) {
			int wallNum = rand() % 10;
			if (wallNum <= 1 && wallsC < wallsCount && rowWallsC < wallsInARow) {
				graph[x][y].isWall = true;
				graph[x][y].picture.setFillColor(sf::Color::Red);
				wallsC++;
				rowWallsC++;
			}
			rowWallsC = 0;
		}
	}
	LiveWallGeneration();
	PaintToNormal();
	Draw(win);
}
void Graph::ChangeAlgo() {
	if (currentAlgoritm == &Graph::SearchWave) {
		currentAlgoritm = &Graph::Search;
		currentAlgo = "A*";
	}
	else {
		currentAlgoritm = &Graph::SearchWave;
		currentAlgo = "Lee's";
	}
}