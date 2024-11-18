#include <fmt/color.h>
#include <fmt/format.h>
#include <numeric>

#include "aare/ClusterFile.hpp"
#include <TApplication.h>
#include <TCanvas.h>
#include <TH1D.h>
int main(int argc, char const *argv[]) {
    // Needed to keep the TCanvas open
    TApplication app("app", nullptr, nullptr);

    // First argument is the name of the program, as second we expect the
    // filename
    if (argc < 2) {
        fmt::print(fg(fmt::terminal_color::magenta), "Usage: {} <filename>\n",
                   argv[0]);
        return 1;
    }

    // Set up a canvas and a histogram
    constexpr int n_bins = 100;
    constexpr double xmin = 0;
    constexpr double xmax = 25000;
    TCanvas c("c", "c", 800, 600);
    TH1D h("hist_name", "hist_title", n_bins, xmin, xmax);

    aare::ClusterFile f(argv[1]);
    size_t chunk_size = 1000;

    // Loop over all clusters in the file and fill the histogram with the sum of
    // all pixel values in the cluster
    for (auto clusters = f.read_clusters(chunk_size); !clusters.empty();
         clusters = f.read_clusters(chunk_size)) {
        for (const auto &cluster : clusters) {
            h.Fill(std::accumulate(std::begin(cluster.data),
                                   std::end(cluster.data), 0.0));
        }
    }
    c.SetLogy();

    h.Draw();
    c.Update();

    app.Run();
    return 0;
}