#include "Graph.h"
#define ASS 100


void Graph::Search(int thisX, int thisY,int startX,int startY, sf::RenderWindow& win) {

	if (thisX >= winHeight || thisY >= winHeight) {
		std::cout << "[ERROR] There is no such element in this graph!" << std::endl;
		return;
	}
/*	int startX=0;
	int startY=0;
		for (int i = 0; i < winWidth; i++) {
			for (int j = 0; j < winHeight; j++) {
				if (graph[i][j].picture.getPosition() == un.GetPos()) {
					startX = i;
					startY = j;
				}
			}
		}    */
	bool** checked;
	checked = new bool* [winHeight];
	for (int i = 0; i < winHeight; i++) {
		checked[i] = new bool[winWidth];
		for (int j = 0; j < winWidth; j++) {
			checked[i][j] = false;

		}
	}
	node** came_from;
	came_from = new node * [winHeight];
	for (int i = 0; i < winHeight; i++) {
		came_from[i] = new node[winWidth];
		/*for (int j = 0; j < winWidth; j++) {
			if (graph[i][j].isWall) came_from[i][j].isWall = true;
		} */
	}


	checked[startX][startY] = true;
	std::queue<node> que;
	que.push(graph[startX][startY]);

	clock_t start = clock();

	while (!que.empty()) {

		node current = que.front();
		if (graph[current.thisX][current.thisY].isWall) {
			que.pop();
			continue;
		}
		if (current.thisX == thisX && current.thisY == thisY) break;
		
		//Вверх
		if (current.thisY < winWidth - 1 && checked[current.thisX][current.thisY + 1] == false) {

			que.push(graph[current.thisX][current.thisY + 1]);
			checked[current.thisX][current.thisY + 1] = true;
			came_from[current.thisX][current.thisY + 1] = current;

		}
		//Вправо
	
		if (current.thisX < winHeight - 1 && checked[current.thisX + 1][current.thisY] == false) {

			que.push(graph[current.thisX + 1][current.thisY]);
			checked[current.thisX + 1][current.thisY] = true;
			came_from[current.thisX + 1][current.thisY] = current;

		}
		//Вниз

		if (current.thisY > 0 && checked[current.thisX][current.thisY - 1] == false) {


			que.push(graph[current.thisX][current.thisY - 1]);
			checked[current.thisX][current.thisY - 1] = true;
			came_from[current.thisX][current.thisY - 1] = current;

		}
		//Налево
		if (current.thisX > 0 && checked[current.thisX - 1][current.thisY] == false) {

			que.push(graph[current.thisX - 1][current.thisY]);
			checked[current.thisX - 1][current.thisY] = true;
			came_from[current.thisX - 1][current.thisY] = current;

		}
	
	/*    //Вправо-вверх
			if ((current.thisY < winWidth && current.thisX > winHeight - 1) && checked[current.thisX - 1][current.thisY + 1] == false) {
				que.push(graph[current.thisX - 1][current.thisY + 1]);
				checked[current.thisX - 1][current.thisY + 1] = true;
				came_from[current.thisX - 1][current.thisY + 1] = current;
			}
			//Вниз вправо
			if ((current.thisY < winWidth && current.thisX < winHeight - 1) && checked[current.thisX + 1][current.thisY + 1] == false) {
				que.push(graph[current.thisX + 1][current.thisY + 1]);
				checked[current.thisX + 1][current.thisY + 1] = true;
				came_from[current.thisX + 1][current.thisY + 1] = current;
			}
			if ((current.thisY > 0 && current.thisX < winHeight - 1) && checked[current.thisX + 1][current.thisY - 1] == false) {
				que.push(graph[current.thisX + 1][current.thisY - 1]);
				checked[current.thisX + 1][current.thisY - 1] = true;
				came_from[current.thisX + 1][current.thisY - 1] = current;
			}

			if ((current.thisY > 0 && current.thisX > 0) && checked[current.thisX - 1][current.thisY - 1] == false) {
				que.push(graph[current.thisX - 1][current.thisY - 1]);
				checked[current.thisX - 1][current.thisY - 1] = true;
				came_from[current.thisX - 1][current.thisY - 1] = current;
			}  */

		
		
		que.pop();
	}

	
	node current = graph[thisX][thisY];

	graph[startX][startY].picture.setFillColor(sf::Color::Magenta);
	while (true) {
		if (current.thisX == startX && current.thisY == startY) break;
		graph[current.thisX][current.thisY].picture.setFillColor(sf::Color::Green);
		current = came_from[current.thisX][current.thisY];
	

	}
	clock_t end = clock();
	LastAlgoExucutionTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
	graph[thisX][thisY].picture.setFillColor(sf::Color::Magenta);

	win.clear();
	Draw(win);
	for (int i = 0; i < winHeight; i++) {
		delete[] checked[i];
	}
	delete[] checked;
	for (int i = 0; i < winHeight; i++) {
		delete[] came_from[i];
	}
	delete[] came_from;

}
void Graph::SearchByCoords(sf::Vector2i endPos, sf::RenderWindow& win, sf::Vector2i start) {
	PaintToNormal();


	for (int i = 0; i < winHeight; i++) {
		for (int j = 0; j < winWidth; j++) {
			if (!graph[i][j].isWall && graph[i][j].picture.getGlobalBounds().contains(endPos.x, endPos.y)) {
			//   SearchWave(graph[i][j].thisX, graph[i][j].thisY, graph[start.x][start.y].thisX, graph[start.x][start.y].thisY, win);
			     (this->*currentAlgoritm)(graph[i][j].thisX, graph[i][j].thisY, graph[start.x][start.y].thisX, graph[start.x][start.y].thisY, win);
			}
		/*	if (!graph[i][j].isWall && graph[i][j].picture.getGlobalBounds().contains(start.x, start.y)) {
				startX = i;
				startY = j;
				if (endX != -1) Search(graph[endX][endY].thisX, graph[endX][endY].thisY, graph[startX][startY].thisX, graph[startX][startY].thisY, win);

			} */
		}
	}
}