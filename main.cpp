#include <bits/stdc++.h>

#include "board.hpp"
#include "common.hpp"
#include "position.hpp"
#include "solver.hpp"

using namespace std;





void test1() {
    const string input(1+R"(
5 3
#.<.....
.>...#0.
.#.^.0##
1#.#.#.1
..v.#...
.^.2#.v.
<.>#....
.v.2#.<<
)");

    auto pos = from_str<Position>(input);
    ASSERT(to_str(pos) == input);
    ASSERT(pos.player() == (1ULL<<yx2idx(3,5)));
    ASSERT(bitboard_str(pos.board(TL_U)) == 1+R"(
00000000
00000000
00010000
00000000
00000000
01000000
00000000
00000000
)");
    ASSERT(bitboard_str(pos.board(TL_D)) == 1+R"(
00000000
00000000
00000000
00000000
00100000
00000010
00000000
01000000
)");
    ASSERT(bitboard_str(pos.board(TL_L)) == 1+R"(
00100000
00000000
00000000
00000000
00000000
00000000
10000000
00000011
)");
    ASSERT(bitboard_str(pos.board(TL_R)) == 1+R"(
00000000
01000000
00000000
00000000
00000000
00000000
00100000
00000000
)");
    ASSERT(bitboard_str(pos.board(TL_WALL)) == 1+R"(
10000000
00000100
01000011
01010100
00001000
00001000
00010000
00001000
)");
    ASSERT(bitboard_str(pos.board(TL_PC0)) == 1+R"(
00000000
00000010
00000100
00000000
00000000
00000000
00000000
00000000
)");
    ASSERT(bitboard_str(pos.board(TL_PC1)) == 1+R"(
00000000
00000000
00000000
10000001
00000000
00000000
00000000
00000000
)");
    ASSERT(bitboard_str(pos.board(TL_PC2)) == 1+R"(
00000000
00000000
00000000
00000000
00000000
00010000
00000000
00010000
)");
    ASSERT(pos.board(TL_PC3) == 0);

    {
        u64 u,d,l,r; tie(u,d,l,r) = pos.moves();
        ASSERT(bitboard_str(u) == 1+R"(
00000000
00000000
00010000
00000000
00000000
00000000
00000000
00000000
)");
        ASSERT(bitboard_str(d) == 1+R"(
00000000
00000000
00000000
00000000
00100000
00000010
00000000
00000000
)");
        ASSERT(bitboard_str(l) == 1+R"(
00100000
00000000
00000000
00000000
00000000
00000000
00000000
00000011
)");
        ASSERT(bitboard_str(r) == 1+R"(
00000000
01000000
00000000
00000000
00000000
00000000
00000000
00000000
)");
    }






}

void test2() {
    const string input(1+R"(
0 1
########
.>######
######v#
0#0#####
#0######
#^######
#####<##
########
)");

    auto pos = from_str<Position>(input);
    ASSERT(to_str(pos) == input);
    ASSERT(pos.player() == (1ULL<<yx2idx(1,0)));

    {
        u64 u,d,l,r; tie(u,d,l,r) = pos.moves();
        ASSERT(bitboard_str(u) == 1+R"(
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
)");
        ASSERT(bitboard_str(d) == 1+R"(
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
)");
        ASSERT(bitboard_str(l) == 1+R"(
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
)");
        ASSERT(bitboard_str(r) == 1+R"(
00000000
01000000
00000000
00000000
00000000
00000000
00000000
00000000
)");
    }
}

int test() {
    test1();
    test2();

    return 0;
}

int main(int argc, char** argv) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed;
    cerr << fixed;

    if(argc == 2 && strcmp(argv[1],"-test") == 0)
        return test();

    auto pos = Position::read_from(cin);

    Solver solver;
    auto sols = solver.solve(pos);

    for(const auto& sol : sols) {
        cout << sol_str(sol) << "\n";
    }

    return 0;
}
