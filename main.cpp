#include "main.h"

 void wvdraw(std::vector<float> vector)
 {
    int vsize = vector.size();
    float xmult = (2.0/vsize);
    int x = 0;

    GLFWwindow* window;
    if (!glfwInit()){}
    window = glfwCreateWindow(1000, 600, "test", NULL, NULL);
    if (!window){glfwTerminate();}
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        for(float i: vector)
        {
            x++;
            float ya = i;
            float xa = (x*xmult)+1;
            glVertex3f(xa, ya, 0.0f);
        }
        glFlush();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
 }

 std::vector<float> getwav(const char* filename, std::vector<float> vector)
 {
    std::ofstream ofs;
    ofs.open("output.txt",std::ofstream::out);

    FILE * inputfile;
    inputfile = fopen(filename,"rw");

    while (!feof(inputfile))
    {
        short data;
        fread(&data, sizeof(short),1,inputfile);
        float result = (float) data / 100000; 
        if(result > 1) {}
        else
        {
            vector.push_back(result); 
            ofs<<result<<std::endl;
        }
    
    }
    int fclose(FILE* inputfile);
    return vector;
 }



 std::vector<float> fftcompute(fftw_complex in[], fftw_complex out[], int N, std::vector<float> fftvec)
 {
    std::ofstream ofs;
    ofs.open("fft.txt",std::ofstream::out);
    int i;
    fftw_plan p;
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    for (i = 0; i < N; i++)
        fftvec.push_back(out[i][0]);
    fftw_destroy_plan(p);
    return fftvec;
 }

 void fftdraw(std::vector<float> vector)
 {
    int vsize = vector.size();
    float xmult = (2.0/vsize);
    int x = 0;

    GLFWwindow* window;
    if (!glfwInit()){}
    window = glfwCreateWindow(1000, 800, "test", NULL, NULL);
    if (!window){glfwTerminate();}
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        for(float i: vector)
        {
            x++;
            float ya = i/100;
            float xa = (x*xmult)-1;
            glVertex3f(xa, ya, 0.0f);
        }
        glFlush();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
 }


int main(int argc, char **argv)
{
    //std::vector<float> vec;
    //std::vector<float> vec2;
    std::vector<float> fftvec;
    std::vector<float> fftreturn;
    int i;
    //std::string inp; std::string path = "wav/";
    //std::cout<<"enter wav file name: ";
    //std::cin>>inp;
    //std::string input = path+inp;

    //const char* openf = input.c_str();

    //vec2 = getwav(openf,vec);
    //int vsize = vec2.size();

    //wvdraw(vec2);
    int N = 100;

    fftw_complex in[N], out[N];

    for (i = 0; i < N; i++) {
      in[i][0] = cos(2*M_PI*i/N);
      in[i][1] = 0;

    }

    /*
    for (int i = 0; i < vsize; i++) {
        in[i][0] = vec2[i];
        in[i][1] = 0;
    }
    */
    fftreturn = fftcompute(in,out,N,fftvec);
    
    fftdraw(fftreturn);


    return 0;
}