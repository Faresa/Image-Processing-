#include "Image.h"
using namespace std;
using namespace MPHFAR001;
int main(int argc,  const char* argv[]) {
    if (argc < 2) {
        cout << "Too few arguments." << endl;
        return 0;
    }
    MPHFAR001::Image image_result;
    string option(argv[1]) , image_string(argv[2]);
    MPHFAR001::Image first_image ,second_image;
    first_image << image_string;

    string output_file = argv[argc-1];
  

    if (option == "-a") { 
        second_image << argv[3];
        image_result = first_image + second_image;
    } else if (option == "-s") { 
        second_image << argv[3];
        image_result = first_image - second_image;
    } else if (option == "-i") { 
        image_result = !first_image;
        image_result >> output_file;
    } else if (option == "-l") { 
        second_image << argv[3];
        image_result = first_image / second_image;
    } else if (option == "-t") { 
        int threshold = stoi(argv[3]);
        image_result = first_image * threshold;
    } else {
        cout << "\n\tSORRY\nCommand: " << option << " failed"<<endl<<endl;
        return 0;
    }
    image_result >> output_file;
    return 0;
}
