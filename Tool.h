//π§æﬂ¿‡
#pragma once

class Tool
{
public:

	void gotoXY(int x, int y);
	void setXY(int x, int y);

	void wait(int seconds);
	void clear(int x, int y, int w, int h);
	void clearLine(int x, int y);

	void printMessage(const char* str);
	void printMessage_Quick(const char* str);
	void setPrintColor(int color);
	void setPrintColor_FrontBack(int foreground, int background);
	void FullScreen();
	void FullScreen_Quick();

	void sidejudge(int& x1, int& y1);
	void viewme(int x0, int y0, int x1, int y1);

	int generateRandomNumber(int num);
};

