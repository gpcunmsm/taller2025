#ifndef DOT_H
#define DOT_H

#include <stdlib.h>

FILE *dotfile;
enum GraphType {
  GRAPH,
  DIGRAPH
};

enum VertexShape {
  BOX,
  POLYGON,
  ELLIPSE,
  CIRCLE,
  HEXAGON
}

int vertexShapes[] = { "box", "polygon", "ellipse", "circle", "hexagon" };
// TODO: add more types, see https://www.graphviz.org/doc/info/shapes.html
// assuming same order of definition for enum and for array

enum GraphType type;

void initGraph(char *filename, char *graphname);
void initDigraph(char *filename, char *graphname);
void close();

void addEdge(char *a, char *b)
void addArc(char *a, char *b);
void setVertexShape(enum VertexShape shape, char *a);
#endif
