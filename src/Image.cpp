#include "Image.h"
#include <sstream>
#include <fstream>
#include <vector>
using namespace MPHFAR001 ;

Image::Image() 
{
    width = height = 0;image_name = "";
}

void Image::save(std::string file_string) 
{
    std::ofstream output_file(file_string,std::ios::binary);
    if(!output_file){
        std::cerr << "Something Went Wrong \n";
        exit(0);
    }       


    output_file << "P5\n# Created By Apollos Prime For CSC3022H Image Processing "<< file_string << std::endl;
    output_file << width << " " << height << std::endl << "255" << std::endl;
    ImageIterator image_iterator = this->begin();
    while (image_iterator != this->end()) {
        output_file << *image_iterator;
        image_iterator++;
    }
    output_file.close();
}

void Image::load(std::string file_string) {
    this->image_name = file_string;
    std::ifstream image_file_stream(file_string, std::ios::binary);
        if(!image_file_stream){
        std::cerr << "File path not found \n";
        exit(0);
    }

    std::string line;
    while (!image_file_stream.eof()) {
        getline(image_file_stream, line);
        if (line[0] == '#' || line == "P5") {
            continue;
        } else if (line == "255") { 
            break;
        } else {
            std::stringstream line_stream(line);
            std::string buff;
            getline(line_stream, buff, ' ');
            width = std::stoi(buff);
            getline(line_stream, buff, ' ');
            height = std::stoi(buff);
        }
    }
    unsigned char *image_data = new unsigned char [height*width];
    image_file_stream.read((char *)image_data, height*width);
    image_file_stream.close();
    data = std::unique_ptr<unsigned char []>(image_data);
}