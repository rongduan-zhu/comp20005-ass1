#ifndef __HELPER_H__
#define __HELPER_H__

#include "polygon.h"

#define MAX_POLYGONS 100

int read_all_polygon(polygon_t *polygons[]);
void stage_writer(polygon_t *polygon[], int stage_number, void (*writer)(polygon_t *[]));
void write_header(int stage_number);

#endif
