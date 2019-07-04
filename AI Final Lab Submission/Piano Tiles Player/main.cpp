#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;

void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    horizontal = desktop.right;
    vertical = desktop.bottom;
}

#define left_click() mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0)

int main()
{
    int X, Y;
    Sleep(5000);
    int x[5], y[5];
    for(int i=0; i<5; i++)
    {
        Sleep(2*1000);
        POINT p;
        if (GetCursorPos(&p))
        {
            x[i] = p.x;
            y[i] = p.y;
        }
        cout << x[i] << " " << y[i] << endl;
    }
    SetCursorPos(x[4],y[4]);
    HDC dc = GetDC(NULL);
    while(true)
    {
        for(int i=0; i<4; i++)
        {
            X=x[i], Y=y[i];
            COLORREF color = GetPixel(dc, X, Y);
            int _red = GetRValue(color);
            int _green = GetGValue(color);
            int _blue = GetBValue(color);
            int _brightness = 0.299*_red + 0.587*_green + 0.114*_blue;
            if(_brightness < 10)
            {
                SetCursorPos(x[i],y[i]);
                left_click();
                SetCursorPos(x[4],y[4]);
            }
        }
    }
    ReleaseDC(NULL, dc);
    return 0;
}
