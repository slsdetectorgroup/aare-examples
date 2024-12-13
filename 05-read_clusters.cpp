

#include "aare/ClusterFile.hpp"
#include <cstdint>
#include <filesystem>
#include <fmt/core.h>

int main() {

    auto path = std::filesystem::path(
        "/mnt/sls_det_storage/moench_data/moenchLGAD_maxIV_202403/clust/"
        "En1800eV_300V_0deg_W17_ExitSlit3");
    auto fname = path / "En1800eV_300V_0deg_W17_xray_d0_f0_24.clust";

    aare::ClusterFile cf(fname);

    size_t chunk_size = 1000;
    auto clusters = cf.read_clusters(chunk_size);
    fmt::print("sizeof(aare:Cluster): {}\n", sizeof(aare::Cluster));
    fmt::print("----------------\n");
    for (size_t i = 0; i < 10; i++) {
        fmt::print("cl.x {}\n", clusters[i].x);
        fmt::print("cl.y {}\n", clusters[i].y);

        int32_t t2;
        int32_t t3;
        char quad;
        double eta2x;
        double eta2y;
        double eta3x;
        double eta3y;

        
        cf.analyze_cluster(clusters[i], &t2, &t3, &quad, &eta2x, &eta2y, &eta3x, &eta3y);
        
        fmt::print("t2: {}\n", t2);
        fmt::print("----------------\n");
    }
}