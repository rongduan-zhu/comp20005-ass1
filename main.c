/* Algorithms are super f**king awesomely stupidly amazingly fun */
/* Algorithms are fun */
/*
    Author: Rongduan Zhu (584 169)
    Github: https://github.com/rongduan-zhu/

    The program is made up of 5 files, main.c, helper.h, helper.c, polygon.h,
    and polygon.c.

    This is a program which calculates the area, perimeter, and eccentricity of
    given polygons. Area is calculated by off set the polygon by the smallest y
    value if the smallest y value is smaller than 0. This brings the polygon
    above the x axis. The area is calculated by calculating the sum of the
    trepezoids formed between each pair of the vertices with the x axis.
    Considering the vertices in a clockwise order, if the next vertex is to the
    right of the current, the area is positive, otherwise it is negative.
*/

#include <stdio.h>
#include <stdlib.h>

#include "polygon.h"
#include "helper.h"

#define NUM_OF_HEADERS 5

/* A wrapper function that calls the necessary functions to do the assignment
*/
void solver();

/* Writes all of the necessary contents for stage 1 except for the header.

    @param polygons          pointer to pointer of polygons
    @param num_of_polygons   number of polygons read
 */
void stage1_write(polygon_t *polygons[], int num_of_polygons);

/* Writes all of the necessary contents for stage 2 except for the header.

    @param polygons          pointer to pointer of polygons
    @param num_of_polygons   number of polygons read
 */
void stage2_write(polygon_t *polygons[], int num_of_polygons);

/* Writes all of the necessary contents for stage 3 except for the header.

    @param polygons          pointer to pointer of polygons
    @param num_of_polygons   number of polygons read
 */
void stage3_write(polygon_t *polygons[], int num_of_polygons);

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
    stage_writer(polygons, num_of_polygons, 3, stage3_write);
}

void stage1_write(polygon_t *polygons[], int num_of_polygons) {
    int i;
    polygon_t *polygon = polygons[0];

    printf("First polygon is %d\n", polygon->poly_id);
    printf("%8s%8s\n", "x_val", "y_val");

    for (i = 0; i < polygon->num_of_vertices; ++i) {
        printf("%7.1f %7.1f\n",
            (polygon->coordinate + i)->x, (polygon->coordinate + i)->y);
    }

    printf("perimeter    = %5.2f m\n", polygon->perimeter);
    printf("area         = %5.2f m^2\n", polygon->area);
    printf("eccentricity = %5.2f\n", polygon->eccentricity);
}

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

void stage3_write(polygon_t *polygons[], int num_of_polygons) {
    int i;
    polygon_t *largest;

    largest = find_largest(polygons, num_of_polygons);
    printf("Largest polygon is %d\n", largest->poly_id);
    printf("%8s%8s\n", "x_val", "y_val");

    for (i = 0; i < largest->num_of_vertices; ++i) {
        printf("%7.1f %7.1f\n",
            (largest->coordinate + i)->x, (largest->coordinate + i)->y);
    }
}
