
#include <iostream>
#include <cmath>
#include <vector>
#include<iomanip>
using namespace std;

const double PI = 3.141592653589793;
double h,k;
int N,M;


void initialize(vector<double>& u, vector<double>& u_new) {
    for (int i = 1; i < N; ++i) {
        double x = i * h;
        u[i] = sin(PI * x);
        u_new[i] = u[i];
    }
}

void apply_boundary_conditions(vector<double>& u) {
    u[0] = 0.0;
    u[N] = 0.0;
}

void print_results(const vector<double>& u, int step) {
    cout << "Time step " << step << ": ";
    for (int i = 0; i <= N; ++i) {
        cout << u[i] << " ";
    }
    cout << endl;
}

int main() {
    cout<<"Enter the value of h ";
    cin>>h;
     cout<<"Enter the value of k ";
    cin>>k;
     cout<<"Enter the number of time stps(M) ";
    cin>>M;
     cout<<"Enter the number of spatial steps ";
    cin>>N;
    vector<double> u(N + 1, 0.0);
    vector<double> u_new(N + 1, 0.0);
    vector<vector<double>> matrix(4,vector<double>(6,0));
    initialize(u, u_new);
    apply_boundary_conditions(u);
   
    for(int i=0;i<u.size();i++){
        matrix[0][i]=u[i];
    }
   cout<<fixed<< setprecision(4);
   
    for (int n = 0; n < M; ++n) {
        for (int i = 1; i < N; ++i) {
            u_new[i] = u[i] + (k / (h * h)) * (u[i - 1] - 2 * u[i] + u[i + 1]);
            matrix[n+1][i] = u_new[i];
        }
        apply_boundary_conditions(u_new);
        u.swap(u_new);
    }
     for(int i=3;i>=0;i--){
         cout<<"Time step "<<i<<": ";
        for(int j=0;j<6;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}