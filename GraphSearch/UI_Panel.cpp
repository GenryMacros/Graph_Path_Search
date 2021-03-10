/*#include "UI_Panel.h"

UI_Panel::UI_Panel() {
	font.loadFromFile("Font/font.otf");
	RebuildIm.create(170, 50, sf::Color::Blue);
	RebuildTex.loadFromImage(RebuildIm);
	RebuildSp.setTexture(RebuildTex);
	RebuildSp.setPosition(sf::Vector2f(840, 50));
	Rebuildtex.setString("Rebuild walls");
	Rebuildtex.setPosition(sf::Vector2f(RebuildSp.getPosition().x + 10, RebuildSp.getPosition().y + 10));
	Rebuildtex.setFillColor(sf::Color::White);
	Rebuildtex.setFont(font);
	Rebuildtex.setCharacterSize(20);

	ElapsedTimeIm.create(240, 50, sf::Color::Blue);
	ElapsedTimeTex.loadFromImage(ElapsedTimeIm);
	ElapsedTimeSp.setTexture(ElapsedTimeTex);
	ElapsedTimeSp.setPosition(sf::Vector2f(805, 700));
	ElapsedTimeText.setString("Execution time: 0ms");
	ElapsedTimeText.setPosition(sf::Vector2f(ElapsedTimeSp.getPosition().x + 10, ElapsedTimeSp.getPosition().y + 15));
	ElapsedTimeText.setFillColor(sf::Color::White);
	ElapsedTimeText.setFont(font);
	ElapsedTimeText.setCharacterSize(15);

	ChangeMethodIm.create(220, 50, sf::Color::Blue);
	ChangeMethodTex.loadFromImage(ChangeMethodIm);
	ChangeMethodSp.setTexture(ChangeMethodTex);
	ChangeMethodSp.setPosition(sf::Vector2f(810, 200));
	ChangeMethodText.setString("Change algorithm");
	ChangeMethodText.setPosition(sf::Vector2f(ChangeMethodSp.getPosition().x + 15, ChangeMethodSp.getPosition().y + 15));
	ChangeMethodText.setFillColor(sf::Color::White);
	ChangeMethodText.setFont(font);
	ChangeMethodText.setCharacterSize(20);


	CurrentMethodIm.create(220, 50, sf::Color::Blue);
	CurrentMethodTex.loadFromImage(CurrentMethodIm);
	CurrentMethodSp.setTexture(CurrentMethodTex);
	CurrentMethodSp.setPosition(sf::Vector2f(810, 255));
	CurrentMethodText.setString("Current:" + std::string("A*"));
	CurrentMethodText.setPosition(sf::Vector2f(CurrentMethodSp.getPosition().x + 5, CurrentMethodSp.getPosition().y + 15));
	CurrentMethodText.setFillColor(sf::Color::White);
	CurrentMethodText.setFont(font);
	CurrentMethodText.setCharacterSize(20);
}

void UI_Panel::DrawPanel(sf::RenderWindow& win, double exTime, std::string& CurrentAlgo) {
	win.draw(RebuildSp);
	win.draw(Rebuildtex);
	ElapsedTimeText.setString("Execution time: " + std::to_string(exTime) + "ms");
	win.draw(ElapsedTimeSp);
	win.draw(ElapsedTimeText);

	win.draw(ChangeMethodSp);
	win.draw(ChangeMethodText);

	CurrentMethodText.setString("Current:" + CurrentAlgo);
	win.draw(CurrentMethodSp);
	win.draw(CurrentMethodText);
}  */