// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_ALGOWRAPPER_HPP
#define ALGOVIZADVENTURE_ALGOWRAPPER_HPP


#include <string>
#include <algoviz/SVG.hpp>
#include "Vector2.hpp"

class AlgoWrapper {
    void clear() {AlgoViz::clear();}

    // wrapper for SVG
    class Window {
        SVG svg;
    public:
        Window(int width, int height, int gWidth, int gHeight, std::string title="Algoviz Adventure") {
            svg = SVG(width, height, gWidth, gHeight, title);
        }
        Window(int width, int height, std::string title="Algoviz Adventure") {
            svg = SVG(width, height, title);
        }

        int getWidth() { return svg.getWidth();}
        int getHeight() { return svg.getHeight();}
        void setViewBox(int x, int y, int w, int h, std::string aspect="") {svg.setViewBox(x,y,w,h,aspect);}

        void clear() {svg.clear();}
        void setColor(std::string color="black") {svg.setColor(color);}
        void setColor(int red, int green, int blue, float alpha=1.0) {svg.setColor(red,green,blue,alpha);}
        void setFill(std::string color) {svg.setFill(color);}
        void setFill(int red, int green, int blue, float alpha=1.0) {svg.setFill(red,green,blue,alpha);}
        void setLineWidth(int width=1) {svg.setLineWidth(width);}
        void setTransform(std::string transform) {svg.setTransform(transform);}
        void drawLine(int x1, int y1, int x2, int y2) {svg.drawLine(x1,y1,x2,y2);}
        void drawLine(Vector2 pos1, Vector2 pos2) { drawLine(pos1.x(), pos1.y(), pos2.x(), pos2.y());}
        void drawCircle(int cx, int cy, int r) {svg.drawCircle(cx,cy,r);}
        void drawCircle(Vector2 pos, int r) { drawCircle(pos.x(), pos.y(), r);}
        void drawRect(int x, int y, int width, int height, int rx=0, int ry=0) {svg.drawRect(x,y,width,height,rx,ry);}
        void drawRect(Vector2 pos, Vector2 dim, Vector2 r) { drawRect(pos.x(), pos.y(), dim.x(), dim.y(), r.x(), r.y());}
        void drawEllipse(int cx, int cy, int rx, int ry) {svg.drawEllipse(cx,cy,rx,ry);}
        void drawEllipse(Vector2 pos, Vector2 r) { drawEllipse(pos.x(), pos.y(), r.x(), r.y());}
        void drawPath(const std::string& d) {svg.drawPath(d);}
        void drawText(const std::string& text, int x, int y, int fontSize=16, const std::string& fontFamily="sans-serif") {svg.drawText(text,x,y,fontSize,fontFamily);}
        void drawText(const std::string& text, Vector2 pos, int fontSize=16, const std::string& fontFamily="sans-serif") {drawText(text,pos.x(),pos.y(),fontSize,fontFamily);}
        void drawImage(const std::string& href, int x, int y, int width, int height) {svg.drawImage(href,x,y,width,height);}
        void drawImage(const std::string& href, Vector2 pos, Vector2 dim) { drawImage(href, pos.x(), pos.y(), dim.x(), dim.y());}
    };

    /* wrapper for SVGElement
     class WindowElement {
     protected:
         SVGElement& el;
     public:
         int getId() {return el.getId();}
         virtual int getX() {return el.getX();}
         virtual int getY() {return el.getY();}
    };*/

    // wrapper for Image
    class Sprite {
        Image image;
    public:
        Sprite(const std::string path, int x, int y, int w, int h, Window* window) {image = Image(path, x, y, w, h, window);}
        Sprite(const std::string path, Vector2 pos, Vector2 dim, Window* window) {Sprite(path, pos.x(), pos.y(), dim.x(), dim.y(), window);}
        Sprite(const Sprite& sprite) {image = Image(sprite);}

        void moveTo(int x, int y) {image.moveTo(x, y);}
        void moveTo(Vector2 pos) { moveTo(pos.x(), pos.y());}
        void rotateTo(int alpha) {image.rotateTo(alpha);}
        void setSize(int w, int h) {image.setSize(w, h);}
        void setSize(Vector2 dim) { setSize(dim.x(), dim.y());}
    };

};


#endif //ALGOVIZADVENTURE_ALGOWRAPPER_HPP
