#include <stdio.h>
#include <stdlib.h>

#include "polygon.h"
#include "helper.h"

#define NUM_OF_HEADERS 5

void solver();
void stage1_write(polygon_t *polygons[], int num_of_polygons);
void stage2_write(polygon_t *polygons[], int num_of_polygons);

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

    stage_writer(polygons, num_of_polygons, 1, stage1_write);
    stage_writer(polygons, num_of_polygons, 2, stage2_write);
}

/* Stage 1 operations */
void stage1_write(polygon_t *polygons[], int num_of_polygons) {
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

/* Stage 2 operations */
void stage2_write(polygon_t *polygons[], int num_of_polygons) {
    int i;
    char *headers[] = {"id", "nval", "perim", "area", "eccen"};

    printf("+-------+-------+-------+-------+-------+\n");

    for (i = 0; i < NUM_OF_HEADERS; ++i) {
        printf("| %5s ", headers[i]);
    }
    printf("|\n");
    printf("+-------+-------+-------+-------+-------+\n");

    for (i = 0; i < num_of_polygons; ++i) {
        printf("| %5d ", polygons[i]->poly_id);
        printf("| %5d ", polygons[i]->num_of_vertices);
        printf("| %5.2f ", polygons[i]->perimeter);
        printf("| %5.2f ", polygons[i]->area);
        printf("| %5.2f ", polygons[i]->eccentricity);
        printf("|\n");
    }

    printf("+-------+-------+-------+-------+-------+\n");
}
