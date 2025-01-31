
void initGraph(char *filename, char *graphname) {
  if ( dotfile == NULL ) {
    dotfile = fopen(filename);
    fprintf(dotfile, "graph %s {\n", graphname);
    type = GRAPH;
  }
}

void initDigraph(char *filename, char *graphname) {
  if ( dotfile == NULL ) {
    dotfile = fopen(filename);
    fprintf(dotfile, "digraph %s {\n", graphname);
    type = DIGRAPH;
  }
}

void close() {
  if ( dotfile != NULL ) {
    fprintf(dotfile, "}");
    fclose(dotfile);
  }
}

void addEdge(char *a, char *b) {
  if ( dotfile != NULL && type == GRAPH ) {
    fprintf(dotfile, "%s -- %s \n", a, b);
  }
}

void addArc(char *a, char *b) {
  if ( dotfile != NULL && type == DIGRAPH) {
    fprintf(dotfile, "%s -> %s \n", a, b);
  }
}

void setVertexShape(enum VertexShape shape, char *a) {
  if ( dotfile != NULL ) {
    fprintf(dotfile, "%s [shape=%s]", vertexShapes[shape], a);
  }
}

