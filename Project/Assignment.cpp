#define _USE_MATH_DEFINES
#include <Gl/glut.h> // Note: this automatically includes other 
// required header files, including: 
//    glu.h      (GL utility functions) 
//    gl.h       (GL functions) 
//    windows.h  (Microsoft windows stuff) 
#include <cmath>

bool isBackgroundBlue = false; // to control background color
float red = 0.9, green = 0.9, blue = 0.9;
float carPositionX = 0.0;
float carSpeed = 0.030;
bool isCarMoving = false;
int w = 770, h = 470;
float camX = 0, camY = 0;


void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // set the background to white

    // Enable lighting and set up a directional light source
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightDirection[] = { 0.0, 0.0, -1.0, 0.0 }; // Directional light in the negative z direction
    glLightfv(GL_LIGHT0, GL_POSITION, lightDirection);

    // Set three light colors: pink, purple, and dark blue
    GLfloat White[] = { 1.0, 1.0, 1.0, 0.0 };  // White
    GLfloat Purple[] = { 0.9, 0.9, 1.0, 0.0 };  // Purple
    GLfloat Pink[] = { 1.0, 0.6, 0.6, 0.0 }; // Pink blue
    GLfloat DarkBlue[] = { 0.0, 0.0, 0.6, 0.0 }; // Dark blue

    glLightfv(GL_LIGHT0, GL_AMBIENT, White);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DarkBlue);
    glLightfv(GL_LIGHT0, GL_SPECULAR, Purple);

    glLightfv(GL_LIGHT1, GL_AMBIENT, DarkBlue);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, White);
    glLightfv(GL_LIGHT1, GL_SPECULAR, Purple);

    glLightfv(GL_LIGHT2, GL_AMBIENT, Purple);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, Pink);
    glLightfv(GL_LIGHT2, GL_SPECULAR, Pink);


    // Enable glColorMaterial to specify GL_AMBIENT_AND_DIFFUSE
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_NORMALIZE);


}

void drawSun() {
    glPushMatrix();
    glTranslatef(75.0, 790.0, 0.0);  // Move to the left corner above
    glColor3f(1.0, 0.9, 0.1); // Yellow color for the 3D sun
    glutSolidSphere(55, 30, 50); // Draw a solid sphere
    glPopMatrix();
}

void drawhouse(void) {

    glColor3f(0.9f, 0.9f, 0.6f);      // set the drawing color
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glRecti(300, 100, 650, 665); // start drawing 'Rectangle'

    //Roof
    glColor3f(0.5f, 0.4f, 0.5f);      // set the drawing color 
    glBegin(GL_QUADS);				// start drawing in 'Quad' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(600, 777);
    glVertex2i(340, 777);
    glVertex2i(288, 665);
    glVertex2i(663, 665);
    glEnd(); // end drawing 

    /////////////////////////////////////////////////////////////////////////////////
    glColor3f(0.9f, 0.9f, 0.6f);      // set the drawing color 
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glRecti(365, 777, 395, 815); // start drawing 'Rectangle'  

}


void drawCircle(float Radius, int numPoints, int X1, int Y1) {  // X1 and Y1 for the postion of the circle

    // draw Circle
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    for (int i = 0; i < numPoints; i++)
    {
        float Angle = i * (2.0 * M_PI / numPoints);
        float X2 = cos(Angle) * Radius;
        float Y2 = sin(Angle) * Radius;
        glVertex2f(X1 + X2, Y1 + Y2);

    }
    glEnd();

}



void drawroad(void) {


    glLineWidth(5);
    glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(0, 50);			// specify the lines geometry
    glVertex2i(45, 50);
    glEnd(); // end drawing 

    glLineWidth(5);
    glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(135, 50);			// specify the lines geometry
    glVertex2i(205, 50);
    glEnd(); // end drawing 


    glLineWidth(5);
    glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(305, 50);			// specify the lines geometry
    glVertex2i(375, 50);
    glEnd(); // end drawing 

    glLineWidth(5);
    glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(475, 50);			// specify the lines geometry
    glVertex2i(545, 50);
    glEnd(); // end drawing 


    glLineWidth(5);
    glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(645, 50);			// specify the lines geometry
    glVertex2i(715, 50);
    glEnd(); // end drawing 

    glColor3f(0.0f, 0.0f, 0.0f);      // set the drawing color 
    glRecti(0, 0, 769, 100); // start drawing 'Rectangle' //door




    glColor3f(0.0f, 0.0f, 0.0f);      // set the drawing color 
    glRecti(0, 0, 769, 100); // start drawing 'Rectangle' //door




}


void drawclouds(void) {

    glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color to white
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face

    // left cloud
    drawCircle(27, 85, 95, 823);
    drawCircle(27, 85, 76, 800);
    drawCircle(27, 85, 115, 800);

    // middle cloud
    drawCircle(27, 85, 220, 785);
    drawCircle(27, 85, 200, 765);
    drawCircle(27, 85, 240, 765);

    // right cloud
    drawCircle(20, 85, 700, 815);
    drawCircle(20, 85, 685, 795);
    drawCircle(20, 85, 715, 795);


}

void drawcar(void) {

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);    // set the drawing color to white
    drawCircle(9, 100, 45, 51);
    drawCircle(9, 100, 105, 51);


    glColor3f(0.0f, 0.0f, 0.0f);      // set the drawing color to black
    drawCircle(17, 100, 45, 51);
    drawCircle(17, 100, 105, 51);

    // draw car
    glColor3f(0.4f, 0.4f, 0.4f);      // set the drawing color 
    glBegin(GL_QUADS);				// start drawing in 'Quad' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(140, 100);
    glVertex2i(9, 100);
    glVertex2i(9, 45);
    glVertex2i(152, 45);
    glEnd(); // end drawing 


    // draw light car
    glPointSize(5);
    glColor3f(1.0f, 1.0f, 0.3f);      // set the drawing color 
    glBegin(GL_POINTS);				// start drawing in 'Points' mode

    glVertex2i(147, 70);
    glEnd(); // end drawing 

    glColor4f(0.8f, 1.0f, 1.0f, 0.9f);      // set the drawing color 
    glBegin(GL_QUADS);				// start drawing in 'Quad' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(70, 149);
    glVertex2i(50, 149);
    glVertex2i(33, 100);
    glVertex2i(70, 100);
    glEnd();



    glColor4f(0.8f, 1.0f, 1.0f, 0.9f);      // set the drawing color 
    glBegin(GL_QUADS);				// start drawing in 'Quad' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the back face
    glVertex2i(100, 149);
    glVertex2i(77, 149);
    glVertex2i(77, 100);
    glVertex2i(114, 100);
    glEnd();

    //Q
    glColor3f(0.4f, 0.4f, 0.4f);      // set the drawing color 
    glBegin(GL_QUADS);				// start drawing in 'Quad' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the back face
    glVertex2i(105, 165);
    glVertex2i(45, 165);
    glVertex2i(25, 100);
    glVertex2i(125, 100);
    glEnd(); // end drawing 

    glPopMatrix();

}


void drawtree(void) {

    // left tree
    glLineWidth(40);
    glColor3f(0.5f, 0.4f, 0.2f);      // set the drawing color  
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(720, 100);			// specify the lines geometry
    glVertex2i(720, 355);
    glEnd(); // end drawing 

    glColor3f(0.4f, 0.5f, 0.3f);      // set the drawing color 
    glBegin(GL_TRIANGLES);				// start drawing in 'Triangle' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(720, 435);
    glVertex2i(680, 350);
    glVertex2i(760, 350);
    glEnd(); // end drawing  


    glColor3f(0.4f, 0.5f, 0.3f);      // set the drawing color t
    glBegin(GL_TRIANGLES);				// start drawing in 'Triangle' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(720, 500);
    glVertex2i(680, 410);
    glVertex2i(760, 410);
    glEnd(); // end drawing  

    glColor3f(0.4f, 0.5f, 0.3f);      // set the drawing color 
    glBegin(GL_TRIANGLES);				// start drawing in 'Triangle' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(720, 565);
    glVertex2i(680, 470);
    glVertex2i(760, 470);
    glEnd(); // end drawing  

    //////////////////////////////////////////////////////////////////////////////// 

     // right tree
    glLineWidth(40);
    glColor3f(0.5f, 0.4f, 0.2f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(230, 100);			// specify the lines geometry
    glVertex2i(230, 355);
    glEnd(); // end drawing 

    glColor3f(0.4f, 0.5f, 0.3f);      // set the drawing color 
    glBegin(GL_TRIANGLES);				// start drawing in 'Triangle' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(230, 435);
    glVertex2i(190, 350);
    glVertex2i(270, 350);
    glEnd(); // end drawing  

    glColor3f(0.4f, 0.5f, 0.3f);      // set the drawing color 
    glBegin(GL_TRIANGLES);				// start drawing in 'Triangle' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(230, 500);
    glVertex2i(190, 410);
    glVertex2i(270, 410);
    glEnd(); // end drawing  

    glColor3f(0.4f, 0.5f, 0.3f);      // set the drawing color
    glBegin(GL_TRIANGLES);				// start drawing in 'Triangle' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(230, 565);
    glVertex2i(190, 470);
    glVertex2i(270, 470);
    glEnd(); // end drawing  


}

void drawdoor(void) {


    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color
    drawCircle(5, 100, 497, 230);

    glColor3f(red, green, blue);      // set the drawing color 
    glRecti(445, 110, 507, 370); // start drawing 'Rectangle'


    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glRecti(437, 100, 515, 380); // start drawing 'Rectangle'



}

void drawwindows(void) {


    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(333, 257);			// specify the lines geometry
    glVertex2i(402, 257);
    glEnd(); // end drawing 


    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(367, 175);			// specify the lines geometry
    glVertex2i(367, 344);
    glEnd(); // end drawing

    // glass
    glColor4f(0.8f, 1.0f, 1.0f, 0.9f);      // set the drawing color
    glRecti(333, 175, 402, 340);

    //left-down window
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glRecti(325, 160, 410, 355); // start drawing 'Rectangle' 


    /////////////////////////////////////////////////////////////////////////////////

    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(333, 515);			// specify the lines geometry
    glVertex2i(404, 515);
    glEnd(); // end drawing 


    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(367, 430);			// specify the lines geometry
    glVertex2i(367, 607);
    glEnd(); // end drawing

    // glass
    glColor4f(0.8f, 1.0f, 1.0f, 0.9f);      // set the drawing color
    glRecti(333, 430, 402, 600); // start drawing 'Rectangle' 

    // left-up window
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color
    glRecti(325, 415, 410, 615); // start drawing 'Rectangle' //window left up


    /////////////////////////////////////////////////////////////////////////////////

    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(548, 257);			// specify the lines geometry
    glVertex2i(617, 257);
    glEnd(); // end drawing 


    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(582, 175);			// specify the lines geometry
    glVertex2i(582, 340);
    glEnd(); // end drawing

    // glass
    glColor4f(0.8f, 1.0f, 1.0f, 0.9f);      // set the drawing color
    glRecti(548, 175, 617, 340); // start drawing 'Rectangle' 

    // right-down window
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glRecti(540, 160, 625, 355); // start drawing 'Rectangle' 


    /////////////////////////////////////////////////////////////////////////////////


    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(548, 515);			// specify the lines geometry
    glVertex2i(619, 515);
    glEnd(); // end drawing 


    glLineWidth(10);
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glBegin(GL_LINES);				// start drawing in 'line' mode
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex2i(582, 430);			// specify the lines geometry
    glVertex2i(582, 607);
    glEnd(); // end drawing


    // glass
    glColor4f(0.8f, 1.0f, 1.0f, 0.9f);      // set the drawing color
    glRecti(548, 430, 617, 600); // start drawing 'Rectangle' 


    // right-up window
    glColor3f(0.7f, 0.7f, 0.6f);      // set the drawing color 
    glRecti(540, 415, 625, 615); // start drawing 'Rectangle' 

}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear display window


    glLoadIdentity();
    gluLookAt(
        //cam pos
        camX, camY, 20,
        //looking at
        0, 0, 0,
        //up dir
        0, 1, 0);

    if (isBackgroundBlue) {
        glClearColor(0.5, 0.7, 0.9, 0.0); // Set the background to blue

        glPushMatrix();
        drawclouds(); // to draw clouds
        glPopMatrix();



    }
    else {
        glClearColor(0.9, 1.0, 1.0, 0.5); // Set the background to white
        glPushMatrix();
        drawSun();     // to draw the 3D sun
        glPopMatrix();

    }


    glPushMatrix();
    glTranslatef(carPositionX, 0.0, 0.0);
    drawcar(); // to draw car
    glPopMatrix();


    glPushMatrix();
    drawwindows();  // to draw windows
    glPopMatrix();


    glPushMatrix();
    drawdoor(); // to draw door
    glPopMatrix();


    glPushMatrix();
    drawhouse();   // to draw house
    glPopMatrix();

    glPushMatrix();
    drawtree();  // to draw tree
    glPopMatrix();


    glPushMatrix();
    drawroad(); // to draw road
    glPopMatrix();




    glFlush();	// send any buffered output to the OpenGL rendering process 

    glutSwapBuffers(); // Swap the front and back buffers to display the rendered image


}

//----------------------------------------------------------------------------------------------------------------

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        isBackgroundBlue = !isBackgroundBlue; // Toggle the background color
        glutPostRedisplay(); // Request a redraw to reflect the color change
    }

}


void processNormalKeys(unsigned char key, int x, int y) {
    switch (key) {

    case 'c':
    case 'C':
        isCarMoving = true; // move the car
        break;

    case 's':
    case 'S':
        isCarMoving = false;  // stop the car moving
        break;

    case 'h':
    case 'H':
        isCarMoving = false;      
        carPositionX = 0.0;  // return to its original position.
        break;

    case 'Y':
    case 'y':
        red = 1.0;
        green = 1.0;
        blue = 0.8; break;  // change door to yellow color

    case 'W':
    case 'w':
        red = 1.0;
        green = 1.0;
        blue = 1.0; break; // change door to white color

    case 'R':
    case 'r':
        red = 1.0;
        green = 0.1;
        blue = 0.2; break; // change door to white color

    case 'G':
    case 'g':
        red = 0.9;
        green = 0.9;
        blue = 0.9; break; // change door to white color

    }

    glutPostRedisplay();

}


void processSpecialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1:
        glEnable(GL_LIGHT0);
        break;

    case GLUT_KEY_F2:
        glDisable(GL_LIGHT0);
        break;

    case GLUT_KEY_F3:
        glEnable(GL_LIGHT1);
        break;

    case GLUT_KEY_F4:
        glDisable(GL_LIGHT1);
        break;

    case GLUT_KEY_END:
        exit(0);

    }
    glutPostRedisplay();
}


void reshape(int w, int h) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Use orthographic projection
    glOrtho(0.0, 769.0, 0.0, 869.0, -100.0, 100.0); // Adjust near and far values

    glViewport(0, 0, w, h);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);;

}

void idle() {
    if (isCarMoving) {
        carPositionX += carSpeed;

    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);	// Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);   // Set display mode

    glutInitWindowPosition(100, 200);	// Set top-left display window position

    glutInitWindowSize(w, h);	// Set display window width and height
    glutCreateWindow("Rana Alshaikh");// Create display window

    init();  	// Execute initialization procedure
    glutDisplayFunc(display);	// Send graphics to display window

    glutMouseFunc(mouse);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys); // Use glutSpecialFunc for special keys
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutMainLoop();		// Display everything and wait

    return 0;
}