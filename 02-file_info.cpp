#include "aare/File.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

int main(int argc, char const *argv[]){
    //First argument is the name of the program, as second we expect the filename
    if (argc < 2){
        fmt::print(fg(fmt::terminal_color::magenta), "Usage: {} <filename>\n", argv[0]);
        return 1;
    }

    //Wrap the code in a try-catch block since we don't know if the file exists
    try{
        aare::File f(argv[1]);
        fmt::print("Frames: {}, Rows: {}, cols: {}\n", f.total_frames(), f.rows(), f.cols());
        return 0;
    } catch (const std::exception &e){
        fmt::print(fg(fmt::terminal_color::red), "Error: {}\n", e.what());
        return 1;
    }
    
}