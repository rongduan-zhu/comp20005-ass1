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
    double min_y;
    double perimeter;
    double area;
    double eccentricity;
    coordinate_t *coordinate;
} polygon_t;

void malloc_polygon_t(polygon_t **polygon, int num_of_vertices);
void free_polygon_t(polygon_t *polygon);
void init_polygon_t(polygon_t *polygon, int num_of_vertices, int poly_id);
void pushback_coordinate_polygon_t(polygon_t *polygon, double x, double y);
void calculate_area(polygon_t *polygon);
void calculate_perimeter(polygon_t *polygon);
void calculate_eccentricity(polygon_t *polygon);
double pair_coordinate_area(coordinate_t *p1, coordinate_t *p2, double y_offset);
double pair_coordinate_length(coordinate_t *p1, coordinate_t *p2);
coordinate_t *get_next_coordinate(polygon_t *polygon, int current_index);

#endif
