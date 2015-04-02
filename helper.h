#ifndef __HELPER_H__
#define __HELPER_H__

#include "polygon.h"

#define MAX_POLYGONS 100
#define M_PI 3.14159265358979323846

int read_all_polygon(polygon_t *polygons[]);
void stage_writer(polygon_t *polygons[], int stage_number, void (*writer)(polygon_t *[]));
void write_header(int stage_number);
void calculate_areas(polygon_t *polygons[], int num_of_polygons);
void calculate_perimeters(polygon_t *polygons[], int num_of_polygons);
void calculate_eccentricities(polygon_t *polygons[], int num_of_polygons);

#endif
