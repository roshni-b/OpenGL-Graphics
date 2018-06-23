#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include<math.h>
using namespace std;

    float cx=100,  cy=100,  r=150,  alpha=60*0.017, beta=330*0.017; 
        int num_segments=150;


void myInit (void)
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
  
void arc(void) 
{ 
        float theta = beta / float(num_segments - 1);

        float tangetial_factor = tanf(theta);

        float radial_factor = cosf(theta);

        
        float x = r * cosf(alpha);
        float y = r * sinf(alpha); 
    
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < num_segments; i++)
        { 
                glVertex2f(x + cx, y + cy);

                float tx = -y; 
                float ty = x; 

                x += tx * tangetial_factor; 
                y += ty * tangetial_factor; 

                x *= radial_factor; 
                y *= radial_factor; 
                
                //glClear (GL_COLOR_BUFFER_BIT);
       // glColor3f (1.0, 0.0, 0.0);
     //   glPointSize(1.0);
        } 
        glEnd(); 
}


void myDisplay(void)
{
        glClear (GL_COLOR_BUFFER_BIT);
        glColor3f (0.0, 0.0, 0.0);
        glPointSize(1.0);

        arc();

        glFlush ();
}

void main(int argc, char** argv)
{        
        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize (640, 480);
        glutInitWindowPosition (400, 400);
        glutCreateWindow ("Arc Drawing:");
        glutDisplayFunc(myDisplay);
        myInit ();
        glutMainLoop();

}
