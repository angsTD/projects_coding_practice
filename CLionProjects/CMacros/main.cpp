#include <iostream>

using namespace std;

#define CHECK_ERROR()\
{\
printf("check error\n");\
}


#define CUBE(a) a*a*a
#define square(x) x*x

int main() {
    std::cout << "Hello, World!" << std::endl;
    CHECK_ERROR();
    int a = CUBE((1+2));
    printf("cube: %d\n",a);
    int x = 36/(square(6)); // Expended as 36/6*6
    printf("%d\n\n", x);


    printf("Current File :%s\n", __FILE__ );
    printf("Current Date :%s\n", __DATE__ );
    printf("Current Time :%s\n", __TIME__ );
    printf("Line Number :%d\n", __LINE__ );

    return 0;
}