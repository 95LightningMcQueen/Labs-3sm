#include "classLin.h"
#include "classKva.h"

int main()
{
    try
    {
        Linear l1(2.0, -4.0);
        l1.Print();
        l1.Solve();
        std::cout << '\n';

        Linear l2(1.0, 1.0);
        std::cout << "Linear l1:" << l1 << '\n' << "Linear l2: " << l2 << '\n';

        Linear sumL = l1 + l2;
        std::cout << "l1+ l2 = " << sumL << '\n';

        Linear diffL = l1 - l2;
        std::cout << "l1 - l2 = " << diffL << '\n';

        Linear prodL = l1 * l2;
        std::cout << "l1 * l2 = " << prodL << '\n';

        Linear domnozh = l1 * 2.0;
        std::cout << "l1 * 2.0 = " << domnozh << '\n';

        Linear divided = l1 / 2.0;
        std::cout << "l1 / 2.0 = " << divided << "\n\n";

        Kvadratnoe q1(2.0, -5.0, 2.0);
        std::cout << "Kvadratnoe q1: " << q1 << '\n';
        q1.Print();
        q1.Solve();
        std::cout << '\n';

        Kvadratnoe q2(1.0, 4.0, 4.0);
        std::cout << "Kvadratnoe q2: " << q2 << '\n';
        q2.Print();
        q2.Solve();
        std::cout << '\n';

        Kvadratnoe q3(1.0, 0.0, 1.0);
        std::cout << "Kvadratnoe q3: " << q3 << '\n';
        q3.Print();
        q3.Solve();
        std::cout << '\n';

        Kvadratnoe qsum = q1 + q2;
        std::cout << "q1 + q2 = " << qsum << '\n';

        Kvadratnoe qdiff = q1 - q2;
        std::cout << "q1 - q2 = " << qdiff << '\n';

        Kvadratnoe qdomnozh = q1 * 0.5;
        std::cout << "q1 * 0.5 = " << qdomnozh << '\n';

        Kvadratnoe qdiv = q1 / 2.0;
        std::cout << "q1 / 2.0 = " << qdiv << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    return 0;
}