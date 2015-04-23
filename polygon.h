/*
    Author: Rongduan Zhu (584 169)
*/

#ifndef __POLYGON_H__
#define __POLYGON_H__


/* Data structure for holding pairs of coordinate */
typedef struct {
    double x;
    double y;
} coordinate_t;


/* Data structure representing a polygon */
typedef struct {
    int num_of_vertices;
    int current; /* Indicating which vertices did the last operation acted on */
    int poly_id;
    double min_y; /* The smallest y coordinate */
    double perimeter;
    double area;
    double eccentricity;
    coordinate_t *coordinate; /* The list of coordinates */
} polygon_t;

/* Allocating memory for a polygon and the vertices. Function asserts if it
   can allocate enough memory otherwise program exits.

   @param polygon           the address of a pointer to a polygon type.
   @param num_of_vertices   the number of vertices for this polygon
 */
void malloc_polygon_t(polygon_t **polygon, int num_of_vertices);

/* Free the allocated memory to the polygon

   @param polygon   pointer to a polygon to free
*/
void free_polygon_t(polygon_t *polygon);

/* Initialize a polygon with initial values.

   @param polygon           a pointer to the polygon to initialize
   @param num_of_vertices   the number of vertices for that polygon
   @param poly_id           the ID of the polygon
*/
void init_polygon_t(polygon_t *polygon, int num_of_vertices, int poly_id);

/* Add a coordinate to the polygon

   @param polygon   the pointer to the polygon to push the new coordinate to
   @param x         the x value of the coordinate
   @param y         the y value of the coordinate
*/
void pushback_coordinate_polygon_t(polygon_t *polygon, double x, double y);

/* Calculate the area of the polygon

   @param polygon   the polygon for which the area needs to be calculated
*/
void calculate_area(polygon_t *polygon);

/* Calculate the perimeter of the polygon

   @param polygon   the polygon for which the perimeter needs to be calculated
 */
void calculate_perimeter(polygon_t *polygon);

/* Calculate the eccentricity

   @param polygon   the polygon for which the eccentricity needs to be
                    calculated
*/
void calculate_eccentricity(polygon_t *polygon);

/* Calculate the area under the two coordinates after offsetting them by the
   smallest y value in the polygon that is less than 0. If the second coordinate
   is to the left of the first coordinate, the area will be negative

   @param p1        pointer to the first coordinate
   @param p2        pointer to the second coordinate
   @param y_offset  the smallest y value which is less than 0, otherwise 0

   @return          the area under the two coordinates.
*/
double pair_coordinate_area(coordinate_t *p1, coordinate_t *p2,
    double y_offset);

/* Calculate the distance between the two coordinates

   @param p1    pointer to the first coordinate
   @param p2    pointer to the second coordinate

   @return      the distance between the two coordinates
*/
double pair_coordinate_length(coordinate_t *p1, coordinate_t *p2);

/* Get the next coordinate given the index. If the index is at the last position
   it will return the first

   @param polygon           the polygon that has the coordinates
   @param current_index     the index of the current coordinate

   @return                  the next coordinate given the current coordinate
                            index
*/
coordinate_t *get_next_coordinate(polygon_t *polygon, int current_index);

#endif
