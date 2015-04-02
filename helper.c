#include <stdio.h>
#include <assert.h>

#include "helper.h"
#include "polygon.h"

int read_all_polygon(polygon_t *polygons[]) {
    int num_of_polygons = 0;
    int num_of_vertices;
    int poly_id;
    int i;
    double x, y;
    polygon_t *current_polygon;

    while (scanf("%d %d", &num_of_vertices, &poly_id) == 2) {
        malloc_polygon_t(&current_polygon, num_of_vertices);
        init_polygon_t(current_polygon, num_of_vertices, poly_id);

        for (i = 0; i < num_of_vertices; ++i) {
            assert(scanf("%lf %lf", &x, &y) == 2);
            pushback_coordinate_polygon_t(current_polygon, x, y);
        }

        polygons[num_of_polygons] = current_polygon;
        ++num_of_polygons;
    }

    return num_of_polygons;
}

void stage_writer(polygon_t *polygons[], int num_of_polygons, int stage_number, void (*writer)(polygon_t *[], int)) {
    write_header(stage_number);
    (*writer)(polygons, num_of_polygons);
}

void write_header(int stage_number) {
    printf("\nStage %d\n=======\n", stage_number);
}

void calculate_areas(polygon_t *polygons[], int num_of_polygons) {
    int i;

    for (i = 0; i < num_of_polygons; ++i) {
        calculate_area(polygons[i]);
    }
}

void calculate_perimeters(polygon_t *polygons[], int num_of_polygons) {
    int i;

    for (i = 0; i < num_of_polygons; ++i) {
        calculate_perimeter(polygons[i]);
    }
}

void calculate_eccentricities(polygon_t *polygons[], int num_of_polygons) {
    int i;

    for (i = 0; i < num_of_polygons; ++i) {
        calculate_eccentricity(polygons[i]);
    }
}

polygon_t *find_largest(polygon_t *polygons[], int num_of_polygons) {
    int i;
    polygon_t *largest = polygons[0];

    for (i = 1; i < num_of_polygons; ++i) {
        if (polygons[i]->area > largest->area) {
            largest = polygons[i];
        } else if (polygons[i]->area == largest->area
                && polygons[i]->poly_id < largest->poly_id) {
            largest = polygons[i];
        }
    }

    return largest;
}
