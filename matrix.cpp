#include <iostream>

using namespace std;


class Mat{
  public:
    static double dot(double v1[], double v2[], int size){
      double out;
      for (int i = 0; i < size; i++){
        out += v1[i] * v2[i];
      }
      return out;
    }

    double *col(int n){
      double *out = new double[this->rows];
      for (int i = 0; i < this->rows; i++){
        out[i] = this->getAt(i, n);
      }

      return out;
    }

  public:
    double **data;
    int cols;
    int rows;
    Mat(int rows, int cols){
      this->data = new double*[rows];
      this->rows = rows;
      this->cols = cols;
      for (int i = 0; i < rows; i++){
        data[i] = new double[cols];
      }
    }
    void setAt(int row, int col, int val){
      this->data[row][col] = val;
    }
    double getAt(int row, int col){
      return this->data[row][col];
    }

    ~Mat(){
      for (int i = 0; i < rows; i++){
        data[i] = new double[cols];
      }
      delete[] data;

    }

    void getFromInput(){
      int temp;
      for (int i = 0; i < this->rows; i ++){
        for (int j = 0; j < this->cols; j++){
          cout << i << " " << j << " entry: ";
          cin >> temp;
          this->setAt(i,j,temp);
        }
      }
    }


    void printOut(){
      for (int i = 0; i < this->rows; i ++){
        for (int j = 0; j < this->cols; j++){
          cout << this->getAt(i, j) << " ";
        }
        cout << endl;
      }

    }

    Mat operator * (Mat &other){
      int rows = this->rows, columns = other.cols;
      Mat out(rows, columns);
      for (int i = 0; i < rows; i ++){
        for (int j = 0; j < columns; j++){
          int entry =  Mat::dot(this->data[j], this->col(i), rows);
          out.setAt(i, j, entry);
        }
      }
      return out;
    }

};

int main(){ 
  int colA, rowA, colB, rowB;
  cout << "Input the sizes of the matricies: ";
  cin >> rowA >> colA >> rowB >> colB;
  Mat A(rowA, colA);
  A.getFromInput();
  Mat B(rowB, colB);
  B.getFromInput();
  Mat C = A * B;
  C.printOut();
}
