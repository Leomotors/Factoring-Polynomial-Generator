#include <vector>
#include <utility>

#include "polynomial.hpp"
#include "polyrand.hpp"
#include "generator.hpp"

namespace PolyGenerator
{
    Polynomial curr_poly;
    std::vector<std::pair<int, int>> curr_roots;

    Polynomial random(int degree, int num_range, int dr_range)
    {
        std::vector<std::pair<int, int>> roots = randPoly(degree, num_range, dr_range);

        int count = roots.size();
        std::vector<int> base_vec({-roots[0].first, roots[0].second});
        Polynomial base(base_vec);
        for (int i = 1; i < count; i++)
        {
            std::vector<int> temp_vec({-roots[i].first, roots[i].second});
            Polynomial temp(temp_vec);
            base = base * temp;
        }
        curr_poly = base;
        curr_roots = roots;
        return base;
    }

    Polynomial getCurrPoly()
    {
        return curr_poly;
    }

    std::vector<std::pair<int, int>> getCurrRoots()
    {
        return curr_roots;
    }
}
