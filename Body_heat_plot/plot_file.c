#include <stdio.h>
#include <stdlib.h>
/*
void plotScatter(int heights,int scale) {
    int maxScale = 38 * scale - 36 * scale; // Assuming 38.0 as max temperature and 36.0 as min

    for (int y = maxScale; y >= 0; y--) {
        for (int x = 0; x < 100; x++) {
            if (heights[x] > y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
*/
int main() {

    // Get the subject name from the user
    printf("Enter the subject name: ");
    //scanf("%s", subject);
    printf("Gianni\n");char subject[100] = "Gianni"; //harcodeado


    // Generate the filename
    char filename[150];
    //snprintf(filename, sizeof(filename), "%s_%s.csv", subject, timestamp);
    snprintf(filename, sizeof(filename), "%s.csv", subject);
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open the file for reading.\n");
        return 1;
    }

    // Skip header line
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);

     // Read the data
    int index;
    float temp;
    int scale = 20;  // Vertical scale factor for better visualization
    int maxScale = 38 * scale - 36 * scale; // Assuming 38.0 as max temperature and 36.0 as min
    int heights[100] = {0};

    while (fscanf(file, "%d,%f\n", &index, &temp) != EOF) {
        heights[index - 1] = (int)((temp - 36.0) * scale);
    }

    // Plot the data
    for (int y = maxScale; y >= 0; y--) {
        // Add vertical axis label every 500 units
        if (y % 5 == 0) {
            printf("%.1f | ", 36.0 + (float)y / scale);
        } else {
            printf("     | ");
        }

        for (int x = 0; x < 100; x++) {
            if (heights[x] > y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Add the horizontal axis
    printf("      ");
    for (int x = 0; x < 100; x++) {
        printf("-");
    }
    printf("\n");


    //plotScatter(heights,scale);
/*
      // Plot the data
    for (int y = maxScale; y >= 0; y--) {
        for (int x = 0; x < 100; x++) {
            if (heights[x] > y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
*/
    // Close the file
    fclose(file);

    return 0;
}
