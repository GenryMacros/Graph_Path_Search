#include "Graph.h"

Graph::Graph(unsigned int WinHeight, unsigned int WinWidth, sf::RenderWindow& win, sf::Color col ) {
	srand(static_cast<unsigned int>(time(0)));
	int multiplier = 12;
	winHeight = WinHeight / multiplier;
	winWidth = WinWidth / multiplier;
	graph = new node * [winWidth];
	baseColor = col;
	float curX = 0.5;
	float curY = 0.5;
	float Xstep = 2 * multiplier;
	float Ystep = 2 * multiplier;
	int wallsC = 0;
	int rowWallsC = 0;
	for (int x = 0; x < winWidth; x++) {
		graph[x] = new node[winHeight];
		for (int y = 0; y < winHeight; y++) {
			graph[x][y] = node(12, sf::Vector2f(curX, curY), col,x,y);
			curY += Ystep;
			int wallNum = rand() % 10;
            
			if (wallNum <= 1 && wallsC < wallsCount && rowWallsC<wallsInARow) {
				graph[x][y].isWall = true;
				graph[x][y].picture.setFillColor(sf::Color::Red);
				wallsC++;
				rowWallsC++;
			} 
		}
		rowWallsC = 0;
		curX += Xstep;
		curY = 0.5;
	}
	LiveWallGeneration();
	//GridWallGeneration();
	PaintToNormal();
	currentAlgoritm = &Graph::Search;
}

void Graph::Live(){
	bool** isWalls = new bool* [winHeight];
	for (int i = 0; i < winWidth; i++) {
		isWalls[i] = new bool[winWidth];
	}

	int counter = 0;
	for (int i = 0; i < winHeight; i++) {
		counter = 0;
		for (int j = 0; j < winWidth; j++) {
			if (j + 1 < winWidth - 1 && graph[i][j + 1].isWall) counter++;
			if (j - 1>0 && graph[i][j - 1].isWall) counter++;
			if (i + 1 < winHeight-1 && graph[i + 1][j].isWall)  counter++;
			if (i - 1>0 && graph[i-1][j].isWall)  counter++;
			if (j + 1 < winWidth - 1 && i + 1 < winHeight - 1 && graph[i+1][j + 1].isWall) counter++;
			if (j + 1 < winHeight - 1 && i - 1 > 0 && graph[i - 1][j + 1].isWall)  counter++;
			if (j - 1 > 0 && i + 1 < winHeight - 1 && graph[i+1][j - 1].isWall) counter++;
			if (j - 1 > 0 && i-1>0 && graph[i - 1][j-1].isWall)  counter++;


			if (counter >= 3)isWalls[i][j] = true;
			else isWalls[i][j] = false;
			counter = 0;
		}
    }

	for (int i = 0; i < winHeight; i++) {
		for (int j = 0; j < winWidth; j++) {
			graph[i][j].isWall = isWalls[i][j];
		}
	}

	for (int i = 0; i < winWidth; i++) {
		delete[] isWalls[i];
	}
	delete[] isWalls;
}

void Graph::LiveWallGeneration() {
	Live();
	Live();
	Live();
}

void Graph::GridWallGeneration() {
	int rowCellsCount = 4;
	int columnCellsCount = 8;
	int cellsWidth = (winWidth - 1) / rowCellsCount;
	int cellsHeight = (winHeight - 1) / columnCellsCount;
	int minWidth = 2;
	int minHeight = 3;
	int maxWidth = cellsWidth - minWidth;
	int maxHeight = cellsHeight - minHeight;

	int curX = 0;
	int curY = 0;
	for (int i = 0; i < columnCellsCount; i++) {
		for (int j = 0; j < rowCellsCount; j++) {
			if (!(i == 0 && j == 0)) {
				int isGen = rand() % 2;
				if (isGen == 1) fillCell(cellsWidth, cellsHeight, curX, curY, minWidth, minHeight, maxWidth, maxHeight);
			}
			curX += cellsWidth;
		}
		curX = 0;
		curY += cellsHeight;
	}
}
void Graph::fillCell(int& cellsWidth, int& cellsHeight, int& curX, int& curY, int&  minWidth, int& minHeight, int& maxWidth, int& maxHeight) {
	int roomHeight = rand()% maxHeight + minHeight;
	int roomWidth = rand()% maxWidth + minWidth;

	for (int i = curY; i <= curY + roomHeight; i++) {
		    graph[i][curX].isWall = true;
			graph[i][curX + roomWidth].isWall = true;
		
	}
	if (curX + roomWidth == 2) return;


	int doorCell = rand()% roomWidth+1;
	int doorCellY = rand() % roomHeight +1;
	for (int i = curX+1; i < curX + roomWidth; i++) {
		if(abs(doorCellY + curX) != i) graph[curY][i].isWall = true;
		if(abs(doorCell  + curX) != i) graph[curY+roomHeight][i].isWall = true;
	}

}


/* void Graph::DirectUnits(Unit& un,sf::RenderWindow& win) {
	if (path.getVertexCount() == 0) return;
//	std::cout << un.GetPos().x << std::endl;
	win.clear();
	
	for (int i = path.getVertexCount()-1; i >0 ; i--) {
		if (path[i].position != sf::Vector2f(0, 0)) {
			un.Move(path[i].position);
				path[i] = sf::Vector2f(0, 0);
				break;
		}
		if (i - 1 == 0) {
			path.clear();
		}

	}
	win.draw(un.getSp());
	Draw(win);
	win.display();
	sf::sleep(sf::milliseconds(60));
} */
node::node(float Radius, sf::Vector2f pos, sf::Color col, int x, int y) {
	picture.setRadius(Radius);
	picture.setFillColor(col);
	picture.setPosition(pos);
	thisX = x;
	thisY = y;	
}