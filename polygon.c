/*
    Author: Rongduan Zhu (584 169)
*/

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "polygon.h"
#include "helper.h"

void malloc_polygon_t(polygon_t **polygon, int num_of_vertices) {
    *polygon = (polygon_t *) malloc(sizeof(polygon_t));
    assert(polygon != NULL);
    (*polygon)->coordinate =
        (coordinate_t *) malloc(sizeof(coordinate_t) * num_of_vertices);
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
    polygon->min_y = 0.0;
    polygon->perimeter = 0.0;
    polygon->area = 0.0;
    polygon->eccentricity = 0.0;
}

void pushback_coordinate_polygon_t(polygon_t *polygon, double x, double y) {
    /* push the polygon to the current position */
    (polygon->coordinate + polygon->current)->x = x;
    (polygon->coordinate + polygon->current)->y = y;

    /* increment the position */
    ++(polygon->current);

    /* if current y is less */
    polygon->min_y = y < polygon->min_y ? y : polygon->min_y;
}

void calculate_area(polygon_t *polygon) {
    int i;
    coordinate_t *current;
    coordinate_t *next;

    for (i = 0; i < polygon->num_of_vertices; ++i) {
        current = polygon->coordinate + i;
        next = get_next_coordinate(polygon, i);

        polygon->area += pair_coordinate_area(current, next, -(polygon->min_y));
    }
}

void calculate_perimeter(polygon_t *polygon) {
    int i;
    coordinate_t *current;
    coordinate_t *next;

    for (i = 0; i < polygon->num_of_vertices; ++i) {
        current = polygon->coordinate + i;
        next = get_next_coordinate(polygon, i);

        polygon->perimeter += pair_coordinate_length(current, next);
    }
}

void calculate_eccentricity(polygon_t *polygon) {
    polygon->eccentricity =
        pow(polygon->perimeter, 2) / polygon->area / 4 / M_PI;
}

double pair_coordinate_area(coordinate_t *p1, coordinate_t *p2,
    double y_offset) {

    double x_diff;

    x_diff = p2->x - p1->x;
    return (2 * y_offset + p1->y + p2->y) * x_diff / 2;
}

double pair_coordinate_length(coordinate_t *p1, coordinate_t *p2) {
    double hypotenuse_square;

    hypotenuse_square = pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2);
    return sqrt(hypotenuse_square);
}

coordinate_t *get_next_coordinate(polygon_t *polygon, int current_index) {
    assert(current_index < polygon->num_of_vertices);
    return current_index == polygon->num_of_vertices - 1
        ? polygon->coordinate : polygon->coordinate + current_index + 1;
}
