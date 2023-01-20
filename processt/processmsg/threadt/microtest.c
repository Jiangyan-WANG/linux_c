#define DEBUG
#ifdef DEBUG
#define PRINT(x) printf((x))
#else
#define PRINT(x)
#endif

int main(){

    PRINT("hello");
    return 0;
}
