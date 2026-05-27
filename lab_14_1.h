#pragma once

using namespace System::Drawing;

class Rect
{
private:
    int x;
    int y;
    int width;
    int height;

public:
    Rect(int _x, int _y, int _w, int _h)
    {
        x = _x;
        y = _y;
        width = _w;
        height = _h;
    }

    void Draw(Graphics^ g)
    {
        Pen^ pen = gcnew Pen(Color::Red, 2);

        g->DrawRectangle(
            pen,
            x,
            y,
            width,
            height
        );
    }
};