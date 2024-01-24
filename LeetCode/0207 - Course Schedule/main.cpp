#include "solution.h"
using namespace Solution;

int main() {
    vector<vector<int>> prerequisites = {{1, 0}, {0,1}};
    int numCourses = 2;

    cout << canFinish(numCourses, prerequisites);

    return -1;
}



