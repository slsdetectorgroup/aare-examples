#include <fmt/format.h>

#include <TH1D.h>
#include <TCanvas.h>

#include "aare/ClusterFile.hpp"
int main()
{
    TCanvas c("c", "c", 800, 600);
    TH1D h("h", "h", 10, 0, 10);

    for (int i = 0; i < 10; i++)
    {
        h.Fill(i);
    }
    return 0;
}