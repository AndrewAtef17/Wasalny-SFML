#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>
#include"Wasalny.h"
#include <windows.h>
#include<fstream>
#include<set>
using namespace std;
using namespace sf;


void drawName(RenderWindow& window);
void drawMain(RenderWindow& window);
void custome(RenderWindow& window);
void admin(RenderWindow& window);
void write(RenderWindow& window, string, int, int, int, sf::Color);
void drawBox(RenderWindow& window, int, int, int, int, sf::Color);
void drawCircle(RenderWindow& window, int, int, int, sf::Color);
void drawline(RenderWindow& window, int, int, int, int, sf::Color);
void drawGraph(RenderWindow& window);

map<int, sf::Vector2f> m;
int cnt = 0, c = 0, adminn = 0;
sf::Event evnt;
int choice = 0, circle = 0, circle2 = 0, circle3 = 0, choice2 = 0, choice3 = 0;
bool one = true, two = false, three = true;
sf::Font font;
extern bool isFound;
extern int choosen, bb, ssss, ssss2, ssss3, number_of_nodes;
extern string currpost, dist;
extern bool Once;

Driver d;
customer C;
Dijkstra ds;

int main()
{
	RenderWindow Wasalny(VideoMode(1000, 462), "Wasalny", /*Style::Fullscreen|*/  Style::Close);




	while (Wasalny.isOpen())
	{
		while (Wasalny.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				Wasalny.close();
			else if (evnt.type == evnt.KeyPressed)
			{
				if (evnt.key.code == sf::Keyboard::Escape)
					Wasalny.close();
				//press enter in main page
				else if (cnt == 1 && evnt.key.code == sf::Keyboard::Return)
				{
					c = 1;
					three = true;
				}
				//pressed right in admin page
				else if (cnt == 3 && evnt.key.code == sf::Keyboard::Right)
				{
					adminn = (adminn + 1) % 5;
				}
				//pressed left in admin page
				else if (cnt == 3 && evnt.key.code == sf::Keyboard::Left)
				{
					if (adminn == 0)
						adminn = 5;
					adminn = (adminn - 1) % 5;
				}
				else if (cnt == 4 && evnt.key.code == sf::Keyboard::Right)
				{
					if (choice3 == 0)
						choice3 = 2;
					choice3 = (choice3 - 1) % 2;
				}
				else if (cnt == 4 && evnt.key.code == sf::Keyboard::Left)
				{
					if (choice3 == 0)
						choice3 = 2;
					choice3 = (choice3 - 1) % 2;
				}
				else if (cnt == 4 && choice3 == 1 && evnt.key.code == sf::Keyboard::Return)
				{
					cnt = 6;
					Wasalny.setVisible(false);
					C.orderTrip(d);
					//system("CLS");
					Wasalny.setVisible(true);
				}
				else if (cnt == 4 && choice3 == 0 && evnt.key.code == sf::Keyboard::Return)
				{
					cnt = 5;
				}
				else if (cnt == 3 && evnt.key.code == sf::Keyboard::B)
				{
					cnt = 1;
				}
				else if ((cnt == 5 || cnt == 6) && evnt.key.code == sf::Keyboard::B)
				{
					cnt = 4;
				}
				else if (cnt == 4 && choice3 == 0 && evnt.key.code == sf::Keyboard::Return)
				{
					cnt = 5;
				}
				else if (cnt == 4 && evnt.key.code == sf::Keyboard::B)
				{
					cnt = 1;
				}
				//pressed A in main page
				else if (cnt == 1 && (evnt.key.code == sf::Keyboard::A))
				{
					cnt = 3;
				}
				//pressed right in main page
				else if (cnt == 1 && evnt.key.code == sf::Keyboard::Right)
				{
					choice2 = (choice2 + 1) % 2;
				}
				//pressed left in main page
				else if (cnt == 1 && evnt.key.code == sf::Keyboard::Left)
				{
					choice2 = (choice2 - 1) % 2;
				}
				//pressed right in login/register page
				else if (cnt == 2 && evnt.key.code == sf::Keyboard::Right)
				{
					choice = (choice + 1) % 2;

				}
				//pressed left in login/register page
				else if (cnt == 2 && evnt.key.code == sf::Keyboard::Left)
				{
					choice = (choice - 1) % 2;
				}
				else if ((cnt == 3 || cnt == 2) && evnt.key.code == sf::Keyboard::B)
				{
					cnt = 1;
					c = 0;
				}
				//pressed enter in login/register page
				else if (cnt == 2 && evnt.key.code == sf::Keyboard::Return)
				{
					Wasalny.setVisible(false);
					if (choice2 == 0 && choice == 0)
					{
						d.registerFn();
						Wasalny.setVisible(true);
						system("CLS");
					}
					else if (choice2 == 0 && choice == 1)
					{
						system("CLS");
						d.login(C);
						if (choice3 == 1)
						{
							cnt = 6;
							c = 0;
						}
						Wasalny.setVisible(true);
						system("CLS");
					}
					else if (choice2 == 1 && choice == 1)
					{
						C.login();
						cnt = 4;
						c = 0;
						Wasalny.setVisible(true);
						system("CLS");
					}
					else if (choice2 == 1 && choice == 0)
					{
						C.registerf();
						Wasalny.setVisible(true);
						system("CLS");
					}
				}
				//press enter in admin page
				else if (cnt == 3 && evnt.key.code == sf::Keyboard::Return)
				{
					Wasalny.setVisible(false);
					if (adminn == 0)
					{
						ds.AddNode();
						Wasalny.setVisible(true);
						system("CLS");
					}
					else if (adminn == 1)
					{
						ds.deleteNode();
						Wasalny.setVisible(true);
						system("CLS");
					}
					else if (adminn == 2)
					{
						ds.deleteGragh();
						Wasalny.setVisible(true);
						system("CLS");
					}
					else if (adminn == 3)
					{
						d.display();
						Wasalny.setVisible(true);
						system("CLS");
					}
					else if (adminn == 4)
					{
						C.display();
						Wasalny.setVisible(true);
						system("CLS");
					}
				}
			}
		}
		font.loadFromFile("lala.ttf");
		if (c == 1)
		{
			cnt = 2;
			drawMain(Wasalny);
			Wasalny.display();
			//three = false;
		}
		else if (cnt == 0 || cnt == 1)
		{
			cnt = 1;
			drawName(Wasalny);
			Wasalny.display();
			one = false;
			three = false;
		}
		else if (cnt == 3)
		{
			admin(Wasalny);
			Wasalny.display();
		}
		else if (cnt == 4)
		{
			custome(Wasalny);
			Wasalny.display();
		}
		else if (cnt == 6 || cnt == 5)
		{
			drawGraph(Wasalny);
			Wasalny.display();
		}
	}
	system("pause");
	return 0;
}

//write text
void write(RenderWindow& window, string t, int s, int x, int y, sf::Color c)
{
	sf::Text name;
	name.setFont(font);
	name.setString(t);
	name.setCharacterSize(s);
	name.setFillColor(c);
	name.setStyle(sf::Text::Bold);
	name.setPosition(x, y);
	if (s == 20)
		name.setStyle(Text::Italic);
	window.draw(name);
}
//draw box
void drawBox(RenderWindow& window, int l, int w, int x, int y, sf::Color c)
{
	sf::RectangleShape box(sf::Vector2f(l, w));
	box.setPosition(x, y);
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineThickness(5);
	box.setOutlineColor(c);
	window.draw(box);
}
//draw first page
void drawName(RenderWindow& window)
{
	string text = "nasr.png";
	sf::Texture nasr;
	nasr.loadFromFile(text);
	sf::Sprite sprite;
	sprite.setTexture(nasr);
	sprite.setPosition(0, 0);
	//sprite.setOrigin(12, 16);
	window.draw(sprite);

	sf::RectangleShape box(sf::Vector2f(210, 50));
	box.setPosition(80, 340);
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineThickness(5);

	sf::RectangleShape boxx(sf::Vector2f(280, 50));
	boxx.setPosition(630, 340);
	boxx.setFillColor(sf::Color::Transparent);
	boxx.setOutlineThickness(5);



	sf::Text name;
	name.setFont(font);
	name.setString("WASALNY");
	name.setCharacterSize(100);
	name.setFillColor(sf::Color::Black);
	name.setStyle(sf::Text::Bold);
	name.setPosition(270, 5);
	window.draw(name);

	font.loadFromFile("lala.ttf");
	sf::Text exit;
	exit.setFont(font);
	exit.setString("Press ESC to exit");
	exit.setCharacterSize(20);
	exit.setFillColor(sf::Color::Black);
	exit.setStyle(sf::Text::Italic);
	exit.setPosition(785, 415);
	window.draw(exit);

	font.loadFromFile("lala.ttf");
	sf::Text Register, login;
	Register.setFont(font);
	Register.setString("Driver");
	if (choice2 == 0) {
		Register.setFillColor(sf::Color::Blue);
		box.setOutlineColor(Color::Blue);
		login.setFillColor(sf::Color::Black);
		boxx.setOutlineColor(sf::Color::Transparent);
	}
	else {
		Register.setFillColor(sf::Color::Black);
		box.setOutlineColor(Color::Transparent);
		login.setFillColor(sf::Color::Blue);
		boxx.setOutlineColor(sf::Color::Blue);
	}
	Register.setCharacterSize(50);
	Register.setStyle(sf::Text::Bold);
	Register.setPosition(100, 325);
	window.draw(box);
	window.draw(Register);


	login.setFont(font);
	login.setString("Customer");
	login.setCharacterSize(50);
	login.setStyle(sf::Text::Bold);
	login.setPosition(650, 325);
	window.draw(boxx);
	window.draw(login);

}
//draw login/register page
void drawMain(RenderWindow& window)
{
	string text = "nasr.png";
	sf::Texture nasr;
	nasr.loadFromFile(text);
	sf::Sprite sprite;
	sprite.setTexture(nasr);
	sprite.setPosition(0, 0);
	//sprite.setOrigin(12, 16);
	window.draw(sprite);

	sf::RectangleShape box(sf::Vector2f(255, 50));
	box.setPosition(80, 340);
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineThickness(5);

	sf::RectangleShape boxx(sf::Vector2f(170, 50));
	boxx.setPosition(680, 340);
	boxx.setFillColor(sf::Color::Transparent);
	boxx.setOutlineThickness(5);

	if (choice2 == 0)
		write(window, "WELCOME Driver", 50, 295, 125, sf::Color::Black);
	else
		write(window, "WELCOME Customer", 50, 265, 125, sf::Color::Black);


	font.loadFromFile("lala.ttf");
	sf::Text name;
	name.setFont(font);
	name.setString("WASALNY");
	name.setCharacterSize(100);
	name.setFillColor(sf::Color::Black);
	name.setStyle(sf::Text::Bold);
	name.setPosition(270, 5);
	window.draw(name);

	font.loadFromFile("lala.ttf");
	sf::Text Register, login;
	Register.setFont(font);
	Register.setString("REGISTER");
	if (choice == 0) {
		Register.setFillColor(sf::Color::Blue);
		box.setOutlineColor(Color::Blue);
		login.setFillColor(sf::Color::Black);
		boxx.setOutlineColor(sf::Color::Transparent);
	}
	else {
		Register.setFillColor(sf::Color::Black);
		box.setOutlineColor(Color::Transparent);
		login.setFillColor(sf::Color::Blue);
		boxx.setOutlineColor(sf::Color::Blue);
	}
	Register.setCharacterSize(50);
	Register.setStyle(sf::Text::Bold);
	Register.setPosition(100, 325);
	window.draw(box);
	window.draw(Register);

	write(window, "press b to back", 20, 785, 415, sf::Color::Black);

	login.setFont(font);
	login.setString("LOGIN");
	login.setCharacterSize(50);
	login.setStyle(sf::Text::Bold);
	login.setPosition(700, 325);
	window.draw(boxx);
	window.draw(login);
}
//draw admin page
void admin(RenderWindow& window) {
	window.clear();

	string text = "nasr.png";
	sf::Texture nasr;
	nasr.loadFromFile(text);
	sf::Sprite sprite;
	sprite.setTexture(nasr);
	sprite.setPosition(0, 0);
	//sprite.setOrigin(12, 16);
	window.draw(sprite);

	write(window, "press b to back", 20, 785, 415, sf::Color::Black);


	font.loadFromFile("lala.ttf");
	write(window, "Wasalny", 100, 270, 5, sf::Color::Black);

	write(window, "WELCOME ADMIN", 50, 295, 125, sf::Color::Black);

	drawBox(window, 160, 50, 45, 240, sf::Color::Black);
	write(window, "ADD NODE", 30, 50, 240, sf::Color::Black);

	drawBox(window, 220, 50, 45, 326, sf::Color::Black);
	write(window, "delete node", 30, 55, 325, sf::Color::Black);

	drawBox(window, 250, 50, 335, 326, sf::Color::Black);
	write(window, "DElete Graph", 30, 350, 325, sf::Color::Black);

	drawBox(window, 300, 50, 635, 240, sf::Color::Black);
	write(window, "Show Customers", 30, 650, 240, sf::Color::Black);

	drawBox(window, 250, 50, 635, 326, sf::Color::Black);
	write(window, "show drivers", 30, 650, 325, sf::Color::Black);

	write(window, "press b to back", 20, 785, 415, sf::Color::Black);

	if (adminn == 0)
	{
		drawBox(window, 160, 50, 45, 240, sf::Color::Blue);
		write(window, "ADD NODE", 30, 50, 240, sf::Color::Blue);
	}
	else if (adminn == 1)
	{
		drawBox(window, 220, 50, 45, 326, sf::Color::Blue);
		write(window, "delete node", 30, 55, 325, sf::Color::Blue);
	}
	else if (adminn == 2)
	{
		drawBox(window, 250, 50, 335, 326, sf::Color::Blue);
		write(window, "DElete Graph", 30, 350, 325, sf::Color::Blue);
	}
	else if (adminn == 4)
	{
		drawBox(window, 300, 50, 635, 240, sf::Color::Blue);
		write(window, "Show Customers", 30, 650, 240, sf::Color::Blue);
	}
	else if (adminn == 3)
	{
		drawBox(window, 250, 50, 635, 326, sf::Color::Blue);
		write(window, "show drivers", 30, 650, 325, sf::Color::Blue);
	}
}
void custome(RenderWindow& window)
{
	string text = "nasr.png";
	sf::Texture nasr;
	nasr.loadFromFile(text);
	sf::Sprite sprite;
	sprite.setTexture(nasr);
	sprite.setPosition(0, 0);
	//sprite.setOrigin(12, 16);
	window.draw(sprite);

	write(window, "press b to back", 20, 785, 415, sf::Color::Black);


	font.loadFromFile("lala.ttf");
	write(window, "Wasalny", 100, 270, 5, sf::Color::Black);

	drawBox(window, 390, 50, 80, 340, sf::Color::Black);
	write(window, "Display graph", 50, 100, 325, sf::Color::Black);

	drawBox(window, 310, 50, 650, 340, sf::Color::Black);
	write(window, "order trip", 50, 670, 325, sf::Color::Black);

	if (choice3 == 0)
	{
		drawBox(window, 390, 50, 80, 340, sf::Color::Blue);
		write(window, "Display graph", 50, 100, 325, sf::Color::Blue);
	}
	else if (choice3 == 1)
	{
		drawBox(window, 310, 50, 650, 340, sf::Color::Blue);
		write(window, "order trip", 50, 670, 325, sf::Color::Blue);
	}
}
void drawCircle(RenderWindow& window, int s, int x, int y, sf::Color c)
{
	x -= s;
	y -= s;
	sf::CircleShape a(s);
	a.setFillColor(c);
	a.setPosition(x, y);
	window.draw(a);
}
void drawline(RenderWindow& window, int x, int y, int x2, int y2, sf::Color c)
{
	int thickness = 5;

	sf::Vector2f point1(x, y), point2(x2, y2);
	sf::Vector2f direction = point2 - point1;
	sf::Vector2f unitDirection = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

	sf::Vector2f offset = (thickness / 2.f) * unitPerpendicular;

	sf::Vertex vertices[4];
	vertices[0].position = point1 + offset;
	vertices[1].position = point2 + offset;
	vertices[2].position = point2 - offset;
	vertices[3].position = point1 - offset;

	for (int i = 0; i < 4; ++i)
		vertices[i].color = c;

	window.draw(vertices, 4, sf::Quads);
}
void drawGraph(RenderWindow& window)
{
	m[0] = sf::Vector2f(90, 140);
	m[1] = sf::Vector2f(90, 400);
	m[2] = sf::Vector2f(190, 270);
	m[3] = sf::Vector2f(340, 190);
	m[4] = sf::Vector2f(340, 290);
	m[5] = sf::Vector2f(340, 390);
	m[6] = sf::Vector2f(490, 190);
	m[7] = sf::Vector2f(490, 290);
	m[8] = sf::Vector2f(490, 390);
	m[9] = sf::Vector2f(640, 190);
	m[10] = sf::Vector2f(640, 290);
	m[11] = sf::Vector2f(640, 390);
	m[12] = sf::Vector2f(840, 140);
	m[13] = sf::Vector2f(890, 270);
	m[14] = sf::Vector2f(840, 400);


	window.clear();
	string text = "nasr.png";
	sf::Texture nasr;
	nasr.loadFromFile(text);
	sf::Sprite sprite;
	sprite.setTexture(nasr);
	sprite.setPosition(0, 0);
	//sprite.setOrigin(12, 16);
	window.draw(sprite);

	write(window, "WASALNY MAP", 50, 300, 5, Color::Black);

	drawline(window, m[0].x, m[0].y, m[2].x, m[2].y, Color::Black);
	drawline(window, m[0].x, m[0].y, m[12].x, m[12].y, Color::Black);
	drawline(window, m[2].x, m[2].y, m[1].x, m[1].y, Color::Black);
	drawline(window, m[2].x, m[2].y, m[3].x, m[3].y, Color::Black);
	drawline(window, m[1].x, m[1].y, m[5].x, m[5].y, Color::Black);
	drawline(window, m[3].x, m[3].y, m[4].x, m[4].y, Color::Black);
	drawline(window, m[4].x, m[4].y, m[5].x, m[5].y, Color::Black);
	drawline(window, m[3].x, m[3].y, m[6].x, m[6].y, Color::Black);
	drawline(window, m[4].x, m[4].y, m[7].x, m[7].y, Color::Black);
	drawline(window, m[5].x, m[5].y, m[8].x, m[8].y, Color::Black);
	drawline(window, m[6].x, m[6].y, m[7].x, m[7].y, Color::Black);
	drawline(window, m[7].x, m[7].y, m[8].x, m[8].y, Color::Black);
	drawline(window, m[6].x, m[6].y, m[9].x, m[9].y, Color::Black);
	drawline(window, m[7].x, m[7].y, m[10].x, m[10].y, Color::Black);
	drawline(window, m[8].x, m[8].y, m[11].x, m[11].y, Color::Black);
	drawline(window, m[9].x, m[9].y, m[10].x, m[10].y, Color::Black);
	drawline(window, m[11].x, m[11].y, m[10].x, m[10].y, Color::Black);
	drawline(window, m[12].x, m[12].y, m[9].x, m[9].y, Color::Black);
	drawline(window, m[12].x, m[12].y, m[13].x, m[13].y, Color::Black);
	drawline(window, m[13].x, m[13].y, m[14].x, m[14].y, Color::Black);
	drawline(window, m[11].x, m[11].y, m[14].x, m[14].y, Color::Black);
	drawline(window, m[10].x, m[10].y, m[13].x, m[13].y, Color::Black);

	drawCircle(window, 40, m[0].x, m[0].y, Color::Yellow);
	write(window, "  Al\nAsher", 20, 56, 110, Color::Black);

	drawCircle(window, 40, m[1].x, m[1].y, Color::Yellow);
	write(window, "  Al\n Ahly", 20, 56, 370, Color::Black);

	drawCircle(window, 40, m[2].x, m[2].y, Color::Yellow);
	write(window, "  Al\nTamen", 20, 156, 240, Color::Black);


	drawCircle(window, 40, m[12].x, m[12].y, Color::Yellow);
	write(window, "  Al\nsabe3", 20, 806, 110, Color::Black);

	drawCircle(window, 40, m[13].x, m[13].y, Color::Yellow);
	write(window, "  Al\nTairan", 20, 856, 240, Color::Black);

	drawCircle(window, 40, m[14].x, m[14].y, Color::Yellow);
	write(window, "  Al\nsades", 20, 806, 370, Color::Black);


	drawCircle(window, 40, m[4].x, m[4].y, Color::Yellow);
	write(window, "  fakhry", 20, 284, 272, Color::Black);

	drawCircle(window, 40, m[7].x, m[7].y, Color::Yellow);
	write(window, "  makram", 20, 434, 272, Color::Black);

	drawCircle(window, 40, m[10].x, m[10].y, Color::Yellow);
	write(window, "  Abbas", 20, 592, 272, Color::Black);


	drawCircle(window, 40, m[3].x, m[3].y, Color::Yellow);
	write(window, "  a5r\nfakhry", 20, 306, 160, Color::Black);

	drawCircle(window, 40, m[6].x, m[6].y, Color::Yellow);
	write(window, "  a5r\nmakram", 20, 456, 160, Color::Black);

	drawCircle(window, 40, m[9].x, m[9].y, Color::Yellow);
	write(window, "  a5r\nabbas", 20, 606, 160, Color::Black);


	drawCircle(window, 40, m[5].x, m[5].y, Color::Yellow);
	write(window, " awel\nfakhry", 20, 306, 360, Color::Black);

	drawCircle(window, 40, m[8].x, m[8].y, Color::Yellow);
	write(window, " awel\nmakram", 20, 456, 360, Color::Black);

	drawCircle(window, 40, m[11].x, m[11].y, Color::Yellow);
	write(window, " awel\nAbbas", 20, 606, 360, Color::Black);

	if (isFound) {
		vector<int> v, v2;
		ssss = d.distinationNumber[d.V[choosen].curr_Destination];
		ds.shortestpathFrom(ssss);
		ssss2 = d.distinationNumber[currpost];
		ds.printpath(ssss, ssss2, v);

		char msg[1000];
		sprintf_s(msg, "driver away: %d km\ndriver arrives in : %d min", ds.Distance[ssss2], ds.Distance[ssss2] * 3);
		write(window, msg, 20, 20, 5, Color::Black);

		for (int i = 0; i < v.size(); i++)
		{
			drawCircle(window, 45, m[v[i]].x, m[v[i]].y, Color::Blue);
			if (i != 0)
				drawline(window, m[v[i - 1]].x, m[v[i - 1]].y, m[v[i]].x, m[v[i]].y, Color::Blue);
			//sleep(sf::milliseconds(2000));

		}
		/*window.display();
		sleep(sf::milliseconds(1000));*/
		ds.shortestpathFrom(ssss2);
		ssss3 = d.distinationNumber[dist];
		ds.printpath(ssss2, ssss3, v2);
		for (int i = 0; i < v2.size(); i++)
		{
			drawCircle(window, 40, m[v2[i]].x, m[v2[i]].y, Color::Red);
			if (i != 0)
				drawline(window, m[v2[i - 1]].x, m[v2[i - 1]].y, m[v2[i]].x, m[v2[i]].y, Color::Red);
			//sleep(sf::milliseconds(2000));
			//window.display();
		}
		//window.display();
		//sleep(sf::milliseconds(1000));

		sprintf_s(msg, "distance: %d km\nExpected time: %d min\nFees: %d Le", ds.Distance[ssss3], ds.Distance[ssss3] * 3, ds.Distance[ssss3] * 3 + 15);
		write(window, msg, 20, 700, 5, Color::Black);
	}
	else if (cnt == 6)
		write(window, "Sorry, There are no drivers\ngoing to this \ndestination currently.\n", 20, 670, 5, Color::Black);

	sf::Text exit;
	exit.setFont(font);
	exit.setString("Press b to back");
	exit.setCharacterSize(20);
	exit.setFillColor(sf::Color::Black);
	exit.setStyle(sf::Text::Italic);
	exit.setPosition(785, 426);
	window.draw(exit);

	write(window, "  Al\nAsher", 20, 56, 110, Color::Black);

	write(window, "  Al\n Ahly", 20, 56, 370, Color::Black);

	write(window, "  Al\nTamen", 20, 156, 240, Color::Black);


	write(window, "  Al\nsabe3", 20, 806, 110, Color::Black);

	write(window, "  Al\nTairan", 20, 856, 240, Color::Black);

	write(window, "  Al\nsades", 20, 806, 370, Color::Black);


	write(window, "  fakhry", 20, 284, 272, Color::Black);

	write(window, "  makram", 20, 434, 272, Color::Black);

	write(window, "  Abbas", 20, 592, 272, Color::Black);


	write(window, "  a5r\nfakhry", 20, 306, 160, Color::Black);

	write(window, "  a5r\nmakram", 20, 456, 160, Color::Black);

	write(window, "  a5r\nabbas", 20, 606, 160, Color::Black);


	write(window, " awel\nfakhry", 20, 306, 360, Color::Black);

	write(window, " awel\nmakram", 20, 456, 360, Color::Black);

	write(window, " awel\nAbbas", 20, 606, 360, Color::Black);
}

