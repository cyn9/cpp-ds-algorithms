#include <iostream>
#include <cassert>

int binarySearch(const int [], const std::size_t &, const int &);
void print(const int [], std::size_t);

int main() {
    int value {0};
    std::size_t N {0};

    std::cout << "Enter number of elements >> ";
    std::cin >> N;

    int arr[N];

    std::cout << "Enter the array elements >> ";
    for (auto i = 0; i < N; ++i)
        std::cin >> arr[i];
    
    std::cout << "Enter an item to be searched >> ";
    std::cin >> value;

    //  Make sure the array is sorted.
    if (!std::is_sorted(arr, arr + N)) {
        std::cout << "The array is not sorted. >> ";
        print(arr, N);
        std::cout << "Sorting using std::sort().\n";
        std::sort(arr, arr + N);
    }

    std::cout << "The array is sorted. >> ";
    print(arr, N);

    // Return the position of the value in the array:
    // Return -1 if not found.
    int pos = binarySearch(arr, N, value);

    // Invalid index check (-1)
    if (pos != -1)
        std::cout << "Found " << value << " at index " << pos << ".\n";
    else
        std::cout << "Not found.\n";

    return 0;
}

int binarySearch(const int A[], const std::size_t &N, const int &value) {
    std::size_t start {0};
    std::size_t end {N - 1};

    while (start <= end) {
        // Find mid index using this instead of (s+e)/2 in order to avoid
        // integer overflow (just in case e+s might be greater than INT_MAX).
        int mid = start + (end-start)/2;
        assert(mid > 0);

        if (A[mid] == value)     { return mid;      }
        else if (A[mid] > value) { end = mid - 1;   }
        else                     { start = mid + 1; }
    }
    
    return -1;
}

void print(const int arr[], std::size_t N) {
    std::cout << "[ ";
    for (std::size_t i = 0; i < N; ++i) 
        std::cout << arr[i] << " ";
    
    std::cout << "]\n";
}