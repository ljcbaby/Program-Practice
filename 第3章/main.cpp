#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cstring>

template <typename T>
inline void swap(T& a, T& b) {
    T t = a;a = b;b = t;
}

template <typename T>
inline void BubbleSort(T begin, T end) {
    int n = end - begin;
    int left = 0, right = n - 1;
    int flag;
    while (left < right) {
        flag = 1;
        for (int i = left; i < right; i++) {
            if (begin[i] > begin[i + 1]) {
                swap(begin[i], begin[i + 1]);
                flag = 0;
            }
        }
        if (flag) break;
        right--;
        flag = 1;
        for (int i = right; i > left; i--) {
            if (begin[i] < begin[i - 1]) {
                swap(begin[i], begin[i - 1]);
                flag = 0;
            }
        }
        if (flag) break;
        left++;
    }
}

template <typename T>
inline void SelectSort(T begin, T end) {
    int n = end - begin;
    int left = 0, right = n - 1;
    while (left < right) {
        int min = right;
        int max = right;
        for (int i = left; i < right; i++) {
            if (begin[i] > begin[max]) max = i;
            if (begin[i] < begin[min]) min = i;
        }
        swap(begin[min], begin[left]);
        if (max == left) max = min;
        swap(begin[max], begin[right]);
        left++;
        right--;
    }
}

template <typename T>
inline void InsertSort(T begin, T end) {
    int n = end - begin;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        typename std::iterator_traits<T>::value_type key = begin[i];
        while (j >= 0 && begin[j] > key) {
            begin[j + 1] = begin[j];
            j--;
        }
        begin[j + 1] = key;
    }
}

template <typename T>
inline void QuickSort(T begin, T end) {
    std::stack<std::pair<T, T>> s;
    s.push(std::make_pair(begin, end));
    srand(time(NULL));
    while (!s.empty()) {
        begin = s.top().first;
        end = s.top().second;
        s.pop();
        if (begin >= end) continue;
        T left = begin;
        T right = end - 1;
        swap(begin[rand() % (end - begin)], begin[0]);
        typename std::iterator_traits<T>::value_type key = *begin;
        while (left < right) {
            while (left < right && *right >= key) right--;
            if (left < right) *left++ = *right;
            while (left < right && *left <= key) left++;
            if (left < right) *right-- = *left;
        }
        *left = key;
        s.push(std::make_pair(left + 1, end));
        s.push(std::make_pair(begin, left));
    }
}

template <typename T>
inline void MergeSort(T begin, T end) {
    int len = end - begin;
    T a = begin;
    T b = new typename std::iterator_traits<T>::value_type[len];
    int seg, start;
    for (seg = 1; seg < len; seg <<= 1) {
        for (start = 0; start < len; start += 2 * seg) {
            int left = start;
            int mid = std::min(start + seg, len);
            int right = std::min(start + 2 * seg, len);
            int pos = left;
            int s1 = left, e1 = mid;
            int s2 = mid, e2 = right;
            while (s1 < e1 && s2 < e2)
                b[pos++] = a[s1] < a[s2] ? a[s1++] : a[s2++];
            while (s1 < e1) b[pos++] = a[s1++];
            while (s2 < e2) b[pos++] = a[s2++];
        }
        T tmp = a;
        a = b;
        b = tmp;
    }
    if (a != begin) {
        for (int i = 0; i < len; i++)
            begin[i] = a[i];
        b = a;
    }
    delete[ ] b;
}

template <typename T>
inline void HeapSort(T begin, T end) {
    int len = end - begin;
    for (int i = len / 2 - 1; i >= 0; i--) {
        int j = i;
        while (j * 2 + 1 < len) {
            int k = j * 2 + 1;
            if (k + 1 < len && begin[k] < begin[k + 1]) k++;
            if (begin[j] < begin[k]) {
                swap(begin[j], begin[k]);
                j = k;
            } else break;
        }
    }
    for (int i = len - 1; i > 0; i--) {
        swap(begin[0], begin[i]);
        int j = 0;
        while (j * 2 + 1 < i) {
            int k = j * 2 + 1;
            if (k + 1 < i && begin[k] < begin[k + 1]) k++;
            if (begin[j] < begin[k]) {
                swap(begin[j], begin[k]);
                j = k;
            } else break;
        }
    }
}

template <typename T>
inline void HeapSortSimple(T begin, T end) {
    std::priority_queue<typename std::iterator_traits<T>::value_type> q;
    for (T i = begin; i < end; i++)
        q.push(*i);
    for (T i = end - 1; i >= begin; i--) {
        *i = q.top();
        q.pop();
    }
}

template <typename T>
inline void OneBucketSort(T begin, T end) {
    std::map<typename std::iterator_traits<T>::value_type, int> m;
    for (T i = begin; i < end; i++)
        m[*i]++;
    int pos = 0;
    for (auto i = m.begin(); i != m.end(); i++) {
        for (int j = 0; j < i->second; j++)
            begin[pos++] = i->first;
    }
}

template <typename T>
inline void ShellSort(T begin, T end) {
    int len = end - begin;
    int pos = 2;
    std::vector<int> gap;
    gap.push_back(1);
    gap.push_back(2);
    while (gap[pos - 1] < len) {
        gap.push_back(gap[pos - 1] + gap[pos - 2]);
        pos++;
    }
    pos -= 2;
    gap.pop_back();
    while (pos >= 0) {
        for (int i = gap[pos]; i < len; i++) {
            typename std::iterator_traits<T>::value_type key = begin[i];
            int j = i - gap[pos];
            while (j >= 0 && begin[j] > key) {
                begin[j + gap[pos]] = begin[j];
                j -= gap[pos];
            }
            begin[j + gap[pos]] = key;
        }
        pos--;
        gap.pop_back();
    }
}

template <typename T>
inline void CombSort(T begin, T end) {
    double shrink_factor = 0.9;
    int len = end - begin;
    int gap = int(len * shrink_factor);
    while (gap) {
        bool swapped = false;
        for (int i = 0; i < len - gap; i++) {
            if (begin[i] > begin[i + gap]) {
                swap(begin[i], begin[i + gap]);
                swapped = true;
            }
        }
        if (!swapped)
            gap = int(gap * shrink_factor);
    }
}

template <typename T>
inline void BucketSort(T begin, T end) {
    int len = end - begin;
    if (len < 1 << 16) {
        OneBucketSort(begin, end);
        return;
    }
    typename std::iterator_traits<T>::value_type max = *begin, min = *begin;
    for (T i = begin + 1; i < end; i++) {
        if (*i > max) max = *i;
        if (*i < min) min = *i;
    }
    if (max - min < 1 << 16) {
        OneBucketSort(begin, end);
        return;
    }
    std::vector<typename std::iterator_traits<T>::value_type>* bucket = new std::vector<typename std::iterator_traits<T>::value_type>[1 << 16];
    for (T i = begin; i < end; i++)
        bucket[(*i - min) >> 16].push_back(*i);
    for (int i = 0; i < 1 << 16; i++)
        ShellSort(bucket[i].begin(), bucket[i].end());
    int pos = 0;
    for (int i = 0; i < 1 << 16; i++) {
        for (typename std::vector<typename std::iterator_traits<T>::value_type>::iterator j = bucket[i].begin(); j != bucket[i].end(); j++)
            begin[pos++] = *j;
    }
    delete[ ] bucket;
}

inline void generate_source(int type, int number, int* arr) {
    if (type == 0 || type == 1 || type == 2) {
        srand(time(NULL));
        for (int i = 0; i < number; i++)
            arr[i] = rand();
    }
    if (type == 3) {
        for (int i = 0; i < number; i++)
            arr[i] = number - i;
    }
    if (type == 4 || type == 5) {
        for (int i = 0; i < number; i++)
            arr[i] = i;
    }
    if (type == 5) {
        srand(time(NULL));
        int rex = rand() % int(5 * log10(number));
        for (int i = 0; i < rex; i++) {
            int pos = rand() % (number - 1);
            swap(arr[pos], arr[pos + 1]);
        }
    }
    if (type == 6) {
        srand(time(NULL));
        int base = rand();
        int bandwise = number / int(10 * log10(number) - 10);
        for (int i = 0; i < number; i++)
            arr[i] = base + rand() % bandwise;
    }
}

int main() {
    freopen("1.out", "w", stdout);
    int test_num[ ] = { 100, 1000, 10000, 50000, 100000, 200000, 500000, 1000000 };
    const char* test_data_type[ ] = { "Randn1", "Randn2", "Randn3", "Inverse", "Preface", "About-Preface", "Narrowband" };
    printf("Clocks per second: %ld\n", CLOCKS_PER_SEC);
    printf("Data\tBubble\tSelect\tInsert\tstd::sort\tstd::stable_sort\tQuick\tMerge\tHeap\tHeapSTL\tOneBucket\tShell\tComb\tBucket\n");
    int* source = new int[test_num[sizeof(test_num) / sizeof(int) - 1]];
    int* sort = new int[test_num[sizeof(test_num) / sizeof(int) - 1]];
    for (unsigned long int i = 0; i < sizeof(test_num) / sizeof(int); i++) {
        int n = test_num[i];
        time_t t_begin, t_end;
        time_t tt_begin, tt_end;
        for (unsigned long int j = 0; j < sizeof(test_data_type) / sizeof(char*); j++) {
            fprintf(stderr, "%d-%s: ", n, test_data_type[j]);
            tt_begin = clock();

            printf("%d-%s\t", n, test_data_type[j]);
            generate_source(j, n, source);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            BubbleSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            SelectSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            InsertSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            std::sort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            std::stable_sort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            QuickSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            MergeSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            HeapSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            HeapSortSimple(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            OneBucketSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            ShellSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            CombSort(sort, sort + n);
            t_end = clock();
            printf("%ld\t", t_end - t_begin);

            memcpy(sort, source, sizeof(int) * n);
            t_begin = clock();
            BucketSort(sort, sort + n);
            t_end = clock();
            printf("%ld\n", t_end - t_begin);

            tt_end = clock();
            fprintf(stderr, "%ld Finished\n", tt_end - tt_begin);
        }
    }
    fclose(stdout);
    return 0;
}
