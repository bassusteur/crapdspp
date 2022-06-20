#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iomanip>
#define PI 3.1415926535897932384626433832795

class functions 
{
 public:
 
 static void getwav(const char* filename)
 {
    std::ofstream ofs;
    ofs.open("output.txt",std::ofstream::out);

    FILE * inputfile;
    inputfile = fopen(filename,"rw");

    while (!feof(inputfile))
    {
        short data;
        fread(&data, sizeof(short),1,inputfile);
        if(data == 0){}else{ofs << data << std::endl;}
    }
    int fclose(FILE* inputfile);
 }

 static std::vector<int> filerw(std::vector<int> vector)
 {
    int x;
    x = 0;
    int number;
    std::string inp;
    std::ifstream in("output.txt");
    while(std::getline(in,inp))
    {
        if(inp.size() > 0)
        {
            number = stoi(inp);
            vector.push_back(number);
        }
    }
    return vector;
 }

 /*
 static void wtfdraw(std::vector<int> vector, int argc,char **argv)
 {
    int vsize = vector.size();
    float map = (vsize/1500);
    int x = 0;
    int max = Findlarge(vector);
    int min = FindMin(vector);
    float sample_rate = 44100;
    float vpsa = vsize/sample_rate;
    float vps = vpsa*sample_rate;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1500,800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGlutenfreeLatex");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for(float i: vector)
    {
        x++;
        glVertex3f(0.1, 0.1, 0.0);
    }
    glEnd();
    glFlush();
    glutMainLoop();

 } */

 
 static void waveformdraw(std::vector<int> vector, int argc,char **argv)
 {
    int vsize = vector.size();
    float xmult = (2.0/vsize);
    int x = 0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1500,800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGlutenfreeLatex");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for(float i: vector)
    {
        x++;
        float ya = i/44100;
        float xa = (x*xmult)-1;
        glVertex3f(xa, ya, 0.0f);
    }
    glEnd();
    glFlush();
    glutMainLoop();
 }
 
};