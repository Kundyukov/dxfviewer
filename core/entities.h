#pragma once
#include <variant>


struct Point
{
    double x, y;
};

struct Line
{
    Point start;
    Point end;
};

struct Circle
{
    Point center;
    double radius;
};

struct Rectangle
{
    Point position;
    double width, height;
};

struct Polygon
{
    std::vector<Point> vertices;
};

using Entity = std::variant<Line, Circle, Rectangle, Polygon>;

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;