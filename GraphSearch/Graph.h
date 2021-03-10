#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime> 
#include <stack>
#include <queue>
#include "List.h"
#include <time.h> 

class node {
public:
	node() = default;
	node(float Radius, sf::Vector2f pos, sf::Color col, int hIndex, int vIndex);
	int thisX;
	int thisY;
	sf::CircleShape picture;
	bool isWall = false;
};
/* class Unit {
public:
	Unit(unsigned int width, unsigned int height, int speed, sf::Vector2f startPos, sf::Color col) {
		im.create(width, height, col);
		tex.loadFromImage(im);
		sp.setTexture(tex);
		Col = col;
		Speed = speed;
	}
	void Move(sf::Vector2f ver) {
		sp.setColor(Col);
	//	sf::Vector2f direction = normalize(ver - sp.getPosition());
		//sp.move(sf::Vector2f(direction.x * Speed, direction.y * Speed));
		sp.setPosition(ver);

	}
	sf::Vector2f GetPos() { return sp.getPosition(); }
	sf::Sprite getSp() { return sp; }
private:
	sf::Vector2f normalize(sf::Vector2f input) {
		float vecLength = pow((pow(input.x, 2) + pow(input.y, 2)), 0.5);
		sf::Vector2f output(input.x / vecLength, input.y / vecLength);
		return output;

	}
	int Speed;
	sf::Image im;
	sf::Texture tex;
	sf::Sprite sp;
	sf::Color Col;
}; */

class Graph {
public:
	Graph() = default;
	Graph(unsigned int WinHeight, unsigned int WinWidth, sf::RenderWindow& win, sf::Color col = sf::Color::Blue);
	void Live();
	void LiveWallGeneration();
	void GridWallGeneration();
	void DestroyWalls();
	void SearchWave(int thisX, int thisY, int startX, int startY, sf::RenderWindow& win);
	void Search(int thisX, int thisY, int startX, int startY, sf::RenderWindow& win);
	void SearchByCoords(sf::Vector2i endPos, sf::RenderWindow& win,sf::Vector2i start);
	void Draw(sf::RenderWindow& win);
	void PaintToNormal();
	void RandomizeWalls(sf::RenderWindow& win);
	void ChangeAlgo();
	sf::Color GetBaseColor() { return baseColor; }
    sf::Color GetWallColor() { return baseWallColor; }
	double GetExecutionTime() { return LastAlgoExucutionTime; }
	int winHeight;
	int winWidth;
	node** graph;
	std::string currentAlgo = "A*";
private:
	void fillCell(int& cellsWidth, int& cellsHeight,int& curX,int& curY, int&  minWidth, int& minHeight, int& maxWidth, int& maxHeight);
	double LastAlgoExucutionTime=0;
	void (Graph::*currentAlgoritm)(int thisX, int thisY, int startX, int startY, sf::RenderWindow& win)=nullptr;
	int wallsCount=350;
	int wallsInARow = 12;
	int unitCurrentX=0;
	int unitCurrentY=0;
	sf::Color baseColor;
	sf::Color baseWallColor=sf::Color::Red;
	sf::VertexArray path;
	
};







