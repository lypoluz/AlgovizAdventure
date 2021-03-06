// Created by Lypoluz (Dominik) on 22.01.2022.

#ifndef ALGOVIZADVENTURE_PATHFINDER_HPP
#define ALGOVIZADVENTURE_PATHFINDER_HPP

#include "../Vector2.hpp"
#include "Node.hpp"
#include "../Logger.hpp"
#include <algorithm>
#include <vector>

class PathFinder {

    bool obstacleArray[30][30]{};
    Vector2 startPos;
    Vector2 endPos;
    Node nodeMatrix[30][30];
    bool pathFound{};
    Node* startNode{};
    Node* endNode{};


    void resetNodeMatrix() {
        for (auto & rows : nodeMatrix)
            for (auto & cell : rows)
                cell = Node();
    };

    bool hasOpen() {
        for (auto & rows : nodeMatrix)
            for (auto & cell : rows)
                if(cell.state == 1)
                    return true;
        return false;
    }

    Node* firstNodeWithState1() {
        for (auto & rows : nodeMatrix)
            for (auto & node : rows)
                if(node.state == 1)
                    return &node;
        return nullptr;
    }

public:
    PathFinder(bool obstacleArray[30][30], const Vector2 &startPos, const Vector2 &endPos) : startPos(startPos), endPos(endPos) {
        for (int x = 0; x < 30; ++x)
            for (int y = 0; y < 30; ++y)
                this->obstacleArray[x][y] = obstacleArray[x][y];
    }

    bool hasPath() const {return pathFound;}

    void calculatePath() {
        pathFound = false;
        resetNodeMatrix();

        for (int x = 0; x < 30; ++x) {
            for (int y = 0; y < 30; ++y) {
                Node n(x, y, !obstacleArray[x][y]);
                nodeMatrix[x][y] = n;
                Vector2 pos(x,y);
                if ((pos-startPos).magnitude() < .5) {startNode = &nodeMatrix[x][y];}
                if ((pos-endPos).magnitude() < .5) {endNode = &nodeMatrix[x][y];}
            }
        }
        nodeMatrix[startNode->x][startNode->y].state = 1;

        while (hasOpen()) {
            Node* current = firstNodeWithState1();
            if(current == nullptr) break;
            for(int x=0; x < 30; ++x) {
                for (int y = 0; y < 30; ++y) {
                    if(nodeMatrix[x][y].state == 1) {
                        if (nodeMatrix[x][y].fCost() < current->fCost()) {
                            current = &nodeMatrix[x][y];
                        }
                    }
                }
            }

            current->state = -1;

            if (current == endNode) {
                pathFound = true;
                break;
            }

            std::vector<Node*> neighbours;
            for(auto x : {-1, 0, 1}) {
                for (auto y : {-1, 0, 1}) {
                    if (std::abs(x) + std::abs(y) != 1) continue;
                    if(current->x+x < 0 or current->x+x >= 30 or
                       current->y+y < 0 or current->y+y >= 30) continue;
                    neighbours.push_back(&nodeMatrix[current->x+x][current->y+y]);
                }
            }

            for (Node* n : neighbours) {
                if(not n->traversable) continue;
                if(n->state == -1) continue;
                float newGCost = current->gCost + (Vector2(current->x, current->y)-Vector2(n->x, n->y)).magnitude();
                if (!(newGCost < n->gCost or n->state != 1)) continue;
                n->gCost = newGCost;
                n->hCost = (Vector2(n->x, n->y)-endPos).magnitude();
                n->parent = current;
                n->state = 1;
            }
        }
    }

    // this is not optimized! O(n!)
    std::vector<Vector2> tracePath() {
        if(endNode == nullptr) return {};
        std::vector<Vector2> path;
        Node* current = endNode;
        while (current != nullptr and current) {
            path.insert(path.begin(), Vector2(current->x, current->y));
            current = current->parent;
        }
        return path;
    }
};

#endif //ALGOVIZADVENTURE_PATHFINDER_HPP
