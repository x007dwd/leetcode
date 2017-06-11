#include <algorithm>
#include <iostream>
#include <sys/time.h>
#include <vector>

using namespace std;
typedef pair<pair<int, int>, float> pos_val;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";

  for (int i = 0, len = v.size(); i < len; i++) {
    if (i != 0) {
      os << ", ";
    }

    os << v[i];
  }

  os << "]";

  return os;
}

vector<vector<float>> generateFSRandomMatrix(int rows, int columns,
                                             float rate) {
  vector<vector<float>> matrix(rows, vector<float>(columns, 0));
  for (int j = 0; j < rows; ++j) {
    for (int i = 0; i < columns; ++i) {
      matrix[j][i] = 0;
    }
  }
  int total = (int)(rows * columns * rate);
  std::vector<int> indexVector;
  for (int i = 0; i < rows * columns; ++i) {
    indexVector.push_back(i); // 0----m*n
  }
  std::random_shuffle(indexVector.begin(), indexVector.end());

  int N = 0, col_idx = 0, row_idx = 0;

  for (int i = 0; i < total; ++i) {
    N = indexVector.at(i);
    col_idx = N % columns;
    row_idx = N / rows;
    // cout << "row:" << row_idx << "\t" << "col:" << col_idx << endl;
    matrix[row_idx][col_idx] = rand() / 1.0 / RAND_MAX * 13.5 + 2.0;
  }
  return matrix;
}

vector<vector<float>> sparse_multiply(vector<vector<float>> &A,
                                      vector<vector<float>> &B) {
  if (A.empty() || A[0].empty() || B[0].empty())
    return vector<vector<float>>();
  vector<pos_val> map_A, map_B; // store nonzero values of A and B
  int n = A.size(), m = B[0].size(), mid = B.size();
  vector<vector<float>> C(n, vector<float>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < mid; ++j) {
      if (abs(A[i][j]) > 1) {
        pos_val tmp(pair<int, int>(i, j), A[i][j]);
        map_A.push_back(tmp);
      }
    }
  }
  for (int i = 0; i < mid; ++i) {
    for (int j = 0; j < m; ++j) {
      if (abs(B[i][j]) > 1) {
        pos_val tmp(pair<int, int>(i, j), B[i][j]);
        map_B.push_back(tmp);
      }
    }
  }
  for (int i = 0; i < map_A.size(); ++i) {
    for (int j = 0; j < map_B.size(); ++j) {
      if (map_A[i].first.second == map_B[j].first.first)
        C[map_A[i].first.first][map_B[j].first.second] +=
            map_A[i].second * map_B[j].second;
    }
  }

  return C;
}

void testMatricesMultiplication(bool verbose) {

  cout << "\rmatrices A and B multiplication. Matrix A has dimensionality m × "
          "n,\n"
          "whereas matrix B has dimensionality n × k.#"
       << flush;

  // generate random matrices
  int rowsA, colsArowsB, colsB;
  cout << "Please input the m, n, k" << endl;
  cin >> rowsA;
  cin >> colsArowsB;
  cin >> colsB;
  float rate = 0.05;

  vector<vector<float>> classicMatrixA =
      generateFSRandomMatrix(rowsA, colsArowsB, rate);
  vector<vector<float>> classicMatrixB =
      generateFSRandomMatrix(colsArowsB, colsB, rate);

  if (verbose) {

    cout << "output matrix A value" << endl;
    for (int l = 0; l < classicMatrixA.size(); ++l) {
      cout << classicMatrixA[l] << endl;
    }

    cout << "output matrix B value" << endl;
    for (int l = 0; l < classicMatrixB.size(); ++l) {
      cout << classicMatrixB[l] << endl;
    }
  }

  vector<vector<float>> manualResult(rowsA, vector<float>(colsB, 0));
  vector<vector<float>> sResult(rowsA, vector<float>(colsB, 0));

  timeval t0, t1, t2;

  gettimeofday(&t0, 0);

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
      manualResult[i][j] = 0;

      for (int k = 0; k < colsArowsB; k++) { // rows in B
        manualResult[i][j] += classicMatrixA[i][k] * classicMatrixB[k][j];
      }
    }
  }

  gettimeofday(&t1, 0);

  sResult = sparse_multiply(classicMatrixA, classicMatrixB);
  gettimeofday(&t2, 0);

  long elapsed = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
  cout << "traditional matrix multiplication scheme use time \n" << elapsed
       << "us" << endl;
  if (verbose) {

    cout << " output the result" << endl;
    for (int l = 0; l < manualResult.size(); ++l) {
      cout << manualResult[l] << endl;
    }
  }
  elapsed = (t2.tv_sec - t1.tv_sec) * 1000000 + t2.tv_usec - t1.tv_usec;
  cout << "sparse matrix multiplication scheme use time \n" << elapsed << "us"
       << endl;
  if (verbose) {

    cout << " output the result" << endl;
    for (int l = 0; l < sResult.size(); ++l) {
      cout << sResult[l] << endl;
    }
  }

  cout << " OK" << endl;
}

int main(int argc, char **argv) {
  srand(time(NULL)); // used at random matrices / vectors generating

  testMatricesMultiplication(false);
  return 0;
}
