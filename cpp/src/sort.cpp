#include <iostream>
#include <vector>
using namespace std;
class sortSolution {
public:
  void merge(std::vector<int> &A, int m, std::vector<int> &B, int n) {
    int ia = m - 1;
    int ib = n - 1;
    int icur = m + n - 1;
    while (ia >= 0 && ib >= 0) {
      A[icur--] = A[ia] > B[ib] ? A[ia--] : B[ib--];
    }
    while (ib >= 0) {
      A[icur--] = B[ib--];
    }
  }
  double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    const int m = A.size();
    const int n = B.size();
    int total = m + n;
    if (total & 0x1)
      return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
    else
      return (find_kth(A.begin(), m, B.begin(), n, total / 2) +
              find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) /
             2.0;
  }

private:
  static int find_kth(std::vector<int>::const_iterator A, int m,
                      std::vector<int>::const_iterator B, int n, int k) {
    // always assume that m is equal or smaller than n
    if (m > n)
      return find_kth(B, n, A, m, k);
    if (m == 0)
      return *(B + k - 1);
    if (k == 1)
      return min(*A, *B);
    // divide k into two parts
    int ia = min(k / 2, m), ib = k - ia;
    if (*(A + ia - 1) < *(B + ib - 1))
      return find_kth(A + ia, m - ia, B, n, k - ia);
    else if (*(A + ia - 1) > *(B + ib - 1))
      return find_kth(A, m, B + ib, n - ib, k - ib);
    else
      return A[ia - 1];
  }

  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    std::vector<int> result;
    size_t inum = nums.size();
    size_t ileft = 0, iright = inum;
    size_t idx = (ileft + iright) / 2;
    while (ileft < iright) {

      if (nums[idx] == target) {
        result.push_back(idx);
        break;
      } else if (nums[idx] < target) {
        ileft = idx;
      } else if (nums[idx] > target) {
        iright = idx;
      }
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  sortSolution ssl;
  std::vector<int> va;
  std::vector<int> vb;
  va.reserve(20);
  for (size_t i = 0; i < 4; i++) {
    va.push_back(i * 5);
    vb.push_back(i * 5 + 1);
  }
  vb.push_back(200);
  // ssl.merge(va, 3, vb, 10);
  std::cout << "Arrays A" << '\n';
  for (size_t i = 0; i < va.size(); i++) {
    std::cout << va[i] << '\t';
  }

  std::cout << "\nArrays B" << '\n';
  for (size_t i = 0; i < vb.size(); i++) {
    std::cout << vb[i] << '\t';
  }
  std::cout << '\n';
  std::cout << "the Median of Sorted Arrays is \t"
            << ssl.findMedianSortedArrays(va, vb) << std::endl;
  std::vector<int> vc;
  vc.push_back(1);
  std::cout << '\n';
  std::cout << "the Median of Sorted Arrays is \t"
            << ssl.findMedianSortedArrays(vc, vb) << std::endl;
  return 0;
}
