#ifndef __HELPER_H__
#define __HELPER_H__

#include "polygon.h"

/* maximum number of polygon */
#define MAX_POLYGONS 100
/* not using math.h's M_PI as its not in all math.h's definition */
#define M_PI 3.14159265358979323846

/* Read all input from stdin and populate them into polygons

   @param polygons  pointer to pointer of polygons

   @return          the number of polygons read
*/
int read_all_polygon(polygon_t *polygons[]);

/* Wrapper to write each stages, then writes the content using the supplied
   writer function

   @param polygons          pointer to pointer of polygons
   @param num_of_polygons   number of polygons read
   @param stage_number      the stage number
   @param writer            function to use to print the content of current
                            stage
*/
void stage_writer(polygon_t *polygons[], int num_of_polygons,
    int stage_number, void (*writer)(polygon_t *[], int));

/* Write the formatted header of each stage

   @param stage_number      the stage number to be written
*/
void write_header(int stage_number);

/* Calculate all of the areas of all of the polygons

   @param polygons          pointer to pointer of polygons
   @param num_of_polygons   the number of polygons read
*/
void calculate_areas(polygon_t *polygons[], int num_of_polygons);

/* Calculate all of the perimeters of all of the polygons

   @param polygons          pointer to pointer of polygons
   @param num_of_polygons   the number of polygons read
*/
void calculate_perimeters(polygon_t *polygons[], int num_of_polygons);

/* Calculate all of the eccentricities of all of the polygons

   @param polygons          pointer to pointer of polygons
   @param num_of_polygons   the number of polygons read
*/
void calculate_eccentricities(polygon_t *polygons[], int num_of_polygons);

/* Find the largest polygon in all of the polygons. If there are multiple,
   taking the polygon with the smallest ID

   @param polygons          pointer to pointer of polygons
   @param num_of_polygons   the number of polygons read
*/
polygon_t *find_largest(polygon_t *polygons[], int num_of_polygons);

#endif
