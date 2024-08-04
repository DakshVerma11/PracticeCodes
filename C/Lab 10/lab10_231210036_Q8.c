/*Write a program to show programming examples with union and enumerations.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>

// Enumeration for shapes
enum Shape {
    CIRCLE,
    RECTANGLE,
    TRIANGLE
};

// Union to represent different properties of shapes
union ShapeProperties {
    struct {
        double radius;
    } circle;

    struct {
        double length;
        double width;
    } rectangle;

    struct {
        double base;
        double height;
    } triangle;
};

// Structure to represent a geometric shape
struct GeometricShape {
    enum Shape shapeType;
    union ShapeProperties properties;
};

// Function to calculate the area of a geometric shape
double calculateArea(struct GeometricShape shape) {
    switch (shape.shapeType) {
        case CIRCLE:
            return 3.14 * shape.properties.circle.radius * shape.properties.circle.radius;
        case RECTANGLE:
            return shape.properties.rectangle.length * shape.properties.rectangle.width;
        case TRIANGLE:
            return 0.5 * shape.properties.triangle.base * shape.properties.triangle.height;
        default:
            return 0.0; // Invalid shape
    }
}

int main() {
    // Example with enumeration and union for geometric shapes
    struct GeometricShape circleShape = {CIRCLE, {.circle.radius = 5.0}};
    struct GeometricShape rectangleShape = {RECTANGLE, {.rectangle.length = 4.0, .rectangle.width = 6.0}};
    struct GeometricShape triangleShape = {TRIANGLE, {.triangle.base = 3.0, .triangle.height = 8.0}};

    // Calculate and print the area of each shape
    printf("Area of Circle: %.2f\n", calculateArea(circleShape));
    printf("Area of Rectangle: %.2f\n", calculateArea(rectangleShape));
    printf("Area of Triangle: %.2f\n", calculateArea(triangleShape));

    return 0;
}



/*In this example, we have an enumeration Shape representing different geometric shapes (circle, rectangle, triangle). The union ShapeProperties holds the properties specific to each shape. The program uses a structure GeometricShape to represent a shape, and a function calculateArea to calculate the area based on the shape's properties.
*/
