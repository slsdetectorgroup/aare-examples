#include "aare/File.hpp"
#


#include <fmt/core.h>
#include <fmt/color.h>

int main(int argc, char const *argv[]){
    //First argument is the name of the program, as second we expect the filename
    if (argc < 2){
        fmt::print(fg(fmt::terminal_color::magenta), "Usage: {} <filename>\n", argv[0]);
        return 1;
    }


    //open the file and read the first frame
    aare::File f(argv[1]);
    auto frame = f.read_frame(); // allocated the memmory and returns a generic frame object

    //Lets look at it as 16bit unsigned integers (hoping it's a jungfrau image)
    auto view = frame.view<uint16_t>();

    fmt::print("Image size: {}x{}\n", frame.rows(), frame.cols());
    fmt::print("Pixel 45,200: {}\n", view(45, 200));


    //We can also read into our own buffer
    auto* buffer = new uint16_t[f.pixels_per_frame()];
    f.read_into(reinterpret_cast<std::byte*>(buffer));

    fmt::print("Pixel 0: {}\n", buffer[0]);

    // Don't forget =) 
    delete[] buffer;


    // For header access etc. you have to use the RawFile class directly

    
}