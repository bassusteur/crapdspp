#include "main.h"

int main(int argc, char **argv)
{
    std::vector<int> vec;
    std::vector<int> vec2;
    std::string in; std::string path = "wav/";
    std::cout<<"enter wav file name: ";
    std::cin>>in;
    std::string input = path+in;

    const char* openf = input.c_str();

    functions::getwav(openf);
    vec2 = functions::filerw(vec);
    int vsize = vec2.size();
    //functions::waveformdraw(vec2,argc,argv);
    int* arr = vec2.data();
    for(int i; i<vsize; i++)
    {
        std::cout << arr[i] << std::endl;
    }



    return 0;
}