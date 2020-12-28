#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "functions.h"



int main()
{   setlocale(LC_ALL, "Rus");

    int count_files = 0;
    std::string file_path_first, file_path_second;    
    
    get_pathes_folder(file_path_first, file_path_second); 

    counter_files(count_files, file_path_first);   
    counter_files(count_files, file_path_second); 

    if (!count_files) {
        std::cout << "-------------------------" << std::endl;
        std::cout << std::setw(19) << "FILES NOT FOUND" << std::endl;
        std::cout << "_________________________" << std::endl << std::endl;
        return 0;
    }

    File* files = new File[count_files];    
    
    int i = 0;
    for (auto& p : std::filesystem::directory_iterator(file_path_first)) {                              //to fill info searched files
        std::string buff = p.path().string();                                                           //
        files[i].set_info(buff, p.file_size());                                                         //
        i++;                                                                                            //    
    };                                                                                                  //
    for (auto& p : std::filesystem::directory_iterator(file_path_second)) {                             //
        std::string buff = p.path().string();                                                           //
        files[i].set_info(buff, p.file_size());                                                         //
        i++;                                                                                            //
    };
        
    searching_dup(files, count_files);
       
    system("pause");

    delete[] files;

    return 0;
}


