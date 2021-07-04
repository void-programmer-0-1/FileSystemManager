#include <string>
#include <iostream>
#include <experimental/filesystem>

#define C "c"
#define CPP "cpp"
#define PY "py"
#define JS "js"
#define CYTHON "pyx"
#define WAV "wav"
#define JAVA "java"
#define ASM "asm"

const std::string C_PATH = "/media/deadpool/VP/C/";
const std::string CPP_PATH = "/media/deadpool/VP/C++/";
const std::string PY_PATH = "/media/deadpool/VP/PythonPrograms/";
const std::string JAVA_PATH = "/media/deadpool/VP/Java/";
const std::string JS_PATH = "/media/deadpool/VP/Js/";
const std::string ASM_PATH = "/media/deadpool/VP/asm/";
const std::string CYTHON_PATH = "/media/deadpool/VP/Cython/";
const std::string WAV_PATH = "/media/deadpool/VP/wav/";



//namespace fs = std::experimental::filesystem;

std::string ExtractExtension(std::string& filename){
    char dot = '.';
    std::string ext;
    size_t index = filename.find(dot);
    if(index != std::string::npos){
        for(int i=index+1;i<filename.length();i++){
            ext.push_back(filename[i]);
        }
    }
    return ext;
}

void copyFile(std::string& from,std::string& to){
    std::experimental::filesystem::copy_file(from,to);
}

void ShowCopyPath(const std::string& filename,std::string& from,const std::string& to){
    std::cout << "copying " << filename << " From :: " << from << " to :: " << to << std::endl;
}

void TraversePath(std::string& path){
    for(const auto & entry : std::experimental::filesystem::directory_iterator(path)){
        
        std::string path_to = entry.path();
        std::string filename;

        for(int i=path.length() + 1;i < path_to.length();i++){
            filename.push_back(path_to[i]);
        }
        
        if(ExtractExtension(filename) == PY){
            std::string to = PY_PATH + filename;
            std::cout << "Detected an Python file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
        else if(ExtractExtension(filename) == C){
            std::string to = C_PATH + filename;
            std::cout << "Detected an C file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
        else if(ExtractExtension(filename) == CPP){
            std::string to = CPP_PATH + filename;
            std::cout << "Detected an C++ file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
        else if(ExtractExtension(filename) == ASM){
            std::string to = ASM_PATH + filename;
            std::cout << "Detected an asm file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
        else if(ExtractExtension(filename) == JAVA){
            std::string to = JAVA_PATH + filename;
            std::cout << "Detected an JAVA file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
        else if(ExtractExtension(filename) == WAV){
            std::string to = WAV_PATH + filename;
            std::cout << "Detected an wav file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
        else if(ExtractExtension(filename) == CYTHON){
            std::string to = CYTHON_PATH + filename;
            std::cout << "Detected an CYTHON file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
        else if(ExtractExtension(filename) == JS){
            std::string to = JS_PATH + filename;
            std::cout << "Detected an js file :: " << filename  << std::endl;
            ShowCopyPath(filename,path_to,to);
            copyFile(path_to,to);
        }
    }
}



int main(int argc,const char* argv[])
{

    std::string path = (std::string)argv[1];
    TraversePath(path);
    


}