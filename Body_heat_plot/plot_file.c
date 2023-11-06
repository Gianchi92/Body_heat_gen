#include <stdio.h>
#include <stdlib.h>

    // para saber el largo del archivo ftell (https://cplusplus.com/reference/cstdio/ftell/?kw=ftell)
    // para sacarme de encima el header puedo usar fseek()


int main() {
    int N_max=100;
    float temp_min=0;
    float temp_max=45;
    float scale = 1;  // Factor de escala

    char buffer[100];
    int index;
    float temp;
    int maxScale = (float)((temp_max-temp_min) * scale );
    int heights[100] = {0};

    printf("Nombre del sujeto: ");
    //char subject[100];scanf("%s", subject);
    printf("Gianni\n");char subject[100] = "Gianni"; //Hardcodeo ------------------------------------


    char filename[150];
    snprintf(filename, sizeof(filename), "%s.csv", subject);
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open the file for reading.\n");
        return 1;
    }
    //printf("%.d\n", sizeof(filename));

    fgets(buffer, sizeof(buffer), file);    // Skippeo header
    while (fscanf(file, "%d,%f\n", &index, &temp) != EOF) {
        heights[index - 1] = (int)((temp - temp_min) * scale);
    }

    for (int y = maxScale; y >= 0; y--) {
        // Cada 5 ploteo escala
        if (y % 5 == 0) {
            printf("%04.1f | ", temp_min + (float)y / scale);
        } else {
            printf("     | ");
        }

        for (int x = 0; x < 100; x++) {
            if (heights[x] == y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("      ");
    for (int x = 0; x < 100; x++) {
        printf("-");
    }
    printf("\n");

    fclose(file);

    char *gnuplotCommands[2048];  // Asegúrate de que este buffer sea lo suficientemente grande para todos tus comandos
    sprintf(gnuplotCommands,
            "set datafile separator ','; "
            "set yrange [0:45]; "
            "set xlabel 'Tiempo [s]'; "
            "set ylabel 'Temperatura [C]'; "
            "set title 'Evolucion de la temperatura paciente %s'; "
            "unset key;"
            "plot 'G:\\My Drive\\LabNIng\\Doctorado\\Programacion_C\\CData\\Body_heat_plot\\Gianni.csv' using 1:2 with points",
            subject);


    char command[2048];
    //sprintf(command, "gnuplot -persist | echo %s", gnuplotCommands);
    //sprintf(command, "gnuplot -persist -e \"%s\"  2> error.log", gnuplotCommands);
    sprintf(command, "gnuplot -persist -e \"%s\" > output.log 2>&1", gnuplotCommands); //OK
    system(command);






/* 1
    char *gnuplotCommands = "set datafile separator ',';"
    "set yrange [0:45];"
    "plot 'G:\\My Drive\\LabNIng\\Doctorado\\Programacion_C\\CData\\Body_heat_plot\\Gianni.csv' using 1:2 with points";
    char command[1024];
    sprintf(command, "echo %s | gnuplot -persist", gnuplotCommands);
    system(command);
*/
/* 2
    // Ahora, utilizamos Gnuplot para trazar el gráfico
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    if (gnuplotPipe == NULL)
    {
    fprintf(stderr, "Error al abrir la tubería a Gnuplot.\n");
    return; // Salir de la función si hay un error
    }
    // Comandos de Gnuplot para trazar la función desde datos proporcionados
    fprintf(gnuplotPipe, "set title 'Evolución de la temperatura paciente %s'\n",subject);
    fprintf(gnuplotPipe, "set xlabel 'X'\n");
    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
    fprintf(gnuplotPipe, "set key outside\n");
    fprintf(gnuplotPipe, "set autoscale x\n");
    fprintf(gnuplotPipe, "plot 'G:\\My Drive\\LabNIng\\Doctorado\\Programacion_C\\CData\\Body_heat_plot\\Gianni.csv' using 1:2 with points");
    // Cerrar la tubería
    pclose(gnuplotPipe);
*/

    return 0;
}
