#include <iostream>
#include <android/log.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#define W 1920
#define H 1080
#define elem 60
#define size 15
#define optim

#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_INFO, "Mysfml", __VA_ARGS__))

class Sort
{
	RectangleShape *shapes;
	RenderWindow *wnd;
public:
	Sort(RenderWindow *);
	void ran();
	void bubSort();
	void draw();
	void inserSort();
	void selectSort();
};
int main(int, char **)
{
	LOGE("started");
	srand(time(NULL));
	ContextSettings ctx;
	ctx.antialiasingLevel = 16;
	RenderWindow app(VideoMode(VideoMode::getDesktopMode()), "Sorting algoritm", Style::Default);//, ctx);
	app.setFramerateLimit(60);
	Sort srt(&app);
	while(app.isOpen())
	{
		Event event;
		while(app.pollEvent(event))
		{
			if(event.type == Event::Closed)
				app.close();
			if(event.type == Event::KeyPressed)
				if(event.key.code == Keyboard::Q)
					app.close();
		}
	//	app.clear(Color::White);
		srt.ran();
		srt.draw();
		app.display();

//		app.clear(Color::Black);
		srt.bubSort();
//		srt.inserSort();
		//srt.selectSort();
	}
	return 0;
}

Sort::Sort(RenderWindow * _wnd):
	wnd(_wnd)
{
	shapes = new RectangleShape[elem];
	for(int i=0; i<elem; i++)
	{
		shapes[i].setSize(Vector2f(1000, size));
		shapes[i].setFillColor(Color::Green);
		shapes[i].setPosition(0,i*20);
	}
}
void Sort::draw()
{
	for(int i=0; i<elem; i++)
		wnd->draw(shapes[i]);
}
void Sort::ran()
{
	for(int i=0; i<elem; i++)
	{
		shapes[i].setSize(Vector2f(rand()%1800, size));
	}
}
void Sort::bubSort()
{
#ifdef optim
	bool swap;
#endif
	for(int i=0; i<elem; i++)
	{
#ifdef optim
	swap = 0;
#endif
		for(int j=0; j<elem-i-1;j++)
		{
			if(shapes[j].getSize().x>shapes[j+1].getSize().x)
			{
				float temp = shapes[j].getSize().x;
				shapes[j].setSize(Vector2f(shapes[j+1].getSize().x, size));
				shapes[j+1].setSize(Vector2f(temp, size));
				shapes[j+1].setFillColor(Color::Blue);
				wnd->clear(Color::Black);
				draw();
				wnd->display();
				shapes[j+1].setFillColor(Color::Green);
#ifdef optim
				swap = 1;
#endif
			}
		}
#ifdef optim
		if(!swap)
			break;
#endif
	}
}
void Sort::inserSort()
{
	for(int i=0; i<elem; i++)
	{
		for(int j=i; j>0; j--)
		{
			if(shapes[j].getSize().x<shapes[j+1].getSize().x)
			{
				float temp = shapes[j].getSize().x;
				shapes[j].setSize(Vector2f(shapes[j+1].getSize().x, size));
				shapes[j+1].setSize(Vector2f(temp, size));
				shapes[j+1].setFillColor(Color::Blue);
				wnd->clear(Color::Black);
				draw();
				wnd->display();
				shapes[j+1].setFillColor(Color::Green);

			}
			else
				break;
		}
	}
}
void Sort::selectSort()
{
	int min;
	for(int i=0; i<elem-1; i++)
	{
		min = i;
		for(int j = i+1; j<elem; j++)
		{
			if(shapes[j].getSize().x<shapes[min].getSize().x)
				min = j;
			float temp = shapes[i].getSize().x;
			shapes[i].setSize(Vector2f(shapes[min].getSize().x, size));
			shapes[min].setSize(Vector2f(temp, size));
			shapes[min].setFillColor(Color::Blue);
//			shapes[i].setFillColor(Color::Red);
			wnd->clear(Color::Black);
			draw();
			wnd->display();
			shapes[min].setFillColor(Color::Green);
		}
	}
}
