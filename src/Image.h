#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <string>
#include <iostream>


namespace MPHFAR001  {
    class Image {
    public:
        Image();
        Image(std::string file_string) {
            this->load(file_string);
        }
        void load(std::string file_string);
        void save(std::string file_string);
        std::string image_name;
        int width , height;
        std::unique_ptr<unsigned char[]> data;


        Image(const Image &rhs) {
            this->image_name = rhs.image_name;
            this->width = rhs.width;
            this->height = rhs.height;
            this->load(this->image_name);
        }
        Image(Image &&rhs) {
            this->image_name = std::move(rhs.image_name);
            this->width = rhs.width;
            this->height = rhs.height;
            this->data = std::move(rhs.data);
        }

        Image &operator=(const Image &rhs) {
            this->width = rhs.width;
            this->height = rhs.height;
            this->load(rhs.image_name);
            return *this;
        }
        Image &operator=(Image &&rhs) {
            this->width = rhs.width;
            this->height = rhs.height;
            this->data = std::move(rhs.data);
            return *this;
        }
        Image operator+=(const Image &rhs_image) {
            ImageIterator rhs_iterator = this->begin();
            ImageIterator lhs_iterator = rhs_image.begin();
            while (rhs_iterator != this->end()) {
                if ((*rhs_iterator + *lhs_iterator) > 255) {
                    *rhs_iterator = 255;
                } else {
                    *rhs_iterator = *rhs_iterator + *lhs_iterator;
                }
                rhs_iterator++;lhs_iterator++;
            }
            return *this;
        }
        Image operator+(const Image &rhs_image) {
            Image lhs_image(*this);
            if (lhs_image.width != rhs_image.width || lhs_image.height != rhs_image.height) {
                std::cout << "Please choose images of The same size , height & width." << std::endl;
                exit(0);
            }
            lhs_image += rhs_image;
            return lhs_image;
        }
        Image operator-=(const Image &rhs_image) {
            ImageIterator rhs_iterator = this->begin();
            ImageIterator lhs_iterator = rhs_image.begin();
            while (rhs_iterator != end()) {
                if ((*rhs_iterator - *lhs_iterator) < 0) {
                    *rhs_iterator = 0;
                } else {
                    *rhs_iterator = *rhs_iterator - *lhs_iterator;
                }
                rhs_iterator++;lhs_iterator++;
            }
            return *this;
        }

        Image operator-(const Image &rhs_image) {
            Image lhs_image(*this);
            if (lhs_image.width != rhs_image.width || lhs_image.height != rhs_image.height) {
                std::cout << "Please choose images of The same size , height & width." << std::endl;
                exit(0);
            }
            lhs_image -= rhs_image;
            return lhs_image;
        }
        Image operator/(const Image &rhs_image) {
            Image lhs_image(*this);
            if (lhs_image.width != rhs_image.width || lhs_image.height != rhs_image.height) {
                std::cout << "Please choose images of The same size , height & width." << std::endl;
                exit(0);
            }

            ImageIterator rhs_iterator = lhs_image.begin();
            ImageIterator lhs_iterator = rhs_image.begin();

            while (rhs_iterator != lhs_image.end()) {
                if (*lhs_iterator == 0) {
                    *rhs_iterator = 0;
                }
                rhs_iterator++;lhs_iterator++;
            }
            return lhs_image;
        }
        Image operator!() {
            Image lhs_image(*this);
            ImageIterator rhs_iterator = lhs_image.begin();
            while (rhs_iterator != lhs_image.end()) {
                *rhs_iterator = (unsigned char) (255 - *rhs_iterator);
                rhs_iterator++;
            }
            return lhs_image;
        }
        Image operator*(const int threshold) {
            Image lhs_image(*this);
            ImageIterator rhs_iterator = lhs_image.begin();
            while (rhs_iterator != lhs_image.end()) {
                *rhs_iterator = (unsigned char) ((*rhs_iterator > threshold) ? 255 : 0);
                rhs_iterator++;
            }
            return lhs_image;
        }



        bool operator==(const Image img) {
            if (this->height != img.height || this->width != img.width) {
                return false;
            }
            ImageIterator rhs_iterator = this->begin();
            ImageIterator lhs_iterator = img.begin();
            while (rhs_iterator != this->end()) {
                if (*rhs_iterator != *lhs_iterator) {
                    return false;
                }
                rhs_iterator++;lhs_iterator++;
            }
            return true;
        }



        void operator<<(const std::string file_string) {
            this->load(file_string);
        }
        void operator>>(const std::string file_string) {
            this->save(file_string);
        }


    

        class ImageIterator {
        private:
      
            unsigned char * pointer;
            int index;
        public:

            ImageIterator(unsigned char *ptr) : pointer(ptr), index(0) { }
            ImageIterator(unsigned char *ptr, int count) : pointer(ptr), index(count) { }
            ImageIterator(const ImageIterator &copyIter) : pointer(copyIter.pointer), index(copyIter.index){ }
            ImageIterator &operator=(const ImageIterator &rhs) {
                this->pointer = std::move(rhs.pointer);
                this->index = rhs.index;
                return *this;
            }
            ImageIterator &operator++() 
            {
                ++index;
                return *this;
            }
            ImageIterator operator++(int) 
            {
                ImageIterator iteration(*this);
                operator++();
                return iteration;
            }

            ImageIterator &operator--() 
            {
                --index;
                return *this;
            }

            ImageIterator operator--(int) 
            {
                ImageIterator iteration(*this);
                operator--();
                return iteration;
            }

            unsigned char &operator*() 
            {
                return pointer[index];
            }
            bool operator!=(const ImageIterator &rhs) 
            {
                return index != rhs.index;
            }   
        };

         ImageIterator begin() const 
        {
            return ImageIterator(this->data.get());
        }
        ImageIterator end() {
            return ImageIterator(this->data.get(), width * height);
        }
    };
}

#endif //IMAGE_H
