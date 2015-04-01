#ifndef __POLYGON_H__
#define __POLYGON_H__

typedef struct {
    double x;
    double y;
} coordinate_t;

typedef struct {
    int num_of_vertices;
    int current;
    int poly_id;
    double perimeter;
    double area;
    double eccentricity;
    coordinate_t *coordinate;
} polygon_t;

void malloc_polygon_t(polygon_t **polygon, int num_of_vertices);
void free_polygon_t(polygon_t *polygon);
void init_polygon_t(polygon_t *polygon, int num_of_vertices, int poly_id);
void pushback_coordinate_polygon_t(polygon_t *polygon, double x, double y);

#endif
