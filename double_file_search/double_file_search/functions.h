#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <fstream>


    bool filecompare(std::ifstream& first, std::ifstream& second);

    void get_pathes_folder(std::string& first, std::string& second);
    
    int counter_files(int& counter, const std::string file);
   
    

    class File
    {
        public:
            File(std::string path, std::string name, uintmax_t size);
            File();
            void get_info();
            void set_info(std::string path, uintmax_t size);
            std::string generation_name_file();
            std::string get_path();
            uintmax_t get_size();           

        private:           
            std::string path;
            uintmax_t size;        
            
    };

    void searching_dup(File* files, const int count_files);

#endif	FUNCTIONS_H