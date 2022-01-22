// Created by Lypoluz (Dominik) on 22.01.2022.

#ifndef ALGOVIZADVENTURE_NODE_HPP
#define ALGOVIZADVENTURE_NODE_HPP

struct Node {
    Node* parent{};
    int x{};
    int y{};
    int state{};
    bool traversable{};
    float gCost{};
    float hCost{};
    float fCost() const {return gCost + hCost;};
    Node() = default;
    Node(int x, int y, bool traversable) : x(x), y(y), traversable(traversable) {}
};

#endif //ALGOVIZADVENTURE_NODE_HPP
