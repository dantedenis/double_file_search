#include "functions.h"
#include <iostream>
#include <string>
#include <filesystem>



     bool filecompare(std::ifstream& first, std::ifstream& second) {
        char ch1 = 0, ch2;
        while (ch1 != EOF) {
            ch1 = first.get(); ch2 = second.get();
            if (ch1 != ch2) {                
                return false;
            }
        }        
        return true;
    };

     void get_pathes_folder(std::string& first, std::string& second) {

         std::cout << "¬ведите путь є1:" << std::endl;         
         std::getline(std::cin, first);

         std::cout << "¬ведите путь є2:" << std::endl;
         std::getline(std::cin, second);
     };

     int counter_files(int& counter, const std::string file) {
     
         for (auto& p : std::filesystem::directory_iterator(file)) {
             counter++;
         };
         return counter;
     };
          
     void searching_dup(File* files, const int count_files) {
         std::cout << std::endl;
         std::cout << std::setw(47) << "DUPLICATE LIST" << std::endl;

         int count = 0;
         for (int i = 0; i < count_files - 1; i++) {

             for (int j = i+1; j < count_files; j++) {
                 if (i != j) {

                     std::ifstream first(files[i].get_path(), std::ios::binary);
                     std::ifstream second(files[j].get_path(), std::ios::binary);

                     if (files[i].get_size() == files[j].get_size()) {
                         if (filecompare(first, second)) {
                             count++;
                             std::cout << "--------------------------------------------------------------------------------" << std::endl;
                             std::cout << std::left << "  " << count << ": " << std::setw(30) << files[i].generation_name_file() << "  (AND)  " << '\t' << files[j].generation_name_file() << std::endl << std::endl;
                             std::cout << "Path 1st file:  \t" << files[i].get_path() << std::endl;
                             std::cout << "Path 2nd file:  \t" << files[j].get_path() << std::endl;
                             std::cout << "________________________________________________________________________________" << std::endl << std::endl;
                         }
                     }
                 }
             }

         }
         if (count == 0) std::cout << "DUPLICATE NOT FOUND" << std::endl << std::endl;
     };
     
    File::File(const std::string path,const std::string name, uintmax_t size) {
        this->path = path;
        
        this->size = size;
        
    };

    std::string File::get_path() {
        return this->path;
    };

    uintmax_t File::get_size() {
        return this->size;
    };

    File::File() {               
        this->size = 0;
    };

    void File::get_info() {       
        std::cout << "Path:  " << path << std::endl;
        std::cout << "Name:  " << File::generation_name_file() << std::endl;
        std::cout << "Size:  " << size << std::endl;
    };

    void File::set_info(std::string path,uintmax_t size) {
        this->path = path;
        this->size = size;        
    };        

    std::string File::generation_name_file() {
       std::string name_def;
       int size = path.length();
       int j = 0;

       for (unsigned int i = (size-1); ; i--) {
           if (path[i] == '/' || path[i] == '\\') {
               j = i;
               break;
           }
       }

       for (unsigned int i = j + 1; i < path.length(); i++) {
           name_def += path[i];
       }
       return name_def;
    };

    std::string path;
    uintmax_t size;
    
   
    
    