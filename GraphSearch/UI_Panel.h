#pragma once


class UI_Panel {
public:
	UI_Panel() {
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
	};
	UI_Panel(const UI_Panel& copy) = delete;
	void DrawPanel(sf::RenderWindow& win, double exTime,std::string& CurrentAlgo) {
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
	}
	sf::Sprite& GetRebuildSp() {
		return RebuildSp;

	}
	sf::Sprite& GetChangeMethodSp() {
		return ChangeMethodSp;

	}
private:
	sf::Font font;
	sf::Image RebuildIm;
	sf::Texture RebuildTex;
	sf::Sprite RebuildSp;
	sf::Text Rebuildtex;

	sf::Image ElapsedTimeIm;
	sf::Texture ElapsedTimeTex;
	sf::Sprite ElapsedTimeSp;
	sf::Text ElapsedTimeText;

	sf::Image ChangeMethodIm;
	sf::Texture ChangeMethodTex;
	sf::Sprite ChangeMethodSp;
	sf::Text ChangeMethodText;

	sf::Image CurrentMethodIm;
	sf::Texture CurrentMethodTex;
	sf::Sprite  CurrentMethodSp;
	sf::Text  CurrentMethodText;

}UI;