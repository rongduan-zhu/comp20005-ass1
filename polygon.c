#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "polygon.h"

void malloc_polygon_t(polygon_t **polygon, int num_of_vertices) {
    *polygon = (polygon_t *) malloc(sizeof(polygon_t));
    assert(polygon != NULL);
    (*polygon)->coordinate = (coordinate_t *) malloc(sizeof(coordinate_t) * num_of_vertices);
    assert((*polygon)->coordinate != NULL);
}

void free_polygon_t(polygon_t *polygon) {
    free(polygon->coordinate);
    free(polygon);
}

void init_polygon_t(polygon_t *polygon, int num_of_vertices, int poly_id) {
    polygon->num_of_vertices = num_of_vertices;
    polygon->current = 0;
    polygon->poly_id = poly_id;
    polygon->perimeter = 0.0;
    polygon->area = 0.0;
    polygon->eccentricity = 0.0;
}

void pushback_coordinate_polygon_t(polygon_t *polygon, double x, double y) {
    (polygon->coordinate + polygon->current)->x = x;
    (polygon->coordinate + polygon->current)->y = y;
    ++(polygon->current);
}
