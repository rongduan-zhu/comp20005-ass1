#include <stdio.h>
#include <stdlib.h>

#include "polygon.h"
#include "helper.h"

void solver();
void stage1_write(polygon_t *polygons[]);

int main(int argc, char *argv[]) {
    solver();

    return 0;
}

void solver() {
    int num_of_polygons;
    polygon_t *polygons[MAX_POLYGONS];

    num_of_polygons = read_all_polygon(polygons);

    calculate_areas(polygons, num_of_polygons);
    calculate_perimeters(polygons, num_of_polygons);
    calculate_eccentricities(polygons, num_of_polygons);

    stage_writer(polygons, 1, stage1_write);
}

/* Stage 1 operations */
void stage1_write(polygon_t *polygons[]) {
    int i;
    polygon_t *polygon = polygons[0];

    printf("First polygon is %d\n", polygon->poly_id);
    printf("%8s%8s\n", "x_val", "y_val");

    for (i = 0; i < polygon->num_of_vertices; ++i) {
        printf("%7f %7f\n",
            (polygon->coordinate + i)->x, (polygon->coordinate + i)->y);
    }

    printf("perimeter    = %.2f m\n", polygon->perimeter);
    printf("area         = %.2f m^2\n", polygon->area);
    printf("eccentricity = %.2f\n", polygon->eccentricity);
}
