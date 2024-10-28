#include "aare/File.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <filesystem>

int main(int argc, char const *argv[]){
    if (argc < 2){
        fmt::print(fg(fmt::terminal_color::magenta), "Usage: {} <filename>\n", argv[0]);
        return 1;
    }

    try{
        aare::File f(argv[1], "r");
        fmt::print("Frames: {}, Rows: {}, cols: {}\n", f.total_frames(), f.rows(), f.cols());
    } catch (const std::exception &e){
        fmt::print(fg(fmt::terminal_color::red), "Error: {}\n", e.what());
    }

    
    return 0;
}