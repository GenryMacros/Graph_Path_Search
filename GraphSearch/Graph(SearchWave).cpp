#include "Graph.h"

void Graph::SearchWave(int thisX, int thisY, int startX, int startY, sf::RenderWindow& win) {
	bool** checked;
	checked = new bool* [winWidth];
	for (int i = 0; i < winWidth; i++) {
		checked[i] = new bool[winHeight];
		for (int j = 0; j < winHeight; j++) {
			checked[i][j] = false;

		}
	}
	int** waveMatrix;
	waveMatrix = new int* [winWidth];
	for (int i = 0; i < winWidth; i++) {
		waveMatrix[i] = new int[winHeight];
	    for (int j = 0; j < winHeight; j++) {
			if (graph[i][j].isWall) waveMatrix[i][j] = -1;
			//else waveMatrix[i][j] = -2;
		} 
	}
	waveMatrix[startX][startY] = 0;
	std::queue<node> que;
	que.push(graph[startX][startY]);
	checked[startX][startY] = true;

	clock_t start = clock();

	while (!que.empty()) {
		node current = que.front();
		if (current.thisX == thisX && current.thisY == thisY) break;
		if (current.thisY < winHeight - 1 && waveMatrix[current.thisX][current.thisY + 1] != -1 && !checked[current.thisX][current.thisY + 1]) {
			waveMatrix[current.thisX][current.thisY + 1] = waveMatrix[current.thisX][current.thisY]+1;
			checked[current.thisX][current.thisY + 1] = true;
			que.push(graph[current.thisX][current.thisY + 1]);
		}
		if (current.thisY > 0 && waveMatrix[current.thisX][current.thisY - 1] != -1 &&  !checked[current.thisX][current.thisY - 1]) {
			waveMatrix[current.thisX][current.thisY - 1] = waveMatrix[current.thisX][current.thisY]+1;
			checked[current.thisX][current.thisY - 1] = true;
			que.push(graph[current.thisX][current.thisY - 1]);
		}
		if (current.thisX < winWidth - 1 && waveMatrix[current.thisX + 1][current.thisY] != -1 && !checked[current.thisX + 1][current.thisY]) {
			waveMatrix[current.thisX + 1][current.thisY] = waveMatrix[current.thisX][current.thisY]+1;
			checked[current.thisX + 1][current.thisY] = true;
			que.push(graph[current.thisX + 1][current.thisY]);
		}
		if (current.thisX > 0 && waveMatrix[current.thisX - 1][current.thisY] != -1 && !checked[current.thisX - 1][current.thisY]) {
			waveMatrix[current.thisX - 1][current.thisY] = waveMatrix[current.thisX][current.thisY]+1;
			checked[current.thisX - 1][current.thisY] = true;
			que.push(graph[current.thisX - 1][current.thisY]);
		}

		que.pop();
	}
	
	
	int currentI = thisX;
	int currentJ = thisY;
	while (true) {
		if (waveMatrix[currentI][currentJ] == 0) break;

		if (currentJ < winHeight - 1 && waveMatrix[currentI][currentJ + 1] == waveMatrix[currentI][currentJ] - 1) {
			
			currentJ++;
		}
		else if (currentJ > 0 && waveMatrix[currentI][currentJ - 1] == waveMatrix[currentI][currentJ] - 1) {
			
			currentJ--;
		}
		else if (currentI < winWidth - 1 && waveMatrix[currentI + 1][currentJ] == waveMatrix[currentI][currentJ] - 1) {
			
			currentI++;
		}
		else  if (currentI > 0 && waveMatrix[currentI - 1][currentJ] == waveMatrix[currentI][currentJ] - 1) {
		
			currentI--;
		}
		graph[currentI][currentJ].picture.setFillColor(sf::Color::Green);
	}
	clock_t end = clock();
	LastAlgoExucutionTime = ((double)(end - start) / CLOCKS_PER_SEC)*1000;
	
	graph[thisX][thisY].picture.setFillColor(sf::Color::Magenta);
	graph[startX][startY].picture.setFillColor(sf::Color::Magenta);

	win.clear();
	Draw(win);
	
	for (int i = 0; i < winHeight; i++) {
		delete[] checked[i];
	}
	delete[] checked;
	for (int i = 0; i < winHeight; i++) {
		delete[] waveMatrix[i];
	}
	delete[] waveMatrix;
}