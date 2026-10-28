#include <iostream>
#include <chrono>

long long callCount = 0;

long long rpower(long long x, int n) {
    callCount++;
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

long long brpower(long long x, int n) {
    callCount++;
    if (n == 0) return 1;
    if (n % 2 == 1) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    for (int n : {8, 16, 32, 64, 128, 256, 512, 1024}) {
        callCount = 0;
        
        auto b = std::chrono::steady_clock::now();
        rpower(1, n); 
        auto e = std::chrono::steady_clock::now();
        long long rc = callCount;
        auto rt = std::chrono::duration_cast<std::chrono::nanoseconds>(e - b).count();
        
        callCount = 0;
        b = std::chrono::steady_clock::now();
        brpower(1, n);
        e = std::chrono::steady_clock::now();
        auto bt = std::chrono::duration_cast<std::chrono::nanoseconds>(e - b).count();
        
        std::cout << "n = " << n << " | rpower: calls = " << rc << ", " << rt  << " ns | brpower: calls = " << callCount << ", " << bt << " ns" << std::endl;
    }
    
    return 0;
}