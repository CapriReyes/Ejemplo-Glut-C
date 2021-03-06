#include <windows.h>
#include <C:\GLUT\include\GL\glut.h>

void inicio() // metodo de inicializacion de la pantalla
{

    glClearColor(0.0,0.0,0.0,0.0); // color de fondo de la pantalla <negro>
    glMatrixMode(GL_PROJECTION); // funcion de uso de pantalla
    //gluOrtho2D(-10.0,10.0,-10.0,10.0); //intervalo del plano a manejar. Logica de plano cartesiano x1,x2,y1,y2
    glOrtho(640,0,480,0, -1, 1); //intervalo del plano a manejar. Logica de canvas inverso x1,x2,y1,y2
}

void dibujar() //Metodo de dibujo en el entorno de trabajo
{
    glClear(GL_COLOR_BUFFER_BIT); // limpia la pantalla


    // ------------------------DIBUJANDO PUNTOS ----------------------------------------
    /*glPointSize(4); // Tamaño en pixeles del punto
    glBegin(GL_POINTS); // GL_POINTS, especifica que se dibujaran puntos
        glColor3f(1,1,1); // Color de los pixeles
        glVertex2d(200,200); // Dibuja un punto en las coordenadas especificadas.
        for(int i=0; i<=640; i+=4){ // El ciclo for ayuda a dibujar una serie de puntos, formando lineas (plano cartesiano)
            glVertex2d(0+i, 220);
            glVertex2d(320, 0+i);
        }
    glEnd();*/
    // -----------------------------------------------------------------------------------


    // ------------------------DIBUJANDO LINEAS ------------------------------------------
    /*glLineWidth(5);
    glBegin(GL_LINES); // GL_LINES ME PERMITE UNIR LINEAS DESDE UN PUNTO INICIAL A UN PUNTO FINAL
        glVertex2i(10,100);
        glVertex2i(600,100);
        glColor3f(1,1,0);
    glEnd();*/
    // -----------------------------------------------------------------------------------



    // ------------------------DIBUJANDO POLÍGONOS Y FIGURAS ------------------------------------------
    glColor3f(1,1,0);
    glLineWidth(5);
    glBegin(GL_POLYGON); // GL_LINE_STRIP, GL_LINE_LOOP, GL_ GL_POLYGON, ETC. Intenta con cada una y observa lo que sucede.
        glVertex2i(500,20);
        glVertex2i(500,300);
        glVertex2i(100,300);
    glEnd();
    // -----------------------------------------------------------------------------------

    glFlush(); // Dibuja a pantalla las funciones de dibujo
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // inicia la libreria GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // configura el modo de video inicial -- single = Simple Buffer | RGB = sistema de colores RGB  --- buffer= calculos en memoria
    glutInitWindowSize(640,480); // Tamaño de la Ventana
    glutInitWindowPosition(100,100); // Incializacion de la Posicion de la ventana
    glutCreateWindow("Primer Ventana con Glut"); // Crea la ventana con parametros de un "Nombre"
    inicio(); //Metodo Inicializa
    glutDisplayFunc(dibujar); // Muestra en pantalla todo lo contenido en el metodo dibujar
    glutMainLoop(); //permite iniciar un ciclo constante del programa
    return EXIT_SUCCESS; // fin del programa
}
